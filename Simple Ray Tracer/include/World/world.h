//
//  world.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef world_h
#define world_h

#include "point.h"
#include "ray.h"
#include "vector.h"

/*
 Helper class that performs calculations in real coordinates
 */

class World {
    
public:
    float static distance(Point* a, Point* b);
    float static dotProduct(Vector* a, Vector* b);
    Ray static createRay(Point* a, Point* b);
    Point static subtractPoints(Point* a, Point* b);
    Vector static pointToVector(Point* a);
    Vector static pointDiffVector(Point* a, Point* b);
    Vector static addVectors(Vector* a, Vector* b);
    
};

#endif /* world_h */
