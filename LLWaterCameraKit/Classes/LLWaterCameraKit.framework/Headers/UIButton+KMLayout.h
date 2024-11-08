//
//  UIButton+KMLayout.h
//  LibKMCamera
//
//  Created by liujiang on 2023/2/22.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// 定义一个枚举（包含了四种类型的button）
typedef NS_ENUM(NSUInteger, KMButtonAlignment) {
    KMButtonAlignmentNone = 0,
    KMButtonAlignmentImageTopTextBottom, // image在上，label在下b
    KMButtonAlignmentImageLeftTextRight, // image在左，label在右
    KMButtonAlignmentImageBottomTextTop, // image在下，label在上
    KMButtonAlignmentImageRightTextLeft // image在右，label在左
};


@interface UIButton (KMLayout)
@property (nonatomic)KMButtonAlignment km_buttonAlignment;
@property (nonatomic)CGFloat km_padding;
/**
 *  设置button的titleLabel和imageView的布局样式，及间距
 *
 *  @param alignment titleLabel和imageView的布局样式
 *  @param padding titleLabel和imageView的间距
 */
- (void)setTitleImageAlignment:(KMButtonAlignment)alignment
                        padding:(CGFloat)padding;
@end

NS_ASSUME_NONNULL_END
