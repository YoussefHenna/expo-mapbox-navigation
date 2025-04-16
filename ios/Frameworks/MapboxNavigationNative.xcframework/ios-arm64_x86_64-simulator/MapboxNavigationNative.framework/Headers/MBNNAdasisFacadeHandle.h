// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <MapboxNavigationNative/MBNNADASISv2MessageCallback.h>

@class MBNNAdasisConfig;

NS_SWIFT_NAME(AdasisFacadeHandle)
__attribute__((visibility ("default")))
@interface MBNNAdasisFacadeHandle : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Caution: Beta feature for ADAS / ADASIS SDK. Method interface may change soon.
 *
 * Sets a callback for ADASIS messages
 */
- (void)setAdasisMessageCallbackForCallback:(nonnull MBNNADASISv2MessageCallback)callback
                               adasisConfig:(nonnull MBNNAdasisConfig *)adasisConfig;
/** Resets a callback for ADASIS messages */
- (void)resetAdasisMessageCallback;
/** Trigger reset of EHP for the case when external reconstructor needs it. */
- (void)triggerResetOfEhProvider;

@end
