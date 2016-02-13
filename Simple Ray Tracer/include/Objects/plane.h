//
//  plane.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef plane_h
#define plane_h

#include <string>

#include "point.h"
#include "surface.h"
#include "vector.h"

/*
 Just a plane.
 */

class Plane: public Surface {
    
private:
    Point position_;
    Vector direction_;
    
public:
    Plane();
    Plane(Point position, Vector direction);
    Plane(float x, float y, float z, float dx, float dy, float dz);
    
    Point* getPosition();
    Vector* getDirection();
    
    void setPosition(Point position);
    void setDirection(Vector direction);
    
    Point* checkCollision(Ray* ray, Point* point);
    Vector calculateNormal(Point* point);
    std::string typeString();
    
};

#endif /* plane_h */
