//
//  UMTAdnSDKInitConfig.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/7/11.
//

#import "UMTInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN
/// adn初始化配置信息
@interface UMTAdnSDKInitConfig : UMTInterfaceBaseObject
/// 用户自定义配置
//@property (nonatomic, strong, readonly) UMTUserConfig *userConfig;
/// 自定义拓展参数
@property (nonatomic, strong, readonly) NSString *customExtParamsStr;

/// appID
@property (nonatomic, copy, readonly) NSString *appID;

/// appKey
@property (nonatomic, copy, readonly) NSString *appKey;

/// appName
@property (nonatomic, copy, readonly) NSString *appName;
/// adn id
@property (nonatomic, assign, readonly) NSInteger adnId;
/// adn的标识
@property (nonatomic, copy, readonly) NSString *adnName;

/// 是否可用状态
@property (nonatomic, assign, readonly) BOOL valid;

/// 是否是自定义adapter，白名单用户权限
@property (nonatomic, assign, readonly) BOOL custom;

/// 自定义adapter初始化的配置类名，该类对象遵循UMTCustomConfigAdapter协议
@property (nonatomic, copy, readonly) NSString *customAdnClassName;

/// 自定义adapter banner广告的配置类名，该类对象遵循UMTCustomBannerAdapter协议
@property (nonatomic, copy, readonly) NSString *customBannerAdapterClassName;

/// 自定义adapter 插屏广告的配置类名，该类对象遵循UMTCustomInterstitialAdapter协议
@property (nonatomic, copy, readonly) NSString *customInterstitialAdapterClassName;

/// 自定义adapter 激励视频广告的配置类名，该类对象遵循UMTCustomRewardedVideoAdapter协议
@property (nonatomic, copy, readonly) NSString *customRewardedVideoAdapterClassName;

/// 自定义adapter 全屏广告的配置类名，该类对象遵循UMTCustomFullscreenVideoAdapter协议
@property (nonatomic, copy, readonly) NSString *customFullscreenVideoAdapterClassName;

/// 自定义adapter 开屏广告的配置类名，该类对象遵循UMTCustomSplashAdapter协议
@property (nonatomic, copy, readonly) NSString *customSplashAdapterClassName;

/// 自定义adapter native广告的配置类名，该类对象遵循UMTCustomNativeAdapter协议
@property (nonatomic, copy, readonly) NSString *customNativeAdapterClassName;

/// 自定义adapter draw广告的配置类名，该类对象遵循UMTCustomDrawAdapter协议
//@property (nonatomic, copy, readonly) NSString *customDrawAdapterClassName;

@end

NS_ASSUME_NONNULL_END
