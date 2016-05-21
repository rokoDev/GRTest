//
//  ResourceManager.m
//  GRTest
//
//  Created by roko on 5/18/16.
//  Copyright © 2016 roko. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h> 
#import <string>
#import <iostream>
#import "Interfaces.hpp"

using namespace std;

class ResourceManager : public IResourceManager {
public:
    string GetResourcePath() const
    {
        NSString* bundlePath = [[NSBundle mainBundle] resourcePath];
        return [bundlePath UTF8String];
    }
    
    TextureDescription LoadPngImage(const string& name)
    {
        NSString* basePath = [NSString stringWithUTF8String:name.c_str()];
        NSString* resourcePath = [[NSBundle mainBundle] resourcePath];
        NSString* fullPath = [resourcePath stringByAppendingPathComponent:basePath];
        
        NSLog(@"Loading PNG image %@...", fullPath);
        
        UIImage* uiImage = [UIImage imageWithContentsOfFile:fullPath];
        CGImageRef cgImage = uiImage.CGImage;
        m_imageData = CGDataProviderCopyData(CGImageGetDataProvider(cgImage));
        
        TextureDescription description;
        description.Size.x = CGImageGetWidth(cgImage);
        description.Size.y = CGImageGetHeight(cgImage);
        bool hasAlpha = CGImageGetAlphaInfo(cgImage) != kCGImageAlphaNone;
        CGColorSpaceRef colorSpace = CGImageGetColorSpace(cgImage);
        switch (CGColorSpaceGetModel(colorSpace)) {
            case kCGColorSpaceModelMonochrome:
                description.Format = hasAlpha ? TextureFormatGrayAlpha : TextureFormatGray;
                break;
            case kCGColorSpaceModelRGB: description.Format = hasAlpha ? TextureFormatRgba : TextureFormatRgb;
                break;
            default:
                assert(!"Unsupported color space.");
                break;
        }
        
        description.BitsPerComponent = CGImageGetBitsPerComponent(cgImage);
        
        return description;
    }
    
    void* GetImageData()
    {
        return (void*) CFDataGetBytePtr(m_imageData);
    }
    
    ivec2 GetImageSize()
    {
        return m_imageSize;
    }
    
    void UnloadImage()
    {
        CFRelease(m_imageData);
    }
    
private:
    CFDataRef m_imageData;
    ivec2 m_imageSize;};

IResourceManager* CreateResourceManager()
{
    return new ResourceManager();
}
