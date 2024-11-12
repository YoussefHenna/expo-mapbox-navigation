// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/** Describes a type of a Mapbox Api response. */
// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNMapboxAPI)
{
    /** Response received from Directions API. */
    MBNNMapboxAPIDirections,
    /** Response received from the MapMatching API. */
    MBNNMapboxAPIMapMatching
} NS_SWIFT_NAME(MapboxAPI);

NSString* MBNNMapboxAPIToString(MBNNMapboxAPI mapbox_api);
