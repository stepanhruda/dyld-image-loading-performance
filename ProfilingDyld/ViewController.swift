import UIKit

class ViewController: UIViewController {

    func loadFrameworks() {
        let frameworksToLoadDynamically = [
            "AFNetworking",
            "Alamofire",
            "Aspects",
            "AWSAutoScaling",
            "AWSCloudWatch",
            "AWSCognito",
            "AWSCore",
            "AWSDynamoDB",
            "AWSEC2",
            "AWSElasticLoadBalancing",
            "AWSKinesis",
            "AWSS3",
            "AWSSES",
            "AWSSimpleDB",
            "AWSSNS",
            "AWSSQS",
            "BlocksKit",
            "Bolts",
            "CocoaAsyncSocket",
            "CocoaLumberjack",
            "FLEX",
            "FMDB",
            "FXBlurView",
            "GBDeviceInfo",
            "GZIP",
            "HexColors",
            "JSQSystemSoundPlayer",
            "MagicalRecord",
            "Mantle",
            "MAObjCRuntime",
            "Masonry",
            "Mixpanel",
            "Moya",
            "NJKWebViewProgress",
            "NPReachability",
            "ObjectiveSugar",
            "Reachability",
            "SAMCategories",
            "Shimmer",
            "SMXMLDocument",
            "SSKeychain",
            "STPTransitions",
            "TMCache",
            "TOMSMorphingLabel",
            "UICKeyChainStore",
            "UIImage_PDF",
            "XMLDictionary",
            "YapDatabase",
            "zipzap"
        ]

        for name in frameworksToLoadDynamically {
            loadFrameworkNamed(name)
        }
    }
    
    @IBAction func loadPressed(sender: AnyObject) {
        println("Start: \(NSDate())")
        loadFrameworks()
        println("End: \(NSDate())")
    }

    func loadFrameworkNamed(name: String) -> Void {
        let path = NSBundle.mainBundle().bundlePath + "/Frameworks/\(name).framework/\(name)"
        dlopen(path, 10)
    }

}
