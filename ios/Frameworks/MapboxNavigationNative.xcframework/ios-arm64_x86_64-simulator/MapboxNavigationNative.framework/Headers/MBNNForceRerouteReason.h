// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNForceRerouteReason)
{
    /** User deviates from the current route */
    MBNNForceRerouteReasonDeviation,
    /** Closure on the current route detected */
    MBNNForceRerouteReasonClosure,
    /** Charge unexpectedly low, need to recharge on the way */
    MBNNForceRerouteReasonInsufficientCharge,
    /** User changes routing settings, route should be re-requested */
    MBNNForceRerouteReasonParametersChange,
    /**  Server cannot determine route id for refreshes and alternatives */
    MBNNForceRerouteReasonRouteInvalidated,
    /**  User calls reroute by their internal unknown for us reason */
    MBNNForceRerouteReasonUserTriggered
} NS_SWIFT_NAME(ForceRerouteReason);
