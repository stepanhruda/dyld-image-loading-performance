//
//  NSNumber+SAMAdditions.h
//  SAMCategories
//
//  Created by Alexander Zats on 5/22/12.
//  Copyright (c) 2012-2014 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Provides extensions to `NSNumber` for various common tasks.
 */
@interface NSNumber (SAMAdditions)

///--------------
/// @name Date from timestamp
///--------------

/**
 Creates an instance of `NSDate` using current number as timestamp.
 @return NSDate with current number as unix timestamp or `nil` if current number contains 0.
 */
- (NSDate *)sam_dateValue;

@end
