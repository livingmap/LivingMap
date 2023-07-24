//
//  CPLPositioningAction.h
//  LivingMapSDK
//
//  Copyright © 2021 LivingMap. All rights reserved.
//

typedef enum {
    PA_CONTINUE,
    PA_RESET_WITH_CURRENT,
    PA_RESET_WITH_ALTERNATIVE,
    PA_SWITCH_TO_ALTERNATIVE,
    PA_CHECK_LOCATIONS,
    PA_CHECK_OUTSIDE_LOCATIONS,
    PA_SWITCH_OUTSIDE,
    PA_SWITCH_INSIDE,
    PA_SWITCH_PDR,
    PA_INITIALIZATION_INJECT
    
} CPLPositioningAction;
