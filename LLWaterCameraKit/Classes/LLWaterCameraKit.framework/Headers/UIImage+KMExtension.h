//
//  UIImage+KMExtension.h
//  LibKMCamera
//
//  Created by liujiang on 2023/1/31.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (KMExtension)
@property (nonatomic, copy, readonly) UIImage *(^toLeftOrientation)(void);
@property (nonatomic, copy, readonly) UIImage *(^toRightOrientation)(void);
@property (nonatomic, copy, readonly) UIImage *(^toUpOrientation)(void);
@property (nonatomic, copy, readonly) UIImage *(^toDownOrientation)(void);

- (UIImage *)km_imageByRotateLeft90;
- (UIImage *)km_imageByRotateRight90;
- (UIImage *)km_imageByRotate180;

- (UIImage *)km_yy_flipHorizontal:(BOOL)horizontal vertical:(BOOL)vertical;

- (UIImage *)imageByResizeToSize:(CGSize)size;
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius;
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                          borderWidth:(CGFloat)borderWidth
                          borderColor:(UIColor *)borderColor;
@end

NS_ASSUME_NONNULL_END
