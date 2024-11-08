//
//  UIView+flashAnimation.h
//  LibKMCamera
//
//  Created by liujiang on 2023/1/30.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (KMExtension)
@property (nonatomic, strong, readonly)UIViewController *viewController;
- (void)displayFlashEffective;

@end

NS_ASSUME_NONNULL_END
