// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNCorrectedLocationData;
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

- (nonnull instancetype)initWithLaneGroupMatching:(nullable MBNNLaneGroupMatching *)laneGroupMatching
                                     laneMatching:(nullable MBNNLaneMatching *)laneMatching
                                       isTeleport:(BOOL)isTeleport
                                         isOnRoad:(BOOL)isOnRoad
                               offRoadProbability:(float)offRoadProbability
                                routeLaneGuidance:(nullable MBNNRouteLaneGuidance *)routeLaneGuidance
                                         inTunnel:(BOOL)inTunnel
                            correctedLocationData:(nullable MBNNCorrectedLocationData *)correctedLocationData;

/**
 * Road-level matching result.
 * Could be empty if we are unsure on which lane group we are or if the off-road was detected.
 */
@property (nonatomic, readonly, nullable) MBNNLaneGroupMatching *laneGroupMatching;

/**
 * Lane-level matching result.
 * Could be empty if we are unsure on which lane we are or if the off-road was detected.
 * Also could be empty if HD lite mode is forced in the configuration.
 */
@property (nonatomic, readonly, nullable) MBNNLaneMatching *laneMatching;

/**
 * Boolean flag defining if teleport has just occurred,
 * i.e. snapped location has just jumped onto another road (aka lane group)
 */
@property (nonatomic, readonly) BOOL isTeleport;

/**
 * Indicates if we're currently on road (as opposite to off-road).
 * Note that even with laneGroupMatching and laneMatching present, we might
 * still consider the current vehicle's position as off-road due to various factors.
 */
@property (nonatomic, readonly) BOOL isOnRoad;

/**
 * Probability of the vehicle being off-road:
 * 1.0 - vehicle is definitely off-road, 0.0 - vehicle is definitely on-road.
 */
@property (nonatomic, readonly) float offRoadProbability;

/** Route lane guidance */
@property (nonatomic, readonly, nullable) MBNNRouteLaneGuidance *routeLaneGuidance;

/** Is current location belongs to tunnel */
@property (nonatomic, readonly) BOOL inTunnel;

/** Corrected GPS location data. */
@property (nonatomic, readonly, nullable) MBNNCorrectedLocationData *correctedLocationData;


- (BOOL)isEqualToHdMatchingResult:(nonnull MBNNHdMatchingResult *)other;

@end
