//
//  UMTNativeOffer.h
//  UMTNative
//
//  Created by guoqiang on 2024/8/27.
//

#import <UBiddingAdSDK/UMTAdSDK.h>

NS_ASSUME_NONNULL_BEGIN
@class UMTNative;
@class UMTNativeOffer;

@protocol UMTNativeDelegate <UMTAdDelegate>
//// 信息流展示
- (void)umtNativeAd:(UMTNative *)native didShowSucc:(UMTNativeOffer *)offer;
//// 信息流渲染成功，仅模板广告，可能不回调
- (void)umtNativeAd:(UMTNative *)native didAdViewRenderSucc:(UMTNativeOffer *)offer;
/// 信息流渲染失败，仅模板广告，可能不回调
- (void)umtNativeAd:(UMTNative *)native didAdView:(UMTNativeOffer *)offer renderFailed:(UMTError *)error;
/// 信息流展示失败，仅支持 baidu
- (void)umtNativeAd:(UMTNative *)native didShow:(UMTNativeOffer *)offer failed:(UMTError *)error;
/// 信息流点击
- (void)umtNativeAd:(UMTNative *)native didClick:(UMTNativeOffer *)offer;
/// 信息流关闭
- (void)umtNativeAd:(UMTNative *)native didClose:(UMTNativeOffer *)offer;
/// 信息流详情关闭，
- (void)umtNativeAd:(UMTNative *)native didDetailClose:(UMTNativeOffer *)offer;
/// 信息流，视频播放状态变更
- (void)umtNativeAd:(UMTNative *)native offer:(UMTNativeOffer *)offer didChangedPlayStatus:(UMTVideoPlayerStatus)status;
/// 信息流，视频播放完成或异常
- (void)umtNativeAd:(UMTNative *)native offer:(UMTNativeOffer *)offer didPlayFinishExtra:(NSDictionary *)extra failed:(UMTError *)error;
/// 信息流，视频播放进度, 仅支持 Gdt，UBiMAXAdx
///  @param time 播放进度，单位： ms
///  @param duration 视频时长，单位：ms
- (void)umtNativeAd:(UMTNative *)native offer:(UMTNativeOffer *)offer didChangedPlayTime:(CGFloat)time duration:(CGFloat)duration extra:(NSDictionary *)extra;

@end

@interface UMTNativeOffer : UMTInterfaceBaseObject
//// 信息流关联对象
@property (nonatomic, weak) UMTNative *nativeAd;
/// 是否模板广告
@property (nonatomic, assign) BOOL isExpress;
/// 如果是模板广告可直接将该视图添加到需要展示的位置，如果是非模板广告可对该视图内部控件进行布局操作
@property (nonatomic, strong) UMTNativeAdView *canvasView;
//// 信息流交互代理对象
@property (nonatomic, weak) id<UMTNativeDelegate> delegate;
///
@property (nonatomic, weak) UIViewController *rootViewController;

/// [必要]渲染广告，模板广告开发者无需传入自渲染容器 selfRenderView
- (void)renderAdView:(UMTNativeAdView *)adView selfRenderView:(UIView<UMTMediationNativeSelfRenderViewCreator> *)view;

/**
 注册自渲染广告点击事件.
 @param containerView : 必要.
                        自渲染广告容器.
 @param clickableViews :  点击组件数组
 @param closableViews :  点击关闭组件数组.
 */
- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews
            closableViews:(NSArray<__kindof UIView *> *_Nullable)closableViews;

/// 视频操作， 支持 GDT, Baidu UBiMAXAdx
- (void)updateVideoAction:(UMTNativeVideoAction)action;

/// 设置静音
/// @param mute YES静音   NO非静音
- (void)setVideoMute:(BOOL)mute;

- (void)destroy;

@end

NS_ASSUME_NONNULL_END
