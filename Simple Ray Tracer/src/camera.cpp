//
//  camera.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/13/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <stdio.h>

#include "camera.h"
#include "point.h"
#include "vector.h"
#include "ray.h"

/*
 Perspective camera
 */

Camera::Camera() {
    position_ = Point();
    direction_ = Vector();
    width_ = 0;
    height_ = 0;
    l_ = 0;
    r_ = 0;
    t_ = 0;
    b_ = 0;
    d_ = 0;
    x_scale_ = 0;
    y_scale_ = 0;
}

Camera::Camera(Point position, Vector direction, float depth) {
    position_ = position;
    direction_ = direction;
    width_ = 0;
    height_ = 0;
    l_ = 0;
    r_ = 0;
    t_ = 0;
    b_ = 0;
    d_ = depth;
    x_scale_ = 0;
    y_scale_ = 0;
    direction_.normalize();
}

Camera::Camera(float x, float y, float z, float dx, float dy, float dz, float depth) {
    position_ = Point(x, y, z);
    direction_ = Vector(dx, dy, dz);
    width_ = 0;
    height_ = 0;
    l_ = 0;
    r_ = 0;
    t_ = 0;
    b_ = 0;
    d_ = depth;
    x_scale_ = 0;
    y_scale_ = 0;
    direction_.normalize();
}

Point* Camera::getPosition() {
    return &position_;
}

Vector* Camera::getDirection() {
    return &direction_;
}

int Camera::getPixelWidth() {
    return width_;
}

int Camera::getPixelHeight() {
    return height_;
}

float Camera::getDepth() {
    return d_;
}

void Camera::setPosition(Point* position) {
    position_ = *position;
}

void Camera::setDirection(Vector* direction) {
    direction_ = *direction;
}

void Camera::setDimensions(int width, int height) {
    width_ = width;
    height_ = height;
}

void Camera::setViewPlane(float l, float r, float t, float b) {
    l_ = l;
    r_ = r;
    t_ = t;
    b_ = b;
}

// Find the scaling of each pixel width and height based on the perspective frame
void Camera::calculateScales() {
    x_scale_ = 1.0 / (float) width_ * (r_ - l_);
    y_scale_ = 1.0 / (float) height_ * (t_ - b_);
}

// Calculate the ray that determines a pixel in the image
Ray Camera::getPixelRay(float x, float y) {
    double endX = d_ * direction_.getX() + (x + 0.5) * x_scale_ - position_.getX();
    double endY = d_ * direction_.getY() + (y + 0.5) * y_scale_ - position_.getY();
    double endZ = d_ * direction_.getZ() - position_.getZ();
    
    Ray r = Ray(position_, Vector(endX, endY, endZ));
    r.getDirection()->normalize();
    
    return r;
}
