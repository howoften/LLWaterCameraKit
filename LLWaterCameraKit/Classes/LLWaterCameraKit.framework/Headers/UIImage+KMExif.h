//
//  UIImage+KMExif.h
//  Pods
//
//  Created by liujiang on 05/09/2023.
//
//

#import <UIKit/UIKit.h>
#import "KMExifContainer.h"


@interface UIImage (EKMExif)

- (NSData *)addExif:(KMExifContainer *)container;

@end
