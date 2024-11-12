// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@protocol MBNNMutableNavigatorSettings;

/** Handle to Navigator Config. Public methods can be called to change selected settings after start. */
NS_SWIFT_NAME(ConfigHandle)
__attribute__((visibility ("default")))
@interface MBNNConfigHandle : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull id<MBNNMutableNavigatorSettings>)mutableSettings __attribute((ns_returns_retained));

@end
