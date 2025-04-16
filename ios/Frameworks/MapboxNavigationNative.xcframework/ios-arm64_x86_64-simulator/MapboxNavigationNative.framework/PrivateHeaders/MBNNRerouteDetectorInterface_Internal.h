// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <MapboxNavigationNative/MBNNForceRerouteCallback_Internal.h>
#import <MapboxNavigationNative/MBNNForceRerouteReason.h>

NS_SWIFT_NAME(RerouteDetectorInterface)
@protocol MBNNRerouteDetectorInterface
/**  Force reroute with the reason provided. Reroute result is notified to observers. */
- (void)forceRerouteForReason:(MBNNForceRerouteReason)reason;
- (void)forceRerouteForReason:(MBNNForceRerouteReason)reason
                     callback:(nonnull MBNNForceRerouteCallback)callback;
/**
 *  Returns true in between reroute request started and observers or a callback notified. Doead not include
 *  user's reaction to a reroute (expected setRoute(...))
 */
- (BOOL)isReroute;
/** Cancels reroute if in progress, has no effect otherwise */
- (void)cancelReroute;
@end
