//
//  CPLSensorCalibration.h
//  LivingMapSDK
//
//  Copyright © 2022 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPLDataContext.h"
#import "CalibrationMatrices.h"
/**
 * @class CPLSensorCalibration
 * @brief The CPLSensorCalibration class
 * @discussion Class that interfaces the calibration mechanism provided by the Common Positioning Library.
 */
@interface CPLSensorCalibration: NSObject

/**
 * @brief Creates an instance of a SensorCalibration.
 * @param configFilePath File path of the main run config.
 * @param dataContext : A shared pointer a CPLDataContext object.
 */
- (instancetype) initWithConfig:(NSString*) configFilePath
                        context:(CPLDataContext*) dataContext;

/**
 * @brief Updates mag configuration following calibration
 */
- (void) updateMagCalibrationConfig;
- (CalibrationMatrices*) getMagCalibrationConfig;


@end
