//
//  UMTSplashAd.h
//  UMTSplash
//
//  Created by guoqiang on 2024/7/11.
//

#import <UBiddingAdSDK/UMTAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class UMTSplash;
@class UMTAdnInfo;
@protocol UMTSplashDelegate <UMTAdDelegate>

/// 开屏广告加载成功
- (void)umtSplashAd:(UMTSplash *)splash didLoadSuccWithExt:(NSDictionary *)ext;
/// 开屏广告加载失败
- (void)umtSplashAd:(UMTSplash *)splash didLoadFailed:(UMTError *)error;


/// 开屏广告展示成功
- (void)umtSplashAd:(UMTSplash *)splash didShowSuccWithExt:(NSDictionary *)ext;
/// 开屏广告展示失败
- (void)umtSplashAd:(UMTSplash *)splash didShowFailed:(UMTError *)error;
/// 开屏广告点击
- (void)umtSplashAd:(UMTSplash *)splash didClickWithExt:(NSDictionary *)ext;
/// 开屏广告即将关闭
/// 目前仅支持 adx gdt
- (void)umtSplashAd:(UMTSplash *)splash willCloseWithExt:(NSDictionary *)ext;
/// 开屏广告关闭
- (void)umtSplashAd:(UMTSplash *)splash didCloseWithExt:(NSDictionary *)ext;
/// 开屏广告跳转详情页回调
/// 目前仅支持  gdt ks
- (void)umtSplashAd:(UMTSplash *)splash willPresentDetailWithExt:(NSDictionary *)ext;
/// 开屏广告关闭详情页回调
- (void)umtSplashAd:(UMTSplash *)splash didDetailCloseWithExt:(NSDictionary *)ext;

@optional
/// 广告源开始加载回调
- (void)umtSplashAd:(UMTSplash *)splash didStartLoadingADSource:(UMTAdnInfo *)adnInfo;

/// 广告源加载成功回调
- (void)umtSplashAd:(UMTSplash *)splash didFinishLoadAdnInfo:(UMTAdnInfo *)adnInfo;

/// 广告源加载失败回调
- (void)umtSplashAd:(UMTSplash *)splash didFailLoadAdnInfo:(UMTAdnInfo *)adnInfo error:(nullable NSError *)error;

@end

@interface UMTSplash : UMTAd
/// 底部自定义视图，不需要传nil
@property (nonatomic, strong) UIView *bottomView;

/// 加载回调代理对象
@property (nonatomic, weak) id <UMTSplashDelegate> loadDelegate;

/// 展示回调代理对象
@property (nonatomic, weak) id <UMTSplashDelegate> showDelegate;


@end

NS_ASSUME_NONNULL_END
