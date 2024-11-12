// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/**
 * Describes a kind of a route response.
 * Defines the origin of a route, not router itself.
 */
// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNRouterOrigin)
{
    /** Route received from Directions API. */
    MBNNRouterOriginOnline,
    /** Route received from the onboard. */
    MBNNRouterOriginOnboard,
    /** Route presented by customer, the origin is unknown, but it's still built with Directions API or local on-board router */
    MBNNRouterOriginCustom,
    /** Customer's route, that obtained from third-party routing engine. */
    MBNNRouterOriginCustomExternal
} NS_SWIFT_NAME(RouterOrigin);

NSString* MBNNRouterOriginToString(MBNNRouterOrigin router_origin);
