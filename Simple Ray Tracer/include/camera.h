//
//  camera.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef camera_h
#define camera_h

#include "point.h"
#include "ray.h"
#include "vector.h"

/*
 Perspective camera
 */

class Camera {
    
private:
    Point position_;
    Vector direction_;
    int width_;
    int height_;
    float l_;
    float r_;
    float t_;
    float b_;
    float d_;
    float x_scale_;
    float y_scale_;
    
public:
    Camera();
    Camera(Point position, Vector direction, float depth);
    Camera(float x, float y, float z, float dx, float dy, float dz, float depth);
    
    Point* getPosition();
    Vector* getDirection();
    int getPixelWidth();
    int getPixelHeight();
    float getDepth();
    
    void setPosition(Point* position);
    void setDirection(Vector* direction);
    void setDimensions(int width, int height);
    void setViewPlane(float l, float r, float t, float b);
    
    void calculateScales();
    Ray getPixelRay(float x, float y);
    
};

#endif /* camera_h */
