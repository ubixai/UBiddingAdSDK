//
//  UMTMediationNativeAd.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/8/27.
//

#import "UMTInterfaceBaseObject.h"
#import "UMTMediationNativeAdData.h"
#import "UMTMediationNativeAdViewCreator.h"

typedef NS_ENUM(NSInteger, UMTShakeStatus) {
    UMTShakeStatusUnknown  = 0, /// 未知，以广告源为准
    UMTShakeStatusEnabled  = 1, /// 开启摇一摇
    UMTShakeStatusDisabled = 2, /// 关闭摇一摇
};

NS_ASSUME_NONNULL_BEGIN

@interface UMTMediationNativeAd : UMTInterfaceBaseObject
// 广告物料，包含有最全的广告数据
@property (nonatomic, strong, nonnull) id<UMTMediationNativeAdData> adData;

// 广告视图创建对象，对常用广告展示元素进行创建（存在意义：对部分adn创建特定视图的支持）
@property (nonatomic, strong, nonnull) id<UMTMediationNativeAdViewCreator> viewCreator;

// 广告视图对象（存在意义：对部分adn创建特定视图的支持）
@property (nonatomic, strong, nonnull) UIView *view;

@property (nonatomic, assign, readonly) BOOL isVideoAd;

// adn获取到的原始广告数据
@property (nonatomic, strong, nonnull) id originMediatedNativeAd;

// 此次广告的摇一摇状态
// UMTShakeStatusUnknown: 未知以广告源为准；UMTShakeStatusEnabled: 开启摇一摇；UMTShakeStatusDisabled: 关闭摇一摇。
// 注意：这是平台意图、非隐私实际生效值——若媒体初始化时禁用传感器(sensorEnabled=NO)，实际也会触发摇一摇。
// 不受 developerRenderShakeView 影响：开发者声明自渲染时仍返回非 Unknown，供开发者判断”要不要画自己的提示”。
@property (nonatomic, assign) UMTShakeStatus shakeStatus;

// 摇一摇提示视图尺寸（pt，默认 {100, 100}）。
// 由 SDK 加载完成时回填，供开发者与 SDK 默认视图共用一套尺寸口径。
@property (nonatomic, assign) CGSize shakeTipSize;
@end

NS_ASSUME_NONNULL_END
