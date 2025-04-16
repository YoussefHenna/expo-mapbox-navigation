// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/** Dead-reckoning sensor fuser state */
// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNDRSensorFusionState)
{
    MBNNDRSensorFusionStateDisabled,
    MBNNDRSensorFusionStateColdStart,
    MBNNDRSensorFusionStateInitialization,
    MBNNDRSensorFusionStateNormalOperation,
    MBNNDRSensorFusionStateFailure
} NS_SWIFT_NAME(DRSensorFusionState);

NSString* MBNNDRSensorFusionStateToString(MBNNDRSensorFusionState drsensor_fusion_state);
