//
//  CPLLocation.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPLPositioningMethod.h"
#import "CPLCRS.h"

/**
 * @class CPLLocation
 * @brief The CPLLocation class
 * @discussion An object representing a location. Used for comunication with the Common Positioning Library
 */
@interface CPLLocation: NSObject

@property (nonatomic, readwrite) bool isValidLocation;
@property (nonatomic, readwrite) double x;
@property (nonatomic, readwrite) double y;
@property (nonatomic, readwrite) int floor;
@property (nonatomic, readwrite) double headingDegrees;
@property (nonatomic, readwrite) double headingRadians;
@property (nonatomic, readwrite) double accuracy;
@property (nonatomic, readwrite) double timestamp;
@property (nonatomic, readwrite) CPLCRS crs;
@property (nonatomic, readwrite) CPLPositioningMethod positioningMethod;

/**
 * @brief Creates an instance of a CPLLocation.
 * @param validLocation: Value defining if the position is with in the grid.
 * @param x: The x coordinate in the crs defined.
 * @param y: The y coordinate in the crs defined.
 * @param floor: The z coordinate defined as a Living Map floor id.
 * @param headingDegrees: The current heading of the device in degrees.
 * @param headingRadians: The current heading of the device in radians.
 * @param accuracy: The estimated error in meters of the x and y coordinates.
 * @param timestamp: The time at which the location was estimated.
 * @param crs: The cordinate reference system of the
 * @param positioningMethod: The method by which the location was derived.
 */
- (instancetype) initWithValidLocation:(bool) isValidLocation
                                         x:(double) x
                                         y:(double) y
                                     floor:(int) floor
                            headingDegrees:(double) headingDegrees
                            headingRadians:(double) headingRadians
                                  accuracy:(double) accuracy
                                 timestamp:(double) timestamp
                                       crs:(CPLCRS) crs
                         positioningMethod:(CPLPositioningMethod) positioningMethod;

@end
