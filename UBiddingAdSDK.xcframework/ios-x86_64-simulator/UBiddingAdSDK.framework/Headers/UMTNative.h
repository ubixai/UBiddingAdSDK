//
//  UMTNative.h
//  UMTNative
//
//  Created by UbiX on 2024/7/3.
//

#import <UBiddingAdSDK/UMTAd.h>

NS_ASSUME_NONNULL_BEGIN
@class UMTNative;
@class UMTNativeOffer;
@class UMTAdnInfo;

@protocol UMTNativeLoadDelegate <UMTAdDelegate>
/// 信息流加载成功
- (void)umtNativeAd:(UMTNative *)native didLoadWithAds:(NSArray <UMTNativeOffer*> *)ads;
/// 信息流加载失败
- (void)umtNativeAd:(UMTNative *)native didLoadFailed:(UMTError *)error;

@optional
/// 广告源开始加载回调
- (void)umtNativeAd:(UMTNative *)native didStartLoadingADSource:(UMTAdnInfo *)adnInfo;
/// 广告源加载成功回调
- (void)umtNativeAd:(UMTNative *)native didFinishLoadAdnInfo:(UMTAdnInfo *)adnInfo;
/// 广告源加载失败回调
- (void)umtNativeAd:(UMTNative *)native didFailLoadAdnInfo:(UMTAdnInfo *)adnInfo error:(nullable NSError *)error;

@end



@interface UMTNative : UMTAd

@property (nonatomic) CGSize size;

/// 是否由开发者自行渲染摇一摇提示视图（默认 NO 由 SDK 托管）
@property (nonatomic, assign) BOOL developerRenderShakeView;

@end

NS_ASSUME_NONNULL_END
