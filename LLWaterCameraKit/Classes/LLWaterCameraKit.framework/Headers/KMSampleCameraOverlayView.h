//
//  KMSampleCameraOverlayView.h
//  LibKMCamera
//
//  Created by liujiang on 2023/2/16.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KMSampleCameraLensSwitch.h"
#import "KMWatermarkedUIElements.h"
#import "KMCameraFloatView.h"

@interface KMSampleCameraOverlayView : UIView

@property (nonatomic, strong) UIView *captureBox;
/// 水印view
@property (nonatomic, strong) KMWatermarkedUIElements *watermarkedView;
@property (nonatomic, strong)KMCameraFloatView *floatView;
@property (nonatomic, strong) KMSampleCameraLensSwitch *modeSwitch; //广角/普通
@property (nonatomic) BOOL disableLandmarkSelect;
@property (nonatomic, readonly)UIImage *watermarkedViewRenderImage;

- (void)configWatermarkInfoForce:(BOOL)forceUpdate;
@end


