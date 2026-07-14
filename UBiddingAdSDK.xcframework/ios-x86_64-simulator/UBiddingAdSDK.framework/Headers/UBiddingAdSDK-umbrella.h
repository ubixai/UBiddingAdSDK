#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "UMTAdapterRewardAdInfo.h"
#import "UMTAdLoadingParams.h"
#import "UMTAdnSDKInitConfig.h"
#import "UMTCustomAdapter.h"
#import "UMTCustomAdapterDelegate.h"
#import "UMTCustomBannerAdapter.h"
#import "UMTCustomBannerAdapterBridge.h"
#import "UMTCustomConfigAdapter.h"
#import "UMTCustomInterstitialAdapter.h"
#import "UMTCustomInterstitialAdapterBridge.h"
#import "UMTCustomNativeAdapter.h"
#import "UMTCustomNativeAdapterBridge.h"
#import "UMTCustomRewardedVideoAdapter.h"
#import "UMTCustomRewardedVideoAdapterBridge.h"
#import "UMTCustomSplashAdapter.h"
#import "UMTCustomSplashAdapterBridge.h"
#import "UMTDislikeReason.h"
#import "UMTDispatchHelper.h"
#import "UMTImage.h"
#import "UMTMediationNativeAd.h"
#import "UMTMediationNativeAdData.h"
#import "UMTMediationNativeAdViewCreator.h"
#import "UMTUAdxMRProviding.h"
#import "UMTAd.h"
#import "UMTAdManager.h"
#import "UMTAdnInfo.h"
#import "UMTAdnMaterial.h"
#import "UMTAdSDK.h"
#import "UMTAdSDKConfiguration.h"
#import "UMTAdSDKManager.h"
#import "UMTBidPlatform.h"
#import "UMTBidResultKey.h"
#import "UMTError.h"
#import "UMTGlobalDefine.h"
#import "UMTInterfaceBaseObject.h"
#import "UMTMediaBidResult.h"
#import "UMTNativeAdView.h"
#import "UMTVideoConfig.h"
#import "UMTAdManager+Splash.h"
#import "UMTSplash.h"
#import "UMTAdManager+Native.h"
#import "UMTNative.h"
#import "UMTNativeAdData.h"
#import "UMTNativeOffer.h"
#import "UMTAdManager+Interstitial.h"
#import "UMTInterstitial.h"
#import "UMTAdManager+RewardedVideo.h"
#import "UMTRewardedVideo.h"
#import "UMTAdManager+Banner.h"
#import "UMTBanner.h"
#import "UbiddingAdSdkDaq.pbobjc.h"
#import "UbiddingConfig.pbobjc.h"
#import "UbiddingMaterial.pbobjc.h"

FOUNDATION_EXPORT double UBiddingAdSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char UBiddingAdSDKVersionString[];

