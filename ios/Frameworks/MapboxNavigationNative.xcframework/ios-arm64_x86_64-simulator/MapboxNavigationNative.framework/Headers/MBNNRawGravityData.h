// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNPoint3d;

/** The gravity component of acceleration applied to the device */
NS_SWIFT_NAME(RawGravityData)
__attribute__((visibility ("default")))
@interface MBNNRawGravityData : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithGravity:(nonnull MBNNPoint3d *)gravity
          monotonicTimestampNanoseconds:(int64_t)monotonicTimestampNanoseconds;

/** A three dimensional vector indicating the direction and magnitude of gravity (in m/s^2) */
@property (nonatomic, readonly, nonnull) MBNNPoint3d *gravity;

/** Monotonic timestamp in nanoseconds */
@property (nonatomic, readonly) int64_t monotonicTimestampNanoseconds;


- (BOOL)isEqualToRawGravityData:(nonnull MBNNRawGravityData *)other;

@end
