// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/** Information about current SDK which will be written to a history */
NS_SWIFT_NAME(SdkHistoryInfo)
__attribute__((visibility ("default")))
@interface MBNNSdkHistoryInfo : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithSdkVersion:(nonnull NSString *)sdkVersion
                                   sdkName:(nonnull NSString *)sdkName;

/** Semver version of SDK used while recording history */
@property (nonatomic, readonly, nonnull, copy) NSString *sdkVersion;

/** Name of SDK(iOS, Android, Driver Apps etc) used while recording history */
@property (nonatomic, readonly, nonnull, copy) NSString *sdkName;


- (BOOL)isEqualToSdkHistoryInfo:(nonnull MBNNSdkHistoryInfo *)other;

@end
