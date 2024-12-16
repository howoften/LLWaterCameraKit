//
//  KMCameraAPI.h
//  LibKMCamera
//
//  Created by liujiang on 2023/1/13.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol FastttCameraDelegate;
@class KMDeviceOrientationMonitor;
#if __has_include(<HXPhotoPicker/HXPhotoPicker.h>)
#import <HXPhotoPicker/HXPhotoPicker.h>
#endif

#define KMDispatchMainAsyncSafe(block) \
    do { \
        if ([NSThread isMainThread]) { \
            block(); \
        } else { \
            dispatch_async(dispatch_get_main_queue(), block); \
        } \
    } while (0)

#define KMDispatchMainSyncSafe(block) \
    do { \
        if ([NSThread isMainThread]) { \
            block(); \
        } else { \
            dispatch_sync(dispatch_get_main_queue(), block); \
        } \
    } while (0)

typedef NS_ENUM(NSInteger, KMDeviceOrientation) {
    KMDeviceOrientationUnkown = 0,
    KMDeviceOrientationPortrait,
    KMDeviceOrientationDown,
    KMDeviceOrientationRight,
    KMDeviceOrientationLeft,
};
typedef NS_ENUM(NSInteger, KMDeviceFlashMode) {
    KMDeviceFlashModeClose = 0,
    KMDeviceFlashModeOpen,
    KMDeviceFlashModeAuto
};
typedef NS_ENUM(NSInteger, KMCameraLensType) {
    KMCameraLensTypeTelePhoto,
    KMCameraLensTypeWideAngle,
};

typedef NS_OPTIONS(NSUInteger, KMCameraSettingOptions) {
    KMCameraSettingOptionsNone                  = 0,
    KMCameraSettingOptionsCustomerService       = 1 << 0,
    KMCameraSettingOptionsWatermarkedConfig     = 1 << 1,
    KMCameraSettingOptionsPhotoQuality          = 1 << 2,
    KMCameraSettingOptionsVideoQuality          = 1 << 3,
    KMCameraSettingOptionsSystemEvaluation      = 1 << 4,
    KMCameraSettingOptionsPrivatePolicy         = 1 << 5,
    KMCameraSettingOptionsNotifications         = 1 << 6,
    KMCameraSettingOptionsLogoffAccount         = 1 << 7,
    KMCameraSettingOptionsFeedback              = 1 << 8,
    KMCameraSettingOptionsUpdate                = 1 << 9,
    KMCameraSettingOptionsLogout                = 1 << 10,
    KMCameraSettingOptionsAll                   = ~0UL
};
typedef NS_ENUM(NSInteger, KMCameraMediaType) {
    KMCameraMediaTypePhotoAndVideo = 0,
    KMCameraMediaTypeVideo,
    KMCameraMediaTypePhoto,
};
typedef NS_ENUM(NSInteger, KMVideoRecordQuality) {
    KMVideoRecordQualityHigh = 0,
    KMVideoRecordQualityMedium,
    KMVideoRecordQualityLow,
};
@interface KMCameraAPI : NSObject {
    @private
    BOOL _lockOrientation;
    BOOL _enableVideoCaptureMirroredForFrontCameraPosition;
    BOOL _enableVideoLayerAndVideoCaptureMirroredForFrontCameraPosition;
    KMCameraLensType _lensType;
    pthread_mutex_t mutex_lock;
    KMDeviceOrientation _currentOrientation;
    KMDeviceOrientationMonitor *_orientationMonitor;
    NSMutableArray *_orientationChangedBlocks;
    NSPointerArray *_rotatableSubviews;
    NSPointerArray *_gestureResponders;
    NSMapTable *_cameraAndControllerMap;
    NSMapTable *_cameraAndOverlayMap;
    NSMutableArray *_takePictureCompletionBlocks;
    NSPointerArray<FastttCameraDelegate> *_delegates;
    NSPointerArray *_ignoredElementsForCapture;
    __weak UIViewController *_currentSampleContainerController;
    __weak UIViewController *_currentSamplePhotoCameraController;
    __weak UIViewController *_currentSampleVideoCameraController;
}
extern NSString *const KMCameraAPIWillExitNotificationName;
extern NSString *const KMCameraAPIPhotoCaptureStamp;
extern NSString *const KMStringInitialValue;
@property (nonatomic, class, readonly)KMCameraAPI *shared;
@property (nonatomic, assign)BOOL lockOrientation;
@property (nonatomic, assign)BOOL presentPhotoEditAfterTakingPhoto;
@property (nonatomic, assign)BOOL dismissAfterTakingPhoto;
@property (nonatomic, assign)BOOL waitUntilWatermarkElementApply;//阻塞拍摄直到水印合成结束才进行下一次合成
@property (nonatomic, strong)UIColor *themeColor;
@property (nonatomic, strong)NSString *albumName; //照片或视频要保存到的相册名称
@property (nonatomic, assign, readonly)KMDeviceOrientation currentOrientation;
@property (nonatomic, strong, readonly)NSPointerArray *gestureResponders;
@property (nonatomic, assign, readonly)BOOL supportWideAngleLens;
@property (nonatomic, strong, readonly)NSString *userName;
@property (nonatomic, strong, readonly)NSString *phoneNumber;
@property (nonatomic, strong, readonly)NSString *hotelCode;
@property (nonatomic, strong, readonly)NSString *userId;
@property (nonatomic, assign, readonly)BOOL visitorRole;
@property (nonatomic, strong, readonly)NSString *userToken;
@property (nonatomic, weak, readonly)UIViewController *currentSampleContainerController;
@property (nonatomic, weak, readonly)UIViewController *currentSamplePhotoCameraController;
@property (nonatomic, weak, readonly)UIViewController *currentSampleVideoCameraController;
@property (nonatomic, assign)KMCameraSettingOptions settingOptions;//配置设置页设置项 当使用示例相机界面时有效
@property (nonatomic, assign)BOOL removeSettingPageIfNoSettingOptionsConfigured; //当设置页无设置项时，移除此页面，当使用示例相机界面时有效
@property (nonatomic, copy, readonly)BOOL(^clickSettingOptionsListener)(KMCameraSettingOptions option);
@property (nonatomic)BOOL throttleBackgroundFetch; //节省不必要刷新
@property (nonatomic)BOOL enableVideoCaptureMirroredForFrontCameraPosition; //设置前置是否镜像
@property (nonatomic)BOOL enableVideoLayerAndVideoCaptureMirroredForFrontCameraPosition API_DEPRECATED("Use KMCameraAPI's enableCaptureVideoMirroredForFrontCameraPosition instead.", ios(4.0, 6.0)); //设置前置是否镜像
@property (nonatomic)KMCameraMediaType supportCameraMdeiaType; //可支持拍摄的类型
@property (nonatomic, assign)KMCameraMediaType defaultCameraMdeiaType;
@property (nonatomic, readonly)KMCameraMediaType currentCameraMdeiaType;
@property (nonatomic, readonly)CGSize cameraWindowSize;
@property (nonatomic, readonly)BOOL isFrontCameraPosition;
@property (nonatomic, assign)NSInteger maxDurationWhenRecordVideo;

@property (nonatomic, strong)NSDictionary *locationInfo;
@property (nonatomic, assign)BOOL onProductEnv; //接口环境
@property (nonatomic, assign, readonly)BOOL embeddedInKMAPP; //是否工作在格美相机app项目
@property (nonatomic, class)KMDeviceFlashMode cameraFlashMode;
@property (nonatomic, class)KMCameraLensType cameraLensType;
@property (nonatomic, class, readonly)NSString *photoNameForSave;
@property (nonatomic, class, readonly)NSString *videoNameForSave;
@property (nonatomic)KMVideoRecordQuality videoQuality;
@property (nonatomic)KMVideoRecordQuality photoQuality;

+ (void)configWithUserName:(NSString *)userName phoneNumer:(NSString *)phoneNumber hotelCode:(NSString *)hotelCode userId:(NSString *)userId userToken:(NSString *)userToken visitorRole:(BOOL)isVisitorRole inProductEnv:(BOOL)productEnv;

+ (UIView *)cameraViewForDelegate:(id<FastttCameraDelegate>)delegate;

+ (void)startDeviceOrientationMonitor:(void(^)(KMDeviceOrientation orientation))orientationChange;

+ (void)addRotatableSubviewsFromArray:(NSArray <UIView *> *)subviewsToAdd;
+ (void)removeRotatableSubviewsFromArray:(NSArray <UIView *> *)subviewsToRemove;


+ (void)takePhotoBeforeAddWatermark:(void(^)(UIImage *))beforeWatermark completion:(void(^)(UIImage *, UIImage *))completion;
#if __has_include(<HXPhotoPicker/HXPhotoPicker.h>)
+ (void(^)(UIImage *originalImage, HXPhotoModel *videoModel))takeVideoCompletion;
#else
+ (void(^)(UIImage *originalImage, NSURL * videoURL))takeVideoCompletion;
#endif
+ (void)revertCameraPosition;
//+ (void)revertCameraPositionToFront:(BOOL)isFront;
//+ (BOOL)isFronCameraPosition;

// 水印更新
+ (void)insertUIElement:(UIView *)element atIndexPath:(NSIndexPath *)indexPath;
+ (void)addUIElement:(UIView *)element atRow:(NSInteger)row;
+ (void)removeUIElement:(UIView *)element;
+ (void)removeUIElementsForRow:(NSInteger)row;
+ (void)setAlignTrailinng:(BOOL)alignTrailing;
+ (void)disableWatermarkElementsShadow:(BOOL)disable;
+ (void)boldWatermarkElements:(BOOL)bold;

+ (void)addGestureResponder:(UIView *)responder;
+ (void)addIgnoredUIElementForCapture:(UIView *)ignoredUIElement;
+ (void)setCustomSpacing:(CGFloat)spacing atIndex:(int)index API_AVAILABLE(ios(11.0));

+ (void)setCameraLensType:(KMCameraLensType)lensType;
+ (KMCameraLensType)cameraLensType;
+ (void)openSystemPhotoAlbum;
+ (void)openSystemSettings;
+ (UIViewController *)presentSampleCameraController;
+ (void)dismissSampleCameraControllerAnimated:(BOOL)animated;
+ (UIViewController *)newSampleCameraController;
#if __has_include(<HXPhotoPicker/HXPhotoPicker.h>)
+ (void)presentPhotoLibraryDidDone:(void (^)(NSArray<HXPhotoModel *> *allList, NSArray<HXPhotoModel *> *photoList, NSArray<HXPhotoModel *> *videoList, BOOL isOriginal))didDone cancel:(void (^)(void))cancel;
+ (void)presentPhotoLibraryWithMaxPhotosCount:(NSUInteger)maxCount alreadyChoseAssets:(NSArray<HXCustomAssetModel *> *)choseAssets allowSelection:(BOOL)allowSelection didDone:(void (^)(NSArray<HXPhotoModel *> *allList, NSArray<HXPhotoModel *> *photoList, NSArray<HXPhotoModel *> *videoList, BOOL isOriginal))didDone cancel:(void (^)(void))cancel;
+ (void)presentPhotoLibraryWithPhotoManager:(HXPhotoManager *)photoManager allowSelection:(BOOL)allowSelection didDone:(void (^)(NSArray<HXPhotoModel *> *allList, NSArray<HXPhotoModel *> *photoList, NSArray<HXPhotoModel *> *videoList, BOOL isOriginal))didDone cancel:(void (^)(void))cancel;
+ (void)addPhotoTakenListenerForCamersController:(UIViewController *)viewController ignoreIfAdded:(BOOL)ifIgnored completion:(void(^)(UIImage *originalImage, UIImage * watermarkImage, HXPhotoModel *photoModel))completion;

#else
+ (void)addPhotoTakenListenerForCamersController:(UIViewController *)viewController ignoreIfAdded:(BOOL)ifIgnored completion:(void(^)(UIImage *originalImage, UIImage * watermarkImage))completion;

#endif

+ (void)setSampleCameraClickListenerForSettingOptions:(BOOL(^)(KMCameraSettingOptions option))clickEvents; //返回YES表示响应次事件
+ (void)setSampleCamerNetworkResponseListenerForUrlString:(NSString *)urlString responseCallback:(void(^)(id response))responseCallback;

+ (BOOL)photoCaptureByKMCamera:(UIImage *)image;
+ (BOOL)photoCaptureByOldVersionKMCamera:(UIImage *)image;
+ (BOOL)photoDataCaptureByKMCamera:(NSData *)imageData;
+ (BOOL)photoDataCaptureByOldVersionKMCamera:(NSData *)imageData;
+ (NSString *)captureUserIDForForImage:(UIImage *)image;
+ (NSString *)captureUserIDForForImageData:(NSData *)imageData;
+ (NSDate *)photoCaptureDateForImage:(UIImage *)image;
+ (NSDate *)photoDataCaptureDateForImage:(NSData *)imageData;
+ (CLLocation *)captureLocationCoordinate2DForImage:(UIImage *)image;
+ (CLLocation *)captureLocationCoordinate2DForImageData:(NSData *)imageData;
@end
 
@interface KMCameraAPI (Store)

@end
