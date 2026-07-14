//
//  UMTMediaBidResult.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/7/11.
//

#import <Foundation/Foundation.h>

// UMTBidLossType 定义在伞头 import 之前：外部头依赖本枚举，而伞头会回头 import 这些头，
// 若枚举放在伞头 import 之后会成环 —— 其它头的 @interface 在本枚举就绪前被编译，报 unknown type。
// 枚举原始值与安卓 BidLossReasons / proto loss_reason 口径对齐（1-6 同号）：媒体在
// didReceiveBidResult 收到的 result.lossType 即此口径，与埋点 ubidding_bid_loss_reason 一致。
// ⚠️ 无 0 值：adn.lossReason 默认 Other(6) 由 loadAdnAdWith 显式重置（UMTAdReqBaseService.m），
// 不再依赖零值初始化——改这里务必同步赋默认值的地方。
typedef enum : NSUInteger {
    /// 底价过滤
    UMTBidLossTypePriceFilter = 1,
    /// 广告出价低于最高价（竞价失败）
    UMTBidLossTypeNormal = 2,
    /// 广告返回超时
    UMTBidLossTypeTimeout = 3,
    /// 素材屏蔽 / 审核未通过
    UMTBidLossTypeMaterialBlocked = 4,
    /// 广告失效或过期
    UMTBidLossTypeExpired = 5,
    /// 其他/未知（兜底）
    UMTBidLossTypeOther = 6,

} UMTBidLossType;

#import <UBiddingAdSDK/UMTAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface UMTMediaBidResult : UMTInterfaceBaseObject
@property (nonatomic, assign) BOOL win;

@property (nonatomic, assign, readonly) int64_t winnerPrice;

@property (nonatomic, assign, readonly) BOOL hasWinnerPrice;

@property (nonatomic, assign, readonly) int64_t secondPrice;

@property (nonatomic, assign, readonly) BOOL hasSecondPrice;

@property (nonatomic, copy, readonly) NSString *lossDescription;

@property (nonatomic, assign, readonly) UMTBidLossType lossType;

@property (nonatomic, copy, readonly) NSString *winnerAdnID;

@property (nonatomic, copy, readonly) NSDictionary *ext;

@property (nonatomic, strong, readonly) id originNativeAdData;

/// 竞胜方广告主名（选填，仅部分广告源提供，见技术方案物料可得性）
@property (nonatomic, copy, readonly, nullable) NSString *winAdSource;

/// 竞胜方标题（选填）
@property (nonatomic, copy, readonly, nullable) NSString *winAdTitle;

@end

NS_ASSUME_NONNULL_END
