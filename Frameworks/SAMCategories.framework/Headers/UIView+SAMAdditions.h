//
//  UIView+SAMAdditions.h
//  SAMCategories
//
//  Created by Sam Soffes on 2/15/10.
//  Copyright (c) 2010-2014 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Provides extensions to `UIView` for various common tasks.
 */
@interface UIView (SAMAdditions)

///-------------------------
/// @name Taking Screenshots
///-------------------------

/**
 Takes a screenshot of the underlying `CALayer` of the receiver and returns a `UIImage` object representation.

 @return An image representing the receiver
 */
- (UIImage *)sam_imageRepresentation;


///-------------------------
/// @name Hiding and Showing
///-------------------------

/**
 Sets the `alpha` value of the receiver to `0.0`.
 */
- (void)sam_hide;

/**
 Sets the `alpha` value of the receiver to `1.0`.
 */
- (void)sam_show;


///------------------------
/// @name Fading In and Out
///------------------------

/**
 Fade out the receiver.
 
 The receiver will fade out in `0.2` seconds.
 */
- (void)sam_fadeOut;

/**
 Fade out the receiver and remove from its super view
 
 The receiver will fade out in `0.2` seconds and be removed from its `superview` when the animation completes.
 */
- (void)sam_fadeOutAndRemoveFromSuperview;

/**
 Fade in the receiver.
 
 The receiver will fade in in `0.2` seconds.
 */
- (void)sam_fadeIn;


///----------------------------------
/// @name Managing the View Hierarchy
///----------------------------------

/**
 Returns an array of the receiver's superviews.
 
 The immediate super view is the first object in the array. The outer most super view is the last object in the array.
 
 @return An array of view objects containing the receiver
 */
- (NSArray *)sam_superviews;

/**
 Returns the first super view of a given class.
 
 If a super view is not found for the given `superviewClass`, `nil` is returned.
 
 @param superviewClass A Class to search the `superviews` for
 
 @return A view object or `nil`
 */
- (id)sam_firstSuperviewOfClass:(Class)superviewClass;

/**
 Returns the true center of the view, regardless of orientation
 */
 - (CGPoint)sam_trueCenter;


///------------------
/// @name Auto Layout
///------------------

/**
 Remove all constraints and mark the receiver as needing update constraints.
 */
- (void)sam_resetConstraints;

@end
