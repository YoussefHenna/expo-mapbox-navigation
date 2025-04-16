// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNAdasisConfigMessageOptions;
@class MBNNAdasisConfigProfileshortTypeOptions;

/**
 * PROFILE SHORT message options
 * options - common options for PROFILE SHORT message
 * types - options for each type of PROFILE SHORT message
 * minDistanceBetweenCurvatures - if distance between curvature from previous one is less than this value, current curvature will be dropped
 * bandwidthEnabled - Combine 2 profile short message values of the same profile type and path into 1 profile message with value1 filled
 */
NS_SWIFT_NAME(Profileshort)
__attribute__((visibility ("default")))
@interface MBNNProfileshort : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithOptions:(nonnull MBNNAdasisConfigMessageOptions *)options
                                  types:(nonnull MBNNAdasisConfigProfileshortTypeOptions *)types;

- (nonnull instancetype)initWithOptions:(nonnull MBNNAdasisConfigMessageOptions *)options
                                  types:(nonnull MBNNAdasisConfigProfileshortTypeOptions *)types
           minDistanceBetweenCurvatures:(uint16_t)minDistanceBetweenCurvatures
                       bandwidthEnabled:(BOOL)bandwidthEnabled;

@property (nonatomic, readonly, nonnull) MBNNAdasisConfigMessageOptions *options;
@property (nonatomic, readonly, nonnull) MBNNAdasisConfigProfileshortTypeOptions *types;
@property (nonatomic, readonly) uint16_t minDistanceBetweenCurvatures;
@property (nonatomic, readonly) BOOL bandwidthEnabled;

- (BOOL)isEqualToProfileshort:(nonnull MBNNProfileshort *)other;

@end
