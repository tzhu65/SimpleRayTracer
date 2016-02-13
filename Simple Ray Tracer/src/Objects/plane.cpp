//
//  plane.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <string>
#include <stdio.h>

#include "plane.h"
#include "vector.h"
#include "world.h"

using namespace std;

/*
 Just a plane.
 */

Plane::Plane() {
    position_ = Point(0.0, 0.0, 0.0);
    direction_ = Vector(0.0, 0.0, 0.0);
}

Plane::Plane(Point position, Vector direction) {
    position_ = position;
    direction_ = direction;
}

Plane::Plane(float x, float y, float z, float dx, float dy, float dz) {
    position_ = Point(x, y, z);
    direction_ = Vector(dx, dy, dz);
}

Point* Plane::getPosition() {
    return &position_;
}

Vector* Plane::getDirection() {
    return &direction_;
}

void Plane::setPosition(Point position) {
    position_ = position;
}

void Plane::setDirection(Vector direction) {
    direction_ = direction;
}

Point* Plane::checkCollision(Ray* ray, Point* point) {
    
    // Build vector from ray origin to plane point
    Vector r = World::pointDiffVector(&position_, ray->getPoint());
    r.normalize();

    float side_check = World::dotProduct(&r, &direction_);  // If negative, then on side of normal vector
    float dot_product = World::dotProduct(ray->getDirection(), &direction_);
    double theta = acos(dot_product);
    
    double ninety = (90.0 / 360.0 * 2.0 * 3.14159265);
    if ((side_check > 0 && dot_product > 0 && theta < ninety) ||
        (side_check < 0 && dot_product < 0 && theta > ninety)) {
        
        // Solving for t
        float Px = position_.getX();
        float Py = position_.getY();
        float Pz = position_.getZ();
        
        double px = direction_.getX();
        double py = direction_.getY();
        double pz = direction_.getZ();
        
        double Rx = ray->getPoint()->getX();
        double Ry = ray->getPoint()->getY();
        double Rz = ray->getPoint()->getZ();
        
        double rx = ray->getDirection()->getX();
        double ry = ray->getDirection()->getY();
        double rz = ray->getDirection()->getZ();
        
        double numerator = (Px*px + Py*py + Pz*pz - px*Rx - py*Ry - pz*Rz);
        double denominator = (px*rx + py*ry + pz*rz);
        
        double t = numerator / denominator;
        
        point->setX(Rx + t*rx);
        point->setY(Ry + t*ry);
        point->setZ(Rz + t*rz);
        
        return point;
    } else {
        return nullptr;
    }
}

// Calculates the surface normal given a point on the surface
Vector Plane::calculateNormal(Point* point) {
    return direction_;
}

string Plane::typeString() {
    return "plane object!";
}
