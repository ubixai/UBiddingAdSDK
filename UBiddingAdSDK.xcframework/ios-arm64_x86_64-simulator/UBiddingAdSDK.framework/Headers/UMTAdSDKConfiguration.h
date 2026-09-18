//
//  UMTAdSDKConfiguration.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/7/10.
//

#import <Foundation/Foundation.h>
#import <UBiddingAdSDK/UMTInterfaceBaseObject.h>

NS_ASSUME_NONNULL_BEGIN

/// 付费用户, 0: 未知；1: 否；2: 是
typedef NS_ENUM (int, UMTUserInfoSubscribe) {
    UMTUserInfoSubscribe_Unknown              = 0,
    UMTUserInfoSubscribe_No                   = 1,
    UMTUserInfoSubscribe_Yes                  = 2,
};

@interface UMTUserInfoConfig : UMTInterfaceBaseObject
/// 用户在媒体上注册的 ID
@property (nonatomic, copy) NSString *userId;
/// 渠道，字符的规则：[A-Za-z0-9_]
@property (nonatomic, copy) NSString *channel;
/// 子渠道， 字符的规则：[A-Za-z0-9_]
@property (nonatomic, copy) NSString *subChannel;
/// 付费用户, 0: 未知；1: 否；2: 是
@property (nonatomic, assign) UMTUserInfoSubscribe isSubscriber;
/// 流量分组ID或者标签ID
@property (nonatomic, copy) NSString *pubSegmentId;

@end

extern NSString *const kUMTExtraMap_StorageSpaceEnabled;

@interface UMTAdSDKConfiguration : NSObject

+ (instancetype)configuration NS_SWIFT_NAME(configuration());

///Register the App key that’s already been applied before requesting an ad from Network.
/// the unique identifier of the App
@property (nonatomic, copy, nullable) NSString *appID;
/**  是否允许用户读取网络状态信息， 默认允许  **/
@property (nonatomic, assign) BOOL canReadNetType;
/**  是否允许用户读取定位信息， 默认不允许  **/
@property (nonatomic, assign) BOOL locationEnabled;
/**  是否允许用户读取idfa， 默认不允许  **/
@property (nonatomic, assign) BOOL canReadIDFA;
/** 用户不允许读取idfa，需传入自定义值 */
@property (nonatomic, copy, nullable) NSString *customIDFA;
/**  是否限制个性化广告推荐 默认不限制   **/
@property (nonatomic, assign) BOOL limitPersonalAds;
/**  是否打开日志模式，默认不打开  **/
@property (nonatomic, assign) BOOL debugLogEnabled;
/**  传感器是否生效，默认打开:YES  **/
@property (nonatomic, assign) BOOL sensorEnabled;

/// 开发者是否自行渲染信息流摇一摇提示视图，默认 NO（由 SDK 托管兜底）。
/// true 仅代表开发者声明自行渲染；SDK 信任声明，不检查布局、不兜底。
/// 对不允许开发者替换的广告源（优量汇、聚推、趣盟、百度）不改变既定策略。
/// 注意⚠️：加载前传入，能同时影响广告源请求参数和后续挂载。
@property (nonatomic, assign) BOOL developerRenderShakeView;

/**
  设置扩展信息
  已支持的key有：
 kUMTExtraMap_StorageSpaceEnabled, 是否允许获取可用存储空间大小：，默认开启，值为字符串格式，"0"：不可获取；非"0"：可以获取
 */
@property (nonatomic,strong) NSDictionary <NSString *, NSString *> *extraMap;
// 流量分组信息配置
@property (nonatomic, strong) UMTUserInfoConfig *userInfoConfig;

@end

NS_ASSUME_NONNULL_END
