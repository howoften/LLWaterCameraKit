//
//  KMCameraVideoCountdownView.h
//  KMCameraComponent
//
//  Created by liujiang on 2023/9/1.
//

#import <UIKit/UIKit.h>

@interface KMCameraCountdownView : UIView

@property(nonatomic)NSTimeInterval maxDuration;
@property(nonatomic)BOOL hiddenWhenStop;
@property(nonatomic, copy)void(^reachMaxDuration)(void);

- (void)start;
- (void)stop;
@end

