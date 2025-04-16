// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

@class MBNNAdasisConfig;

NS_SWIFT_NAME(AdasisConfigBuilder)
__attribute__((visibility ("default")))
@interface MBNNAdasisConfigBuilder : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

/** Returns default ADASIS v2 config. */
+ (nonnull MBNNAdasisConfig *)defaultOptions __attribute((ns_returns_retained));
/**
 * Builds adasis v2 configuration from JSON.
 * Example JSON:
 * ```
 * {
 * "dataSending": {
 * "outputBinaryFormat": "ADASISv2BE",
 * "messageIntervalMs": 100,
 * "messagesInPackage": 10,
 * "metadataCycleSeconds": 5,
 * "enableRetransmission": false,
 * "retransmissionMeters": 100,
 * "treeTrailingLength": 300,
 * "enableUpdates": true,
 * "sortMessagesByMppAndDist": false
 * },
 * "pathConfigs": {
 * "stub": {
 * "enable": true,
 * "radiusMeters": 2000
 * },
 * "segment": {
 * "enable": true,
 * "radiusMeters": 2000
 * },
 * "profileshort": {
 * "enable": true,
 * "radiusMeters": 2000,
 * "types": {
 * "slopeStep": true,
 * "slopeLinear": false,
 * "curvature": true,
 * "roadCondition": true,
 * "variableSpeedSign": true,
 * "headingChange": true,
 * "historyAverageSpeed": true
 * },
 * "minDistanceBetweenCurvatures": 0,
 * "bandwidthEnabled": true
 * },
 * "profilelong": {
 * "enable": true,
 * "radiusMeters": 2000,
 * "types": {
 * "lonLat": false,
 * "trafficSign": {
 * "enableSpeedLimit": true,
 * "enableYield": true,
 * "enableStop": true,
 * "enableTrafficLight": true,
 * "enablePedestrianCrossing": true,
 * "enableZebra": true,
 * "enablePassLeftOrRightSide": true,
 * "enableDanger": true,
 * "enablePassLeftSide": true,
 * "enablePassRightSide": true,
 * "enableDomesticAnimalsCrossing": true,
 * "enableWildAnimalsCrossing": true,
 * "enableRoadWorks": true,
 * "enableResidentialArea": true,
 * "enableEndOfResidentialArea": true,
 * "enableRightBend": true,
 * "enableLeftBend": true,
 * "enableDoubleBendRightFirst": true,
 * "enableDoubleBendLeftFirst": true,
 * "enableCurvyRoad": true,
 * "enableOvertakingByGoodsVehiclesProhibited": true,
 * "enableEndOfProhibitionOnOvertakingForGoodsVehicles": true,
 * "enableDangerousIntersection": true,
 * "enableTunnel": true,
 * "enableFerryTerminal": true,
 * "enableNarrowBridge": true,
 * "enableHumpbackBridgeBridge": true,
 * "enableRiverBank": true,
 * "enableRiverBankLeft": true,
 * "enablePriorityRoad": true,
 * "enableIntersection": true,
 * "enableIntersectionWithMinorRoad": true,
 * "enableIntersectionWithPriorityToTheRight": true,
 * "enableDirectionToTheRight": true,
 * "enableDirectionToTheLeft": true,
 * "enableCarriagewayNarrows": true,
 * "enableCarriagewayNarrowsRight": true,
 * "enableCarriagewayNarrowsLeft": true,
 * "enableLaneMergeCenter": true,
 * "enableOvertakingProhibited": true,
 * "enableLaneMergeLeft": true,
 * "enableLaneMergeRight": true,
 * "enableEndOfProhibitionOnOvertaking": true,
 * "enableProtectiveOvertaking": true,
 * "enablePedestrians": true,
 * "enableChildren": true,
 * "enableSchoolZone": true,
 * "enableCyclists": true,
 * "enableTwoWayTraffic": true,
 * "enableRailwayCrossingWithGates": true,
 * "enableRailwayCrossingWithoutGates": true,
 * "enableRailwayCrossing": true,
 * "enableTramway": true,
 * "enableFallingRocks": true,
 * "enableFallingRocksLeft": true,
 * "enableFallingRocksRight": true,
 * "enableSteepDropLeft": true,
 * "enableSteepDropRight": true,
 * "enableVariableSignMechanicElements": true,
 * "enableSlipperyRoad": true,
 * "enableSteepAscent": true,
 * "enableSteepDescent": true,
 * "enableUnevenRoad": true,
 * "enableHump": true,
 * "enableDip": true,
 * "enableRoadFloods": true,
 * "enableIcyRoad": true,
 * "enableSideWinds": true,
 * "enableTrafficCongestion": true,
 * "enableHighAccidentArea": true,
 * "enableVariableSignLightElements": true,
 * "enablePriorityOverOncomingTraffic": true,
 * "enablePriorityForOncomingTraffic": true,
 * "enableSpeedCam": true,
 * "enableRailroadCrossing": true,
 * "enableSpeedBump": true
 * }
 * }
 * }
 * }
 * }
 * ```
 */
+ (nonnull MBNNAdasisConfig *)fromJsonForJson:(nonnull NSString *)json __attribute((ns_returns_retained));

@end
