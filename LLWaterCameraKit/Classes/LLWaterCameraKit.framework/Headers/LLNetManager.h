//
//  NetManager.h
//  Empty
//
//  Created by 刘江 on 2018/11/14.
//  Copyright © 2018年 Liujiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LLNetReachability.h"

@interface LLNetManager : NSObject
@property (nonatomic, strong)NSDate *serverDate;


@property (nonatomic, assign)NSUInteger timeoutInterval;
@property (nonatomic, assign)BOOL signAsRequestParam;
@property (nonatomic, assign)BOOL signAsRequestHeader;



+ (LLNetManager *)shareInstance;
+ (NSURLSessionDataTask *)getWithUrlString:(NSString *)url parameters:(NSDictionary *)parameters success:(void(^)(id response))successBlock failure:(void(^)(NSError *error))failureBlock;

+ (NSURLSessionDataTask *)postWithUrlString:(NSString *)url parameters:(NSDictionary *)parameters success:(void(^)(id response))successBlock failure:(void(^)(NSError *error))failureBlock;

+ (NSURLSessionDataTask *)postFormDataWithUrlString:(NSString *)url parameters:(NSDictionary *)parameters success:(void(^)(id response))successBlock failure:(void(^)(NSError *error))failureBlock;

+ (NSURLSessionDataTask *)postApplicationJsonWithUrlString:(NSString *)url parameters:(NSDictionary *)parameters success:(void(^)(id response))successBlock failure:(void(^)(NSError *error))failureBlock;


+ (void)setHttpHeader:(NSString *)value key:(NSString *)key;
+ (void)setExtraHTTPHeaderForEveryRequest:(NSDictionary *(^)(NSString *ts, NSString *url))extraBlock;
+ (void)setNetworkresponseArriveObserver:(void(^)(id response))responseArriveObserver;

+ (void)startNetReachilityMonitorWithHostName:(NSString *)hostName;
+ (LLNetworkStatus)currentReachabilityStatus;


@end

@interface LLNetManager (KMCameraAPI)
+ (NSURLSessionDataTask *)postWeatherRequestWithUrlString:(NSString *)url parameters:(NSDictionary *)parameters success:(void(^)(id response))successBlock failure:(void(^)(NSError *error))failureBlock;
+ (NSURLSessionDataTask *)getMISTokenWithUrlString:(NSString *)url parameters:(NSDictionary *)parameters success:(void(^)(id response))successBlock failure:(void(^)(NSError *error))failureBlock;

@end
