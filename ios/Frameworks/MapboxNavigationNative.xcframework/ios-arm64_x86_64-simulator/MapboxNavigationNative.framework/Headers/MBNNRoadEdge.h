// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_SWIFT_NAME(RoadEdge)
__attribute__((visibility ("default")))
@interface MBNNRoadEdge : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithOffset:(CLLocationCoordinate2D)offset
                              accuracy:(nullable NSNumber *)accuracy;

/** Offset in meters relative to ego position. */
@property (nonatomic, readonly) CLLocationCoordinate2D offset;

/**
 * Accuracy of the measurement used to produce the road edge. The value must be non-negative.
 * The higher the value, the worse the accuracy is (similar to GPS's horizontal accuracy).
 *
 * For example, given the standard deviation `S` of the camera's road edge detection, one could
 * calculate the accuracy as 1 / S. But since we expect the value to increase with lower accuracy,
 * we could just use `S` as the value itself.
 *   Note: strictly speaking the resulted value would be called "precision", but the term "accuracy"
 *   is more generic, allowing a broader set of inputs.
 */
@property (nonatomic, readonly, nullable) NSNumber *accuracy;


@end
