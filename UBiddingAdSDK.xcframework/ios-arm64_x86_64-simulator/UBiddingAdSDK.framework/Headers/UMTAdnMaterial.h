//
//  UMTAdnMaterial.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/8/16.
//

#import "UMTInterfaceBaseObject.h"
#import "UMTGlobalDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface UMTAdnMaterial : UMTInterfaceBaseObject
// 素材url
@property (nonatomic, copy) NSString *materialUrl;
// 视频封面
@property (nonatomic, copy) NSString *coverImgUrl;
// md5
@property (nonatomic, copy) NSString *materialId;

@property (nonatomic, assign) UMTAdnMaterialType materialType;

@property (nonatomic, copy) NSString *rulersId;

/// 素材高度（px），图片和视频共用
@property (nonatomic, assign) int32_t height;
/// 素材宽度（px），图片和视频共用
@property (nonatomic, assign) int32_t width;
/// 视频时长（ms），仅视频有效
@property (nonatomic, assign) int32_t duration;

@end

NS_ASSUME_NONNULL_END
