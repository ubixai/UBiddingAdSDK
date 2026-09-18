//
//  UMTImage.h
//  UMTAdSDK
//
//  Created by guoqiang on 2024/8/27.
//

#import "UMTInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface UMTImage : UMTInterfaceBaseObject
// image.If is nil,Please use imageURL as the standard to display image.
@property (nonatomic, copy) UIImage *image;

// image address URL
@property (nonatomic, copy) NSString *imageURLStr;

@property (nonatomic, strong) NSURL *imageURL;

// image width
@property (nonatomic, assign) float width;

// image height
@property (nonatomic, assign) float height;

// image scale
@property (nonatomic, assign) float scale;
@end

NS_ASSUME_NONNULL_END
