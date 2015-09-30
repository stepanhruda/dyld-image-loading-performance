//
//  UIApplication+SAMAdditions.h
//  SAMCategories
//
//  Created by Sam Soffes on 10/20/10.
//  Copyright (c) 2010-2014 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Provides extensions to `UIApplication` for various common tasks.
 */
@interface UIApplication (SAMAdditions)

///------------------
/// @name Directories
///------------------

/**
 Returns the file URL of the documents directory.
 */
- (NSURL *)sam_documentsDirectoryURL;

/**
 Returns the file URL of the caches directory.
 */
- (NSURL *)sam_cachesDirectoryURL;

/**
 Returns the file URL of the downloads directory.
 */
- (NSURL *)sam_downloadsDirectoryURL;

/**
 Returns the file URL of the library directory.
 */
- (NSURL *)sam_libraryDirectoryURL;

/**
 Returns the file URL of the application support directory.
 */
- (NSURL *)sam_applicationSupportDirectoryURL;


///----------------
/// @name Utilities
///----------------

/**
 Aggregates calls to settings `networkActivityIndicatorVisible` to avoid flashing of the indicator in the status bar.
 Simply use `sam_setNetworkActivity:` instead of `setNetworkActivityIndicatorVisible:`.
 
 Specify `YES` if the application should show network activity and `NO` if it should not. A spinning indicator in the
 status bar shows network activity. The application may explicitly hide or show this indicator.
 
 @param inProgress A Boolean value that turns an indicator of network activity on or off.
 */
- (void)sam_setNetworkActivity:(BOOL)inProgress;

/** Checks for pirated application indicators.
 
 This isn't bulletproof, but should catch a lot of cases.
 
 Thanks Marco Arment: <http://twitter.com/marcoarment/status/27965461020>
 
 @return `YES` if the application may be pirated. `NO` if it is probably not pirated.
 */
- (BOOL)sam_isPirated;

@end
