//
//  KMSampleFeedbackController.h
//  LibKMCamera
//
//  Created by liujiang on 2023/2/24.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class KMFeedListData;
@interface KMSampleFeedbackController : UIViewController
@property (nonatomic, strong) KMFeedListData *cellData;

@end


//反馈类别列表
@interface KMFeedListData : NSObject

@property (nonatomic, strong) NSString *CategoryName;//部门名字
@property (nonatomic, strong) NSString *CategoryDescription;//部门描述
@property (nonatomic, strong) NSString *CategoryId;//部门ID

- (void)configData:(NSDictionary *)dict;
@end
NS_ASSUME_NONNULL_END
