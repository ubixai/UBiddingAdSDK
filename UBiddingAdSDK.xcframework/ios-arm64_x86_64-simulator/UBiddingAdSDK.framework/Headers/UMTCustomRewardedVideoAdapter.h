//
//  UMTCustomRewardedVideoAdapter.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/9/7.
//

#ifndef UMTCustomRewardedVideoAdapter_h
#define UMTCustomRewardedVideoAdapter_h

#import <UBiddingAdSDK/UMTAdSDK.h>

@protocol UMTCustomRewardedVideoAdapterBridge;

/// 自定义激励视频广告的adapter广告协议
@protocol UMTCustomRewardedVideoAdapter <UMTCustomAdapterDelegate>

/// 加载广告的方法
/// @param slotID adn的广告位ID
/// @param parameter 广告加载的参数
- (void)loadRewardedVideoAdWithSlotID:(NSString *)slotID andParameter:(NSDictionary *)parameter;

/// 展示广告的方法
/// @param viewController 控制器对象
/// @param parameter 展示广告的参数，接入媒体配置
- (void)showAdFromRootViewController:(UIViewController *_Nonnull)viewController parameter:(NSDictionary *)parameter;


@optional
/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<UMTCustomRewardedVideoAdapterBridge> bridge;

/// 回调信息补充
@property (nonatomic, copy, nullable, readonly) NSDictionary *extroInfoMap;

@end

#endif /* UMTCustomRewardedVideoAdapter_h */
