//
//  UMTCustomNativeAdapter.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/8/26.
//  Copyright © 2024 UBiX. All rights reserved.
//

#ifndef UMTCustomNativeAdapter_h
#define UMTCustomNativeAdapter_h

#import "UMTCustomAdapterDelegate.h"
#import "UMTCustomNativeAdapterBridge.h"
#import "UMTMediationNativeAd.h"
#import "UMTNativeAdView.h"
#import "UMTAd.h"
#import "UMTVideoConfig.h"


#pragma mark - 信息流自渲染摇一摇
/// 摇一摇渲染模式：由广告对象自声明，驱动四类差异化渲染策略。
typedef NS_ENUM(NSInteger, UMTShakeRenderMode) {
    /// 广告源自带摇一摇提示（GDT/趣盟/...），SDK 与开发者都不加
    UMTShakeRenderModeADNAuto           = 0,
    /// 广告源无摇一摇能力：开发者自渲染时 SDK 不兜底；开发者未声明时 SDK 挂默认视图
    UMTShakeRenderModeDeveloperOrSDK    = 1,
    /// 天璇：开发者自渲染时 SDK 不兜底；开发者未声明时天璇自行处理
    UMTShakeRenderModeDeveloperOrADN    = 2,
    /// 广告源提供独立摇一摇 widget（百度/聚推）：SDK 取视图、按 90% 等比缩放居中挂载
    UMTShakeRenderModeSDKAttachADNView  = 3,
};


/// 自定义Native广告的adapter广告协议
@protocol UMTCustomNativeAdapter <UMTCustomAdapterDelegate>

/// 加载广告的方法
/// @param slotID adn的广告位ID
/// @param size 广告展示尺寸
/// @param imageSize 图片或视频展示尺寸
/// @param parameter 广告加载的参数
- (void)loadNativeAdWithSlotID:(NSString *)slotID andSize:(CGSize)size imageSize:(CGSize)imageSize parameter:(NSDictionary *)parameter;

/// 渲染广告，为模板广告时会回调该方法，需对广告进行渲染
/// @param expressAdView 模板广告
- (void)renderForExpressAdView:(UIView *)expressAdView;

/// 为模板广告设置控制器
/// @param viewController 控制器
/// @param expressAdView 模板广告
- (void)setRootViewController:(UIViewController *)viewController forExpressAdView:(UIView *)expressAdView;

/// 渲染广告，为非模板广告时会回调该方法
- (void)renderView:(UMTNativeAdView *)nativeAdView selfRenderView:(nonnull UIView<UMTMediationNativeSelfRenderViewCreator> *)selfRenderView;

/// 为非模板广告设置控制器
/// @param viewController 控制器
/// @param nativeAd 非模板广告
- (void)setRootViewController:(UIViewController *)viewController forNativeAd:(UMTMediationNativeAd *)nativeAd;

/// 注册容器和可点击区域
/// @param containerView 容器视图
/// @param views 可点击视图组
- (void)registerContainerView:(__kindof UIView *)containerView andClickableViews:(NSArray<__kindof UIView *> *)views closableViews:(NSArray *)closableViews forNativeAd:(UMTMediationNativeAd *)nativeAd;

@optional

/// 当前加载的广告的状态，native模板广告
- (UMTMediatedAdStatus)mediatedAdStatusWithExpressView:(UIView *)view;

/// 当前加载的广告的状态，native非模板广告
- (UMTMediatedAdStatus)mediatedAdStatusWithMediatedNativeAd:(UMTMediationNativeAd *)ad;


- (void)unRegisterViewNativeAd:(UMTMediationNativeAd *)nativeAd;

/// 广告视图即将被展示回调，只会调用一次
/// @param expressAdView 模板广告视图
/// @param mediatedNativeAd 广告数据
- (void)adViewWillAddToSuperViewWithExpressAdView:(__kindof UIView *)expressAdView orMediatedNativeAd:(UMTMediationNativeAd *)mediatedNativeAd;

/// 收到视频播放控制事件
/// @param action 播放/暂停/停止/静音
///  @param nativeAdView 广告视图
- (void)updateVideoAction:(UMTNativeVideoAction)action nativeAd:(UMTNativeAdView *)nativeAdView parameters:(NSDictionary *)parameters;

/// 视频已播放时长，单位 ms
- (CGFloat)videoPlayTimeOfNativeAd:(UMTNativeAdView *)view;

/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<UMTCustomNativeAdapterBridge> bridge;

/// 上报dislike的原因，仅限非模板广告自定义关闭按钮时使用
/// @param ad 非模板广告数据
/// @param reasons dislike的原因。数据基于ADN提供的原因修改
- (void)reportDislikeAd:(UMTMediationNativeAd *)ad withReasons:(NSArray<UMTDislikeReason *> *)reasons;

/// 待上报的视频事件枚举类型
- (void)reportVideoEvent:(NSInteger)event forAd:(UMTMediationNativeAd *)ad withParameters:(NSDictionary *)parameters;

#pragma mark - 信息流自渲染摇一摇

/// 声明该广告源在信息流自渲染摇一摇上的渲染模式。基类默认返回 UMTShakeRenderModeADNAuto。
/// @param nativeAd 当前物料
/// @return 渲染模式枚举
- (UMTShakeRenderMode)feedShakeRenderModeForNativeAd:(UMTMediationNativeAd *)nativeAd;

/// 取广告源提供的摇一摇提示视图（仅 SDKAttachADNView 模式，如百度）。
/// @param widthDp  最终宽（已按容器 90% 等比缩放）
/// @param heightDp 最终高（已按容器 90% 等比缩放）
/// @param nativeAd 当前物料
/// @return 广告源提供的提示视图；返回 nil 表示该广告不展示提示（如百度缩放后 < 80dp 时）
- (nullable UIView *)renderShakeViewWithWidthDp:(CGFloat)widthDp
                                      heightDp:(CGFloat)heightDp
                                     nativeAd:(UMTMediationNativeAd *)nativeAd;

@end

#endif /* UMTCustomNativeAdapter_h */
