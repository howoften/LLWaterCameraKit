//
//  KMCameraModeSeekBar.h
//  KMCameraComponent
//
//  Created by liujiang on 2023/8/31.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KMCameraModeSeekBar : UIView
@property (nonatomic)BOOL enabled;
@property (nonatomic)NSInteger selectedIndex;

- (instancetype)initWithTitles:(NSArray<NSString *> *)titles;

@end

NS_ASSUME_NONNULL_END
