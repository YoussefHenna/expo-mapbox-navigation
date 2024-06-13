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

- (nonnull instancetype)initWithOffset:(CLLocationCoordinate2D)offset;

/** Offset in meters relative to ego position. */
@property (nonatomic, readonly) CLLocationCoordinate2D offset;


@end
