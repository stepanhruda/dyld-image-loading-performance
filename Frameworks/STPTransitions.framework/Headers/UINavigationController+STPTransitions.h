@import UIKit;

@class STPTransition;

@interface UINavigationController (STPTransitions)

- (void)pushViewController:(UIViewController *)viewController
           usingTransition:(STPTransition *)transition;

- (void)popToViewController:(UIViewController*)viewController
            usingTransition:(STPTransition *)transition;

    
- (UIViewController *)popViewControllerUsingTransition:(STPTransition *)transition;

@end
