// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/**
 * PROFILE SHORT message options
 * slopeStep - if true, slopeStep type will be generated
 * slopeLinear - if true, slopeLinear type will be generated
 * curvature - if true, curvature type will be generated
 * roadCondition - if true, roadCondition type will be generated
 * variableSpeedSign - if true, variableSpeedSign type will be generated
 * headingChange - if true, headingChange type will be generated
 * historyAverageSpeed - if true, historyAverageSpeed type will be generated
 */
NS_SWIFT_NAME(AdasisConfigProfileshortTypeOptions)
__attribute__((visibility ("default")))
@interface MBNNAdasisConfigProfileshortTypeOptions : NSObject

- (nonnull instancetype)init;

- (nonnull instancetype)initWithSlopeStep:(BOOL)slopeStep
                              slopeLinear:(BOOL)slopeLinear
                                curvature:(BOOL)curvature
                            roadCondition:(BOOL)roadCondition
                        variableSpeedSign:(BOOL)variableSpeedSign
                            headingChange:(BOOL)headingChange
                      historyAverageSpeed:(BOOL)historyAverageSpeed;

@property (nonatomic, readonly) BOOL slopeStep;
@property (nonatomic, readonly) BOOL slopeLinear;
@property (nonatomic, readonly) BOOL curvature;
@property (nonatomic, readonly) BOOL roadCondition;
@property (nonatomic, readonly) BOOL variableSpeedSign;
@property (nonatomic, readonly) BOOL headingChange;
@property (nonatomic, readonly) BOOL historyAverageSpeed;

- (BOOL)isEqualToAdasisConfigProfileshortTypeOptions:(nonnull MBNNAdasisConfigProfileshortTypeOptions *)other;

@end
