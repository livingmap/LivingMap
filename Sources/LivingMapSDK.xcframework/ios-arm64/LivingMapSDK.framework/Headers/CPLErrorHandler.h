//
//  CPLErrorHandler.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NSString * CplException NS_STRING_ENUM;
static CplException const _Nonnull CplExceptionInitializationException = @"InitializationException";
static CplException const _Nonnull CplExceptionGridFileException = @"GridFileException";
static CplException const _Nonnull CplExceptionNoGridFoundException = @"NoGridFoundException";
static CplException const _Nonnull CplExceptionDataAlreadyUploadedException = @"DataAlreadyUploadedException";
static CplException const _Nonnull CplExceptionDataNotUploadedException = @"DataNotUploadedException";
static CplException const _Nonnull CplExceptionPositioningException = @"PositioningException";
static CplException const _Nonnull CplExceptionNoSynchronizationException = @"NoSynchronizationException";
static CplException const _Nonnull CplExceptionNoHeadingEstimatorException = @"NoHeadingEstimatorException";
static CplException const _Nonnull CplExceptionHeadingEstimationException = @"HeadingEstimationException";
static CplException const _Nonnull CplExceptionNoFloorEstimatorException = @"NoFloorEstimatorException";
static CplException const _Nonnull CplExceptionFloorEstimatorException = @"FloorEstimatorException";
static CplException const _Nonnull CplExceptionNoStepLengthEstimatorException = @"NoStepLengthEstimatorException";
static CplException const _Nonnull CplExceptionStepLengthEstimatorException = @"StepLengthEstimatorException";
static CplException const _Nonnull CplExceptionNonRecoverableException = @"NonRecoverableException";

/**
 * Implemented to catch thrown errors from the C++ based Common Positioning Library.
 * @brief Checks if the call to the Objective-C++ code block resulted in an exception.
 * @param tryBlock: block or throwable code.
 * @return Nullable NSException holding the information of the thrown exception.
*/
NS_INLINE NSException * _Nullable tryBlock(void(^_Nonnull tryBlock)(void)) {
    @autoreleasepool {
        @try {
            @autoreleasepool {
                tryBlock();
            }
        }
        @catch (NSException *exception) {
            return exception;
        }
        @finally {
            // TODO: add release references. https://livingmap.atlassian.net/browse/PPS-963
        }
    }
    return nil;
}
