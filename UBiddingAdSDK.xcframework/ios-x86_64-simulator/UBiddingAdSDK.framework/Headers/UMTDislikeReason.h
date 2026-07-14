//
//  UMTDislikeReason.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/8/27.
//

#import "UMTInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface UMTDislikeReason : UMTInterfaceBaseObject
//- (instancetype)initWithID:(NSString *)ID name:(NSString *)name subReasons:(NSArray<BUMDislikeReason *> *)reasons;

@property (nonatomic, copy, readonly) NSString *ID;

@property (nonatomic, copy, readonly) NSString *name;

@property (nonatomic, copy, readonly) NSArray<UMTDislikeReason *> *subReasons;

@property (nonatomic, assign) BOOL isSelected;
@end

NS_ASSUME_NONNULL_END
