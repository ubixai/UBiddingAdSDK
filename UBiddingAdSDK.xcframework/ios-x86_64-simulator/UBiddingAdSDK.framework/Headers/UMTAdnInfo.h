//
//  UMTAdnInfo.h
//  UBiMAXAdSDK
//
//  Created by guoqiang on 2025/1/16.
//

#import "UMTInterfaceBaseObject.h"
#import "UMTGlobalDefine.h"
#import "UMTAdSDKConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

///  adn 扩展参数 子平台名称,
///  仅支持 UBiXAdx
extern NSString *const UMTAdnExtraParam_PlatformName;
///  adn 扩展参数 子平台广告位,
///  仅支持 UBiXAdx
extern NSString *const UMTAdnExtraParam_PlatformSlotId;
///  adn 扩展参数 广告位,
///  仅支持 UBiXAdx
extern NSString *const UMTAdnExtraParam_SlotId;


@interface UMTAdnInfo : UMTInterfaceBaseObject

@property (nonatomic, copy, readonly) NSString *adnId;

@property (nonatomic, copy, readonly) NSString *adnName;

@property (nonatomic, copy, readonly) NSString *adnSlotId;

@property (nonatomic, assign) uint64_t price;

@property (nonatomic, assign, readonly) int64_t signedPrice;

@property (nonatomic, strong) NSDictionary *extraParams;

/// 竞价类型 (1=ClientBidding, 2=Waterfall)
@property (nonatomic, assign, readonly) NSInteger adnBiddingType;

/// 瀑布流层级索引
@property (nonatomic, assign, readonly) NSInteger adnWaterfallIndex;

/// 流量分组 ID
@property (nonatomic, copy, readonly, nullable) NSString *trafficGroupId;

/// 广告 eCPM 价格（单位：分）
@property (nonatomic, assign, readonly) uint64_t ecpm;

/// 广告 eCPM signed 价格（单位：分）
@property (nonatomic, assign, readonly) int64_t signedEcpm;

/// 请求 ID
@property (nonatomic, copy, readonly, nullable) NSString *requestId;

/// 聚合广告位 ID
@property (nonatomic, copy, readonly, nullable) NSString *adSlotId;

/// 广告类型
@property (nonatomic, assign, readonly) UMTAdType adType;

/// 用户信息配置
@property (nonatomic, copy, readonly, nullable) UMTUserInfoConfig *userInfoConfig;

/// ABTest ID
@property (nonatomic, copy, readonly, nullable) NSString *abTestId;

/// 扩展数据
@property (nonatomic, copy, readonly, nullable) NSString *extraData;

/// 竞价底价（单位：分）
@property (nonatomic, assign, readonly) uint64_t bidFloor;

/// 广告源广告类型
@property (nonatomic, assign, readonly) UMTAdType adnAdType;

/// 竞价时机 (1=竞价前渲染, 2=竞价后渲染)
@property (nonatomic, assign, readonly) NSInteger bidMoment;

@end

NS_ASSUME_NONNULL_END
