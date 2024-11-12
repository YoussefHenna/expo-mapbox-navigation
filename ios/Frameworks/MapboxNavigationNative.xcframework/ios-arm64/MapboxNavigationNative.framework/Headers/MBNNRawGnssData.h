// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNRawGnssLocation;
@class MBNNRawGnssSatelliteData;

/** Raw GNSS data */
NS_SWIFT_NAME(RawGnssData)
__attribute__((visibility ("default")))
@interface MBNNRawGnssData : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithLocation:(nonnull MBNNRawGnssLocation *)location
                              satellites:(nonnull NSArray<MBNNRawGnssSatelliteData *> *)satellites
           monotonicTimestampNanoseconds:(int64_t)monotonicTimestampNanoseconds;

/** Raw GNSS location data */
@property (nonatomic, readonly, nonnull) MBNNRawGnssLocation *location;

/** Raw GNSS satellites data */
@property (nonatomic, readonly, nonnull, copy) NSArray<MBNNRawGnssSatelliteData *> *satellites;

/** Monotonic timestamp in nanoseconds */
@property (nonatomic, readonly) int64_t monotonicTimestampNanoseconds;


- (BOOL)isEqualToRawGnssData:(nonnull MBNNRawGnssData *)other;

@end
