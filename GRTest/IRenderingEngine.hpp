//
//  IRenderingEngine.hpp
//  GRTest
//
//  Created by roko on 5/6/16.
//  Copyright © 2016 roko. All rights reserved.
//

#ifndef IRenderingEngine_hpp
#define IRenderingEngine_hpp

#include <stdio.h>

// Physical orientation of a handheld device, equivalent to UIDeviceOrientation.
enum DeviceOrientation {
    DeviceOrientationUnknown,
    DeviceOrientationPortrait,
    DeviceOrientationPortraitUpsideDown,
    DeviceOrientationLandscapeLeft,
    DeviceOrientationLandscapeRight,
    DeviceOrientationFaceUp,
    DeviceOrientationFaceDown,
};

// Interface to the OpenGL ES renderer; consumed by GLView.
struct IRenderingEngine
{
    virtual void Initialize(int width, int height) = 0;
    virtual void Render() const = 0;
    virtual void UpdateAnimation(float timeStep) = 0;
    virtual void OnRotate(DeviceOrientation newOrientation) = 0;
    virtual ~IRenderingEngine() {}
};

// Creates an instance of the renderer and sets up various OpenGL state.
struct IRenderingEngine * CreateRenderer1();

#endif /* IRenderingEngine_hpp */
