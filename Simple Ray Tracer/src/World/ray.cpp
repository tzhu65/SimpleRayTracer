//
//  ray.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <stdio.h>

#include "point.h"
#include "ray.h"
#include "vector.h"

/*
 The core ray for ray tracing.
 */

Ray::Ray() {
    point_ = Point();
    direction_ = Vector();
}

Ray::Ray(Point point, Vector direction) {
    point_ = point;
    direction_ = direction;
}

Point* Ray::getPoint() {
    return &point_;
}

Vector* Ray::getDirection() {
    return &direction_;
}

void Ray::setPoint(Point point) {
    point_ = point;
}

void Ray::setDirection(Vector direction) {
    direction_ = direction;
}
