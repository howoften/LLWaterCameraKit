//
//  KMMarkTextView.h
//  KMWaterCamera
//
//  Created by Jimmy on 2020/12/23.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KMMarkTextView : UIView

/// textBlock
@property (nonatomic, copy) void(^textBlock)(NSString *text);
@property (nonatomic) BOOL treatDoubleBytesAsTwoCharacter;

/// viewType
@property (nonatomic, copy) NSString *alertTitle; // 1 水印标题 2 备注
@property (nonatomic) int limitLength; 
/// 本身含有的信息
@property (nonatomic, copy) NSString *textString;

@end

NS_ASSUME_NONNULL_END
