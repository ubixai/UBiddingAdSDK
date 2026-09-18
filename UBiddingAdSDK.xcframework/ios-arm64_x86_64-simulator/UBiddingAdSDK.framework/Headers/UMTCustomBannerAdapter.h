//
//  UMTCustomBannerAdapter.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/9/6.
//

#ifndef UMTCustomBannerAdapter_h
#define UMTCustomBannerAdapter_h

#import "UMTCustomBannerAdapterBridge.h"
#import "UMTCustomAdapter.h"
#import "UMTCustomAdapterDelegate.h"

/// 自定义横幅广告的adapter广告协议
@protocol UMTCustomBannerAdapter <UMTCustomAdapterDelegate>

/// 加载广告的方法
/// @param slotID adn的广告位ID
/// @param size 广告展示尺寸
/// @param parameter 广告加载的参数
- (void)loadBannerAdWithSlotID:(NSString *)slotID andSize:(CGSize)size parameter:(NSDictionary *)parameter;

/// 展示广告的方法
/// @param parentView 父视图
/// @param parameter 展示广告的参数，由UbiXM接入媒体配置
- (void)showBannerAdInParentView:(UIView *)parentView parameter:(NSDictionary *)parameter;


@optional
/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<UMTCustomBannerAdapterBridge> bridge;

@end

#endif /* UMTCustomBannerAdapter_h */
