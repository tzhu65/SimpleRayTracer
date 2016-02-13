//
//  surface.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef surface_h
#define surface_h

#include <string>

#include "material.h"
#include "point.h"
#include "material.h"
#include "ray.h"

/*
 Parent class that all world objects inherit from.
 */

class Surface {
    
private:
    Point position_;
    Material material_;
    
public:
    virtual Point* getPosition();
    Material* getMaterial();
    
    void setPosition(Point position);
    void setMaterial(Material material);
    
    virtual Point* checkCollision(Ray* ray, Point* point);
    virtual Vector calculateNormal(Point* point);
    virtual std::string typeString();
    
};

#endif /* surface_h */
