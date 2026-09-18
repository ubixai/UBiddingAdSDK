//
//  UMTAdManager+Native.h
//  UMTNative
//
//  Created by guoqiang on 2024/8/26.
//

#import <UBiddingAdSDK/UMTAdSDK.h>
#import <UBiddingAdSDK/UMTNative.h>

NS_ASSUME_NONNULL_BEGIN

@interface UMTAdManager (Native)

- (void)loadNativeAd:(UMTNative *)native extra:(NSDictionary *)extra delegate:(id<UMTNativeLoadDelegate>)delegate;

- (BOOL)isReadyForNative:(UMTNative *)native;

//- (void)showNative:(UMTNative *)native delegate:(id<UMTNativeDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
