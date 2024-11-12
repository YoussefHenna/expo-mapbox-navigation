// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(LaneGroupPosition)
__attribute__((visibility ("default")))
@interface MBNNLaneGroupPosition : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithLaneGroupId:(uint64_t)laneGroupId
                               percentAlong:(double)percentAlong;

/** Road (aka lane group) id in HD graph */
@property (nonatomic, readonly) uint64_t laneGroupId;

/**
 * Percent along the lane geometry [0-1].
 * 0 means the first geometry point, 1 means the last geometry point.
 */
@property (nonatomic, readonly) double percentAlong;


- (BOOL)isEqualToLaneGroupPosition:(nonnull MBNNLaneGroupPosition *)other;

@end
