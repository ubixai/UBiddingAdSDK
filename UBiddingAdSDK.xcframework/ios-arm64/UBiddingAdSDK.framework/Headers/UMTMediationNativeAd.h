//
//  UMTMediationNativeAd.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/8/27.
//

#import "UMTInterfaceBaseObject.h"
#import "UMTMediationNativeAdData.h"
#import "UMTMediationNativeAdViewCreator.h"

NS_ASSUME_NONNULL_BEGIN

@interface UMTMediationNativeAd : UMTInterfaceBaseObject
// 广告物料，包含有最全的广告数据
@property (nonatomic, strong, nonnull) id<UMTMediationNativeAdData> adData;

// 广告视图创建对象，对常用广告展示元素进行创建（存在意义：对部分adn创建特定视图的支持）
@property (nonatomic, strong, nonnull) id<UMTMediationNativeAdViewCreator> viewCreator;

// 广告视图对象（存在意义：对部分adn创建特定视图的支持）
@property (nonatomic, strong, nonnull) UIView *view;

@property (nonatomic, assign, readonly) BOOL isVideoAd;

// adn获取到的原始广告数据
@property (nonatomic, strong, nonnull) id originMediatedNativeAd;
@end

NS_ASSUME_NONNULL_END
