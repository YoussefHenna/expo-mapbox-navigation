// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MapboxNavigationNative/MBNNRoadMarkingColor.h>
#import <MapboxNavigationNative/MBNNRoadMarkingType.h>
@class MBXCoordinate2D;

/** Road marking detected by the camera system */
NS_SWIFT_NAME(RoadMarking)
__attribute__((visibility ("default")))
@interface MBNNRoadMarking : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithType:(MBNNRoadMarkingType)type
                               color:(nullable NSNumber *)color
                              offset:(nullable MBXCoordinate2D *)offset
                         probability:(nullable NSNumber *)probability
                            accuracy:(nullable NSNumber *)accuracy;

/** Type of the road marking */
@property (nonatomic, readonly) MBNNRoadMarkingType type;

/** Color of the road marking */
@property (nonatomic, readonly, nullable) NSNumber *color;

/** Offset of the road marking in meters, relative to the car */
@property (nonatomic, readonly, nullable) MBXCoordinate2D *offset;

/** Detection probability in [0.0, 1.0] range */
@property (nonatomic, readonly, nullable) NSNumber *probability;

/**
 * Accuracy of the measurement used to produce the road marking. The value must be non-negative.
 * The higher the value, the worse the accuracy is (similar to GPS's horizontal accuracy).
 *
 * For example, given the standard deviation `S` of the camera's road marking detection, one could
 * calculate the accuracy as 1 / S. But since we expect the value to increase with lower accuracy,
 * we could just use `S` as the value itself.
 *   Note: strictly speaking the resulted value would be called "precision", but the term "accuracy"
 *   is more generic, allowing a broader set of inputs.
 */
@property (nonatomic, readonly, nullable) NSNumber *accuracy;


@end
