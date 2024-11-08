//
//  KMMarkDateView.h
//  KMWaterCamera
//
//  Created by Jimmy on 2020/12/23.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^DateBlock)(NSInteger index);

@interface KMMarkDateView : UIView

/// dateBlock
@property (nonatomic, copy) DateBlock dateBlock;

/// dateType
@property (nonatomic) NSInteger dateType;

@end

NS_ASSUME_NONNULL_END
