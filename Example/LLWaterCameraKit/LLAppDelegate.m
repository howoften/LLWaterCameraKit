//
//  LLAppDelegate.m
//  LLWaterCameraKit
//
//  Created by howoften on 11/08/2024.
//  Copyright (c) 2024 howoften. All rights reserved.
//

#import "LLAppDelegate.h"
#import <LLWaterCameraKit/KMCameraAPI.h>
#ifndef PROD
#define PROD 0
#endif

@implementation LLAppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{

    [KMCameraAPI configWithUserName:@"李道运" phoneNumer:@"13788972485" hotelCode:@"" userId:@"1002018032100011" userToken:@"1002014050400041" visitorRole:YES
#if PROD
        inProductEnv:YES];
#else
        inProductEnv:NO];
#endif

    KMCameraAPI.shared.locationInfo = @{ @"latitude": @(31.303143),
                                         @"longitude": @(121.308186),
                                         @"address": @"上海市嘉定区沪宜公路1183号(121.308186,31.303143)",
                                         @"country": @"中国",
                                         @"province": @"上海市",
                                         @"city": @"上海市",
                                         @"district": @"嘉定区",
                                         @"town": @"南翔镇",
                                         @"street": @"沪宜公路",
                                         @"poiList":@[@"上海市嘉定区沪宜公路1183号", @"南翔高科商务中心", @"爱就投大厦"],
                                         @"timestamp":[NSDate date],

    };
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        KMCameraAPI.shared.locationInfo = @{
//    });
    
//    [KMCameraAPI presentSampleCameraController];
//    [KMCameraAPI presentPhotoLibraryWithMaxPhotosCount:3 alreadyChoseAssets:nil allowSelection:NO didDone:^(NSArray<HXPhotoModel *> *allList, NSArray<HXPhotoModel *> *photoList, NSArray<HXPhotoModel *> *videoList, BOOL isOriginal) {
//
//    } cancel:^{
//
//    }];
    KMCameraAPI.shared.albumName = @"相机组件";
    KMCameraAPI.shared.videoQuality = KMVideoRecordQualityLow;
    KMCameraAPI.shared.dismissAfterTakingPhoto = NO;
    KMCameraAPI.shared.presentPhotoEditAfterTakingPhoto = NO;
    KMCameraAPI.shared.maxDurationWhenRecordVideo = 60;
    KMCameraAPI.shared.supportCameraMdeiaType = KMCameraMediaTypePhotoAndVideo;
    KMCameraAPI.shared.defaultCameraMdeiaType = KMCameraMediaTypePhoto;
    [KMCameraAPI addPhotoTakenListenerForCamersController:KMCameraAPI.shared.currentSamplePhotoCameraController ignoreIfAdded:YES completion:^(UIImage * _Nonnull originalImage, UIImage * _Nonnull watermarkImage, HXPhotoModel * _Nonnull __strong photoModel) {
        
    }];
    KMCameraAPI.shared.settingOptions = KMCameraSettingOptionsAll;
    KMCameraAPI.shared.removeSettingPageIfNoSettingOptionsConfigured = YES;
    KMCameraAPI.shared.enableVideoCaptureMirroredForFrontCameraPosition = NO;
    [KMCameraAPI setSampleCameraClickListenerForSettingOptions:^BOOL(KMCameraSettingOptions option) {
        if (option == KMCameraSettingOptionsLogout) {
//            return YES;
        }
        if (option == KMCameraSettingOptionsCustomerService) {
            return YES;
        }
        return NO;
    }];
    return YES;
}
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
