//
//  NSString+SAMAdditions.h
//  SAMCategories
//
//  Created by Sam Soffes on 6/22/09.
//  Copyright (c) 2009-2014 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonHMAC.h>

/**
 Provides extensions to `NSString` for various common tasks.
 */
@interface NSString (SAMAdditions)

///------------------------
/// @name Checking Contents
///------------------------

/**
 Returns a Boolean if the receiver contains the given `string`.
 
 @param string A string to test the the receiver for
 
 @return A Boolean if the receiver contains the given `string`
 */
- (BOOL)sam_containsString:(NSString *)string;


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
 Returns a string of the HMAC digest of the receiver.
 
 @param key The key to use in the HMAC digest.
 @param algorithm The algorithm to use for the HMAC digest.
 @return The string of the HMAC digest of the receiver.
 */
- (NSString *)sam_HMACDigestWithKey:(NSString *)key algorithm:(CCHmacAlgorithm)algorithm;


///-------------------------
/// @name Comparing Versions
///-------------------------

/**
 Returns a comparison result for the receiver and a given `version`.
 
 Examples:
 
 <pre><code>[@"10.4" compareToVersionString:@"10.3"]; // NSOrderedDescending
 [@"10.5" compareToVersionString:@"10.5.0"]; // NSOrderedSame
 [@"10.4 Build 8L127" compareToVersionString:@"10.4 Build 8P135"]; // NSOrderedAscending</code></pre>
 
 @param version A version string to compare to the receiver
 
 @return A comparison result for the receiver and a given `version`
 */
- (NSComparisonResult)sam_compareToVersionString:(NSString *)version;


///-----------------------------------
/// @name HTML Escaping and Unescaping
///-----------------------------------

/**
 Returns a new string with any HTML escaped.
 
 @return A new string with any HTML escaped.
 
 @see unescapeHTML
 */
- (NSString *)sam_escapeHTML;

/**
 Returns a new string with any HTML unescaped.
 
 @return A new string with any HTML unescaped.
 
 @see escapeHTML
 */
- (NSString *)sam_unescapeHTML;


///----------------------------------
/// @name URL Escaping and Unescaping
///----------------------------------

/**
 Returns a new string escaped for a URL query parameter.
 
 The following characters are escaped: `:/=,!$&'()*+;[]@#?%` as well as new lines. Spaces are escaped to the `+`
 character. (`+` is escaped to `%2B`).
 
 @return A new string escaped for a URL query parameter.
 
 @see stringByUnescapingFromURLQuery
 */
- (NSString *)sam_stringByEscapingForURLQuery;

/**
 Returns a new string unescaped from a URL query parameter.
 
 `+` characters are unescaped to spaces.
 
 @return A new string escaped for a URL query parameter.
 
 @see stringByEscapingForURLQuery
 */
- (NSString *)sam_stringByUnescapingFromURLQuery;


///----------------------
/// @name Base64 Encoding
///----------------------

/**
 Returns a string representation of the receiver Base64 encoded.
 
 @return A Base64 encoded string
 */
- (NSString *)sam_base64EncodedString;

/**
 Returns a new string contained in the Base64 encoded string.
 
 This uses `NSData`'s `dataWithBase64String:` method to do the conversion then initializes a string with the resulting
 `NSData` object using `NSUTF8StringEncoding`.
 
 @param base64String A Base64 encoded string
 
 @return String contained in `base64String`
 */
+ (NSString *)sam_stringWithBase64String:(NSString *)base64String;


///------------------------
/// @name Generating a UUID
///------------------------

/**
 Returns a new string containing a Universally Unique Identifier.
 */
+ (NSString *)sam_stringWithUUID;


///--------------------------
/// @name Working with Ranges
///--------------------------

/**
 Adjust a range to account for composed characters.
 
 @param range Input range
 @return adjusted range
 */
- (NSRange)sam_composedRangeWithRange:(NSRange)range;

/**
 Adjust a range to account for composed characters and get a substring for that range.

 @param range Input range
 @return Substring with adjusted range
 */
- (NSString *)sam_composedSubstringWithRange:(NSRange)range;

/**
 Get the range of a word for a given character index.
 
 @param index Character index
 @return Range of the containing word.
 */
- (NSRange)sam_wordRangeAtIndex:(NSUInteger)index;

@end
