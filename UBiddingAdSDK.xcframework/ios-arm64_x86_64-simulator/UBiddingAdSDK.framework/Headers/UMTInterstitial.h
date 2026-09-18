//
//  UMTInterstitial.h
//  UMTInterstitial
//
//  Created by UbiX on 2024/7/3.
//

#import <UBiddingAdSDK/UMTAd.h>

NS_ASSUME_NONNULL_BEGIN

@class UMTInterstitial;
@class UMTAdnInfo;

@protocol UMTInterstitialLoadDelegate <UMTAdDelegate>
/// 插屏加载成功
- (void)umtInterstitial:(UMTInterstitial *)interstitialAd didLoadWithExtra:(NSDictionary *)extra;
/// 插屏加载失败
- (void)umtInterstitial:(UMTInterstitial *)interstitialAd didLoadFailed:(UMTError *)error;

@optional
/// 广告源开始加载回调
- (void)umtInterstitial:(UMTInterstitial *)interstitialAd didStartLoadingADSource:(UMTAdnInfo *)adnInfo;
/// 广告源加载成功回调
- (void)umtInterstitial:(UMTInterstitial *)interstitialAd didFinishLoadAdnInfo:(UMTAdnInfo *)adnInfo;
/// 广告源加载失败回调
- (void)umtInterstitial:(UMTInterstitial *)interstitialAd didFailLoadAdnInfo:(UMTAdnInfo *)adnInfo error:(nullable NSError *)error;

@end

@protocol UMTInterstitialShowDelegate <UMTAdDelegate>

/// 插屏展示
- (void)umtInterstitial:(UMTInterstitial *)interstitialAd didShowWithExtra:(NSDictionary *)extra;
/// 插屏展示失败
- (void)umtInterstitial:(UMTInterstitial *)interstitialAd didShowFailed:(UMTError *)error;
/// 插屏点击
- (void)umtInterstitial:(UMTInterstitial *)interstitialAd didClickWithExtra:(NSDictionary *)extra;
/// 插屏关闭
- (void)umtInterstitial:(UMTInterstitial *)interstitialAd didCloseWithExtra:(NSDictionary *)extra;
/// 插屏详情关闭
- (void)umtInterstitial:(UMTInterstitial *)interstitialAd didDetailCloseWithExtra:(NSDictionary *)extra;

@end

@interface UMTInterstitial : UMTAd

@property (nonatomic, weak) id <UMTInterstitialShowDelegate> showDelegate;

@end

NS_ASSUME_NONNULL_END
