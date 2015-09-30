//
//  UIScrollView+SAMAdditions.h
//  SAMCategories
//
//  Created by Sam Soffes on 4/12/10.
//  Copyright (c) 2010-2014 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Provides extensions to `UIScrollView` for various common tasks.
 */
@interface UIScrollView (SAMAdditions)

///----------------
/// @name Scrolling
///----------------

/**
 Scroll to the top of the receiver without animation.
 */
- (void)sam_scrollToTop;

/**
 Scroll to the top of the receiver.
 
 @param animated `YES` to animate the transition at a constant velocity to the new offset, `NO` to make the transition immediate.
 */
- (void)sam_scrollToTopAnimated:(BOOL)animated;

@end
