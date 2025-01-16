//
//  LLWebViewHelper.h
//  WebviewComponent
//
//  Created by 刘江 on 2019/7/31.
//

#import <UIKit/UIKit.h>
#import "KMCameraTool+ZIP.h"
#import "KMI18NManager.h"
NS_ASSUME_NONNULL_BEGIN


FOUNDATION_EXTERN_INLINE BOOL KMObjectIsEmpty(id anyObject);
FOUNDATION_EXTERN_INLINE BOOL KMIsBangScreen(void);
FOUNDATION_EXTERN_INLINE BOOL responseCodeEqual(id responseObject, int equalToCode);
FOUNDATION_EXTERN_INLINE id callFunc(id receiver, NSString *aSelectorName, NSArray *arguments);

@interface KMCameraTool : NSObject<KMCameraToolZipInterface>
@property(nonatomic, class, readonly)NSString *deviceName;
@property(nonatomic, class, readonly)NSString *sysVersion;
@property(nonatomic, class, readonly)NSString *identifierForVendor;
@property(nonatomic, class, readonly)NSString *deviceModel;
@property(nonatomic, class, readonly)NSString *appVersion;
@property(nonatomic, class, readonly)NSString *appBuildVersion;
@property(nonatomic, class, readonly)NSString *appName;
@property(nonatomic, class, readonly)NSString *appBundleIdentifier;
@property(nonatomic, class, readonly)CGFloat statusBarHeight;
@property(nonatomic, class, readonly)NSString *deviceId;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithPath:(NSString *)path NS_DESIGNATED_INITIALIZER;

+ (UIViewController *)topViewController;

+ (NSBundle *)rootBundle;

+ (NSBundle *)resourceBunlde;

+ (NSString *)filePathForName:(NSString *)fileName sourceType:(NSString *)type;

+ (NSString *)imagefilePathForName:(NSString *)fileName sourceType:(NSString *)type;

+ (NSString *)pngImagefilePathForName:(NSString *)fileName;

+ (NSString *)jpegImagefilePathForName:(NSString *)fileName;

+ (UIImage *)shotWithView:(UIView *)view;

+ (UIImage *)shotWithView:(UIView *)view scope:(CGRect)scope;

+ (NSString *)longestSubStringBetweenFirstString:(NSString *)first andSecondString:(NSString *)second;

+ (NSString *)convertHex2Dec:(NSString *)hexString;

+ (NSString *)convertDec2Hex:(NSString *)decString;

+ (NSDictionary *)requestParameterForURL:(NSURL *)url;

+ (NSString *)imgElementForHTMLText:(NSString *)text;

+ (BOOL)validHexColorCodeString:(NSString *)colorString;

+ (BOOL)typeCompareForUnspecialObject:(id)object1 another:(id)object2;
+ (BOOL)typeCompareForUnspecialObject:(id)object1 class:(Class)classType;
+ (NSData *)decompressWeatherResponseData:(NSData *)responseData;
+ (NSString *)sortedKeysAndAddPercentEncoding:(NSDictionary *)params;
+ (BOOL)locationServiceAvailable;
+ (NSTimeZone *)timeZoneForCountryName:(NSString *)country;

+ (NSString *)infoPlistValueForKey:(NSString *)key;

@end

@interface UIImage (KMCameraBundle)
+ (UIImage *)pngImageInCameraBundleNamed:(NSString *)imageNamed;
+ (UIImage *)jpegImageInCameraBundleNamed:(NSString *)imageNamed;
@end

@interface UIView (KMToast)
- (void)showDarkContentToast:(NSString *)message;
- (void)showWhiteContentToast:(NSString *)message;
- (void)showTopInfiniteDarkContentToast:(id)message onTap:(void(^)(void))onTap;
- (void)showTopInfiniteWhiteContentToast:(id)message onTap:(void(^)(void))onTap;

- (void)showWhiteLoadingWithText:(NSString *)text;
- (void)showDarkLoadingWithText:(NSString *)text;
- (void)hideLoading;
- (void)hideToast;
@end
@interface NSObject (KMToast)
+ (void)showDarkContentToast:(NSString *)message;
+ (void)showWhiteContentToast:(NSString *)message;
+ (void)showTopInfiniteDarkContentToast:(id)message onTap:(void(^)(void))onTap;
+ (void)showTopInfiniteWhiteContentToast:(id)message onTap:(void(^)(void))onTap;

+ (void)showWhiteLoadingWithText:(NSString *)text;
+ (void)showDarkLoadingWithText:(NSString *)text;
+ (void)hideLoading;
+ (void)hideToast;
@end

@interface UIView (RemoveConstraints)

- (void)removeAllConstraints;

@end

@interface  NSData (Base64)
@property (nonatomic, readonly)NSString *base64String;
@end
NS_ASSUME_NONNULL_END
