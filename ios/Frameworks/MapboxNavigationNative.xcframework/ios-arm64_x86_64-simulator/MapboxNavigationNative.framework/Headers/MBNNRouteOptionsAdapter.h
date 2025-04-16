// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/**  Provides a class for modification of route options, e.g. for reroutes */
NS_SWIFT_NAME(RouteOptionsAdapter)
@protocol MBNNRouteOptionsAdapter
/**
 *  @param `url` is the initial request URL.
 *  Note, part of the URL before '?' cannot be modified and must be the same as in the initial url.
 *  Other parameters of the request that cannot be modified are `sku` (actually not passed in the request
 *  and added later), `access_token`, `context`, `reason`, `routes_history`, and other parameters that
 *  belong to the waypoints, like `waypoints`, `bearings`, etc.
 *  Changing of the locked parameters will be ignored and the original values are reset in the resulting request.
 *
 *  @returns URL with the modified route request parameters
 *
 *  User is responsible for making the resulting request valid.
 */
- (nonnull NSString *)modifyRouteRequestOptionsForUrl:(nonnull NSString *)url;
@end
