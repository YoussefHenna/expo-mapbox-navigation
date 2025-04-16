// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNCurveElement;

/** State of EV, like state of change, consumption, etc. */
NS_SWIFT_NAME(EvStateData)
__attribute__((visibility ("default")))
@interface MBNNEvStateData : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithEnergyConsumptionCurve:(nonnull NSArray<MBNNCurveElement *> *)energyConsumptionCurve
                                  auxiliaryConsumption:(nullable NSNumber *)auxiliaryConsumption
                                 evPreConditioningTime:(nullable NSNumber *)evPreConditioningTime;

- (nonnull instancetype)initWithEvInitialCharge:(uint32_t)evInitialCharge
                         energyConsumptionCurve:(nonnull NSArray<MBNNCurveElement *> *)energyConsumptionCurve
                           auxiliaryConsumption:(nullable NSNumber *)auxiliaryConsumption
                          evPreConditioningTime:(nullable NSNumber *)evPreConditioningTime;

@property (nonatomic, readonly) uint32_t evInitialCharge;
@property (nonatomic, readonly, nonnull, copy) NSArray<MBNNCurveElement *> *energyConsumptionCurve;
@property (nonatomic, readonly, nullable) NSNumber *auxiliaryConsumption;
@property (nonatomic, readonly, nullable) NSNumber *evPreConditioningTime;

- (BOOL)isEqualToEvStateData:(nonnull MBNNEvStateData *)other;

@end
