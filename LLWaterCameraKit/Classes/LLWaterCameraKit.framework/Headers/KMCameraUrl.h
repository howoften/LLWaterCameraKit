//
//  KMCameraUrl.h
//  LibKMCamera
//
//  Created by liujiang on 2023/2/21.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KMCameraUrl : NSObject

@property(nonatomic, class, readonly)NSString *nearbyHotels;

@property(nonatomic, class, readonly)NSString *todayWeather;

@property(nonatomic, class, readonly)NSString *feedback;

@property(nonatomic, class, readonly)NSString *webFeedbackToken;

@property(nonatomic, class, readonly)NSString *webFeedbackH5;
@end

