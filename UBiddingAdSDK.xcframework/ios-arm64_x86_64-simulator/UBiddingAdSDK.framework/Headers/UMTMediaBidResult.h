//
//  UMTMediaBidResult.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/7/11.
//

#import <Foundation/Foundation.h>

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
