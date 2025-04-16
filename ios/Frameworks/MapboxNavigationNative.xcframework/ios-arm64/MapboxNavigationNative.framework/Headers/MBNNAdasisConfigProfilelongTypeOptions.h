// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNAdasisConfigProfilelongTrafficSignOptions;

/**
 * PROFILE LONG message options
 * lonLat - if true, longitude and latitude types will be generated
 * trafficSign - for each of supported straffic signs: if true, the Traffic Sign type will be generated
 */
NS_SWIFT_NAME(AdasisConfigProfilelongTypeOptions)
__attribute__((visibility ("default")))
@interface MBNNAdasisConfigProfilelongTypeOptions : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithTrafficSign:(nonnull MBNNAdasisConfigProfilelongTrafficSignOptions *)trafficSign;

- (nonnull instancetype)initWithLonLat:(BOOL)lonLat
                           trafficSign:(nonnull MBNNAdasisConfigProfilelongTrafficSignOptions *)trafficSign;

@property (nonatomic, readonly) BOOL lonLat;
@property (nonatomic, readonly, nonnull) MBNNAdasisConfigProfilelongTrafficSignOptions *trafficSign;

- (BOOL)isEqualToAdasisConfigProfilelongTypeOptions:(nonnull MBNNAdasisConfigProfilelongTypeOptions *)other;

@end
