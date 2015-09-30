//
//  NPReachability.h
//
//  Updated and converted to ARC by Abizer Nasir.
//  
//  Copyright (c) 2011, Nick Paulson
//  All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//  
//  Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
//  Neither the name of the Nick Paulson nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

/**
 NPReachability is an evolution of Apple's Reachability class that provides information about the network status.

 As well as supporting the original's Notification based monitoring, this class supports both KVO and Blocks, so you can choose whichever way of handling changes as your application requires.

 This class is written as a singleton, so be sure to reference it as

 NPReachability *reachability = [NPReachability sharedInstance];

 Make sure you maintain a strong reference to at least one object of this class or else ARC will clean it up underneath you.

 ## Block support

 Handlers are declared as

 typedef void (^ReachabilityHandler)(NPReachability *curReach);

 This takes the NPReachability object as a parameter. As originally written this class passed the `SCNetworkReachabilityFlags` as a parameter, but you can get that and more by messaging the object directly

 You add blocks to be executed when the network status changes by using:

 - (id)addHandler:(ReachabilityHandler)handler;

 This returns an opaque object which you should use to remove the handler at the appropriate time (in a `dealloc`, say) with:

 - (void)removeHandler:(id)opaqueObject;

 ## KVO support

 Two properties can observed for changes to the network status:

 @property (assign, readonly, nonatomic, getter=isCurrentlyReachable) BOOL currentlyReachable;
 @property (assign, readonly, nonatomic) SCNetworkReachabilityFlags currentReachabilityFlags;

 ## NSNotification

 When the network status changes a `NPReachabilityChangedNotification` is sent with the NPReachability instance as the notification object.

 ## Dependencies

 - Xcode 5.0+ for ARC support, automatic synthesis and compatibility libraries. This might work for Xcode 4.2+, but I haven't been able to test it.
 - The SystemConfiguration Framework should be added to your projects

 Please use and improve!
 */

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

@class NPReachability;

/**
 The Name of the NSNotification that is  posted when the reachability changes. the notification object is the current instance of NPReachability
 */
extern NSString * const NPReachabilityChangedNotification;

/**
 Definition of the handler block that is performed on changes to reachability

 @param curReach the current NPReachability instance
 */
typedef void (^ReachabilityHandler)(NPReachability *curReach);

/**
 An enum for the Network status
 */
typedef NS_ENUM(NSUInteger, NPRNetworkStatus) {
    NPRNotReachable,
	NPRReachableViaWiFi,
	NPRReachableViaWWAN
};

/**
 Mike Ash style constant structures for keys
 */
extern const struct NPReachabilityKeysStruct {
    __unsafe_unretained NSString *currentlyReachable;
    __unsafe_unretained NSString *currentReachabilityFlags;
    __unsafe_unretained NSString *currentNetworkStatus;
} NPReachabilityKeys;


@interface NPReachability : NSObject 

/**
 Whether or not the network is currently reachable. KVO compliant.
 */
@property (nonatomic, readonly, getter=isCurrentlyReachable) BOOL currentlyReachable;

/**
 The SystemConfiguration reachability flags. KVO compliant.
 */
@property (nonatomic, readonly) SCNetworkReachabilityFlags currentReachabilityFlags;

/**
 The current network status. KVO compliant.
 */
@property (nonatomic, readonly) NPRNetworkStatus currentNetworkStatus;

/**
 The singleton initialiser.
 
 Be sure to maintain at least one strong reference to an instance to prevent it being released out from under you.

 @return A singleton instance of NPReachability
 */
+ (NPReachability *)sharedInstance;

/**
 A convenience class method for SCNetworkReachabilityFlags for whether or not they indicate a connection is available

 @param flags The flags to test against.

 @return YES if a connection is available, NO otherwise.
 */
+ (BOOL)isReachableWithFlags:(SCNetworkReachabilityFlags)flags;


/**
 Add a handler block to be run when reachability changes.
 
 Strong references are kept to objects in the handler block, so be careful to avoid retain cycles.

 @param handler A ReachabilityHandler block that takes one parameter, the instance of the NPReachability class.

 @return An opaque object that is used to remove the handler when it is no longer required.
 */
- (id)addHandler:(ReachabilityHandler)handler;

/**
 Removes a reachability changed handler from the object.
 
 It is safe to attempt to remove an object that has already been removed.

 @param opaqueObject The opaque object that was returned by the call `addHandler:` that was used when adding the handler block.
 */
- (void)removeHandler:(id)opaqueObject;

/**
 A string description of the current SCNetworkReachability flags.
 
 Useful for logging/debugging.
 
 The string is of the form -- -------
 
 Where the provided values are:
 
 W - kSCNetworkReachabilityFlagsIsWWAN
 R - kSCNetworkReachabilityFlagsReachable
 
 t - kSCNetworkReachabilityFlagsTransientConnection
 c - kSCNetworkReachabilityFlagsConnectionRequired
 C - kSCNetworkReachabilityFlagsConnectionOnTraffic
 i - kSCNetworkReachabilityFlagsInterventionRequired
 D - kSCNetworkReachabilityFlagsConnectionOnDemand
 l - kSCNetworkReachabilityFlagsIsLocalAddress
 d - kSCNetworkReachabilityFlagsIsDirect

 @return A summary string of the current reachability flags
 */
- (NSString *)reachabilityFlagsAsString;


@end
