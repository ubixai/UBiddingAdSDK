//
//  UMTUAdxMRProviding.h
//  UBiMAXAdSDK
//
//  Copyright © 2026 UBiX. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UMTUAdxMRProviding <NSObject>

/// 万分比字符串,如 @"500" 表示 5%;无则 nil。
- (nullable NSString *)mrValue;

@end

NS_ASSUME_NONNULL_END
