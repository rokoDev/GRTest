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

struct Vertex {
    float Position[2];
    float Color[4];
};

// Define the positions and colors of two triangles.
const Vertex Vertices[] = {
    {{-0.5, -0.866},    {1, 1, 0.5f, 1}},
    {{0.5, -0.866},     {1, 1, 0.5f, 1}},
    {{0, 1},            {1, 1, 0.5f, 1}},
    {{-0.5, -0.866},    {0.5f, 0.5f, 0.5f}},
    {{0.5, -0.866},     {0.5f, 0.5f, 0.5f}},
    {{0, -0.4f},        {0.5f, 0.5f, 0.5f}},
};

// Creates an instance of the renderer and sets up various OpenGL state.
struct IRenderingEngine * CreateRenderer1();
struct IRenderingEngine * CreateRenderer2();

// Interface to the OpenGL ES renderer; consumed by GLView.
struct IRenderingEngine
{
    virtual void Initialize(int width, int height) = 0;
    virtual void Render() const = 0;
    virtual void UpdateAnimation(float timeStep) = 0;
    virtual void OnRotate(DeviceOrientation newOrientation) = 0;
    virtual ~IRenderingEngine() {}
};

#endif /* IRenderingEngine_hpp */
