
//  CalibrationMatrices.h
//  LivingMapSDK
//
//  Copyright © 2022 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MagCalibrationMethod.h"

/**
 * @class CalibrationMatrices
 * @brief CalibrationMatrices class
 * @discussion An object representing CalibrationMatrices . Used for comunication with the Common Positioning Library
 */
@interface CalibrationMatrices: NSObject

@property (nonatomic, readwrite) NSArray *magBias;
@property (nonatomic, readwrite) NSArray *accBias;
@property (nonatomic, readwrite) NSArray *gyrBias;
@property (nonatomic, readwrite) NSArray *magMatrix;
@property (nonatomic, readwrite) NSArray *accMatrix;
@property (nonatomic, readwrite) NSArray *gyrMatrix;
@property (nonatomic, readwrite) double accuracy;
/**
 * @brief Creates an instance of a CalibrationMatrices.
 * @param magCalibrationMethod :  method to be used with  CPL mag calibration.
 * @param magBias : Linear bias associated with magnetometer readings.
 * @param accBias : Linear bias associated with accelerometer readings.
 * @param gyrBias : Linear bias associated with gyroscope readings.
 * @param magMatrix : Non-linear bias associated with magnetometer readings.
 * @param accMatrix : Non-linear bias associated with accelerometer readings.
 * @param gyrMatrix : Non-linear bias associated with gyroscope readings.
 * @param accuracy : Double represent CPL calibration accuracy.
 */
- (instancetype) initWithMagBias:(NSArray*) magBias
                         accBias:(NSArray*) accBias
                         gyrBias:(NSArray*) gyrBias
                       magMatrix:(NSArray*) magMatrix
                       accMatrix:(NSArray*) accMatrix
                       gyrMatrix:(NSArray*) gyrMatrix
                        accuracy:(double) accuracy;
@end
