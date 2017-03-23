__Put your party hat on! The image loading time is ~75% faster on iOS 9.3 beta 2.__

Here is an example app launch comparison, profiled on an iPad Air 2:

```swift
// iOS 9.2
total time: 4.7 seconds (100.0%)
...
total images loading time: 3.9 seconds (82.5%)

// iOS 9.3 beta 2
total time: 1.7 seconds (100.0%)
...
total images loading time: 1.2 seconds (73.2%)
```

__Important note__: The performance improvement is in system libraries your binary dynamically links against. Users on iOS <9.3 won't see any difference even if your app is compiled with the Xcode 7.3 toolchain.

I still recommend using one of the workarounds described below, until your project's deployment target can be iOS 9.3 or higher.

The cost has been significantly reduced, but it's not free, so make sure you profile your launch time if you have a non-trivial app!

---

### Original issue

__tl;dr:__ _dyld takes too long to load frameworks, which makes apps slow to open_

[rdar://22920190](http://www.openradar.me/radar?id=6332266275930112)

### Problem

Since iOS 8, it is possible to ship dynamic libraries inside the app bundle to App Store. It is the way to ship Swift dependencies and to share your Swift code with extensions – you cannot use static libraries with Swift, plus frameworks allow you to share symbols instead of shipping them multiple times and inflating your bundle size.

There is a __major performance issue when using frameworks__ – the image loading/linking time that dyld takes during first app launch is so long, that a mid-sized app (i.e. an app with a couple of dozen dependencies) takes several seconds to open. On older devices, the app will often get killed by watchdog before managing to launch at all.

The linking time was bad on iOS 8, and the performance is notably worse on iOS 9.

### Reproducibility

Typically you add frameworks to your app through _Link Binary With Libraries_ step in Xcode, which results in a `-framework` flag passed to _ld_ during build, and consequently in a `LC_LOAD_DYLIB` command in the final executable. However, _dyld_ commands get executed before _lldb_ or _dtrace_ get attached, so it's hard to track down what's happening.

This example app doesn't link against the frameworks, but instead invokes `dlopen` manually during runtime, still consistently reproducing the issue. It uses a set of frameworks as built by `use_frameworks!` through CocoaPods. Presumably Carthage and manual dependencies through e.g. git submodules run into the same issue.

<img width="794" alt="screen shot 2015-09-30 at 10 50 54 am" src="https://cloud.githubusercontent.com/assets/2835783/10197718/f282b962-6766-11e5-8661-0722546555c3.png">

_Note: NSDate is a naïve way to measure performance, but it's good enough here since the operation is in the order of seconds here._

_Another note: Included frameworks only contain arm64 and armv7 slices, make sure you run the app on a physical device with one of these architectures. We want to be using dyld that ships with iOS anyway, iOS Simulator can possibly be using a different one._

### Example run

This is a sample measure `dlopen` takes when running the example on iPad Air 2 – on an iPad 2 the same operation takes 8(!) seconds.

```
Start: 2015-09-30 14:32:57 +0000
End: 2015-09-30 14:33:00 +0000
```

When using Instruments, only a fraction of the time taken is reported in time profiler. You can see below that only 215ms is attributed to _dyld_, while the thread was clearly blocked on `dlopen` for 3 seconds.

<img width="698" alt="screen shot 2015-09-30 at 11 16 44 am" src="https://cloud.githubusercontent.com/assets/2835783/10197701/ddbe596e-6766-11e5-9046-28b8e52309b6.png">

However, _dyld_ can profile the initialization time when passed `DYLD_PRINT_APIS` and `DYLD_PRINT_STATISTICS` environment variables. Combining this with "poor man's profiling" (pausing the process multiple times and seeing what the stack trace looks like), what seems to take the vast majority of time is phase 6 of loading a Mach-O image, more specifically the `ImageLoaderMachO::loadCodeSignature` function, even more specifically loading the signature from disk using `fcntl` ([full source](http://www.opensource.apple.com/source/dyld/dyld-353.2.3/src/ImageLoaderMachO.cpp)):

```cpp
siginfo.fs_file_start=offsetInFatFile;				// start of mach-o slice in fat file 
siginfo.fs_blob_start=(void*)(long)(codeSigCmd->dataoff);	// start of CD in mach-o file
siginfo.fs_blob_size=codeSigCmd->datasize;			// size of CD
int result = fcntl(fd, F_ADDFILESIGS, &siginfo);
```

---

### Workaround

It is possible to move all symbols (even when using Swift) into your app executable as suggested by [Accelerator](https://github.com/johnno1962/Accelerator). In this way, _dyld_ doesn't need to load the frameworks on launch. This only works if you are compiling the framework from source.

1. __Get rid of linker `-framework` flags and promise to provide `-filelist` instead.__ If you're using CocoaPods, it can be automated through a `post_install` step in Podfile.

  ```ruby
post_install do |installer|
  pods_target = installer.aggregate_targets.detect do |target|
  # Target label is either `Pods` or `Pods-#{name_of_your_main_target}` based on how complex your dependency graph is.
    target.label == "Pods"
  end

  puts '+ Removing framework dependencies'

  pods_target.xcconfigs.each_pair do |config_name, config|
    next if config_name == 'Test'
    config.other_linker_flags[:frameworks] = Set.new
    config.attributes['OTHER_LDFLAGS[arch=armv7]'] = '$(inherited) -filelist "$(OBJROOT)/Pods.build/$(CONFIGURATION)$(EFFECTIVE_PLATFORM_NAME)-armv7.objects.filelist"'
    config.attributes['OTHER_LDFLAGS[arch=arm64]'] = '$(inherited) -filelist "$(OBJROOT)/Pods.build/$(CONFIGURATION)$(EFFECTIVE_PLATFORM_NAME)-arm64.objects.filelist"'
    config.attributes['OTHER_LDFLAGS[arch=i386]'] = '$(inherited) -filelist "$(OBJROOT)/Pods.build/$(CONFIGURATION)$(EFFECTIVE_PLATFORM_NAME)-i386.objects.filelist"'
    config.attributes['OTHER_LDFLAGS[arch=x86_64]'] = '$(inherited) -filelist "$(OBJROOT)/Pods.build/$(CONFIGURATION)$(EFFECTIVE_PLATFORM_NAME)-x86_64.objects.filelist"'
    config.save_as(Pathname.new("#{pods_target.support_files_dir}/#{pods_target.label}.#{config_name}.xcconfig"))
  end

end
  ```
  
Notice that we don't remove frameworks `if config_name == 'Test'`. _xctest_ bundles seem to have issues running properly. Let me know if you succeed in running tests with this setup!

2. __Create a filelist per architecture, containing object files to be linked into the final executable.__ Again, if you're using CocoaPods, automate it by the following script. Run it after _Manifest.lock_ is verified in your main target (it needs to happen after all dependencies are compiled, but before the main executable is linked).

  ```ruby
#!/usr/bin/ruby

intermediates_directory = ENV['OBJROOT']
configuration = ENV['CONFIGURATION']
platform = ENV['EFFECTIVE_PLATFORM_NAME']
archs = ENV['ARCHS']

archs.split(" ").each do |architecture|

  Dir.chdir("#{intermediates_directory}/Pods.build") do

    filelist = ""

    Dir.glob("#{configuration}#{platform}/*.build/Objects-normal/#{architecture}/*.o") do |object_file|

      filelist += File.absolute_path(object_file) + "\n"

    end

    File.write("#{configuration}#{platform}-#{architecture}.objects.filelist", filelist)

  end

end
  ```

3. __Link your app executable against any static libraries needed.__ You might or might not get linker errors if you don't, so make sure you test the hell out of your app.

4. __Resource bundles don't exist, include all resources into your main bundle.__ Also edit your code in case it expects resource bundles to exist.

5. If using CocoaPods, completely skip the _Embed Pod Frameworks_ step for configurations that use this workaround (e.g. not for tests).

   ```
   if [[ "$CONFIGURATION" == "Test" ]]; then
    "${SRCROOT}/Pods/Target Support Files/Pods-YourTarget/Pods-YourTarget-frameworks.sh"
   fi
   ```

---

### Another workaround

Link against all frameworks using `-weak_framework` and invoke `dlopen` during the run of the app (the example app does this). You'll need to ensure the framework is loaded before using any symbols from it. You will still take the _dyld_ performance hit, but this gives you flexibility when the hit happens.
