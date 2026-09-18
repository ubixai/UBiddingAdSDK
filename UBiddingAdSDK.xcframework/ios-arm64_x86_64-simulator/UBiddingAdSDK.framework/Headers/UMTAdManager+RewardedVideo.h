//
//  UMTAdManager+RewardedVideo.h
//  UMTRewardedVideo
//
//  Created by guoqiang on 2024/9/7.
//

#import <UBiddingAdSDK/UMTAdSDK.h>
#import <UBiddingAdSDK/UMTRewardedVideo.h>

NS_ASSUME_NONNULL_BEGIN

@interface UMTAdManager (RewardedVideo)


- (void)loadRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd
                   extra:(NSDictionary *)extra
                delegate:(id<UMTRewardedVideoLoadDelegate>)delegate;

- (BOOL)isReadyForRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd;

- (void)showRewardedVideo:(UMTRewardedVideo *)rewardedVideoAd inRootVC:(UIViewController *)rootVC delegate:(id<UMTRewardedVideoShowDelegate>)delegate;



@end

NS_ASSUME_NONNULL_END
