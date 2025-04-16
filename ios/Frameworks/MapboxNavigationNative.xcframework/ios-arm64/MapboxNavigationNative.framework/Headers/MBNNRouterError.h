// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>
#import <MapboxNavigationNative/MBNNRouterErrorType.h>
#import <MapboxNavigationNative/MBNNRouterOrigin.h>

NS_SWIFT_NAME(RouterError)
__attribute__((visibility ("default")))
@interface MBNNRouterError : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithMessage:(nonnull NSString *)message
                                   type:(MBNNRouterErrorType)type
                              requestId:(uint64_t)requestId
                             refreshTtl:(nullable NSNumber *)refreshTtl
                           routerOrigin:(MBNNRouterOrigin)routerOrigin
                                    url:(nonnull NSString *)url;

- (nonnull instancetype)initWithMessage:(nonnull NSString *)message
                                   type:(MBNNRouterErrorType)type
                              requestId:(uint64_t)requestId
                             refreshTtl:(nullable NSNumber *)refreshTtl
                           routerOrigin:(MBNNRouterOrigin)routerOrigin
                                    url:(nonnull NSString *)url
                            isRetryable:(BOOL)isRetryable;

/** Error message */
@property (nonatomic, readonly, nonnull, copy) NSString *message;

/** Error type */
@property (nonatomic, readonly) MBNNRouterErrorType type;

/** Request ID */
@property (nonatomic, readonly) uint64_t requestId;

/** TTL in seconds for refresh in case of ThrottlingError */
@property (nonatomic, readonly, nullable) NSNumber *refreshTtl;

/** Which router produces the error */
@property (nonatomic, readonly) MBNNRouterOrigin routerOrigin;

/** Request URL */
@property (nonatomic, readonly, nonnull, copy) NSString *url;

/** True if retrying the request may lead to success */
@property (nonatomic, readonly) BOOL isRetryable;


- (BOOL)isEqualToRouterError:(nonnull MBNNRouterError *)other;

@end
