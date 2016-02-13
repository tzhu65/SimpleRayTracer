//
//  sphere.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef sphere_h
#define sphere_h

#include <string>

#include "point.h"
#include "surface.h"

/*
 Just a ball.
 */

class Sphere: public Surface {
    
private:
    Point position_;
    float radius_;
    
public:
    Sphere();
    Sphere(float x, float y, float z, float radius);
    
    Point* getPosition();
    float getRadius();
    
    void setPosition(Point position);
    void setRadius(float radius);
    
    Point* checkCollision(Ray* ray, Point* point);
    Vector calculateNormal(Point* point);
    std::string typeString();
    
};

#endif /* sphere_h */
