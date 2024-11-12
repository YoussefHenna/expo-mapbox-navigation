// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/** Odometry data */
NS_SWIFT_NAME(OdometryData)
__attribute__((visibility ("default")))
@interface MBNNOdometryData : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithX:(float)x
                                y:(float)y
                                z:(float)z
                         yawAngle:(float)yawAngle
    monotonicTimestampNanoseconds:(int64_t)monotonicTimestampNanoseconds;

/** Position */
@property (nonatomic, readonly) float x;

@property (nonatomic, readonly) float y;
@property (nonatomic, readonly) float z;
/** The bearing of the car in the vehicle’s local coordinate system */
@property (nonatomic, readonly) float yawAngle;

/** Monotonic timestamp in nanoseconds */
@property (nonatomic, readonly) int64_t monotonicTimestampNanoseconds;


- (BOOL)isEqualToOdometryData:(nonnull MBNNOdometryData *)other;

@end
