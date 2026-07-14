//
//  UMTAdLoadingParams.h
//  UBiMAXAdSDK
//
//  Created by guoqiang on 2024/12/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// UBiMAX 请求ID，NSString
extern NSString *const UMTAdLoadingParamRequestId;
/// UBiMAX 广告位ID，NSString
extern NSString *const UMTAdLoadingParamMediationSlotId;
/// ADN广告位名称，平台配置名称，NSString
extern NSString *const UMTAdLoadingParamAdnName;
/// ADN平台ID，平台生成的唯一ID，NSString
extern NSString *const UMTAdLoadingParamAdnId;
/// 当前广告源的初始化配置（UMTAdnSDKInitConfig，per-源，含 appId 等），双体系不同 appId 场景下 adapter 从中取本体系 appId
extern NSString *const UMTAdLoadingParamAdnConfig;
/// 获取竞价类型 NSNumber  1:in-app-bidding 2:waterfall
extern NSString *const UMTAdLoadingParamBiddingType;
/// 底价过滤，NSString，仅支持整数值, 单位：分
extern NSString *const UMTAdLoadingParamBidFloorPrice;
/// 是否是静音，NSNumber/NSInteger, 枚举 UMTVideoMuteType
extern NSString *const UMTAdLoadingParamVideoMute;
/// 视频播放网络控制,  NSNumber/NSInteger，枚举 UMTVideoPlayType
extern NSString *const UMTAdLoadingParamVideoPlayNet;
/// 渲染类型 NSNumber, 1: 模板，2: 自渲染
extern NSString * const UMTAdLoadingParamRenderType;
/// 超时时间，NSNumber/NSInteger, 毫秒
extern NSString *const UMTAdLoadingParamTolerateTimeout;

#pragma mark - 自定义补充

/// 自定义Adapter扩展参数， NSString，JSON格式
extern NSString *const UMTAdLoadingParamExtJson;
/// 初始化响应扩展参数字典（NSDictionary，SDK 从 initResponse.ubiddingpbExt JSON 解析而来）
extern NSString *const UMTAdLoadingParamInitExtDic;

#pragma mark - 开屏广告

/// 自定义底部视图，UIView
extern NSString *const UMTAdLoadingParamSPCustomBottomView;

#pragma mark - 插屏广告

/// 自定义扩展参数key
/// 插屏点击后是否关闭广告 NSNumber ,默认 @NO 不关闭
extern NSString *const UMTAdLoadingParamInter_CloseAfterClick;

#pragma mark - 横幅广告

/// banner的父容器
extern NSString *const UMTAdLoadingParamBannerParentView;


#pragma mark - Native广告

/// 期望广告尺寸，NSValue/CGSize
extern NSString *const UMTAdLoadingParamExpectSize;

#pragma mark - 加载回调参数，即adapter开发者通过`- ***Ad:didLoadWithExt/Fail*** ext:`中NSDictionary回调的数据

/// 【可选】Adn 广告ECPM，NSString，单位分
extern NSString *const UMTAdnAdLoadedExtECPM;
/// 【可选】Adn 广告的加载标识，NSString
extern NSString *const UMTAdnAdLoadedRequestId;

NS_ASSUME_NONNULL_END
