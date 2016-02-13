//
//  sphere.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <string>
#include <stdio.h>

#include "point.h"
#include "sphere.h"
#include "world.h"

using namespace std;

/*
 Just a ball.
 */

Sphere::Sphere() {
    position_ = Point(0.0, 0.0, 0.0);
    radius_ = 0.0;
}

Sphere::Sphere(float x, float y, float z, float radius) {
    position_ = Point(x, y, z);
    radius_ = radius;
}

Point* Sphere::getPosition() {
    return &position_;
}

float Sphere::getRadius() {
    return radius_;
}

void Sphere::setPosition(Point position) {
    position_ = position;
}

void Sphere::setRadius(float radius) {
    radius_ = radius;
}

Point* Sphere::checkCollision(Ray* ray, Point* point) {
    
    // Draw ray from center of the sphere to the ray origin
    Point L = World::subtractPoints(&position_, ray->getPoint());
    Vector l = World::pointToVector(&L);
    
    float h = World::distance(&position_, ray->getPoint());
    float a = World::dotProduct(&l, ray->getDirection());
    float new_r = pow(pow(h, 2) - pow(a, 2), 0.5);
    
    if (new_r < radius_) {
        
        // Calculate the intersection point
        float a_small = pow(pow(radius_, 2) - pow(new_r, 2), 0.5);
        float d = a - a_small;  // Distance till the intersection point
        
        float x = ray->getDirection()->getX() * d + ray->getPoint()->getX();
        float y = ray->getDirection()->getY() * d + ray->getPoint()->getY();
        float z = ray->getDirection()->getZ() * d + ray->getPoint()->getZ();

        // Make sure the sphere is on the correct side of the ray
        double x_dir = (x - ray->getPoint()->getX()) / ray->getDirection()->getX();
        double y_dir = (y - ray->getPoint()->getY()) / ray->getDirection()->getY();
        double z_dir = (z - ray->getPoint()->getZ()) / ray->getDirection()->getZ();
        if (x_dir < 0 || y_dir < 0 || z_dir < 0) {
            return nullptr;
        }
        
        // Set the point
        point->setX(x);
        point->setY(y);
        point->setZ(z);
        
        return point;
    } else {
        
        // Outside the bounds of the circle
        return nullptr;
    }
}

// Calculates the surface normal given a point on the surface
Vector Sphere::calculateNormal(Point* point) {
    Point p = World::subtractPoints(point, &position_);
    Vector d = World::pointToVector(&p);
    return d;
}

string Sphere::typeString() {
    return "sphere object!";
}
