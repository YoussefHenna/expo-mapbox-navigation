// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <MapboxNavigationNative/MBNNDRSensorFusionState.h>

/** Dead-reckoning sensor fusion status. */
NS_SWIFT_NAME(DRSensorFusionStatus)
__attribute__((visibility ("default")))
@interface MBNNDRSensorFusionStatus : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithState:(MBNNDRSensorFusionState)state
                 progressInitDistance:(uint8_t)progressInitDistance
            progressCorrectionBuckets:(uint8_t)progressCorrectionBuckets;

/** State of internal sensor fuser. */
@property (nonatomic, readonly) MBNNDRSensorFusionState state;

/** Calculated progress of initialization distance (percentage, range *0..100*) */
@property (nonatomic, readonly) uint8_t progressInitDistance;

/** Calculated progress of correction buckets (percentage, range *0..100*) */
@property (nonatomic, readonly) uint8_t progressCorrectionBuckets;


- (BOOL)isEqualToDRSensorFusionStatus:(nonnull MBNNDRSensorFusionStatus *)other;

@end
