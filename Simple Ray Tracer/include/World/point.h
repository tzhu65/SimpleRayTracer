//
//  point.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef Point_h
#define Point_h

/*
 3D point in the Cartesian coordinate system.
 */

class Point {
    
private:
    float x_;
    float y_;
    float z_;
    
public:
    Point();
    Point(float x, float y, float z);
    float getX();
    float getY();
    float getZ();
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    
};

#endif /* point_h */
