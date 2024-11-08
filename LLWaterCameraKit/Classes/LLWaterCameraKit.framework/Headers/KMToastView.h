//
//  KMToastView.h
//  KMToastViewDemo
//
//  Created by liujiang on 2022/12/6.
//
//

#import <Foundation/Foundation.h>

typedef enum {
    KMToastGravityTop = 0,
    KMToastGravityCenter,
    KMToastGravityBottom
} KMToastGravity;

typedef enum {
    KMToastDurationShort = 2,
    KMToastDurationNormal = 4,
    KMToastDurationLong = 10,
    KMToastDurationInfinite = NSIntegerMax
} KMToastDuration;

#define KMToastViewWillAppearNotification       @"KMToastViewWillAppearNotificatio"
#define KMToastViewDidAppearNotification        @"KMToastViewDidAppearNotification"
#define KMToastViewWillDisappearNotification    @"KMToastViewWillDisappearNotification"
#define KMToastViewDidDisappearNotification     @"KMToastViewDidDisappearNotification"
#define KMToastViewDidDismissNotification       @"KMToastViewDidDismissNotification"

#define KMToastViewUserInfoKey                  @"KMToastViewUserInfoKey"
#define KMToastViewStringUserInfoKey            @"KMToastViewStringUserInfoKey"

@interface KMToastView : NSObject

@property (strong, nonatomic) id message;
@property (assign, nonatomic) NSTextAlignment textAlignment;
@property (assign, nonatomic) NSLineBreakMode lineBreakMode;
@property (assign, nonatomic) KMToastGravity gravity;
@property (assign, nonatomic) NSTimeInterval duration;
@property (strong, nonatomic) UIColor *textColor, *backgroundColor, *borderColor, *shadowColor;
@property (strong, nonatomic) UIFont *font;
@property (assign, nonatomic) CGFloat borderWidth, cornerRadius, shadowOpacity, shadowRadius, fadeInDuration, fadeOutDuration;
@property (assign, nonatomic) CGSize shadowOffset;
@property (assign, nonatomic) UIEdgeInsets innerEdgeInsets;
@property (assign, nonatomic) NSInteger yOffset;
@property (copy, nonatomic) void(^onTap)(void);

+ (id)makeToast:(id)message;
+ (id)makeToast:(id)message gravity:(KMToastGravity)gravity;
+ (id)makeToast:(id)message duration:(NSTimeInterval)duration;
+ (id)makeToast:(id)message gravity:(KMToastGravity)gravity duration:(NSTimeInterval)duration;

+ (void)dismissToast;

- (void)show;
- (void)showInView:(UIView *)view;

@end
