//
//  UMTRewardedVideo.h
//  UBiXMediationToolRewardedVideo
//
//  Created by UbiX on 2024/7/3.
//

#import <UBiddingAdSDK/UMTAd.h>

NS_ASSUME_NONNULL_BEGIN

@class UMTRewardedVideo;
@class UMTAdnInfo;

@protocol UMTRewardedVideoLoadDelegate <UMTAdDelegate>
/// 激励视频加载成功
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didLoadWithExtra:(NSDictionary *)extra;
/// 激励视频加载失败
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didLoadFailed:(UMTError *)error;

@optional
/// 广告源开始加载回调
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didStartLoadingADSource:(UMTAdnInfo *)adnInfo;
/// 广告源加载成功回调
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didFinishLoadAdnInfo:(UMTAdnInfo *)adnInfo;
/// 广告源加载失败回调
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didFailLoadAdnInfo:(UMTAdnInfo *)adnInfo error:(nullable NSError *)error;

@end

@protocol UMTRewardedVideoShowDelegate <UMTAdDelegate>
/// 激励视频展示
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didShowWithExtra:(NSDictionary *)extra;
/// 激励视频展示失败
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didShowFailed:(UMTError *)error;
/// 激励视频点击
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didClickWithExtra:(NSDictionary *)extra;
/// 激励视频关闭
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didCloseWithExtra:(NSDictionary *)extra;
/// 激励视频 奖励发放
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didRewardedWithExtra:(NSDictionary *)extra;
/// 激励视频 播放状态变更
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didChangedPlayStatus:(UMTVideoPlayerStatus)status;
/// 激励视频播放完成或异常
- (void)umtRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd didPlayFinishWithExtra:(NSDictionary *)extra failed:(UMTError *)error;

@end

@interface UMTRewardedVideo : UMTAd

@property (nonatomic, weak) id <UMTRewardedVideoLoadDelegate> loadDelegate;
@property (nonatomic, weak) id <UMTRewardedVideoShowDelegate> showDelegate;

@end

NS_ASSUME_NONNULL_END
