//
//  LLViewController.m
//  LLWaterCameraKit
//
//  Created by howoften on 11/08/2024.
//  Copyright (c) 2024 howoften. All rights reserved.
//

#import "LLViewController.h"
#import <LLWaterCameraKit/KMCameraComponent.h>
#import <LLWaterCameraKit/LLNetManager.h>
#import <LLWaterCameraKit/NSDate+KMExtension.h>

@interface LLViewController ()

@end

@implementation LLViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    NSLog(@">>>>>>>>>>>>%f", CFAbsoluteTimeGetCurrent());
    [LLNetManager postWithUrlString:@"http://10.3.104.119:8067/webservice1.asmx/GetReackItemDetail" parameters:@{
        @"ManagerTripID": @"4238",
        @"SerialNum": @"02010011",
        @"stand": @"门设置位置、尺寸需与图纸相符（不符0.5分）",
        @"titleName": @"大门"
    } success:^(id response) {
        NSLog(@"<<<<<<<<<<<<%f", CFAbsoluteTimeGetCurrent());
    } failure:^(NSError *error) {
        NSLog(@"<<<<<<<<<<<<%f", CFAbsoluteTimeGetCurrent());
    }];
    
    [LLNetManager setExtraHTTPHeaderForEveryRequest:^NSDictionary *(NSString *ts, NSString *url) {
        if ([url hasSuffix:@"GetReackItemDetail"]) {
            return @{@"Authorization": @"tgKy2RsrkuY2q0yCeeTtyErSyGKomAEWHtzyWZm2UG59YJ/pQb2Fgldy8Z3JSrg91Y2FoRer2o/wgEH9AlLCWyKpFWBYF2kbHIstjGR36c2Bn0fmAXPnllclPbTpXz0QQpjc2a+AQIKUJWt26x2RTmf1DdomuqsNYm/9y5LqeOw="};
        }
        return nil;
    }];
    
    NSDate *date = [NSDate dateWithShanghaiTimeZoneAndUSPOSIXFormat:@"yyyy-MM-dd HH:mm:ss" dateString:@"2024-05-04 12:00:00"];
    NSString *str = [date stringWithShanghaiTimeZoneAndUSPOSIXFormat:@"yyyy-MM-dd HH:mm"];
    NSLog(@"%@", date);
}
- (IBAction)open:(id)sender {
    [KMCameraAPI presentSampleCameraController];
    [KMCameraAPI addPhotoTakenListenerForCamersController:KMCameraAPI.shared.currentSamplePhotoCameraController ignoreIfAdded:YES completion:^(UIImage * _Nonnull originalImage, UIImage * _Nonnull watermarkImage, HXPhotoModel * _Nonnull __strong photoModel) {
        
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)openAlbum:(id)sender {
    [KMCameraAPI presentPhotoLibraryDidDone:^(NSArray<HXPhotoModel *> * _Nonnull allList, NSArray<HXPhotoModel *> * _Nonnull photoList, NSArray<HXPhotoModel *> * _Nonnull videoList, BOOL isOriginal) {
        HXPhotoModel *model = photoList.firstObject;
        [model requestImageDataWithLoadOriginalImage:NO startRequestICloud:nil progressHandler:nil success:^(NSData * _Nullable imageData, UIImageOrientation orientation, HXPhotoModel * _Nullable model, NSDictionary * _Nullable info) {
            BOOL byKmCamera = [KMCameraAPI photoDataCaptureByKMCamera:imageData];
            BOOL byOldKmCamera = [KMCameraAPI photoDataCaptureByOldVersionKMCamera:imageData];
            NSDate *date = [KMCameraAPI photoDataCaptureDateForImage:imageData];
            NSLog(@"%d--%@", byKmCamera, date);
        } failed:^(NSDictionary * _Nullable info, HXPhotoModel * _Nullable model) {
            
        }];
        
    } cancel:^{
        
    }];
}

@end
