//
//  color.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef color_h
#define color_h

/*
 RGB value
 */

class Color {
    
private:
    float r_;
    float g_;
    float b_;
    
public:
    Color();
    Color(float r, float g, float b);
    float getR();
    float getG();
    float getB();
    void setR(float r);
    void setG(float g);
    void setB(float b);
    void setValues(float r, float g, float b);
    void setColor(Color* color);
    void multiply(float f);
    void addColor(Color* c);
    void multiplyColor(Color* c);
    
};

#endif /* color_h */
