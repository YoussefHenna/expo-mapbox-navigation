// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNRerouteStrategyForMatchRoute)
{
    /**
     * Do nothing and skip reroute, show the initial map-matched api route
     * and allow user to return to it
     */
    MBNNRerouteStrategyForMatchRouteRerouteDisabled,
    /**
     * In case of off-route create a directions-api route from the current position
     * to the final destination of the map-matched api route
     */
    MBNNRerouteStrategyForMatchRouteNavigateToFinalDestination
} NS_SWIFT_NAME(RerouteStrategyForMatchRoute);

NSString* MBNNRerouteStrategyForMatchRouteToString(MBNNRerouteStrategyForMatchRoute reroute_strategy_for_match_route);
