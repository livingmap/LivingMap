//
//  CPLHeadingEstimation.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPLDataContext.h"

/**
 * @class CPLHeadingEstimation
 * @brief The CPLHeadingEstimation class
 * @discussion Class that interfaces the heading functionality provided by the Common Positioning Library.
 */
@interface CPLHeadingEstimation : NSObject

/**
 * @brief Creates an instance of a HeadingEstimation.
 * @param configFilePath: File path of the main run config.
 * @param dataContext: A shared pointer a CPLDataContext object.
 * @param timeInterval: ...
 */
- (instancetype) initWithConfig:(NSString*) configFilePath
                     andContext:(CPLDataContext*) context;

- (void) reset;

/**
 * Uses the data contained with in the data context, passed to this object upon instantiation, to estimate the current
 * heading of the device. The data with in the data context should be synchronised before calling this function.
 * @brief Generates a heading estimate based on the most recently uploaded data contained with in the data context.
 * @throws NoHeadingEstimatorException, DataNotUploadedException, NoSynchronizationException,
 *         HeadingEstimationException, NonRecoverableException
 * @return Heading estimate in radians.
 */
- (double) calculateHeadingEstimate;

@end
