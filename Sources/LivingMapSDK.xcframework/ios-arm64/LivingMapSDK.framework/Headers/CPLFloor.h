//
//  CPLFloor.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPLFloorStatus.h"
/**
 * @class CPLFloor
 * @brief The CPLFloor class
 * @discussion An object representing a cplFloor. Used for comunication with the Common Positioning Library
 */
@interface CPLFloor: NSObject

@property (nonatomic, readwrite) CPLFloorStatus status;
@property (nonatomic, readwrite) int estimatedFloorId;
@property (nonatomic, readwrite) double heightChange;
@property (nonatomic, readwrite) CPLLocation* nextFloorLocation;
@property (nonatomic, readwrite) CPLLocation* startLocation;

/**
 * @brief Creates an instance of a CPLFloor.
 * @param CPLFloorStatus: define current floor change status
 * @param estimatedFloorId: The estimated FloorId after ascending ot descending.
 * @param heightChange: Height difference since last level status.
 * @param nextFloorLocation: new floor location.
 * @param startLocation: start location on the new floor.
 */
- (instancetype) initWithStatus:(CPLFloorStatus) status
               estimatedFloorId:(int) estimatedFloorId
                   heightChange:(double) heightChange
               nextFloorLocation:(CPLLocation*) nextFloorLocation
                  startLocation:(CPLLocation*) startLocation;

@end
