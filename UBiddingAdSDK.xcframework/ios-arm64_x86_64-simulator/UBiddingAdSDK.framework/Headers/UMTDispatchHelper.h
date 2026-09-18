//
//  UMTDispatchHelper.h
//  UBiMAXAdSDK
//
//  Copyright © 2026 UBiX. All rights reserved.
//
//  #import <UBiddingAdSDK/UMTDispatchHelper.h> 显式引用。
//

#ifndef UMTDispatchHelper_h
#define UMTDispatchHelper_h

#import <Foundation/Foundation.h>

/// 主线程安全派发:已在主线程则同步执行 block,否则异步派发到主线程。
NS_INLINE void UMTDispatchMainAsyncSafe(dispatch_block_t _Nullable block) {
    if (!block) {
        return;
    }
    if (NSThread.isMainThread) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

#endif /* UMTDispatchHelper_h */
