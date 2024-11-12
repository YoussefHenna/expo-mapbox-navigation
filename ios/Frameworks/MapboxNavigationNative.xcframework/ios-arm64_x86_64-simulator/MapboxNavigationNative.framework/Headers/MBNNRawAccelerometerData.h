// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNPoint3d;

/** The acceleration applied to the device */
NS_SWIFT_NAME(RawAccelerometerData)
__attribute__((visibility ("default")))
@interface MBNNRawAccelerometerData : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithAcceleration:(nonnull MBNNPoint3d *)acceleration
               monotonicTimestampNanoseconds:(int64_t)monotonicTimestampNanoseconds;

/** Acceleration vector expressed in the device's reference frame (in m/s^2) */
@property (nonatomic, readonly, nonnull) MBNNPoint3d *acceleration;

/** Monotonic timestamp in nanoseconds */
@property (nonatomic, readonly) int64_t monotonicTimestampNanoseconds;


- (BOOL)isEqualToRawAccelerometerData:(nonnull MBNNRawAccelerometerData *)other;

@end
