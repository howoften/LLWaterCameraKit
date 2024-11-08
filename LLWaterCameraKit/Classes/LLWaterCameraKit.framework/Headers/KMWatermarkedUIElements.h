//
//  KMWatermarkedUIFactory.h
//  LibKMCamera
//
//  Created by liujiang on 2023/2/21.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMShadowLabel.h"
NS_ASSUME_NONNULL_BEGIN

@interface KMWatermarkedUIElements : NSObject

@property (nonatomic, strong)UIButton *locateButton;

@property (nonatomic, strong)KMShadowLabel *titleLabel;

@property (nonatomic, strong)KMShadowLabel *addressLabel;
@property (nonatomic, strong)KMShadowLabel *gpsLabel;

@property (nonatomic, strong)KMShadowLabel *landmarkLabel;

@property (nonatomic, strong)KMShadowLabel *nowDateLabel;
@property (nonatomic, strong)KMShadowLabel *weekdayLabel;
@property (nonatomic, strong)KMShadowLabel *peresonNameLabel;
@property (nonatomic, strong)KMShadowLabel *phoneNumLabel;
@property (nonatomic, strong)KMShadowLabel *captureVendorLabel;

@property(nonatomic, strong)KMShadowLabel *remarkLabel;
@property(nonatomic, strong)KMShadowLabel *hotelCodeLabel;
@property(nonatomic, strong)KMShadowLabel *deviceIDLabel;

@property(nonatomic, strong)KMShadowLabel *weatherLabel;
@end

NS_ASSUME_NONNULL_END
