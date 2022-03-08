//
//  CPLPositioning.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CPLLocation.h"
#import "CPLDataContext.h"
#import "CPLMetrics.h"
#import "CPLPositioningAction.h"

/**
 * @class CPLPositioning
 * @brief The CPLPositioning class
 * @discussion Class that interfaces the positioning functionality provided by the Common Positioning Library.
 */
@interface CPLPositioning: NSObject

/**
 * @brief Creates an instance of Positioning.
 * @param configFilePath: File path for the main run config.
 * @param gridFilePath: File path for the grid.
 * @param gatewaysFilePath: File path for the gateways.
 * @param dataContext: A shared pointer a CPLDataContext object.
 * @param initLocation: Starting location.
 * @throws GridFileException, NoGridFoundException, InitializationException
 */
- (instancetype) initWithConfig:(NSString*) configFilePath
                           grid:(NSString*) gridFilePath
                       gateways:(NSString*) gatewaysFilePath
                    dataContext:(CPLDataContext*) dataContext
                  initLocation:(CPLLocation*) initLocation;

/**
 * Use this constructor if you don't need or want to initialize the starting grid or location, for example if
 * not using the CPL for positioning (yet). Note, however, that you should call `resetLocation`.
 * @brief Creates an instance of Positioning.
 * @param configFilePath: File path for the main run config.
 * @param gridFilePath: File path for the grid.
 * @param gatewaysFilePath: File path for the gateways.
 * @param dataContext: A shared pointer a CPLDataContext object.
 * @throws GridFileException, NoGridFoundException, InitializationException
 */
- (instancetype) initWithConfig:(NSString*) configFilePath
                           grid:(NSString*) gridFilePath
                       gateways:(NSString*) gatewaysFilePath
                    dataContext:(CPLDataContext*) dataContext;

/**
 * Complete step - called after each step or set of new data is collected. Updates particle positions, calculates
 * new weights and resamples.
 * @param pdr_heading - best available heading from the device
 * @param gyro_rotation  - optional rotation (GRV) of phone relative to an unknown starting orientation, used for LTM
 * @param step_length - optional the step length in meters, if set to 0 then the step length as specified in the run config is used
 * @return True if successful and a location determined; False otherwise (e.g. for LTM if not enough steps made)
 * @throws DataNotUploadedException, PositioningException, NonRecoverableException
 */
- (bool) completeStep:(double) pdrHeading
         gyroRotation:(double) gyroRotation
           stepLength:(double) stepLength;

/**
 * @brief Gets the current location.
 * @return The current best estimated location.
 */
- (CPLLocation*) getLocation;

/**
 * @brief Gets all the current location estimations.
 * @return An array of the current location estimations.
 */
- (NSArray*) getParticleLocations;

/**
 * Grids are loaded on a floor by floor basis, as a result this will only evaluate if the location is with in the grid loaded for the current floor.
 * @brief Determines if the given location in the currently with in the loaded grid.
 * @param location: The location you wish to verify is in the grid.
 * @return A boolean based on if the provided location is with in the currenty loaded grid.
 */
- (bool) isLocationInGrid:(CPLLocation*) location;

/**
 * Reset location based on a known location. This will be used for changing floors or grids.
 * Known location is used to determine which grid to use if there is more than one grid per floor.
 * If already using the correct grid, then the particles will be reinitialised around the known location.
 * @param init_location - this is used firstly to determine which floor's grid should be used. It does not need to be
 *        'valid', i.e. with coordinates, but these should be set if there is a recent location available. If no
 *        coordinates are provided, then there will be a full-grid initialisation.
 * @param allow_full_grid_initialization - allow full grid initialization if the initial location is invalid and
 *        cannot be used.
 *        If set to true, then a full-grid initialisation will take place and the function will return true.
 *        If set to false, then *no* full-grid initialisation will take place and the function will return false.
 *        Typically, you will want to set this to false if you have an alternative positioning method to use, and true if
 *        you have no choice but to let the CPL find a location after several iterations with a full-grid reset.
 * @param use_nearest_entry_point - find the nearest entry point to the given location, and use it if it is within the
 *        initialization range. This is useful for floor changes to re-adjust the location to the likely entry point
 *        on the new floor.
 * @param reachable_points_only - only distribute particles to points that can be reached from the given location,
 *        i.e. without going through a wall. This can be thought of like a 'flood fill' of the area.
 * @param initialization_range - if provided, will initialise particles in a circle with a radius of this value
 *        Default is 0 - the radius will be determined by the configuration parameter initialization_range_meters
 *        If using a location with an accuracy in metres, this can be used, but check the relevant documentation regarding
 *        the distribution of the accuracy value and set the sigma-rule accordingly. For example, in Android the accuracy
 *        represents 1 standard deviation in metres (the location will be within this distance 68% of the time). In Apple
 *        Core Location, however, the value is said to represent 3 standard deviations (the location will be within the
 *        distance 99.7% of the time).
 * @param sigma_rule - if set to 0, use a uniform distribution for the new particles, otherwise use a normal distribution
 *        where the given sigma-rule applies to the initialization_range.
 * @return true if the location was reset successfully, false otherwise
 */
- (bool) resetLocation:(CPLLocation*) initLocation
   allowFullGridInitialization: (bool) allowFullGridInitialization
           initializationRange:(int) initializationRange
          useNearestEntryPoint:(bool) useNearestEntryPoint
           reachablePointsOnly:(bool) reachablePointsOnly
                     sigmaRule:(int) sigmaRule;

/**
 * @brief Performance metrics for the positioning system.
 * @return A set of properties related to positioning performance.
 */
- (CPLMetrics*) getMetrics;

/**
 * Review the current state of the positioning system (currently only the particle filter)
 * i.e. IF particle filter metrics suggest the particles are leaving the grid
 *      AND particles are near an exit point (gateway)
 *      THEN check if alternate locations would be better
 * @param current_location
 * @return PositioningAction:
 *   PA_CONTINUE: OK, carry on with the current positioning method
 *   PA_CHECK_LOCATIONS: Metrics suggest that the positioning is struggling
 *                       Check alternative locations with choose_alternative_location() and call inject_location with it
 *   PA_RESET_WITH_CURRENT: Metrics suggest that the positioning is failing.
 *                       Reset the CPL with the latest CPL location (local reset) or an alternative if you so wish
 *   PA_RESET_WITH_ALTERNATIVE: Metrics suggest that the positioning is failing repeatedly
 *                       Reset the CPL with an alternative
 *   PA_SWITCH_TO_ALTERNATIVE: Metrics suggest that the positioning is failing repeatedly and is unlikely to recover
 *                       Switch to an alternative positioning method if one is available
 *   PA_CHECK_OUTSIDE_LOCATIONS: Metrics suggest that the position could be leaving the surveyed area.
 *                       Check alternative locations with choose_alternative_location() and consider using PDR
 *   PA_SWITCH_OUTSIDE: Metrics suggest that the position is leaving the area covered by the particle filter.
 *                      Consider switching to an alternative outdoor positioning method (GPS)
 *   PA_SWITCH_INSIDE: Metrics suggest that the position is moving into the area covered by the particle filter.
 *                     Consider (re)starting the particle filter with the current position.
 */
- (CPLPositioningAction) reviewPositioning:(CPLLocation*) currentLocation;

/**
 * See if any of the locations provided by other means are better than the current location. Normally this would be
 * called after a call to review_positioning() has suggested switching (indoor or outdoor).
 * This will determine a best available location based on the "positioning switching" config section of the
 * run_config.
 * @param current_location - the given current location
 * @param alternative_locations - the list of alternative location
 * @param must_be_inside - boolean to indicate whether the alternative must be surveyed/indoor location
 * @return a Location, the current_location or one of the alternative_locations.
 */
- (CPLLocation*) chooseAlternativeLocation:(CPLLocation*) currentLocation
                       alternativeLocation:(CPLLocation*) alternativeLocation
                              mustBeInside:(bool) mustBeInside;

/**
 * Inject location - new particles will be generated at the given new location.
 * @param new_location - the location where to inject the particles
 * @param likelihood - the proportion of the existing particles to be used in the new location
 * @param range - will inject particles in a circle with a radius of this value
 *        If using a location with an accuracy in metres, this can be used, but check the relevant documentation regarding
 *        the distribution of the accuracy value and set the sigma-rule accordingly. For example, in Android the accuracy
 *        represents 1 standard deviation in metres (the location will be within this distance 68% of the time). In Apple
 *        Core Location, however, the value is said to represent 3 standard deviations (the location will be within the
 *        distance 99.7% of the time).
 * @param sigma_rule - if set to 0, use a uniform distribution for the new particles, otherwise use a normal distribution
 *        where the given sigma-rule applies to the initialization_range.
 */
- (void) injectLocation:(CPLLocation*) location
         withLikelihood:(int) likelihood
               andRange:(int) range
              sigmaRule:(int) sigmaRule;

@end
