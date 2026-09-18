//
//  UMTCustomInterstitialAdapterBridge.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/9/6.
//

#ifndef UMTCustomInterstitialAdapterBridge_h
#define UMTCustomInterstitialAdapterBridge_h

@protocol UMTCustomInterstitialAdapter;

/// 自定义Interstitial广告的adapter的回调协议
@protocol UMTCustomInterstitialAdapterBridge <NSObject>
@optional

/// 在广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ext 回传信息
- (void)interstitialAd:(id<UMTCustomInterstitialAdapter>_Nonnull)adapter didLoadWithExt:(NSDictionary *)ext;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
/// @param ext 回传信息
- (void)interstitialAd:(id<UMTCustomInterstitialAdapter>_Nonnull)adapter didLoadFailWithError:(NSError *_Nullable)error ext:(NSDictionary *)ext;

/// 在模板广告渲染成功时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ext 回传信息
- (void)interstitialAd:(id<UMTCustomInterstitialAdapter>_Nonnull)adapter didRenderSuccessWithExt:(NSDictionary *)ext;

/// 在广告渲染失败时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)interstitialAd:(id<UMTCustomInterstitialAdapter>_Nonnull)adapter renderFailedWithError:(NSError *)error;

/// 在广告已经展示时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdDidVisible:(id<UMTCustomInterstitialAdapter>_Nonnull)adapter;

/// 广告展示失败的时候调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)interstitialAdDidShowFailed:(id<UMTCustomInterstitialAdapter>)adapter error:(NSError *)error;

/// 在广告关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdDidClose:(id<UMTCustomInterstitialAdapter>_Nonnull)adapter;

/// 在广告点击事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdDidClick:(id<UMTCustomInterstitialAdapter>_Nonnull)adapter;

/// 在广告即将展示详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdWillPresentFullScreenModal:(id<UMTCustomInterstitialAdapter>_Nonnull)adapter;

/// 在广告关闭详情页或者appstore时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdWillDismissFullScreenModal:(id<UMTCustomInterstitialAdapter>_Nonnull)adapter;

/// 广告点击跳转使用的控制器
- (UIViewController *)viewControllerForPresentingModalView;

@end
#endif /* UMTCustomInterstitialAdapterBridge_h */
