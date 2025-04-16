// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(CurveElement)
__attribute__((visibility ("default")))
@interface MBNNCurveElement : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithFirst:(float)first
                               second:(float)second;

@property (nonatomic, readonly) float first;
@property (nonatomic, readonly) float second;

- (BOOL)isEqualToCurveElement:(nonnull MBNNCurveElement *)other;

@end
