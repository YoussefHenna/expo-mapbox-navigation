// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNRawGnssSatelliteData;

/** Raw GNSS data */
NS_SWIFT_NAME(RawGnssData)
__attribute__((visibility ("default")))
@interface MBNNRawGnssData : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithGdop:(nullable NSNumber *)gdop
                                pdop:(nullable NSNumber *)pdop
                                tdop:(nullable NSNumber *)tdop
                                vdop:(nullable NSNumber *)vdop
                                hdop:(nullable NSNumber *)hdop
                                ndop:(nullable NSNumber *)ndop
                                edop:(nullable NSNumber *)edop
                          satellites:(nonnull NSArray<MBNNRawGnssSatelliteData *> *)satellites
       monotonicTimestampNanoseconds:(int64_t)monotonicTimestampNanoseconds;

/**
 * Dilution of Precision (DOP) - an indicator of satellite geometry for a unique constellation of satellites used to determine a position.
 * Positions tagged with a higher DOP value generally constitute poorer measurement results than those tagged with lower DOP.
 *
 * Geometric dilution of precision
 */
@property (nonatomic, readonly, nullable) NSNumber *gdop;

/** Position dilution of precision */
@property (nonatomic, readonly, nullable) NSNumber *pdop;

/** Time dilution of precision */
@property (nonatomic, readonly, nullable) NSNumber *tdop;

/** Vertical dilution of precision */
@property (nonatomic, readonly, nullable) NSNumber *vdop;

/** Horizontal dilution of precision */
@property (nonatomic, readonly, nullable) NSNumber *hdop;

/** Northing dilution of precision */
@property (nonatomic, readonly, nullable) NSNumber *ndop;

/** Easting dilution of precision */
@property (nonatomic, readonly, nullable) NSNumber *edop;

/** Raw GNSS satellites data */
@property (nonatomic, readonly, nonnull, copy) NSArray<MBNNRawGnssSatelliteData *> *satellites;

/** Monotonic timestamp in nanoseconds */
@property (nonatomic, readonly) int64_t monotonicTimestampNanoseconds;


- (BOOL)isEqualToRawGnssData:(nonnull MBNNRawGnssData *)other;

@end
