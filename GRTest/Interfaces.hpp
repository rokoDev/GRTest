//
//  Interfaces.hpp
//  GRTest
//
//  Created by roko on 5/14/16.
//  Copyright © 2016 roko. All rights reserved.
//

#ifndef Interfaces_hpp
#define Interfaces_hpp

#include <stdio.h>

#pragma once
#include "Vector.hpp"
#include "Quaternion.hpp"
#include <vector>
#include <string>

using std::string;

using std::vector;

struct IApplicationEngine {
    virtual void Initialize(int width, int height) = 0;
    virtual void Render() const = 0;
    virtual void UpdateAnimation(float timeStep) = 0;
    virtual void OnFingerUp(ivec2 location) = 0;
    virtual void OnFingerDown(ivec2 location) = 0;
    virtual void OnFingerMove(ivec2 oldLocation, ivec2 newLocation) = 0;
    virtual ~IApplicationEngine() {}
};

enum VertexFlags {
    VertexFlagsNormals = 1 << 0,
    VertexFlagsTexCoords = 1 << 1
};

struct ISurface {
    virtual int GetVertexCount() const = 0;
    virtual int GetLineIndexCount() const = 0;
    virtual int GetTriangleIndexCount() const = 0;
    virtual void GenerateVertices(vector<float>& vertices, unsigned char flags = 0) const = 0;
    virtual void GenerateLineIndices(vector<unsigned short>& indices) const = 0;
    virtual void GenerateTriangleIndices(vector<unsigned short>& indices) const = 0;
    virtual ~ISurface() {}
};

struct Visual { vec3 Color;
    ivec2 LowerLeft;
    ivec2 ViewportSize;
    Quaternion Orientation;
};

struct IRenderingEngine {
    virtual void Initialize(const vector<ISurface*>& surfaces) = 0;
    virtual void Render(const vector<Visual>& visuals) const = 0;
    virtual ~IRenderingEngine() {}
};

enum TextureFormat {
    TextureFormatGray,
    TextureFormatGrayAlpha,
    TextureFormatRgb,
    TextureFormatRgba
};

struct TextureDescription {
    TextureFormat Format;
    int BitsPerComponent;
    ivec2 Size;
};

struct IResourceManager {
    virtual string GetResourcePath() const = 0;
    virtual TextureDescription LoadPngImage(const string& filename) = 0;
    virtual void* GetImageData() = 0;
    virtual ivec2 GetImageSize() = 0;
    virtual void UnloadImage() = 0;
    virtual ~IResourceManager() {}
};

IResourceManager* CreateResourceManager();

IApplicationEngine* CreateApplicationEngine(IRenderingEngine* renderingEngine, IResourceManager* resourceManager);
namespace ES1 { IRenderingEngine* CreateRenderingEngine(IResourceManager* resourceManager); }
namespace ES2 { IRenderingEngine* CreateRenderingEngine(IResourceManager* resourceManager); }

#endif /* Interfaces_hpp */
