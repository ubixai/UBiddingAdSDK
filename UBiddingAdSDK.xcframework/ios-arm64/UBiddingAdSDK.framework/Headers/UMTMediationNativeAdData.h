//
//  UMTMediationNativeAdData.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/8/27.
//

#ifndef UMTMediationNativeAdData_h
#define UMTMediationNativeAdData_h

#import "UMTImage.h"
#import "UMTDislikeReason.h"

typedef NS_ENUM (NSInteger, UMTMediationNativeAdCallToType) {
    UMTMediationNativeAdCallToTypeUnknown        = 0,
    UMTMediationNativeAdCallToTypeNone           = 1,  // pure ad display
    UMTMediationNativeAdCallToTypeURL            = 2,  // open the webpage using a browser
    UMTMediationNativeAdCallToTypePage           = 3,  // open the webpage within the app
    UMTMediationNativeAdCallToTypeDownload       = 4,  // download the app
    UMTMediationNativeAdCallToTypePhone          = 5,  // make a call
    UMTMediationNativeAdCallToTypeMessage        = 6,  // send messages
    UMTMediationNativeAdCallToTypeEmail          = 7,  // send email
    UMTMediationNativeAdCallToTypeVideoAdDetail  = 8,   // video ad details page
    UMTMediationNativeAdCallToTypeWechat = 9,          // open wechat
    UMTMediationNativeAdCallToTypeDeepLink = 10,       // deep link
    UMTMediationNativeAdCallToTypeOthers         = 100 //其他广告sdk返回的类型
};

typedef NS_ENUM (NSInteger, UMTMediationNativeAdMode) {
    UMTMediationNativeAdModeUnknown          = 00, // 未知
    UMTMediationNativeAdModeSmallImage       = 02, // 水平小图样式
    UMTMediationNativeAdModeLargeImage       = 03, // 水平大图样式
    UMTMediationNativeAdModeGroupImage       = 04, // 水平组图样式
    UMTMediationNativeAdModeLandscapeVideo   = 05, // 水平视频样式
    UMTMediationNativeAdModePortraitVideo    = 15, // 垂直视频样式
    UMTMediationNativeAdModePortraitImage    = 16, // 垂直图片样式
};

typedef UMTMediationNativeAdMode;

/// 媒体native ad数据协议，配合UMTMediationNativeAdViewCreator使用
@protocol UMTMediationNativeAdData <NSObject>

/// 广告支持的跳转类型
@property (nonatomic, assign, readonly) UMTMediationNativeAdCallToType callToType;

/// 物料图片集，如果图片有宽高，请尽量配置width和height
@property (nonatomic, copy, readonly, nullable) NSArray<UMTImage *> *imageList;

/// app类型广告的广告商app图标，如果图标有宽高，请尽量配置width和height
@property (nonatomic, strong, readonly, nullable) UMTImage *icon;

/// 广告adn的logo，如果logo有宽高，请尽量配置width和height
@property (nonatomic, strong, readonly, nullable) UMTImage *adLogo;

/// 广告标题
@property (nonatomic, copy, readonly, nullable) NSString *adTitle;

/// 广告详情描述
@property (nonatomic, copy, readonly, nullable) NSString *adDescription;

/// 应用来源、市场，例如'App Store'
@property (nonatomic, copy, readonly, nullable) NSString *source;

/// 按钮文案，例如'下载/安装'
@property (nonatomic, copy, readonly, nullable) NSString *buttonText;

/// 图片/视频模式
@property (nonatomic, assign, readonly) UMTMediationNativeAdMode imageMode;

/// app评分，区间为1-5，如果没有值返回-1
@property (nonatomic, assign, readonly) NSInteger score;

/// 评论数量，如果没有值返回-1
@property (nonatomic, assign, readonly) NSInteger commentNum;

/// 广告安装包体大小，单位KB，如果没有值返回-1
@property (nonatomic, assign, readonly) NSInteger appSize;

/// 视频时长，单位 ms，如果没有值返回0
@property (nonatomic, assign, readonly) NSInteger videoDuration;

/// 视频纵横比(width/height)，如果没有值或者异常返回0
@property (nonatomic, assign, readonly) CGFloat videoAspectRatio;

/// 媒体扩展数据
@property (nonatomic, copy, readonly, nullable) NSDictionary *mediaExt;

/// app购买价格，例如'免费'，没有则为nil
@property (nonatomic, strong, readonly, nullable) NSString *appPrice;

/// 广告商标识，广告商的名称或者链接
@property (nonatomic, copy, readonly, nullable) NSString *advertiser;

/// 品牌名称，若广告返回中无品牌名称则为空
@property (copy, nonatomic, readonly, nullable) NSString *brandName;

/// ADN提供的不喜欢广告的原因，可能为空
@property (nonatomic, copy, readonly, nullable) NSArray<UMTDislikeReason *> *dislikeReasons;

/// ADN提供的视频类型广告的资源路径，部分ADN需要申请白名单，可能为空
@property (nonatomic, copy, readonly, nullable) NSString *videoUrl;

@optional
/// be allowed to play video ad via custome player, contact BD to add to allow list.
@property (nonatomic, assign, readonly) BOOL allowCustomVideoPlayer;

/// video resolution width
@property (nonatomic, assign, readonly) NSInteger videoResolutionWidth;

/// video resolution height
@property (nonatomic, assign, readonly) NSInteger videoResolutionHeight;

/// adx name, if it exists, it is recommended to display this text
@property (nonatomic, copy, nullable) NSString *ADXName;

@end

#endif /* UMTMediationNativeAdData_h */
