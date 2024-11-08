//
//  KMSampleContainerVCViewController.h
//  KMCameraComponent
//
//  Created by liujiang on 2023/8/29.
//

#import <UIKit/UIKit.h>
#import "KMSamplePhotoCameraController.h"
#import "KMSampleVideoCameraController.h"

NS_ASSUME_NONNULL_BEGIN

@interface KMSampleContainerVC : UIViewController
@property (nonatomic, strong)KMSamplePhotoCameraController *photoController;
@property (nonatomic, strong)KMSampleVideoCameraController *videoController;

@property (nonatomic, assign)NSUInteger uniqueIdentifier;

@end

NS_ASSUME_NONNULL_END
