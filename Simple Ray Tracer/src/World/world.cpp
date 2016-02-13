//
//  world.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <cmath>
#include <stdio.h>

#include "ray.h"
#include "world.h"

using namespace std;

float World::distance(Point* a, Point* b) {
    float dx = a->getX() - b->getX();
    float dy = a->getY() - b->getY();
    float dz = a->getZ() - b->getZ();
    
    float distance = pow(pow(dx, 2) + pow(dy, 2) + pow(dz, 2), 0.5);
    return distance;
}

float World::dotProduct(Vector* a, Vector* b) {
    return (a->getX() * b->getX()) + (a->getY() * b->getY()) + (a->getZ() * b->getZ());
}

Ray World::createRay(Point* a, Point* b) {
    float dx = b->getX() - a->getX();
    float dy = b->getY() - a->getY();
    float dz = b->getZ() - a->getZ();
    
    Vector direction = Vector(dx, dy, dz);
    direction.normalize();
    
    Ray r = Ray(*a, direction);
    return r;
}

Point World::subtractPoints(Point* a, Point* b) {
    float dx = a->getX() - b->getX();
    float dy = a->getY() - b->getY();
    float dz = a->getZ() - b->getZ();
    return Point(dx, dy, dz);
}

Vector World::pointToVector(Point* a) {
    return Vector(a->getX(), a->getY(), a->getZ());
}

Vector World::pointDiffVector(Point* a, Point* b) {
    float dx = a->getX() - b->getX();
    float dy = a->getY() - b->getY();
    float dz = a->getZ() - b->getZ();
    return Vector(dx, dy, dz);
}

Vector World::addVectors(Vector* a, Vector* b) {
    float x = a->getX() + b->getX();
    float y = a->getY() + b->getY();
    float z = a->getZ() + b->getZ();
    Vector v = Vector(x, y, z);
    return v;
}
