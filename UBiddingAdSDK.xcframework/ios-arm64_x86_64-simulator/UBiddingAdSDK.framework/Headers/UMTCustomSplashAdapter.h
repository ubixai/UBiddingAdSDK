//
//  UMTCustomSplashAdapter.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/7/11.
//

#ifndef UMTCustomSplashAdapter_h
#define UMTCustomSplashAdapter_h

#import "UMTCustomSplashAdapterBridge.h"
#import "UMTCustomAdapter.h"
#import "UMTCustomAdapterDelegate.h"

/// 开屏广告自定义实现协议
@protocol UMTCustomSplashAdapter <UMTCustomAdapterDelegate>

/// 加载开屏广告
/// @param slotID 广告位ID
/// @param parameter 广告加载参数
- (void)loadSplashAdWithSlotID:(NSString *)slotID andParameter:(NSDictionary *)parameter;

/// 展示开屏广告
/// @param window 广告展示窗口
/// @param parameter 广告展示参数
- (void)showSplashAdInWindow:(UIWindow *)window parameter:(NSDictionary *)parameter;

@optional

/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<UMTCustomSplashAdapterBridge > bridge;


@end

#endif /* UMTCustomSplashAdapter_h */
