#import <UIKit/UIKit.h>

#import "Mantle.h"
#import "MTLJSONAdapter.h"
#import "MTLManagedObjectAdapter.h"
#import "MTLModel+NSCoding.h"
#import "MTLModel.h"
#import "MTLReflection.h"
#import "MTLValueTransformer.h"
#import "NSArray+MTLManipulationAdditions.h"
#import "NSDictionary+MTLManipulationAdditions.h"
#import "NSError+MTLModelException.h"
#import "NSObject+MTLComparisonAdditions.h"
#import "NSValueTransformer+MTLInversionAdditions.h"
#import "NSValueTransformer+MTLPredefinedTransformerAdditions.h"
#import "EXTKeyPathCoding.h"
#import "EXTRuntimeExtensions.h"
#import "EXTScope.h"
#import "metamacros.h"

FOUNDATION_EXPORT double MantleVersionNumber;
FOUNDATION_EXPORT const unsigned char MantleVersionString[];

