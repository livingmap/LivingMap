//
//  CPLDataContext.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @class CPLDataContext
 * @brief The CPLDataContext class
 * @discussion An object used to store and share data between multiple other objects.
 */
@interface CPLDataContext: NSObject

#ifdef __cplusplus
@property (unsafe_unretained,assign,atomic) std::shared_ptr<cpl::DataContext> dataContext;
#endif

/**
 * @brief Creates an instance of a CPLDataContext.
 */
- (instancetype) init;

/**
 * Given a file path pointing to the main cpl run config, this function deserialises and extracts the appropriate information stored.
 * Once extracted, the configuration data contain with in the `Calibration` json object is used to configure how this class calibrates
 * data provided to it.
 * @brief Configures how data calibration operates.
 * @param configFilePath: File path of the main run config.
 */
- (void) setCalibrationConfig:(NSString*) configFilePath;

/**
 * @brief Stores the provided data.
 * @param calibratedMagData: An array of CPLDeviceReading objects that contain mag data.
 * @throws DataAlreadyUploadedException
 * @return A reference to this object.
 */
- (instancetype) uploadMagnetometerReadings:(NSArray*) calibratedMagData move:(bool) move;

/**
 * @brief Stores the provided data.
 * @param accelerometerData: An array of CPLDeviceReading objects that contain acceleration data.
 * @throws DataAlreadyUploadedException
 * @return A reference to this object.
 */
- (instancetype) uploadAccelerometerReadings:(NSArray*) accelerometerData move:(bool) move;

/**
 * @brief Stores the provided data.
 * @param gravityData: An array of CPLDeviceReading objects that contain gravity data.
 * @throws DataAlreadyUploadedException
 * @return A reference to this object.
 */
- (instancetype) uploadGravityReadings:(NSArray*) gravityData move:(bool) move;

/**
 * @brief Stores the provided data.
 * @param gyroscopeData: An array of CPLDeviceReading objects that contain gyroscope data.
 * @throws DataAlreadyUploadedException
 * @return A reference to this object.
 */
- (instancetype) uploadGyroscopeReadings:(NSArray*) gyroscopeData move:(bool) move;

/**
 * @brief Stores the provided data.
 * @param pressureData: An array of CPLDeviceReading objects that contain pressure data.
 * @throws DataAlreadyUploadedException
 * @return A reference to this object.
 */
- (instancetype) uploadPressureData:(NSArray*) pressureData move:(bool) move;

/**
 * @brief Remove all data uploaded to the context.
 * @return A reference to this object.
 */
- (instancetype) clearData;

/**
 * @brief Synchronises the data currently stored in this object.
 * @param stepStartTime: start time (seconds)
 * @param stepEndTime: end time (seconds)
 * @param syncTimeInterval: required time between readings (seconds)
 * @throws SynchronizationException
 * @return A reference to this object.
 */
- (instancetype) synchronizeData:(double) stepStartTime
                     stepEndTime:(double) stepEndTime
                syncTimeInterval:(double) syncTimeInterval;

/**
 * @brief 'Tilt Compensate' mag readings against gravity vector.
 * @throws DataNotUploadedException, NoSynchronizationException
 * @return A reference to this object.
 */
- (instancetype) tiltCompensateMag;

/**
 * @brief 'Tilt Compensate' acceleromter readings against gravity vector.
 * @throws DataNotUploadedException, NoSynchronizationException
 * @return A reference to this object.
 */
- (instancetype) tiltCompensateAcc;
@end
