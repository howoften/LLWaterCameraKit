//
//  GMWatermarkedSettingModel.h
//  GMWaterCamera
//
//  Created by liujiang on 2022/12/2.
//  Copyright © 2022 GreenTree Inn. All rights reserved.
//

/**
 @brief 定位viewModel类，记录了定位信息，水印设置信息
 */
#import <Foundation/Foundation.h>

@class KMWatermarkedSettingModelItem;
NS_ASSUME_NONNULL_BEGIN

extern NSString *const KMLocationServiceStartDescrption;

@interface KMWatermarkedInfo : NSObject
@property float version;
@property (nonatomic, strong)KMWatermarkedSettingModelItem *alignRight;

@property (nonatomic, strong)KMWatermarkedSettingModelItem *watermarkedTitle;

@property (nonatomic, strong)KMWatermarkedSettingModelItem *address;

@property (nonatomic, strong)KMWatermarkedSettingModelItem *landmark;

@property (nonatomic, strong)KMWatermarkedSettingModelItem *captureTime;

@property (nonatomic, strong)KMWatermarkedSettingModelItem *capturePerson;
@property (nonatomic, strong)KMWatermarkedSettingModelItem *capturePersonNickname;
@property (nonatomic, strong)KMWatermarkedSettingModelItem *capturePersonPhoneNumConfused;

@property (nonatomic, strong)KMWatermarkedSettingModelItem *captureVendor;

@property (nonatomic, strong)KMWatermarkedSettingModelItem *remark;

@property (nonatomic, strong)KMWatermarkedSettingModelItem *weather;

@property (nonatomic, strong)KMWatermarkedSettingModelItem *temporaryLandmark;
@property (nonatomic, strong)KMWatermarkedSettingModelItem *hotelCode;

@property (nonatomic, assign)int flashMode;
@property (nonatomic, assign, readonly)CGFloat cameraAspectRatio;

@property (nonatomic, strong, readonly)NSArray<NSString *> *nearbyHotels;
@property (nonatomic, strong, readonly)NSDictionary *weatherInfo;

@property (nonatomic, class, readonly)KMWatermarkedInfo *singleton;

@property (nonatomic, strong, readonly)NSArray<KMWatermarkedSettingModelItem *> *totalSettingOptions;

- (void)saveChanges;

- (void)sendWeatherRequestCompletion:(void(^)(NSDictionary *resp))completion;

@end


@interface KMWatermarkedSettingModelItem : NSObject
@property (nonatomic, assign)BOOL enabled;
@property (nonatomic, assign)BOOL showSwitchControl;
@property (nonatomic, assign)BOOL rightIndicator;
@property (nonatomic, strong)NSString *desc;

@property (nonatomic, strong)NSString *title;
@property (nonatomic, strong)NSString *content;

@property (nonatomic, assign)NSDictionary *toDictionary;
+ (instancetype)instanceWithTitle:(NSString *)title;
@end
NS_ASSUME_NONNULL_END
