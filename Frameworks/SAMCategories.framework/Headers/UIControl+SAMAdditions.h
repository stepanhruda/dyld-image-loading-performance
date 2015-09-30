//
//  UIControl+SAMAdditions.h
//  SAMCategories
//
//  Created by Sam Soffes on 4/19/10.
//  Copyright (c) 2010-2014 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Provides extensions to `UIControl` for various common tasks.
 */
@interface UIControl (SAMAdditions)

/**
 Removes all targets and actions for all events from an internal dispatch table.
 */
- (void)sam_removeAllTargets;

/**
 Sets exclusive target for specified event, all previous targets will be removed, usefull for table cells etc
 */
- (void)sam_setTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;

@end
