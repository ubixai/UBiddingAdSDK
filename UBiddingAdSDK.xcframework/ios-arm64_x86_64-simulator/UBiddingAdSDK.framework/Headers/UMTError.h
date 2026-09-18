//
//  UMTError.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/8/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UMTError : NSError

+ (instancetype)errorWithCode:(NSInteger)code
                      message:(nullable NSString*)message;

@end

NS_ASSUME_NONNULL_END
