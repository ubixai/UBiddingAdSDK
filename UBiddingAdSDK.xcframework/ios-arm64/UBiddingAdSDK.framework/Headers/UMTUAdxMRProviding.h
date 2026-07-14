//
//  UMTUAdxMRProviding.h
//  UBiMAXAdSDK
//
//  Copyright © 2026 UBiX. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// UADX mr 透传能力协议。
///
/// 由具备「透传 mr」能力的 adapter(当前为天璇 / Merak)遵循;UADX 侧(`UMTUAdxMRUtil`)
/// 通过本协议读取 mr,以此替代对具体 adapter 类的源码耦合与字符串反射调用。
@protocol UMTUAdxMRProviding <NSObject>

/// 解密后的透传 mr(万分比字符串,如 @"500" 表示 5%);无则 nil。
- (nullable NSString *)mrValue;

@end

NS_ASSUME_NONNULL_END
