@class STPTransition;

@interface STPTransitionCenter : NSObject <UINavigationControllerDelegate,
                                           UIViewControllerTransitioningDelegate>

- (void)setNextPushOrPresentTransition:(STPTransition *)transition
                    fromViewController:(UIViewController *)viewController;
- (void)setNextPopOrDismissTransition:(STPTransition *)transition
                   fromViewController:(UIViewController *)viewController;
- (void)removeAllTransitionsForViewController:(UIViewController *)viewController;

- (STPTransition *)nextPushOrPresentTransitionFromViewController:(UIViewController *)viewController;
- (STPTransition *)nextPopOrDismissTransitionFromViewController:(UIViewController *)viewController;

+ (instancetype)sharedInstance;

@end
