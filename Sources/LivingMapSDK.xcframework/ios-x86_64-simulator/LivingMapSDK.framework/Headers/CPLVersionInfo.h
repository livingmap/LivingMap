//
//  CPLVersionInfo.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @class CPLVersionInfo
 * @brief The CPLVersionInfo class
 * @discussion A namespace exposing version information of the Common Positioning Library.
 */
@interface CPLVersionInfo: NSObject

/**
 * Only includes the branch name if not built off master. The format of the version is as follows CPL-MAJOR_VERSION.MINOR_VERSION.PATCH_NUMBER-COMMIT_COUNT-COMMIT_HASH[+BRANCH_NAME] e.g. CPL-1.2.3-22-aabbccdd+my-branch
 * @brief Get the build version of the library as an extended string containing full information about the build.
 * @return The build version
 */
+ (NSString*) buildVersion;

/**
 * Version is returned with the following format; MAJOR_VERSION.MINOR_VERSION.PATCH_NUMBER, e.g. 1.2.3
 * @brief Get the base version of the library.
 * @return The base version
 */
+ (NSString*) baseVersion;

@end
