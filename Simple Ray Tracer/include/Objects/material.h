//
//  material.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef material_h
#define material_h

#include "color.h"

/*
 Describes the color/shading of a surface
 */

class Material {
    
private:
    Color ka_;
    Color kd_;
    Color ks_;
    float specular_power_;
    
public:
    Material();
    Material(Color ka, Color kd, Color ks, float specular_power);
    
    Color* getKa();
    Color* getKd();
    Color* getKs();
    float getSpecularPower();
    
    void setKa(Color ka);
    void setKd(Color kd);
    void setKs(Color ks);
    void setSpecularPower(float specular_power);
    void setValues(Color ka, Color kd, Color ks, float specular_power);
    
};

#endif /* material_h */
