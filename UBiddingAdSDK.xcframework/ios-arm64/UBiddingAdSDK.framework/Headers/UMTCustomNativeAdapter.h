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

@end

#endif /* UMTCustomNativeAdapter_h */
