// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(RoadObjectMatcherConfig)
__attribute__((visibility ("default")))
@interface MBNNRoadObjectMatcherConfig : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithOpenlrMaxDistanceToNode:(nullable NSNumber *)openlrMaxDistanceToNode;

/**
 * Overrides the default max distance(50m) from the LRP to the graph node.
 * Setting max distance causes changes in the amount of fetched graph candidates around the LRP.
 * If the distance is too low, it prevents the algorithm from finding the nearest graph candidates,
 * which could result in failed match operation.
 * If the distance is too high, the performance could drop due to the amount of processing.
 * The best solution is to stick to the original value.
 * The value is allowed to be in range [8;70] meters.
 */
@property (nonatomic, readonly, nullable) NSNumber *openlrMaxDistanceToNode;


@end
