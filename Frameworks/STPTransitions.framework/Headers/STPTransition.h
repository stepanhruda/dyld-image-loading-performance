@import UIKit;

@interface STPTransition : UIPercentDrivenInteractiveTransition <UIViewControllerAnimatedTransitioning>

/**
 *  Animation method executed during the transition. Override in your subclass.
 *
 *  @param fromview The view from which we're animating.
 *  @param toView The view to which we're animating.
 *  @param containerView The view in which all the animations are taking place.
 *  @param onCompletion You're responsible for executing this block after animation is finished.
 *
 *  @discussion fromView is already a subview of containerView. toView is not, add it when it becomes required.
 *  Don't forget to execute the onCompletion block.
 */
//
- (void)animateFromView:(UIView *)fromView
                 toView:(UIView *)toView
        inContainerView:(UIView *)containerView
    executeOnCompletion:(void (^)(BOOL))onCompletion;

/**
 *  Transition's duration. You are responsible for assigning this.
 *  @discussion Duration is used for other views to synchronize their animations, e.g. the navigation bar.
 */
@property (nonatomic, assign) NSTimeInterval transitionDuration;

/**
 *  Completion block executed when the transition is finished.
 *
 *  @param transition The transition that got completed, so you don't have to get a weak reference to it.
 *  @param transitionCompleted Is NO if the transition was cancelled and its original view is still showing.
 */
@property (nonatomic, copy) void (^onCompletion)(STPTransition *transition, BOOL transitionCompleted);

#pragma mark - Modal Transitions

/**
 *  The way custom modal transitions are treated in landscape mode is very strange at the moment.
 *  This property is automatically assigned if the transition is used for a modal and STPTransitions does its best to try to fix it for you.
 */
@property (nonatomic, assign) BOOL needsRotationFixForModals;

#pragma mark - Reverse Transitions

/**
 *  Transition is marked as reversed when being used while popping or dismissing a view controller.
 *  Take advantage of this property to implement both ways of a transition's animation in one class.
 *
 *  @discussion You can also assign this property manually to choose which way a transition goes when switching between two child view controllers.
 */
@property (nonatomic, assign, getter = isReversed) BOOL reversed;

/**
 *  When pushing or presenting a view controller, the transition assigned to this property gets used for the returning operation (i.e. pop or dismiss).
 *  @discussion This property is ignored when popping, dismissing and switching child view controllers.
 */
@property (nonatomic, strong) STPTransition *reverseTransition;

#pragma mark - Interactive Transitions

/**
 *  Gets called when the gesture recognizer begins.
 *
 *  Typically, you want to push/pop/present/dismiss/switch in this block.
 */
@property (nonatomic, copy) void (^onGestureTriggered)(STPTransition *transition, UIGestureRecognizer *recognizer);

/**
 *  A block asking for the completion percentage for the current state of the transition.
 *
 *  Based on the percentage, the transition's interactive animation gets adjusted accordingly.
 */
@property (nonatomic, copy) CGFloat (^completionPercentageForGestureRecognizerState)(UIGestureRecognizer *recognizer);

/**
 *  A block called when the user ends their gesture, asking whether an interactive transition should be completed.
 *
 *  If you return YES, the transition will finish the animation (going to the 'to' view controller). Otherwise, it will return to the state before the user's gesture began (going back to the 'from' view controller).
 */
@property (nonatomic, copy) BOOL (^shouldCompleteTransitionOnGestureEnded)(UIGestureRecognizer *recognizer, CGFloat completion);

/**
 *  Returns YES if the transition was kicked off interactively using the recognizer.
 *
 *  @discussion Even a transition with a gesture recognizer can be triggered non-interactively (e.g. using a button instead of a gesture).
 */
@property (nonatomic, readonly) BOOL wasTriggeredInteractively;


/**
 *  Gesture recognizer to trigger the transition via a gesture. You're responsible for adding the recognizer to the appropriate view.
 */
@property (nonatomic, weak) UIGestureRecognizer *gestureRecognizer;

/**
 *  View controller that this transition is from. This property becomes available during the transiton.
 */
@property (nonatomic, weak, readonly) UIViewController *fromViewController;

/**
 *  View controller that this transition is to. This property becomes available during the transiton.
 */
@property (nonatomic, weak, readonly) UIViewController *toViewController;

@end
