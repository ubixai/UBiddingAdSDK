//
//  UMTDispatchHelper.h
//  UBiMAXAdSDK
//
//  Copyright © 2026 UBiX. All rights reserved.
//
//  内部工具头:不收入对外伞头 UMTAdSDK.h,仅供 adapter 等通过
//  #import <UBiddingAdSDK/UMTDispatchHelper.h> 显式引用。
//

#ifndef UMTDispatchHelper_h
#define UMTDispatchHelper_h

#import <Foundation/Foundation.h>

/// 主线程安全派发:已在主线程则同步执行 block,否则异步派发到主线程。
/// 用于把广告对象创建 / show / destroy 等主线程相关操作收口,替代散落的
/// `dispatch_async(dispatch_get_main_queue(), ...)`,并省去已在主线程时多余的 runloop 跳转。
/// 注意与无条件 dispatch_async 的差异:在主线程会「同步立即」执行(可能在当前调用栈内完成)。
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
