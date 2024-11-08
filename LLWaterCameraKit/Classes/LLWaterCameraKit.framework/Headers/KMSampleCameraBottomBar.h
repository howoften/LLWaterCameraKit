//
//  KMSampleCameraBottomBar.h
//  LibKMCamera
//
//  Created by liujiang on 2023/2/17.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KMSampleCameraBottomBar : UIView
@property (nonatomic, strong)UIImage *thumbnailPhoto;

@property (nonatomic, strong)UIButton *albumButton;

@property (nonatomic, strong)UIButton *shootButtonPhoto;
@property (nonatomic, strong)UIButton *shootButtonVideo;

@property (nonatomic, strong)UIButton *revertButton;
@property (nonatomic, strong)UIImageView *thumbnailImageView;

@property (nonatomic)BOOL turnPhotoMode; //YES照片拍摄，NO视频拍摄

@property (nonatomic, copy)void(^onCaptureEvent)(BOOL isPhotoMode, void(^)(UIImage *thumbnail)); //isPhotoMode => YES照片拍摄，NO视频拍摄
@property (nonatomic, copy)void(^onRevertCameraPosition)(BOOL isPhotoMode);

@end

NS_ASSUME_NONNULL_END
