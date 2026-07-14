//
//  UMTAdSDKConfiguration.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/7/10.
//

#import <Foundation/Foundation.h>
#import <UBiddingAdSDK/UMTInterfaceBaseObject.h>
#import <CoreLocation/CoreLocation.h>

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
#if __has_include(<CoreLocation/CoreLocation.h>)
/** 允许用户传递定位信息，如果用户传递了此值，则聚合SDK不再进行该值的获取 */
@property (nonatomic, assign)CLLocationDegrees latitude;
@property (nonatomic, assign)CLLocationDegrees longitude;
#endif
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
