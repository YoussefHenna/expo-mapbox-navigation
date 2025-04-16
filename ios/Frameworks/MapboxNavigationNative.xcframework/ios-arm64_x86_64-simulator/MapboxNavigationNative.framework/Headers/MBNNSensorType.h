// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

// NOLINTNEXTLINE(modernize-use-using)
typedef NS_ENUM(NSInteger, MBNNSensorType)
{
    /** Report if current weather is clear | fog | rain | snow */
    MBNNSensorTypeWeather,
    /** Current lane number, starting from 1 from the road boundary, e.g. for right side traffic 1 means the right lane */
    MBNNSensorTypeLane,
    /** Is trailer attached? Is maximum load over 3.5t? See adas::VehicleType for the supported types */
    MBNNSensorTypeVehicleType
} NS_SWIFT_NAME(SensorType);

NSString* MBNNSensorTypeToString(MBNNSensorType sensor_type);
