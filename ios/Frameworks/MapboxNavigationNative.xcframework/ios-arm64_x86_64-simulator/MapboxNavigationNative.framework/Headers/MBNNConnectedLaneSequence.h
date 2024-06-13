// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(ConnectedLaneSequence)
__attribute__((visibility ("default")))
@interface MBNNConnectedLaneSequence : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithLaneIds:(nonnull NSArray<NSNumber *> *)laneIds
                            isDivergent:(BOOL)isDivergent
                                 length:(double)length
             isOnRouteLaneGuidanceStart:(BOOL)isOnRouteLaneGuidanceStart
            isOnRouteLaneGuidanceFinish:(BOOL)isOnRouteLaneGuidanceFinish
                incomingSequenceIndexes:(nonnull NSArray<NSNumber *> *)incomingSequenceIndexes
                outboundSequenceIndexes:(nonnull NSArray<NSNumber *> *)outboundSequenceIndexes
         incomingMergingSequenceIndexes:(nonnull NSArray<NSNumber *> *)incomingMergingSequenceIndexes
               mergingIntoSequenceIndex:(nullable NSNumber *)mergingIntoSequenceIndex;

/**
 * Lane ids belonging to the sequence.
 * Lane ids are guaranteed to be ordered in the same way as they are located in the graph.
 * E.g. if lanes located in graph like this: `1 -> 2 -> 3`, then `laneIds` would be [1, 2, 3].
 */
@property (nonatomic, readonly, nonnull, copy) NSArray<NSNumber *> *laneIds;

/**
 * If true - all lanes in the sequence are divergent.
 * If false - all lanes in the sequence are NOT divergent.
 * Note, it's guaranteed that ALL lanes in the sequence are either divergent or not.
 */
@property (nonatomic, readonly) BOOL isDivergent;

/** Lane sequence length, calculated just as a summ of all lane lengths */
@property (nonatomic, readonly) double length;

/**
 * If true - that means this sequence starts from start of current `RouteLaneGuidance`.
 * In other words, if current `RouteLaneGuidance` starts from graph edge A ("graph edge" = "lane group"),
 * which contains lanes [X, Y, Z], then each lane sequence starting from one of lanes X, Y, Z
 * would have this flag set to true.
 */
@property (nonatomic, readonly) BOOL isOnRouteLaneGuidanceStart;

/**
 * If true - that means this sequence finishes on finish of current `RouteLaneGuidance`.
 * In other words, if current `RouteLaneGuidance` finishes on graph edge A ("graph edge" = "lane group"),
 * which contains lanes [X, Y, Z], then each lane sequence finishing on one of lanes X, Y, Z
 * would have this flag set to true.
 */
@property (nonatomic, readonly) BOOL isOnRouteLaneGuidanceFinish;

/** Incoming lane sequences, i.e. sequences starting on the current sequence's finish */
@property (nonatomic, readonly, nonnull, copy) NSArray<NSNumber *> *incomingSequenceIndexes;

/** Outbound lane sequences, i.e. sequences finishing on the current sequence's start */
@property (nonatomic, readonly, nonnull, copy) NSArray<NSNumber *> *outboundSequenceIndexes;

/** Sequences which merge into the current sequence */
@property (nonatomic, readonly, nonnull, copy) NSArray<NSNumber *> *incomingMergingSequenceIndexes;

/** Optional sequence which the current sequence merges into */
@property (nonatomic, readonly, nullable) NSNumber *mergingIntoSequenceIndex;


- (BOOL)isEqualToConnectedLaneSequence:(nonnull MBNNConnectedLaneSequence *)other;

@end
