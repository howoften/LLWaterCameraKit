//
//  KMWeakProxy.h
//  LibKMCamera
//
//  Created by liujiang on 2023/2/22.
//  Copyright © 2023 GreenTree Inn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KMWeakProxy : NSProxy
@property (nonatomic, weak, readonly) id target;

- (instancetype)initWithTarget:(id)target;
+ (instancetype)proxyWithTarget:(id)target;

@end

NS_ASSUME_NONNULL_END
