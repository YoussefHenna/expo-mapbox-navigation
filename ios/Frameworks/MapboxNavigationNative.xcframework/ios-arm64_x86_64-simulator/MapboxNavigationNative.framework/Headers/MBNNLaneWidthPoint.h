// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(LaneWidthPoint)
__attribute__((visibility ("default")))
@interface MBNNLaneWidthPoint : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithPercentAlong:(float)percentAlong
                                   leftWidth:(float)leftWidth
                                  rightWidth:(float)rightWidth;

/**
 * Percent along lane geometry.
 * 0 means start of the geometry, 1 - end of the geometry
 */
@property (nonatomic, readonly) float percentAlong;

/** Left width (i.e. distance from lane center to left polygon border) in meters */
@property (nonatomic, readonly) float leftWidth;

/** Right width (i.e. distance from lane center to right polygon border) in meters */
@property (nonatomic, readonly) float rightWidth;


- (BOOL)isEqualToLaneWidthPoint:(nonnull MBNNLaneWidthPoint *)other;

@end
