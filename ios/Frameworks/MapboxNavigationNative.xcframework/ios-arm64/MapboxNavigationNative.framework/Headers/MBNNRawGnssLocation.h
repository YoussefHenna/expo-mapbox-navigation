// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/** Raw GNSS location data */
NS_SWIFT_NAME(RawGnssLocation)
__attribute__((visibility ("default")))
@interface MBNNRawGnssLocation : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithAltitude:(float)altitude
                                 bearing:(float)bearing
                                   speed:(float)speed
                                latitude:(float)latitude
                               longitude:(float)longitude
                         bearingAccuracy:(float)bearingAccuracy
                           speedAccuracy:(float)speedAccuracy
                      horizontalAccuracy:(float)horizontalAccuracy
                        verticalAccuracy:(float)verticalAccuracy;

/** Altitude */
@property (nonatomic, readonly) float altitude;

/** Bearing (degrees) */
@property (nonatomic, readonly) float bearing;

/** Speed (meters per second) */
@property (nonatomic, readonly) float speed;

/** Location coordinates */
@property (nonatomic, readonly) float latitude;

@property (nonatomic, readonly) float longitude;
/** Accuracy */
@property (nonatomic, readonly) float bearingAccuracy;

@property (nonatomic, readonly) float speedAccuracy;
@property (nonatomic, readonly) float horizontalAccuracy;
@property (nonatomic, readonly) float verticalAccuracy;

- (BOOL)isEqualToRawGnssLocation:(nonnull MBNNRawGnssLocation *)other;

@end
