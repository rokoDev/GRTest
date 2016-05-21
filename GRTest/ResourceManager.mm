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
    
    void LoadPngImage(const string& name)
    {
        NSString* basePath = [NSString stringWithUTF8String:name.c_str()];
        NSString* resourcePath = [[NSBundle mainBundle] resourcePath];
        NSString* fullPath = [resourcePath stringByAppendingPathComponent:basePath];
        UIImage* uiImage = [UIImage imageWithContentsOfFile:fullPath];
        CGImageRef cgImage = uiImage.CGImage;
        m_imageSize.x = CGImageGetWidth(cgImage);
        m_imageSize.y = CGImageGetHeight(cgImage);
        m_imageData = CGDataProviderCopyData(CGImageGetDataProvider(cgImage));
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
