//
//  point.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <stdio.h>

#include "point.h"

/*
 3D point in the Cartesian coordinate system.
 */

Point::Point() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}

Point::Point(float x, float y, float z) {
    x_ = x;
    y_ = y;
    z_ = z;
}

float Point::getX() {
    return x_;
}

float Point::getY() {
    return y_;
}

float Point::getZ() {
    return z_;
}

void Point::setX(float x) {
    x_ = x;
}

void Point::setY(float y) {
    y_ = y;
}

void Point::setZ(float z) {
    z_ = z;
}
