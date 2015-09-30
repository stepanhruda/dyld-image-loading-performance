//
//  NSUserDefaults+SAMAdditions.h
//  SAMCategories
//
//  Created by Sam Soffes on 4/22/14.
//  Copyright (c) 2014 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSUserDefaults (SAMAdditions)

/**
 It is recommended to use `[[[UIDevice currentDevice] identifierForVendor] UUIDString]` on iOS.
 */
+ (void)sam_setSignatureSalt:(NSString *)salt;
+ (NSString *)sam_signatureSalt;

- (id)sam_signedObjectForKey:(NSString *)defaultName;
- (void)sam_setSignedObject:(id)value forKey:(NSString *)defaultName;
- (void)sam_removeSignedObjectForKey:(NSString *)defaultName;

- (NSArray *)sam_signedArrayForKey:(NSString *)defaultName;
- (NSDictionary *)sam_signedDictionaryForKey:(NSString *)defaultName;
- (NSData *)sam_signedDataForKey:(NSString *)defaultName;
- (NSString *)sam_signedStringForKey:(NSString *)defaultName;
- (NSInteger)sam_signedIntegerForKey:(NSString *)defaultName;
- (float)sam_signedFloatForKey:(NSString *)defaultName;
- (double)sam_signedDoubleForKey:(NSString *)defaultName;
- (BOOL)sam_signedBoolForKey:(NSString *)defaultName;
- (NSURL *)sam_signedURLForKey:(NSString *)defaultName;

- (void)sam_setSignedInteger:(NSInteger)value forKey:(NSString *)defaultName;
- (void)sam_setSignedFloat:(float)value forKey:(NSString *)defaultName;
- (void)sam_setSignedDouble:(double)value forKey:(NSString *)defaultName;
- (void)sam_setSignedBool:(BOOL)value forKey:(NSString *)defaultName;
- (void)sam_setSignedURL:(NSURL *)url forKey:(NSString *)defaultName;

@end
