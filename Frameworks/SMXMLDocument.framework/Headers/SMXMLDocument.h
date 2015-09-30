/*
 The MIT License
 
 Copyright (c) 2011 Spotlight Mobile
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE. 
*/

/*
 
 SMXMLDocument
 -------------
 Created by Nick Farina (nfarina@gmail.com)
 Version 1.0
 
 */

// SMXMLDocument is a very handy lightweight XML parser for iOS.

extern NSString *const SMXMLDocumentErrorDomain;

@class SMXMLDocument;

@interface SMXMLElement : NSObject<NSXMLParserDelegate>

@property (nonatomic, weak) SMXMLDocument *document;
@property (nonatomic, weak) SMXMLElement *parent;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, retain) NSString *value;
@property (nonatomic, retain) NSArray *children;
@property (nonatomic, retain) NSDictionary *attributes;
@property (nonatomic, readonly) SMXMLElement *firstChild, *lastChild;

- (id)initWithDocument:(SMXMLDocument *)document;
- (SMXMLElement *)childNamed:(NSString *)name;
- (NSArray *)childrenNamed:(NSString *)name;
- (SMXMLElement *)childWithAttribute:(NSString *)attributeName value:(NSString *)attributeValue;
- (NSString *)attributeNamed:(NSString *)name;
- (SMXMLElement *)descendantWithPath:(NSString *)path;
- (NSString *)valueWithPath:(NSString *)path;

@end

@interface SMXMLDocument : NSObject<NSXMLParserDelegate>

@property (nonatomic, retain) SMXMLElement *root;
@property (nonatomic, retain) NSError *error;

- (id)initWithData:(NSData *)data error:(NSError **)outError;

- (NSString *)fullDescription; // like -description, this writes the document out to an XML string, but doesn't truncate the node values.

+ (SMXMLDocument *)documentWithData:(NSData *)data error:(NSError **)outError;

@end
