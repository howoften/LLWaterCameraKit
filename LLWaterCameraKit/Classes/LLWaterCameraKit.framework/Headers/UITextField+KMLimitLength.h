//
//  limitInputLength.h
//  GMWaterCamera
//
//  Created by liujiang on 2022/12/14.
//  Copyright © 2022 GreenTree Inn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol KMTextFieldLimitInputDelegate <UITextFieldDelegate>
- (void)textFieldValueDidChange:(UITextField *)textField length:(int)length;

@end
@protocol KMTexViewLimitInputDelegate <UITextViewDelegate>
- (void)textViewValueDidChange:(UITextView *)textView length:(int)length;

@end

@interface UITextField (KMLimitLength)
@property (nonatomic, readonly)NSInteger textLength;
@property (nonatomic, assign)int maxInputLength;
@property (nonatomic) BOOL treatDoubleBytesAsTwoCharacter;

@end


@interface UITextView (KMLimitLength)
@property (nonatomic, readonly)NSInteger textLength;
@property (nonatomic, assign)int maxInputLength;
@property (nonatomic) BOOL treatDoubleBytesAsTwoCharacter;

@end
NS_ASSUME_NONNULL_END
