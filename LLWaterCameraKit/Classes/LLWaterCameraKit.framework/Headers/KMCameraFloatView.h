//
//  KMCameraFloatView.h
//  LibKMCamera
//
//  Created by liujiang on 2023/1/30.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KMCameraFloatView : UIView
@property(nonatomic, strong)UIImageView *preview;
@property(nonatomic, strong)UIStackView *mainStackView;
@property(nonatomic, assign)BOOL alignTrailing;


- (void)insert:(UIView *)element at:(NSIndexPath *)indexPath;
- (void)remove:(UIView *)element;
- (void)removeRowAt:(NSInteger)row;
- (void)add:(UIView *)element forRow:(NSInteger)row;
- (void)setCustomSpacing:(CGFloat)spacing atIndex:(int)index API_AVAILABLE(ios(11.0));
- (void)disableShadow:(BOOL)disable;
- (void)boldElements:(BOOL)bold;
@end

NS_ASSUME_NONNULL_END
