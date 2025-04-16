// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(TimeZone)
__attribute__((visibility ("default")))
@interface MBNNTimeZone : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithOffset:(nonnull NSString *)offset
                            identifier:(nonnull NSString *)identifier
                          abbreviation:(nonnull NSString *)abbreviation;

/** e.g. "-06:00" */
@property (nonatomic, readonly, nonnull, copy) NSString *offset;

/** e.g. "America/New_York" */
@property (nonatomic, readonly, nonnull, copy) NSString *identifier;

/** e.g. "EDT" */
@property (nonatomic, readonly, nonnull, copy) NSString *abbreviation;


- (BOOL)isEqualToTimeZone:(nonnull MBNNTimeZone *)other;

@end
