// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNRouteAlternative;
@protocol MBNNRouteInterface;

NS_SWIFT_NAME(SetRoutesResult)
__attribute__((visibility ("default")))
@interface MBNNSetRoutesResult : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithPrimaryRoute:(nullable id<MBNNRouteInterface>)primaryRoute
                                alternatives:(nonnull NSArray<MBNNRouteAlternative *> *)alternatives;

/** Primary route set to navigator. */
@property (nonatomic, readonly, nullable) id<MBNNRouteInterface> primaryRoute;

/**
 * Additional information about alternative routes relative to the primary route.
 * Routes in the array will be in the same order as in the `SetRoutesParams.alternativeRoutes`.
 */
@property (nonatomic, readonly, nonnull, copy) NSArray<MBNNRouteAlternative *> *alternatives;


@end
