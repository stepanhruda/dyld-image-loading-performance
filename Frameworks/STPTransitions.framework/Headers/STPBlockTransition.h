#import "STPTransition.h"

@interface STPBlockTransition : STPTransition

+ (instancetype)transitionWithAnimation:(void (^)(UIView *fromView,
                                                  UIView *toView,
                                                  UIView *containerView,
                                                  void (^executeWhenAnimationIsCompleted)(BOOL finished)))animationBlock;

@end
