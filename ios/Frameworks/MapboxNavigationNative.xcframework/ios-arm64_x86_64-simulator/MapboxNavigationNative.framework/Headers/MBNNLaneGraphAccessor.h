// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
@class MBXCoordinate2D;

@class MBNNLaneData;
@class MBNNLaneGroupData;
@class MBNNLaneWidthPoint;

NS_SWIFT_NAME(LaneGraphAccessor)
@protocol MBNNLaneGraphAccessor
/**
 * Gets all data related to the road (aka lane group), except road geometry.
 * Empty if laneGroupId is invalid, or tile with the road is not loaded.
 */
- (nullable MBNNLaneGroupData *)getLaneGroupDataForLaneGroupId:(uint64_t)laneGroupId;
/**
 * Gets lane group geometry (aka road center line).
 * Empty if laneGroupId is invalid, or tile with the lane is not loaded.
 */
- (nullable NSArray<MBXCoordinate2D *> *)getLaneGroupGeometryForLaneGroupId:(uint64_t)laneGroupId;
/**
 * Gets lane group's smoothed geometry.
 * Smoothed geometry depends on group sequence we need to smooth, so this method
 * requires `routeId` to identify the sequence.
 * Result is empty if provided route id is unknown, or if it doesn't contain provided `laneGroupId`.
 */
- (nullable NSArray<MBXCoordinate2D *> *)getSmoothedLaneGroupGeometryForLaneGroupId:(uint64_t)laneGroupId
                                                                            routeId:(nonnull NSString *)routeId;
/**
 * Gets all data related to the lane, except lane geometry.
 * Empty if laneId is invalid, or tile with the lane is not loaded.
 */
- (nullable MBNNLaneData *)getLaneDataForLaneId:(uint64_t)laneId;
/**
 * Gets lane geometry.
 * Empty if laneId is invalid, or tile with the lane is not loaded.
 */
- (nullable NSArray<MBXCoordinate2D *> *)getLaneGeometryForLaneId:(uint64_t)laneId;
/**
 * Gets lane width points, sorted by percent along the lane geometry.
 * If not empty - it's guaranteed the first point would have `percentAlong = 0.0`,
 * and the last point would have `percentAlong = 1.0`.
 */
- (nullable NSArray<MBNNLaneWidthPoint *> *)getLaneWidthPointsForLaneId:(uint64_t)laneId;
@end
