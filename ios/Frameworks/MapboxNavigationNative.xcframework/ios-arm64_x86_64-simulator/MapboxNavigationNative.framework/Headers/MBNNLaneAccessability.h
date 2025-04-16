// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(LaneAccessability)
__attribute__((visibility ("default")))
@interface MBNNLaneAccessability : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithDesignated:(nonnull NSArray<NSString *> *)designated;

/** Indicates whether a lane is designated to specified vehicle types. */
@property (nonatomic, readonly, nonnull, copy) NSArray<NSString *> *designated;


- (BOOL)isEqualToLaneAccessability:(nonnull MBNNLaneAccessability *)other;

@end
