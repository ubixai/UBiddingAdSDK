//
//  umtBanner.h
//  umtBanner
//
//  Created by UbiX on 2024/7/3.
//

#import <UBiddingAdSDK/UMTAd.h>

NS_ASSUME_NONNULL_BEGIN

@class UMTBanner;
@class UMTAdnInfo;

@protocol UMTBannerLoadDelegate <UMTAdDelegate>
/// 横幅加载成功
- (void)umtBanner:(UMTBanner *)bannerAd didLoadWithExtra:(NSDictionary *)extra;
/// 横幅加载失败
- (void)umtBanner:(UMTBanner *)bannerAd didLoadFailed:(UMTError *)error;

@optional
/// 广告源开始加载回调
- (void)umtBanner:(UMTBanner *)bannerAd didStartLoadingADSource:(UMTAdnInfo *)adnInfo;
/// 广告源加载成功回调
- (void)umtBanner:(UMTBanner *)bannerAd didFinishLoadAdnInfo:(UMTAdnInfo *)adnInfo;
/// 广告源加载失败回调
- (void)umtBanner:(UMTBanner *)bannerAd didFailLoadAdnInfo:(UMTAdnInfo *)adnInfo error:(nullable NSError *)error;

@end

@protocol UMTBannerShowDelegate <UMTAdDelegate>

/// 横幅展示
- (void)umtBanner:(UMTBanner *)bannerAd didShowWithExtra:(NSDictionary *)extra;
/// 横幅展示失败
- (void)umtBanner:(UMTBanner *)bannerAd didShowFailed:(UMTError *)error;
/// 横幅点击
- (void)umtBanner:(UMTBanner *)bannerAd didClickWithExtra:(NSDictionary *)extra;
/// 横幅关闭
- (void)umtBanner:(UMTBanner *)bannerAd didCloseWithExtra:(NSDictionary *)extra;
/// 横幅详情打开
- (void)umtBanner:(UMTBanner *)bannerAd willPresentDetailWithExtra:(NSDictionary *)extra;
/// 横幅详情关闭
- (void)umtBanner:(UMTBanner *)bannerAd didDetailCloseWithExtra:(NSDictionary *)extra;

@end

@interface UMTBanner : UMTAd

@property (nonatomic, weak) id <UMTBannerShowDelegate> showDelegate;

/// 横幅广告视图（用于展示广告）
@property (nonatomic, strong, readonly) UIView *adView;

/// 初始化横幅广告
/// @param slotId 广告位ID
/// @param size 广告尺寸
- (instancetype)initWithSlotId:(NSString *)slotId adSize:(CGSize)size;

/// 销毁
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
