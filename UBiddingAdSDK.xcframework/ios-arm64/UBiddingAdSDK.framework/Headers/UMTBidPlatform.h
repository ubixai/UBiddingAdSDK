//
//  UMTBidPlatform.h
//  UMTAdSDK
//
//  竞价回传：竞胜方平台 id
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, UMTBidPlatform) {
    UMTBidPlatformUnknown    = 0,
    UMTBidPlatformUBiX       = 1,   // UBiX 聚合
    UMTBidPlatformGDT        = 2,   // 优量汇
    UMTBidPlatformKuaiShou   = 3,   // 快手
    UMTBidPlatformBaidu      = 4,   // 百度
    UMTBidPlatformGromore    = 5,   // Gromore
    UMTBidPlatformPangle     = 6,   // 穿山甲
    UMTBidPlatformQuMeng     = 7,   // 趣盟
    UMTBidPlatformTopOn      = 8,   // TopOn
    UMTBidPlatformFancy      = 9,   // Fancy
    UMTBidPlatformMeiShu     = 10,  // 美数
    UMTBidPlatformBeiZi      = 11,  // 倍孜
    UMTBidPlatformWangMai    = 12,  // 旺脉
    UMTBidPlatformUBiXMerak  = 16,  // 天璇
};
