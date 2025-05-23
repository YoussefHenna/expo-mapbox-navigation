// This file is generated and will be overwritten automatically.

#import <MapboxNavigationNative/MBNNNavigator.h>
#import <MapboxNavigationNative/MBNNRefreshRouteCallback_Internal.h>
#import <MapboxNavigationNative/MBNNSetAlternativeRoutesCallback_Internal.h>
#import <MapboxNavigationNative/MBNNSetRouteCallback_Internal.h>

@interface MBNNNavigator ()
- (void)setRoutesForParams:(nullable MBNNSetRoutesParams *)params
                    reason:(MBNNSetRoutesReason)reason
                  callback:(nonnull MBNNSetRouteCallback)callback;
- (void)setRoutesDataForParams:(nullable MBNNSetRoutesDataParams *)params
                        reason:(MBNNSetRoutesReason)reason
                      callback:(nonnull MBNNSetRouteCallback)callback;
- (void)setAlternativeRoutesForRoutes:(nonnull NSArray<id<MBNNRouteInterface>> *)routes
                             callback:(nonnull MBNNSetAlternativeRoutesCallback)callback;
- (void)refreshRouteForRouteRefreshResponse:(nonnull NSString *)routeRefreshResponse
                                   callback:(nonnull MBNNRefreshRouteCallback)callback __attribute__((deprecated));
- (void)refreshRouteForRouteRefreshResponse:(nonnull NSString *)routeRefreshResponse
                                    routeId:(nonnull NSString *)routeId
                                   callback:(nonnull MBNNRefreshRouteCallback)callback __attribute__((deprecated));
- (void)refreshRouteForRouteRefreshResponse:(nonnull NSString *)routeRefreshResponse
                                    routeId:(nonnull NSString *)routeId
                              geometryIndex:(uint32_t)geometryIndex
                                   callback:(nonnull MBNNRefreshRouteCallback)callback __attribute__((deprecated));
- (void)setRerouteControllerForController:(nonnull id<MBNNRerouteControllerInterface>)controller __attribute__((deprecated));
- (nullable id<MBNNRerouteControllerInterface>)getRerouteController __attribute((ns_returns_retained));
- (nullable id<MBNNRerouteDetectorInterface>)getRerouteDetector __attribute((ns_returns_retained));
- (nonnull id<MBNNTelemetry>)getTelemetryForEventsMetadataProvider:(nonnull id<MBNNEventsMetadataInterface>)eventsMetadataProvider __attribute((ns_returns_retained));
- (nonnull id<MBNNRouterInterface>)getRouter __attribute((ns_returns_retained));
@end
