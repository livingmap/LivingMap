//
//  CPLFloor.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AltitudeStatus.h"
/**
 * @class CPLFloor
 * @brief The CPLFloor class
 * @discussion An object representing a cplFloor. Used for comunication with the Common Positioning Library
 */
@interface CPLFloor: NSObject

@property (nonatomic, readwrite) AltitudeStatus status;
@property (nonatomic, readwrite) float estimatedFloorId;
@property (nonatomic, readwrite) CPLLocation* startLocation;
@property (nonatomic, readwrite) double heightChange;
@property (nonatomic, readwrite) double remainingHeight;
@property (nonatomic, readwrite) double heightAtStartOfChange;
@property (nonatomic, readwrite) double statusUpdateTime;
@property (nonatomic, readwrite) double statusChangeStartTime;
@property (nonatomic, readwrite) double statusChangeEndTime;



/**
 * @brief Creates an instance of a CPLFloor.
 * @param CPLFloorStatus: define current floor change status
 * @param estimatedFloorId: The estimated FloorId after ascending ot descending.
 * @param statusUpdateTime: Time stamp of the status update.
 * @param startLocation: start location on the new floor.
 */
- (instancetype) initWithStatus:(AltitudeStatus) status
               estimatedFloorId:(float) estimatedFloorId
                  startLocation:(CPLLocation*) startLocation
                   heightChange:(double) heightChange
                remainingHeight:(double) remainingHeight
          heightAtStartOfChange:(double) heightAtStartOfChange
               statusUpdateTime:(double) statusUpdateTime
          statusChangeStartTime:(double) statusChangeStartTime
            statusChangeEndTime:(double) statusChangeEndTime;

@end
