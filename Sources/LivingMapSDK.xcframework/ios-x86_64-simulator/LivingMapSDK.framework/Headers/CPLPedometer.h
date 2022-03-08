//
//  CPLPedometer.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPLDataContext.h"

/**
 * @class CPLPedometer
 * @brief The CPLPedometer class
 * @discussion Class that interfaces the pedometer functionality provided by the Common Positioning Library.
 */
@interface CPLPedometer : NSObject

/**
 * @brief Creates an instance of a Pedometer.
 * @param configFilePath: File path of the main run config.
 * @param dataContext: A shared pointer a CPLDataContext object.
 */
- (instancetype) initWithConfig:(NSString*) configFilePath
                     andContext:(CPLDataContext*) dataContext;

/**
 * Get the step length based on the acceleration data provided. If acceleration data
 * was not provided, an exception will be thrown
 * @param stepFrequency: Measured in Hz; If the step frequency is zero, the run config defined default will be used.
 * @throws NoStepLengthEstimatorException, DataNotUploadedException, StepLengthEstimatorException, NonRecoverableException
 * @return The estimated step length.
 */
- (double) calculateStepLength:(double) stepFrequency;

@end
