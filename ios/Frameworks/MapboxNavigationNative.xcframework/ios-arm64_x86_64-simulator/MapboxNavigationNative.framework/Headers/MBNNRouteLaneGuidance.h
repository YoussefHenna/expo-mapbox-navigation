// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNConnectedLaneSequence;
@class MBNNRouteLane;

NS_SWIFT_NAME(RouteLaneGuidance)
__attribute__((visibility ("default")))
@interface MBNNRouteLaneGuidance : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithRouteLaneGroups:(nonnull NSArray<NSNumber *> *)routeLaneGroups
                                     routeLanes:(nonnull NSArray<MBNNRouteLane *> *)routeLanes
                         connectedLaneSequences:(nonnull NSArray<MBNNConnectedLaneSequence *> *)connectedLaneSequences;

/**
 * Lane group ids matched to the route.
 * All lanes in routeLanes will belong to one of the groups in this list. The order of lane groups
 * ids follows the route guidance direction. In other words, it starts from some position before
 * ego and goes onward along the route.
 */
@property (nonatomic, readonly, nonnull, copy) NSArray<NSNumber *> *routeLaneGroups;

/** Lanes matched on the route */
@property (nonatomic, readonly, nonnull, copy) NSArray<MBNNRouteLane *> *routeLanes;

/**
 * All route lanes are split into connected lane sequences.
 * Each lane sequence has its own properties, describing not a singular lane, but the whole sequence.
 * Those sequence properties should be used to decide if we should show this lanes to the user.
 * Example: divergent lane sequence with small length could be hide to improve UX.
 */
@property (nonatomic, readonly, nonnull, copy) NSArray<MBNNConnectedLaneSequence *> *connectedLaneSequences;


- (BOOL)isEqualToRouteLaneGuidance:(nonnull MBNNRouteLaneGuidance *)other;

@end
