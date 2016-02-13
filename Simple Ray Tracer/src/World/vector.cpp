//
//  vector.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <cmath>
#include <stdio.h>

#include "vector.h"

using namespace std;

Vector::Vector() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}

Vector::Vector(float x, float y, float z) {
    x_ = x;
    y_ = y;
    z_ = z;
}

float Vector::getX() {
    return x_;
}

float Vector::getY() {
    return y_;
}

float Vector::getZ() {
    return z_;
}

void Vector::setX(float x) {
    x_ = x;
}

void Vector::setY(float y) {
    y_ = y;
}

void Vector::setZ(float z) {
    z_ = z;
}

void Vector::normalize() {
    float distance = pow(pow(x_, 2) + pow(y_, 2) + pow(z_, 2), 0.5);
    x_ = x_ / distance;
    y_ = y_ / distance;
    z_ = z_ / distance;
}
