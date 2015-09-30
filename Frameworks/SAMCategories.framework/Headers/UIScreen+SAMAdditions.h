//
//  UIScreen+SAMAdditions.h
//  SAMCategories
//
//  Created by Sam Soffes on 2/4/11.
//  Copyright (c) 2011-2014. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Provides extensions to `UIScreen` for various common tasks.
 */
@interface UIScreen (SAMAdditions)

///---------------------------
/// @name Accessing the Bounds
///---------------------------

/**
 Returns the bounds of the screen for the current device orientation.
 
 @return A rect indicating the bounds of the screen.
 
 @see boundsForOrientation:
 */
- (CGRect)sam_currentBounds;

/**
 Returns the bounds of the screen for a given device orientation. `UIScreen`'s `bounds` method always returns the bounds
 of the screen of it in the portrait orientation.
 
 @param orientation The orientation to get the screen's bounds.
 
 @return A rect indicating the bounds of the screen.
 
 @see currentBounds
 */
- (CGRect)sam_boundsForOrientation:(UIInterfaceOrientation)orientation;


///------------------------
/// @name Screen Attributes
///------------------------

/**
 Returns a Boolean indicating if the screen is a Retina display.
 
 @return A Boolean indicating if the screen is a Retina display.
 */
- (BOOL)sam_isRetina;

/**
 Check if the receiver is running on the iPhone 5 form factor.

 @return `YES` if the device is running on the iPhone 5 form factor and `NO` if it is not.
 */
- (BOOL)sam_isGiraffe;

@end
