//
//  DeviceOrientation.h
//  DeviceOrientation
//
//  Created by Tg W on 17/2/22.
//  Copyright © 2017年 oopsr. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TgDirection) {
    TgDirectionUnkown = 0,
    TgDirectionPortrait,
    TgDirectionDown,
    TgDirectionRight,
    TgDirectionleft,
};

@protocol KMDeviceOrientationDelegate <NSObject>

- (void)directionChange:(TgDirection)direction;

@end
@interface KMDeviceOrientationMonitor : NSObject
@property (nonatomic, assign, class)TgDirection direction;
@property(nonatomic, weak)id<KMDeviceOrientationDelegate>delegate;

- (instancetype)initWithDelegate:(id<KMDeviceOrientationDelegate>)delegate;
/**
 开启监听
 */
- (void)startMonitor;
/**
 结束监听，请stop
 */
- (void)stop;

@end
