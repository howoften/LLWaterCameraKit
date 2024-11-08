//
//  KMCameraTransitionView.h
//  KMCameraComponent
//
//  Created by liujiang on 2023/8/31.
//

#import <UIKit/UIKit.h>


@interface KMCameraTransitionView : UIView
@property(nonatomic, strong)UIImageView *imageView;

@property (nonatomic)BOOL showAnimated;
@property (nonatomic)BOOL dismissAnimated;
@end
