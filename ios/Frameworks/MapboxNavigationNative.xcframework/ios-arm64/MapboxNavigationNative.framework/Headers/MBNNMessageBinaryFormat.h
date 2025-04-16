// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNMessageBinaryFormat)
{
    /** Big-endian format */
    MBNNMessageBinaryFormatADASISv2BE,
    /** Little-endian format */
    MBNNMessageBinaryFormatADASISv2LE,
    /** Message format described in adasis.fbs */
    MBNNMessageBinaryFormatFlatBuffers,
    /** Internal format for testing purposes only, do not use in production */
    MBNNMessageBinaryFormatMapboxInternal
} NS_SWIFT_NAME(MessageBinaryFormat);

NSString* MBNNMessageBinaryFormatToString(MBNNMessageBinaryFormat message_binary_format);
