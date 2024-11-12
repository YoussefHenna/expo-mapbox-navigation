// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNLaneGroupMatching;
@class MBNNLaneMatching;
@class MBNNRouteLaneGuidance;

NS_SWIFT_NAME(HdMatchingResult)
__attribute__((visibility ("default")))
@interface MBNNHdMatchingResult : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithLaneGroupMatching:(nonnull MBNNLaneGroupMatching *)laneGroupMatching
                                     laneMatching:(nullable MBNNLaneMatching *)laneMatching
                                       isTeleport:(BOOL)isTeleport
                                routeLaneGuidance:(nullable MBNNRouteLaneGuidance *)routeLaneGuidance;

/** Road-level matching result */
@property (nonatomic, readonly, nonnull) MBNNLaneGroupMatching *laneGroupMatching;

/**
 * Lane-level matching result.
 * May be empty if we are unsure on which lane we are.
 * Also could be empty if HD lite mode is forced in the configuration.
 */
@property (nonatomic, readonly, nullable) MBNNLaneMatching *laneMatching;

/**
 * Boolean flag defining if teleport has just occurred,
 * i.e. snapped location has just jumped onto another road (aka lane group)
 */
@property (nonatomic, readonly) BOOL isTeleport;

/** Route lane guidance */
@property (nonatomic, readonly, nullable) MBNNRouteLaneGuidance *routeLaneGuidance;


- (BOOL)isEqualToHdMatchingResult:(nonnull MBNNHdMatchingResult *)other;

@end
