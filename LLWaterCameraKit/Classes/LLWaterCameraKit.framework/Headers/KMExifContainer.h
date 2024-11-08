//
//  ExifContainer.h
//  KMCameraComponent
//
//  Created by liujiang on 05/09/2023.
//
//

#import <Foundation/Foundation.h>

@class CLLocation;

@interface KMExifContainer : NSObject

- (void)addLocation:(CLLocation *)currentLocation;
- (void)addUserComment:(NSString *)comment;
- (void)addCreationDate:(NSDate *)date;
- (void)addDescription:(NSString *)description;
- (void)addProjection:(NSString *)projection;

- (void)setValue:(NSString *)key forExifKey:(NSString *)value;

- (NSDictionary *)exifData;
@end
