//
//  light.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef light_h
#define light_h

#include "color.h"
#include "point.h"

/*
 Illuminator
 */

class Light {
    
private:
    Point position_;
    Color color_;
    float fadeout_;
    
public:
    Light();
    Light(Point point, Color color, float fadeout);
    
    Point* getPosition();
    Color* getColor();
    float getFadeout();
    
    void setPosition(Point position);
    void setColor(Color color);
    void setFadeout(float fadeout);
    
};

#endif /* light_h */
