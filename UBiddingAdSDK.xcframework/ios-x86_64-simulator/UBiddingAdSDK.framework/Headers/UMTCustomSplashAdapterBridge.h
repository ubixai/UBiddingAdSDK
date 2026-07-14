//
//  UMTCustomSplashAdapterBridge.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/7/11.
//

#ifndef UMTCustomSplashAdapterBridge_h
#define UMTCustomSplashAdapterBridge_h

@protocol UMTCustomSplashAdapter;

/// 自定义开屏广告的adapter的回调协议
@protocol UMTCustomSplashAdapterBridge <NSObject>
@optional

/// 在广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ext 回传信息
- (void)splashAd:(id<UMTCustomSplashAdapter>_Nonnull)adapter didLoadWithExt:(NSDictionary *)ext;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
/// @param ext 回传信息
- (void)splashAd:(id<UMTCustomSplashAdapter>_Nonnull)adapter didLoadFailWithError:(NSError *_Nullable)error ext:(NSDictionary *)ext;

/// 在广告渲染成功时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ext 回传信息
- (void)splashAd:(id<UMTCustomSplashAdapter>_Nonnull)adapter didRenderSuccessWithExt:(NSDictionary *)ext;

/// 在广告渲染失败时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)splashAd:(id<UMTCustomSplashAdapter>_Nonnull)adapter didRenderFailedWithError:(NSError *)error;


/// 在广告曝光时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidShow:(id<UMTCustomSplashAdapter>_Nonnull)adapter;

/// 广告展示失败的时候调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)splashAdDidShowFailed:(id<UMTCustomSplashAdapter>)adapter error:(NSError *)error;

/// 在广告点击事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClick:(id<UMTCustomSplashAdapter>_Nonnull)adapter;

/// 在广告被点击跳过时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClickSkip:(id<UMTCustomSplashAdapter>_Nonnull)adapter;

/// 在广告即将关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdWillClose:(id<UMTCustomSplashAdapter>_Nonnull)adapter;

/// 在广告关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClose:(id<UMTCustomSplashAdapter>_Nonnull)adapter;

/// 在广告关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
//- (void)splashAdDidClose:(id<UMTCustomSplashAdapter>_Nonnull)adapter withType:(UMTSplashAdCloseType)closeType;

/// 在广告即将展示详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdWillPresentFullScreenModal:(id<UMTCustomSplashAdapter>_Nonnull)adapter;

/// 在广告关闭详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdWillDismissFullScreenModal:(id<UMTCustomSplashAdapter>_Nonnull)adapter;

/// 在广告倒计时结束时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidCountDownToZero:(id<UMTCustomSplashAdapter>_Nonnull)adapter;

/// 广告点击跳转使用的控制器
- (UIViewController *)viewControllerForPresentingModalView;
@end


#endif /* UMTCustomSplashAdapterBridge_h */
