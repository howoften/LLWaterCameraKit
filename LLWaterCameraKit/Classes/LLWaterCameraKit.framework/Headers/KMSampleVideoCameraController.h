//
//  KMSampleVideoCameraController.h
//  KMCameraComponent
//
//  Created by liujiang on 2023/8/31.
//

#import <UIKit/UIKit.h>
@class KMSampleCameraOverlayView;
@class HXPhotoModel;
NS_ASSUME_NONNULL_BEGIN

@interface KMSampleVideoCameraController : UIViewController
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-property-synthesis"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
@property (nonatomic, strong) KMSampleCameraOverlayView *view;
@property (nonatomic, assign)NSUInteger uniqueIdentifier;

#pragma clang diagnostic pop
@property (nonatomic, copy)void(^runningStateObserve)(BOOL);
@property (nonatomic, readonly)BOOL isRunning; //相机session是否正在运行
@property (nonatomic, readonly)BOOL isReady;   //相机session是否初始化完成

- (void)takeVideo:(void(^)(BOOL success, UIImage *thumbnail, HXPhotoModel *videoModel))completion;
- (void)revertCameraPosition;
@end

NS_ASSUME_NONNULL_END

/**
 GPUImageChromaKeyBlendFilter:第二张图像有选择地替换第一张图像中的某种颜色。

 thresholdSensitivity: 阈值灵敏度：How close a color match needs to exist to the target color to be replaced (默认0.4)
 smoothing: 平滑度：融合颜色的平滑程度。 (默认0.1)
 GPUImageDissolveBlendFilter: 两张图片溶解混合模式。

 mix: 第二张图覆盖第一张图的程度。 (范围(0.0, 1.0), 默认0.5)。
 GPUImageMultiplyBlendFilter: 两张图片多重混合。

 GPUImageAddBlendFilter: 两张图的加法混合。

 GPUImageSubtractBlendFilter: 两张图的减法混合。

 GPUImageDivideBlendFilter: 两张图的除法混合。

 GPUImageOverlayBlendFilter: 叠加模式：两张图的叠加混合。

 GPUImageDarkenBlendFilter: 变暗模式：通过取图像之间每个颜色分量的最小值来融合两个图像。

 GPUImageLightenBlendFilter: 变亮模式：通过获取图像之间每个颜色分量的最大值来融合两个图像。

 GPUImageColorBurnBlendFilter: 两个图像的颜色加深混合。

 GPUImageColorDodgeBlendFilter: 两个图像的颜色减淡混合。

 GPUImageScreenBlendFilter: 滤色混合。

 GPUImageExclusionBlendFilter: 排除混合。

 GPUImageDifferenceBlendFilter: 差值混合。

 GPUImageHardLightBlendFilter: 强光混合。

 GPUImageSoftLightBlendFilter: 柔光混合。

 GPUImageAlphaBlendFilter: 根据第二张图的alpha通道，将第二张图混合到第一张图上。

 mix: 第二张图片覆盖第一张图片的程度（0.0-1.0，默认值1.0）
 GPUImageSourceOverBlendFilter: 将源应用于两个图像的混合(Applies a source over blend of two images)。

 GPUImageNormalBlendFilter: 普通混合。

 GPUImageColorBlendFilter: 颜色混合。

 GPUImageHueBlendFilter: 色相混合。

 GPUImageSaturationBlendFilter: 饱和度混合。

 GPUImageLuminosityBlendFilter: 亮度混合。

 GPUImageLinearBurnBlendFilter: 线性加深混合。

 GPUImagePoissonBlendFilter: 泊松（Poisson）混合。

 mix: 混合范围从0.0（仅图像1）到1.0（仅图像2渐变），以1.0作为正常水平。
 numIterations: 传播梯度的次数。 如果您想获得接近收敛的效果，则可以将其提高到100甚至1000。 是的，这会很慢。(The number of times to propagate the gradients. Crank this up to 100 or even 1000 if you want to get anywhere near convergence. Yes, this will be slow.)
 GPUImageMaskFilter: 用一张图遮罩另一张图。

 作者：开发者老岳
 链接：https://www.jianshu.com/p/98d47b84ba56
 来源：简书
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
