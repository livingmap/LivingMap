//
//  CPLMetrics.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @class CPLMetrics
 * @brief The CPLMetrics class
 * @discussion An object representing the performance of the Common positioning Library's positioning system.
 */
@interface CPLMetrics: NSObject

@property (nonatomic, readwrite) int activeParticleCount;
@property (nonatomic, readwrite) int clusterCount;
@property (nonatomic, readwrite) int depletion;
@property (nonatomic, readwrite) int stepsSinceInitialization;
@property (nonatomic, readwrite) int resampleCount;
@property (nonatomic, readwrite) int totalCheckLocationsCount;
@property (nonatomic, readwrite) int totalResetSwitchCount;
@property (nonatomic, readwrite) double effectiveSampleSize;
@property (nonatomic, readwrite) double entropy;
@property (nonatomic, readwrite) double meanHeadingOffset;
@property (nonatomic, readwrite) double meanStepLengthOffset;
@property (nonatomic, readwrite) double meanWeight;
@property (nonatomic, readwrite) double particlesArea;
@property (nonatomic, readwrite) double executionTime;
@property (nonatomic, readwrite) bool didResample;

/**
 * @brief Creates an instance of a CPLMetrics.
 * @param activeParticleCount
 * @param clusterCount
 * @param depletion
 * @param stepsSinceInitialization
 * @param resampleCount
 * @param totalCheckLocationsCount
 * @param totalResetSwitchCount
 * @param effectiveSampleSize
 * @param entropy
 * @param meanHeadingOffset
 * @param meanStepLengthOffset
 * @param meanWeight
 * @param particlesArea
 * @param didResample
 */
- (instancetype) initWithActiveParticleCount:(int) activeParticleCount
                                clusterCount:(int) clusterCount
                                   depletion:(int) depletion
                    stepsSinceInitialization:(int) stepsSinceInitialization
                               resampleCount:(int) resampleCount
                    totalCheckLocationsCount:(int) totalCheckLocationsCount
                       totalResetSwitchCount:(int) totalResetSwitchCount
                         effectiveSampleSize:(double) effectiveSampleSize
                                     entropy:(double) entropy
                           meanHeadingOffset:(double) meanHeadingOffset
                        meanStepLengthOffset:(double) meanStepLengthOffset
                                  meanWeight:(double) meanWeight
                               particlesArea:(double) particlesArea
                               executionTime:(double) executionTime
                                 didResample:(bool) didResample;

@end
