//
//  UIColor+SAMAdditions.h
//  SAMCategories
//
//  Created by Sam Soffes on 4/19/10.
//  Copyright (c) 2010-2014 Sam Soffes. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Provides extensions to `UIColor` for various common tasks.
 */
@interface UIColor (SAMAdditions)

/**
 Creates and returns an UIColor object containing a hue, saturation, lightness value.

 @param hue The hue for the new color.
 @param saturation The saturation for the new color.
 @param lightness The lightness for the new color.
 @param alpha The alpha for the new color.

 @return An UIColor object containing a value.
 
 This converts the color from HSL to HSB and uses UIKit's built-in HSB initializer.
 */
+ (instancetype)sam_colorWithHue:(CGFloat)hue saturation:(CGFloat)saturation lightness:(CGFloat)lightness alpha:(CGFloat)alpha;

/**
 Creates and returns an UIColor object containing a CSS value.

 @param css The value for the new color.

 @return An UIColor object containing a value.
 */
+ (instancetype)sam_colorWithCSS:(NSString *)css;

+ (instancetype)sam_colorWithCSSName:(NSString *)name;

/**
 Creates and returns an UIColor object containing a CSS RGB(A) value.

 @param rgb The value for the new color.

 @return An UIColor object containing a value.

 Example input: `rgb(255, 0, 0)`, `rgba(100, 200, 300, 0.4)`

 The default alpha value is `1.0`.
 */
+ (instancetype)sam_colorWithRGB:(NSString *)rgb;

/**
 Creates and returns an UIColor object containing a CSS HSL(A) value.

 @param hsl The value for the new color.

 @return An UIColor object containing a value.

 Example input: `hsl(0, 50%, 20%)`, `hsla(40, 30%, 10%, 0.5)` 

 The default alpha value is `1.0`.
 */
+ (instancetype)sam_colorWithHSL:(NSString *)hsl;

/**
 Creates and returns an UIColor object containing a given value.
 
 @param hex The value for the new color. The `#` sign is not required.
 
 @return An UIColor object containing a value.
 
 You can specify hex values in the following formats: `rgb`, `rrggbb`, or `rrggbbaa`.
 
 The default alpha value is `1.0`.
 
 */
+ (instancetype)sam_colorWithHex:(NSString *)hex;

/**
 Returns the receiver's value as a hex string.
 
 @return The receiver's value as a hex string.
 
 The value will be `nil` if the color is in a color space other than Grayscale or RGB. The `#` sign is omitted. Alpha
 will be omitted.
 */
- (NSString *)sam_hexValue;

/**
 Returns the receiver's value as a hex string.
 
 @param includeAlpha `YES` if alpha should be included. `NO` if it should not.
 
 @return The receiver's value as a hex string.
 
 The value will be `nil` if the color is in a color space other than Grayscale or RGB. The `#` sign is omitted. Alpha is
 included if `includeAlpha` is `YES`.
 */
- (NSString *)sam_hexValueWithAlpha:(BOOL)includeAlpha;

/**
 The receiver's red component value.
 
 The value of this property is a floating-point number in the range `0.0` to `1.0`. `-1.0` is returned if the color is
 not in the RGB colorspace.
 */
- (CGFloat)sam_red;

/**
 The receiver's green component value.
 
 The value of this property is a floating-point number in the range `0.0` to `1.0`. `-1.0` is returned if the color is
 not in the RGB colorspace.
 */
- (CGFloat)sam_green;

/**
 The receiver's blue component value.
 
 The value of this property is a floating-point number in the range `0.0` to `1.0`. `-1.0` is returned if the color is
 not in the RGB colorspace.
 */
- (CGFloat)sam_blue;

/**
 The receiver's alpha value.
 
 The value of this property is a floating-point number in the range `0.0` to `1.0`, where `0.0` represents totally
 transparent and `1.0` represents totally opaque.
 */
- (CGFloat)sam_alpha;

- (instancetype)sam_colorByInterpolatingToColor:(UIColor *)nextColor progress:(CGFloat)progress;

@end
