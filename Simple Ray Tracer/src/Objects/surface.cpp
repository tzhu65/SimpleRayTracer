//
//  surface.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <string>
#include <stdio.h>

#include "material.h"
#include "point.h"
#include "surface.h"

using namespace std;

/*
 Parent class that all world objects inherit from.
 */

Point* Surface::getPosition() {
    return &position_;
}

Material* Surface::getMaterial() {
    return &material_;
}

void Surface::setPosition(Point position) {
    position_ = position;
}

void Surface::setMaterial(Material material) {
    material_ = material;
}

Point* Surface::checkCollision(Ray* ray, Point* point) {
    return nullptr;
}

// Calculates the surface normal given a point on the surface
Vector Surface::calculateNormal(Point* point) {
    return Vector(0.0, 0.0 ,0.0);
}

string Surface::typeString() {
    return "surface object";
}
