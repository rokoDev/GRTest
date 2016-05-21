//
//  ParametricSurface.hpp
//  GRTest
//
//  Created by roko on 5/14/16.
//  Copyright © 2016 roko. All rights reserved.
//

#ifndef ParametricSurface_hpp
#define ParametricSurface_hpp

#include <stdio.h>
#include "Interfaces.hpp"

struct ParametricInterval {
    ivec2 Divisions;
    vec2 UpperBound;
    vec2 TextureCount;
};

class ParametricSurface : public ISurface
{
public:
    int GetVertexCount() const;
    int GetLineIndexCount() const;
    int GetTriangleIndexCount() const;
    void GenerateVertices(vector<float>& vertices, unsigned char flags) const;
    void GenerateLineIndices(vector<unsigned short>& indices) const;
    void GenerateTriangleIndices(vector<unsigned short>& indices) const;
    
protected:
    void SetInterval(const ParametricInterval& interval);
    virtual vec3 Evaluate(const vec2& domain) const = 0;
    virtual bool InvertNormal(const vec2& domain) const { return false; }
    
private:
    vec2 ComputeDomain(float i, float j) const;
    vec2 m_upperBound;
    ivec2 m_slices;
    ivec2 m_divisions;
    vec2 m_textureCount;
};

#endif /* ParametricSurface_hpp */
