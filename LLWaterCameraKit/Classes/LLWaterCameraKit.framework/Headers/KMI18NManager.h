//
//  KMI18NManager.h
//  KMWaterCamera
//
//  Created by liujiang on 2023/1/6.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KMI18NManager : NSObject
@property (nonatomic, class, readonly)KMI18NManager *shared;

@property (nonatomic, strong, readonly)NSString *preferredLanguage;
@property (nonatomic, strong, readonly)NSString *currentLanguage;
@property (nonatomic, strong, readonly)NSString *currentRegion;

@end

@interface NSString (KMCameraLocalized)
@property (nonatomic, strong, readonly)NSString *km_localizedString;

@property (nonatomic, strong, readonly)NSString *toPinyin;
@property (nonatomic, strong, readonly)NSString *toPinyinWithCapitalLetterStart;
@end
