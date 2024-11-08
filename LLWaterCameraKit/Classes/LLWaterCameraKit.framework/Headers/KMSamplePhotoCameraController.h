//
//  KMSamplePhotoCameraController.h
//  LibKMCamera
//
//  Created by liujiang on 2023/2/16.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>
@class KMSampleCameraOverlayView;
NS_ASSUME_NONNULL_BEGIN

@interface KMSamplePhotoCameraController : UIViewController
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-property-synthesis"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
@property (nonatomic, strong) KMSampleCameraOverlayView *view;
#pragma clang diagnostic pop
@property (nonatomic, assign)NSUInteger uniqueIdentifier;

@property (nonatomic, copy)void(^runningStateObserve)(BOOL);
@property (nonatomic, readonly)BOOL isRunning; //相机session是否正在运行
@property (nonatomic, readonly)BOOL isReady;   //相机session是否初始化完成

#pragma clang diagnostic pop


- (void)takePicture:(void(^)(BOOL success, UIImage *thumbnail))completion;
- (void)revertCameraPosition;
@end

NS_ASSUME_NONNULL_END
