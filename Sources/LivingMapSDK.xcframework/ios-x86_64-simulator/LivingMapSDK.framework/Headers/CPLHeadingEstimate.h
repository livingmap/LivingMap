
//  CPLHeadingEstimate.h
//  LivingMapSDK
//
//  Copyright © 2022 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPLHeadingEstimateType.h"

/**
 * @class CPLHeadingEstimate
 * @brief CPLHeadingEstimate class
 * @discussion An object representing a CPL heading estimate . Used for comunication with the Common Positioning Library
 */
@interface CPLHeadingEstimate: NSObject

@property (nonatomic, readwrite) double heading;
@property (nonatomic, readwrite) double accuracy;
@property (nonatomic, readwrite) double gyro_rotation;
@property (nonatomic, readwrite) CPLHeadingEstimateType estimateType;

/**
 * @brief Creates an instance of a CPLHeadingEstimate.
 * @param heading: The reduin calculated heading value.
 * @param accuracy: The heading accuracy value.
 * @param estimateType: The method by which the heading was derived.
 */
- (instancetype) initWithHeading:(double) heading
                        accuracy:(double) accuracy
                   gyro_rotation:(double) gyro_rotation
                    estimateType:(CPLHeadingEstimateType) estimateType;

@end
