//
//  light.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <stdio.h>

#include "light.h"
#include "point.h"

/*
 Illuminator
 */

Light::Light() {
    position_ = Point(0.0, 0.0, 0.0);
    color_ = Color(0.0, 0.0, 0.0);
    fadeout_ = 0;
}

Light::Light(Point position, Color color, float fadeout) {
    position_ = position;
    color_ = color;
    fadeout_ = fadeout;
}

Point* Light::getPosition() {
    return &position_;
}

Color* Light::getColor() {
    return &color_;
}

float Light::getFadeout() {
    return fadeout_;
}

void Light::setPosition(Point position) {
    position_ = position;
}

void Light::setColor(Color color) {
    color_ = color;
}

void Light::setFadeout(float fadeout) {
    fadeout_ = fadeout;
}
