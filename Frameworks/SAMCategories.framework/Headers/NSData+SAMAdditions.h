//
//  NSData+SAMAdditions.h
//  SAMCategories
//
//  Created by Sam Soffes on 9/29/08.
//  Copyright (c) 2008-2014 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Provides extensions to `NSData` for various common tasks.
 */
@interface NSData (SAMAdditions)

///--------------
/// @name Digests
///--------------

/**
 Returns a string of the MD2 digest of the receiver.

 @return The string of the MD2 digest of the receiver.
 */
- (NSString *)sam_MD2Digest;

/**
 Returns a string of the MD4 digest of the receiver.

 @return The string of the MD4 digest of the receiver.
 */
- (NSString *)sam_MD4Digest;

/**
 Returns a string of the MD5 digest of the receiver.
 
 @return The string of the MD5 digest of the receiver.
 */
- (NSString *)sam_MD5Digest;

/**
 Returns a string of the SHA1 digest of the receiver.
 
 @return The string of the SHA1 digest of the receiver.
 */
- (NSString *)sam_SHA1Digest;

/**
 Returns a string of the SHA224 digest of the receiver.

 @return The string of the SHA224 digest of the receiver.
 */
- (NSString *)sam_SHA224Digest;

/**
 Returns a string of the SHA256 digest of the receiver.
 
 @return The string of the SHA256 digest of the receiver.
 */
- (NSString *)sam_SHA256Digest;

/**
 Returns a string of the SHA384 digest of the receiver.

 @return The string of the SHA384 digest of the receiver.
 */
- (NSString *)sam_SHA384Digest;

/**
 Returns a string of the SHA512 digest of the receiver.

 @return The string of the SHA512 digest of the receiver.
 */
- (NSString *)sam_SHA512Digest;

/**
 Returns a hexadecimal representation of the receiver.
 
 @return A hexadecimal representation of the receiver.
 */
- (NSString *)sam_hexadedimalString;


///-----------------------------------
/// @name Base64 Encoding and Decoding
///-----------------------------------

/**
 Returns a string representation of the receiver Base64 encoded.
 
 @return A Base64 encoded string
 */
- (NSString *)sam_base64EncodedString;

/**
 Returns a new data contained in the Base64 encoded string.
 
 @param base64String A Base64 encoded string
 
 @return Data contained in `base64String`
 */
+ (NSData *)sam_dataWithBase64String:(NSString *)base64String;

@end
