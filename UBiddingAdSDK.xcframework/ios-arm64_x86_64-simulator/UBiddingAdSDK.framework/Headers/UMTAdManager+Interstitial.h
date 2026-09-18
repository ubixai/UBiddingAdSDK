//
//  UMTAdManager+Interstitial.h
//  UMTInterstitial
//
//  Created by guoqiang on 2024/9/6.
//

#import <UBiddingAdSDK/UMTAdSDK.h>
#import <UBiddingAdSDK/UMTInterstitial.h>

NS_ASSUME_NONNULL_BEGIN

@interface UMTAdManager (Interstitial)

/**
  设置扩展信息
  @param extra 必须为有效的字符串格式的键值对
 
  已支持的key有：
    UMTAdLoadingParamInter_CloseAfterClick,
    插屏点击后是否关闭广告，默认不关闭，值为@BOOL格式，@NO：不关闭；@YES：关闭
 */
- (void)loadInterstitial:(UMTInterstitial *)interstitialAd
                   extra:(NSDictionary *)extra
                delegate:(id<UMTInterstitialLoadDelegate>)delegate;

- (BOOL)isReadyForInterstitial:(UMTInterstitial *)interstitialAd;

- (void)showInterstitial:(UMTInterstitial *)interstitialAd inRootVC:(UIViewController *)rootVC delegate:(id<UMTInterstitialShowDelegate>)delegate;


@end

NS_ASSUME_NONNULL_END
