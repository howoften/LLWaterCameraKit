//
//  KMWaterMarkCell.h
//  KMWaterCamera
//
//  Created by Jimmy on 2020/12/23.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol KMWaterMarkCellDelegete <NSObject>

- (void)switchBtnClickedWithIndexPath:(NSIndexPath *)indexPath andisOn:(BOOL)isOn;

@end

@interface KMWaterMarkCell : UITableViewCell

/// waterMarkCellDelegete
@property (nonatomic, weak) id<KMWaterMarkCellDelegete> waterMarkCellDelegete;

/// indexPath
@property (nonatomic) NSIndexPath *indexPath;

@property (nonatomic, strong)UIStackView *leftStack;
/// switchBtn
@property (nonatomic, strong) UISwitch *switchBtn;
/// nameLabel
@property (nonatomic, strong) UILabel *nameLabel;

/// nameLabel
@property (nonatomic, strong) UILabel *detailLabel;

@end

NS_ASSUME_NONNULL_END
