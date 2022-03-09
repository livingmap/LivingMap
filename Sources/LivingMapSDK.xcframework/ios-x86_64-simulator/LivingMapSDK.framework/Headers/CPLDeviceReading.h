//
//  CPLDeviceReading.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @class CPLDeviceReading
 * @brief The CPLDeviceReading class
 * @discussion An object representing a sensor reading. Used for comunication with the Common Positioning Library
 */
@interface CPLDeviceReading : NSObject

@property (nonatomic, readwrite) double x;
@property (nonatomic, readwrite) double y;
@property (nonatomic, readwrite) double z;
@property (nonatomic, readwrite) double w;
@property (nonatomic, readwrite) double timestamp;

/**
 * @brief Creates an instance of a CPLDeviceReading.
 * @param x: The x component of the reading.
 * @param y: The y component of the reading.
 * @param z: The z component of the reading.
 * @param w: The w component of the reading.
 * @param timestamp: The time at which the reading was taken.
 */
- (instancetype) initWithX:(double) x
                         y:(double) y
                         z:(double) z
                         w:(double) w
                 timestamp:(double) timestamp;

@end
