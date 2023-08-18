//
// Copyright © 2023 osy. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import "VMDisplayMetalViewController.h"
#import <TargetConditionals.h>

@class VMCursor;
@class VMScroll;
@class GCController;

NS_ASSUME_NONNULL_BEGIN

@interface VMDisplayMetalViewController ()

// cursor handling
@property (nonatomic) CGPoint lastTwoPanOrigin;
@property (nonatomic) BOOL mouseLeftDown;
@property (nonatomic) BOOL mouseRightDown;
@property (nonatomic) BOOL mouseMiddleDown;
@property (nonatomic) BOOL pencilForceRightClickOnce;
@property (nonatomic) VMCursor *cursor;
@property (nonatomic) VMScroll *scroll;

// Gestures
@property (nonatomic) UISwipeGestureRecognizer *swipeUp;
@property (nonatomic) UISwipeGestureRecognizer *swipeDown;
@property (nonatomic) UISwipeGestureRecognizer *swipeScrollUp;
@property (nonatomic) UISwipeGestureRecognizer *swipeScrollDown;
@property (nonatomic) UIPanGestureRecognizer *pan;
@property (nonatomic) UIPanGestureRecognizer *twoPan;
@property (nonatomic) UIPanGestureRecognizer *threePan;
@property (nonatomic) UITapGestureRecognizer *tap;
@property (nonatomic) UITapGestureRecognizer *tapPencil;
@property (nonatomic) UITapGestureRecognizer *twoTap;
@property (nonatomic) UILongPressGestureRecognizer *longPress;
@property (nonatomic) UIPinchGestureRecognizer *pinch;

//Gamepad
@property (nonatomic) GCController *controller;

#if !defined(TARGET_OS_VISION) || !TARGET_OS_VISION
// Feedback generators
@property (nonatomic) UISelectionFeedbackGenerator *clickFeedbackGenerator;
#endif

@end

NS_ASSUME_NONNULL_END

static inline CGFloat CGPointToPixel(CGFloat point) {
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
    return 2.0;
#else
    return point * [UIScreen mainScreen].scale; // FIXME: multiple screens?
#endif
}
