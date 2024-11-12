// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNRouteState)
{
    /**
     * We have no route.
     * All route-related fields(`remainingLegDistance`, `remainingLegDuration`, `stepIndex` etc) are INVALID.
     */
    MBNNRouteStateInvalid,
    /**
     * We have initialized route, but haven't started route tracking yet.
     * Progress route-related fields(`remainingLegDistance`, `remainingLegDuration`, `stepIndex` etc) are valid,
     * but if there were no location updates before, navigator uses the route's starting point as the current position.
     */
    MBNNRouteStateInitialized,
    /**
     * We are on the route: all route-related fields are valid
     * All route-related fields(`remainingLegDistance`, `remainingLegDuration`, `stepIndex` etc) are VALID.
     */
    MBNNRouteStateTracking,
    /**
     * We've approached to route end: route will be automatically reset (i.e. next `RouteState` is `invalid`)
     * All route-related fields(`remainingLegDistance`, `remainingLegDuration`, `stepIndex` etc) are VALID.
     */
    MBNNRouteStateComplete,
    /**
     * We've gone of route: route will be automatically reset (i.e. next `RouteState` is `invalid`)
     * All route-related fields(`remainingLegDistance`, `remainingLegDuration`, `stepIndex` etc) are INVALID.
     */
    MBNNRouteStateOffRoute,
    /**
     * We are probably about to go off-route.
     * All route-related fields(`remainingLegDistance`, `remainingLegDuration`, `stepIndex` etc) are VALID.
     */
    MBNNRouteStateUncertain
} NS_SWIFT_NAME(RouteState);

NSString* MBNNRouteStateToString(MBNNRouteState route_state);
