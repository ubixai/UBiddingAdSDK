//
//  UMTVideoConfig.h
//  UBiMAXAdSDK
//
//  Created by guoqiang on 2025/1/20.
//

#import "UMTInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    UMTNativeVideoAction_Start = 1, // 开始播放
    UMTNativeVideoAction_Pause,     // 暂停播放
    UMTNativeVideoAction_Resume,    // 恢复播放
    UMTNativeVideoAction_Stop,      // 停止播放
    UMTNativeVideoAction_MuteChange,// 静音变更
} UMTNativeVideoAction;

/// 是否静音，NSNumber, 1: 静音，非1: 非静音
extern NSString *const UMTVideoConfigParamKey_Mute;

@interface UMTVideoConfig : UMTInterfaceBaseObject

@end

NS_ASSUME_NONNULL_END
