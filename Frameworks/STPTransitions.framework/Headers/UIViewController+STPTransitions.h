@import UIKit;

@class STPTransition;

@interface UIViewController (STPTransitions)

@property (nonatomic, weak) UIViewController *sourceViewController;
@property (nonatomic, assign) BOOL fixInterfaceOrientationRotation;

- (void)presentViewController:(UIViewController *)viewControllerToPresent
              usingTransition:(STPTransition *)transition
                 onCompletion:(void (^)(void))completion;

- (void)dismissViewControllerUsingTransition:(STPTransition *)transition
                                onCompletion:(void (^)(void))completion;

- (void)transitionFromViewController:(UIViewController *)fromViewController
                    toViewController:(UIViewController *)toViewController
                     usingTransition:(STPTransition *)transition;

// You can override these methods in your UIViewController subclass to react to a transition.
// Outer view controller is either lower in the navigation stack, or the presenting controller.
- (void)willPerformTransitionAsOuterViewController:(STPTransition *)transition;
// Inner view controller is either higher in the navigation stack, or the presented controller.
- (void)willPerformTransitionAsInnerViewController:(STPTransition *)transition;

@end
