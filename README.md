__tl;dr:__ _dyld takes too long to load frameworks, which makes apps slow to open_

### Problem

Since iOS 8, it is possible to ship dynamic libraries inside the app bundle to App Store. It is the way to ship Swift dependencies and to share your Swift code with extensions – you cannot use static libraries with Swift, plus frameworks allow you to share symbols instead of shipping them multiple times and inflating your bundle size.

There is a __major performance issue when using frameworks__ – the image loading/linking time that dyld takes during first app launch is so long, that a mid-sized app (i.e. an app with a couple of dozen dependencies) takes several seconds to open. On older devices, the app will often get killed by watchdog before managing to launch at all.

The linking time was bad on iOS 8, and the performance is notably worse on iOS 9.

### Reproducibility

Typically you add frameworks to your app through _Link Binary With Libraries_ step in Xcode, which results in a `-framework` flag passed to _ld_ during build, and consequently in a `LC_LOAD_DYLIB` command in the final executable. However, _dyld_ commands get executed before _lldb_ or _dtrace_ get attached, so it's hard to track down what's happening.

This example app doesn't link against the frameworks, but instead invokes `dlopen` manually during runtime, still consistently reproducing the issue. It uses a set of frameworks as built by `use_frameworks!` through Cocoapods. Presumably Carthage and manual dependencies through e.g. git submodules run into the same issue.

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


### Workarounds

1. It is possible to move symbols (even when using Swift) inside your app executable to cut down on launch time. I'll post a solution here once I'm sure it can pass App Store review. This is just a hacky temporary solution, not addressing the underlying problem.

1. Another workaround would be to link against your frameworks using `-weak_framework` and invoke `dlopen` during runtime as the example app does. You'd need to ensure the framework is loaded before using any symbols from it. This gives you more flexibility with when to take the performance hit, but cannot be automated.
