//
//  UIDevice+SAMAdditions.h
//  SAMCategories
//
//  Created by Sam Soffes on 7/13/09.
//  Copyright (c) 2009-2014 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Provides extensions to `UIDevice` for various common tasks.
 */
@interface UIDevice (SAMAdditions)

/**
 Returns `YES` if the device is a simulator.
 
 @return `YES` if the device is a simulator and `NO` if it is not.
 */
- (BOOL)sam_isSimulator;

/**
 Returns `YES` if the device is an iPod touch, iPhone, iPhone 3G, or an iPhone 3GS.
 
 @return `YES` if the device is crappy and `NO` if it is not.
 */
- (BOOL)sam_isCrappy;

/**
 Check if the receiver is running iOS 7.

 @return `YES` if the device is running iOS 7 and `NO` if it is not.
*/
- (BOOL)sam_isInnsbruck;

/**
 Returns the device hardware model. `iPhone5,2` or `iPad3,1` for example.
 */
- (NSString *)sam_hardwareModel;

@end
