// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNRouteAlternativesOptions;
@protocol MBNNRouteAlternativesObserver;

NS_SWIFT_NAME(RouteAlternativesControllerInterface)
@protocol MBNNRouteAlternativesControllerInterface
/** Set RouteAlternativesOptions (can be changed in run-time). */
- (void)setRouteAlternativesOptionsForOptions:(nonnull MBNNRouteAlternativesOptions *)options;
/**
 * Invoke when any component of EV data is changed so that it can be used in alternatives requests.
 * You should pass all components of EV data via [data], all the previous values will NOT be cached.
 * For example:
 * {{'engine': 'electric'}, {'ev_initial_charge': '5000'}, {'energy_consumption_curve': '0,300;20,160;80,140;120,180'}}
 */
- (void)onEvDataUpdatedForData:(nonnull NSDictionary<NSString *, NSString *> *)data;
/** Add observer. Requests will not be sent if no one observer present. */
- (void)addObserverForObserver:(nonnull id<MBNNRouteAlternativesObserver>)observer;
/** Remove observer. Requests will not be sent if no one observer present. */
- (void)removeObserverForObserver:(nonnull id<MBNNRouteAlternativesObserver>)observer;
/** Remove all observers. Requests will not be sent if no one observer present. */
- (void)removeAllObservers;
@end
