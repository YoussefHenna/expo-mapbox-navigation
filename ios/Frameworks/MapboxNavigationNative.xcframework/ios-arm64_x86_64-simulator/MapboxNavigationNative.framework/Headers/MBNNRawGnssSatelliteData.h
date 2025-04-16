// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <MapboxNavigationNative/MBNNConstellationType.h>

/** Raw GNSS satellite data */
NS_SWIFT_NAME(RawGnssSatelliteData)
__attribute__((visibility ("default")))
@interface MBNNRawGnssSatelliteData : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithSvid:(int32_t)svid
                  carrierFrequencyHz:(nullable NSNumber *)carrierFrequencyHz
                     basebandCn0DbHz:(nullable NSNumber *)basebandCn0DbHz
                             cn0DbHz:(nullable NSNumber *)cn0DbHz
                           usedInFix:(nullable NSNumber *)usedInFix
                    hasEphemerisData:(nullable NSNumber *)hasEphemerisData
                      hasAlmanacData:(nullable NSNumber *)hasAlmanacData
                   constellationType:(nullable NSNumber *)constellationType
                      azimuthDegrees:(nullable NSNumber *)azimuthDegrees
                    elevationDegrees:(nullable NSNumber *)elevationDegrees
                            residual:(nullable NSNumber *)residual;

/** The satellite id */
@property (nonatomic, readonly) int32_t svid;

/** The carrier frequency of the tracked signal */
@property (nonatomic, readonly, nullable) NSNumber *carrierFrequencyHz;

/** The baseband carrier-to-noise density in dB-Hz */
@property (nonatomic, readonly, nullable) NSNumber *basebandCn0DbHz;

/** The carrier-to-noise density in dB-Hz */
@property (nonatomic, readonly, nullable) NSNumber *cn0DbHz;

/** Whether the specific satellite has been seen and used in the calculation of the location (satellite in use) */
@property (nonatomic, readonly, nullable) NSNumber *usedInFix;

/** Indicates whether ephemeris data is available */
@property (nonatomic, readonly, nullable) NSNumber *hasEphemerisData;

/** Indicates whether almanac data is available */
@property (nonatomic, readonly, nullable) NSNumber *hasAlmanacData;

/** Constellation type */
@property (nonatomic, readonly, nullable) NSNumber *constellationType;

/** The azimuth of the satellite in degrees */
@property (nonatomic, readonly, nullable) NSNumber *azimuthDegrees;

/** The elevation of the satellite in degrees */
@property (nonatomic, readonly, nullable) NSNumber *elevationDegrees;

/** A quality indicator for a GPS position that is determined during the differential correction process. High residuals are not desirable. */
@property (nonatomic, readonly, nullable) NSNumber *residual;


- (BOOL)isEqualToRawGnssSatelliteData:(nonnull MBNNRawGnssSatelliteData *)other;

@end
