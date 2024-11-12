// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(OrientationData)
__attribute__((visibility ("default")))
@interface MBNNOrientationData : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithPitch:(nullable NSNumber *)pitch
                                  yaw:(nullable NSNumber *)yaw
                                 roll:(nullable NSNumber *)roll
        monotonicTimestampNanoseconds:(int64_t)monotonicTimestampNanoseconds;

/** pitch in radians */
@property (nonatomic, readonly, nullable) NSNumber *pitch;

/** yaw in radians */
@property (nonatomic, readonly, nullable) NSNumber *yaw;

/** roll in radians */
@property (nonatomic, readonly, nullable) NSNumber *roll;

/** monotonic timestamp in nanoseconds */
@property (nonatomic, readonly) int64_t monotonicTimestampNanoseconds;


- (BOOL)isEqualToOrientationData:(nonnull MBNNOrientationData *)other;

@end
