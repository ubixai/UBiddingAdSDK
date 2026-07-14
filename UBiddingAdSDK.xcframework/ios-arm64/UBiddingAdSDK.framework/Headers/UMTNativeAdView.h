//
//  UMTNativeAdView.h
//  UMTNative
//
//  Created by guoqiang on 2024/8/27.
//

#import <UIKit/UIKit.h>
#import <UBiddingAdSDK/UMTMediationNativeAd.h>
#import <UBiddingAdSDK/UMTMediationNativeAdData.h>

NS_ASSUME_NONNULL_BEGIN



@protocol UMTNativeAdViewProtocol <NSObject>

/// 广告标题，需要开发者根据广告物料自己指定展示内容
@property (nonatomic, strong, readonly, nonnull) UILabel *titleLabel;

/// 广告描述，需要开发者根据广告物料自己指定展示内容
@property (nonatomic, strong, readonly, nonnull) UILabel *descLabel;

/// 广告图标，可能不存在，需要开发者根据广告物料自己指定展示内容
@property (nonatomic, strong, nullable) UIImageView *iconImageView;

/// 广告大图，需要开发者根据广告物料自己指定展示内容，系统会自动创建，但内容需开发者自行校验
@property (nonatomic, strong, readonly, nonnull) UIImageView *imageView;

/// Ad CTA button. Need to be assigned from a data(BUMMaterialMeta), and need to be add to self(BUMNativeAdView).

/// 广告详情/下载按钮，可能不存在，文案内容需要开发者根据广告物料自己获取
@property (nonatomic, strong, readonly, nonnull) UIButton *callToActionBtn;

/// 广告商视图，可能不存在，开发者可自行赋值处理
@property (nonatomic, strong, nullable) UIView *advertiserView;

/// 广告关闭按钮，可能不存在，开发者需自行处理响应事件
@property (nonatomic, strong, nullable) UIButton *dislikeBtn;

/// 广告LOGO视图，可能不存在，需要开发者根据广告物料自己指定展示内容
@property (nonatomic, strong, nullable) UIView *adLogoView;

/// 媒体视图，即视频广告的视频图层，非视频广告不存在该视图
@property (nonatomic, strong, readonly, nullable) UIView *mediaView;


@end

@interface UMTNativeAdView : UIView <UMTNativeAdViewProtocol>
/// 模板广告视图
@property (nonatomic, strong) UIView *adxExpressView;
/// 广告视图唯一标识
@property (nonatomic, copy, readonly) NSString *adViewId;

- (instancetype)initWithNativeAd:(UMTMediationNativeAd *)nativeAd;

- (instancetype)initWithAdxExpressView:(UIView *)expressV;

/// 非模板Native广告的物料数据，模板广告时为nil
@property (nonatomic, strong, readonly, nullable) UMTMediationNativeAd *native;

@end


NS_ASSUME_NONNULL_END
