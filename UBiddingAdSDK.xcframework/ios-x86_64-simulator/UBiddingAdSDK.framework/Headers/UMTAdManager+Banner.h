//
//  UMTAdManager+Banner.h
//  UMTBanner
//
//  Created by guoqiang on 2024/9/6.
//

#import <UBiddingAdSDK/UMTAdSDK.h>
#import <UBiddingAdSDK/UMTBanner.h>

NS_ASSUME_NONNULL_BEGIN

@interface UMTAdManager (Banner)

/**
  设置扩展信息
  @param extra 必须为有效的字符串格式的键值对
 */
- (void)loadBanner:(UMTBanner *)banner
             extra:(NSDictionary *)extra
          delegate:(id<UMTBannerLoadDelegate>)delegate;

- (BOOL)isReadyForBanner:(UMTBanner *)banner;

- (void)showBanner:(UMTBanner *)banner inParentView:(UIView *)parentView delegate:(id<UMTBannerShowDelegate>)delegate;


@end

NS_ASSUME_NONNULL_END
