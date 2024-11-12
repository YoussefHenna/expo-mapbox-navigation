// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(SpeedData)
__attribute__((visibility ("default")))
@interface MBNNSpeedData : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithSpeed:(float)speed
        monotonicTimestampNanoseconds:(int64_t)monotonicTimestampNanoseconds;

/** Speed in [m/s]. Direction is given by the sign of this value. */
@property (nonatomic, readonly) float speed;

/** monotonic timestamp in nanoseconds */
@property (nonatomic, readonly) int64_t monotonicTimestampNanoseconds;


- (BOOL)isEqualToSpeedData:(nonnull MBNNSpeedData *)other;

@end
