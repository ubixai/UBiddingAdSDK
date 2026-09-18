//
//  UMTAdSDKManager.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/7/10.
//

#import <UBiddingAdSDK/UMTAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class UMTError;

typedef NS_ENUM(NSInteger, UMTAdSDKState) {
    /// The SDK have not start.
    UMTAdSDKStateNotStart = 0,
    /// The SDK has been started.
    UMTAdSDKStateStart = 1
};

typedef void (^UMTCompletionHandler)(BOOL success, UMTError * _Nullable error);

@interface UMTAdSDKManager : UMTInterfaceBaseObject

@property (nonatomic, copy, readonly, class, nonnull) NSString *SDKVersion;

/// The SDK state
@property (nonatomic, assign, readonly, class) UMTAdSDKState state;

+ (void)startSyncWithConfig:(UMTAdSDKConfiguration *)config completionHandler:(UMTCompletionHandler)handler;

@end

NS_ASSUME_NONNULL_END
