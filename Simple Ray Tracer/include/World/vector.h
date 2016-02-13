//
//  vector.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef vector_h
#define vector_h

/*
 Vector that describes a direction starting from the origin
 */

class Vector {
    
private:
    float x_;
    float y_;
    float z_;
    
public:
    Vector();
    Vector(float x, float y, float z);
    float getX();
    float getY();
    float getZ();
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void normalize();
    
};

#endif /* vector_h */
