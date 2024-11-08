//
//  GMSelectHotelView.h
//  GMWaterCamera
//
//  Created by Jimmy on 2020/12/25.
//  Copyright © 2020 Jimmy. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^HotelBlock)(NSString *hotelStr);

@interface KMLandmarakListView : UIView

/// hotelBlock
@property (nonatomic, copy) HotelBlock hotelBlock;

/// hotelArray
@property (nonatomic, strong) NSMutableArray *hotelArray;

@end

NS_ASSUME_NONNULL_END
