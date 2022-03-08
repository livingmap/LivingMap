//
//  CPLFloorEstimation.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPLLocation.h"
#import "CPLDataContext.h"
#import "CPLFloor.h"

/**
 * @class CPLFloorEstimation
 * @brief The CPLFloorEstimation class
 * @discussion Class that interfaces the floor functionality provided by the Common Positioning Library.
 */
@interface CPLFloorEstimation : NSObject 

/**
 * @brief Creates an instance of a FloorEstimation.
 * @param configFilePath: File path of the main run config.
 * @param dataContext: A shared pointer a CPLDataContext object.
 * @param gateWayFilePath: File path of the gateWays file in the app bundle.
 * @param floorHeightFilePath: File path of the floorHeights file in the app bundle.
 */
- (instancetype) initWithConfig:(NSString*) configFilePath
                        context:(CPLDataContext*) dataContext
                gateWayFilePath:(NSString*) gateWayfilePath
            floorHeightFilePath:(NSString*) gridFilePath;

/**
 * @brief Determins the current floor a device is on.
 * @param currentLocation: The current location of the device.
 * @throws NoFloorEstimatorException, DataNotUploadedException, FloorEstimationException, NonRecoverableException
 * @return The current floor change status.
 */
- (CPLFloor*) checkFloorChangeStatus:(CPLLocation*) currentLocation;

/**
 * @brief Resets the floor estimation system to the provided floor.
 * @param floorId: The current location of the device.
 * @throws DataNotUploadedException, FloorEstimationException, NonRecoverableException
 */
- (void) resetFloorChangeStatus:(int) floorId;

@end
