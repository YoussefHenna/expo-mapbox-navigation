// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNFixDirectedCoordinate;
@class MBNNLaneGroupPosition;

NS_SWIFT_NAME(LaneGroupMatching)
__attribute__((visibility ("default")))
@interface MBNNLaneGroupMatching : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithLaneGroupPosition:(nonnull MBNNLaneGroupPosition *)laneGroupPosition
                                snappedCoordinate:(nonnull MBNNFixDirectedCoordinate *)snappedCoordinate
                               smoothedCoordinate:(nullable MBNNFixDirectedCoordinate *)smoothedCoordinate;

/** Snapped lane group position */
@property (nonatomic, readonly, nonnull) MBNNLaneGroupPosition *laneGroupPosition;

/** Coordinate of the vehicle snapped on the map-matched road (aka lane group) */
@property (nonatomic, readonly, nonnull) MBNNFixDirectedCoordinate *snappedCoordinate;

/**
 * Coordinate of the vehicle snapped on the smoothed road (aka lane group).
 * Not empty only in active guidance (i.e. only when there is a current route)
 */
@property (nonatomic, readonly, nullable) MBNNFixDirectedCoordinate *smoothedCoordinate;


- (BOOL)isEqualToLaneGroupMatching:(nonnull MBNNLaneGroupMatching *)other;

@end
