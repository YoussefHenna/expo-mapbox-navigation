// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <MapboxNavigationNative/MBNNRerouteCallback_Internal.h>

@protocol MBNNRouteOptionsAdapter;

NS_SWIFT_NAME(RerouteControllerInterface)
@protocol MBNNRerouteControllerInterface
- (void)rerouteForUrl:(nonnull NSString *)url
             callback:(nonnull MBNNRerouteCallback)callback;
- (void)cancel;
/**
 *  Some of route request options can be modified with `routeRequestOptionsAdapter`.
 *  User must keep the request valid after modification, request will fail otherwise.
 */
- (void)setOptionsAdapterForRouteRequestOptionsAdapter:(nullable id<MBNNRouteOptionsAdapter>)routeRequestOptionsAdapter;
@end
