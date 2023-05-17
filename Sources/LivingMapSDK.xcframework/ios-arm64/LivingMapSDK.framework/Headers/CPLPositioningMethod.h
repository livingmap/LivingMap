//
//  CPLPositioningMethod.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

typedef enum {
    PM_UNDEFINED,
    PM_PARTICLE_FILTER,
    PM_GPS,
    PM_BEACON,
    PM_PDR,
    PM_CORE_LOCATION,
    PM_WIFI,
    PM_FUSED_LOCATION,
    PM_LANDMARK,
    PM_CHECKPOINT_PDR,
    PM_GYRO_PDR
} CPLPositioningMethod;
