// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNAdasisFacadeHandle;
@class MBNNCacheHandle;
@class MBNNConfigHandle;
@class MBNNHistoryRecorderHandle;

NS_SWIFT_NAME(AdasisFacadeBuilder)
__attribute__((visibility ("default")))
@interface MBNNAdasisFacadeBuilder : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

+ (nonnull MBNNAdasisFacadeHandle *)buildForConfig:(nonnull MBNNConfigHandle *)config
                                             cache:(nonnull MBNNCacheHandle *)cache
                                   historyRecorder:(nullable MBNNHistoryRecorderHandle *)historyRecorder __attribute((ns_returns_retained));

@end
