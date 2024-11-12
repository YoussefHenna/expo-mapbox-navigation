// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <MapboxNavigationNative/MBNNForceRerouteCallback_Internal.h>
#import <MapboxNavigationNative/MBNNForceRerouteReason.h>

NS_SWIFT_NAME(RerouteDetectorInterface)
@protocol MBNNRerouteDetectorInterface
- (void)forceRerouteForReason:(MBNNForceRerouteReason)reason;
- (void)forceRerouteForReason:(MBNNForceRerouteReason)reason
                     callback:(nonnull MBNNForceRerouteCallback)callback;
- (BOOL)isReroute;
@end
