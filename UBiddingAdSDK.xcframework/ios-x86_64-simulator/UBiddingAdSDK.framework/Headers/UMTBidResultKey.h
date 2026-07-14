//
//  UMTBidResultKey.h
//  UMTAdSDK
//
//  段1 媒体竞价回传 sendBiddingWin/LossWithInfo: 的字典 key（值定义在 .m，接入方用常量）。
//

#import <Foundation/Foundation.h>

/// 竞胜：次高价 NSNumber(分)
FOUNDATION_EXPORT NSString *const UMTBidResultKeySecondPrice;
/// 竞败：竞胜方最高价 NSNumber(分)
FOUNDATION_EXPORT NSString *const UMTBidResultKeyWinnerPrice;
/// 竞败：竞胜方平台 id NSNumber(UMTBidPlatform)
FOUNDATION_EXPORT NSString *const UMTBidResultKeyWinnerPlatform;
/// 竞败：竞败原因 NSNumber(UMTBidLossType)
FOUNDATION_EXPORT NSString *const UMTBidResultKeyLossType;
/// 竞败：竞胜方广告主名 NSString(选填)
FOUNDATION_EXPORT NSString *const UMTBidResultKeyWinAdSource;
/// 竞败：竞胜方标题 NSString(选填)
FOUNDATION_EXPORT NSString *const UMTBidResultKeyWinAdTitle;
