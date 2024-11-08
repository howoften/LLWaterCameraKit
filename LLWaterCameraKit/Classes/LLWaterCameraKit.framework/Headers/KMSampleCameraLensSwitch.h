//
//  KMSampleCameraLensSwitch.h
//  LibKMCamera
//
//  Created by liujiang on 2023/2/16.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KMSampleCameraLensSwitch : UIView
@property (nonatomic, assign)NSInteger index;

@property (nonatomic, copy)void(^switchAction)(int index);
@end

NS_ASSUME_NONNULL_END
