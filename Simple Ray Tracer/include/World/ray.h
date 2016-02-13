//
//  ray.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef ray_h
#define ray_h

#include "point.h"
#include "vector.h"

/*
 The core ray for ray tracing.
 */

class Ray {
    
private:
    Point point_;
    Vector direction_;
    
public:
    Ray();
    Ray(Point point, Vector direction);
    Point* getPoint();
    Vector* getDirection();
    void setPoint(Point point);
    void setDirection(Vector direction);
    
};

#endif /* ray_h */
