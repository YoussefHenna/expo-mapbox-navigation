// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNEventsMetadata;

/**
 * Clients must provide an implementation of EventsMetadataInterface to pass required metadata to
 * the telemetry subsystem. Implementation must be thread-safe.
 */
NS_SWIFT_NAME(EventsMetadataInterface)
@protocol MBNNEventsMetadataInterface
/** Pass EventsMetadata for filling the events properties */
- (nonnull MBNNEventsMetadata *)provideEventsMetadata;
@end
