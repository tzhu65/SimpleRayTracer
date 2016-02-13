//
//  color.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

/*
 RGB value
 */

#include <stdio.h>

#include "color.h"

Color::Color() {
    r_ = 0;
    g_ = 0;
    b_ = 0;
}

Color::Color(float r, float g, float b) {
    r_ = r;
    g_ = g;
    b_ = b;
}

float Color::getR() {
    return r_;
}

float Color::getG() {
    return g_;
}

float Color::getB() {
    return b_;
}

void Color::setR(float r) {
    r_ = r;
}

void Color::setG(float g) {
    g_ = g;
}

void Color::setB(float b) {
    b_ = b;
}

void Color::setValues(float r, float g, float b) {
    r_ = r;
    g_ = g;
    b_ = b;
}

void Color::setColor(Color* color) {
    r_ = color->getR();
    g_ = color->getG();
    b_ = color->getB();
}

void Color::multiply(float f) {
    r_ *= f;
    g_ *= f;
    b_ *= f;
}

void Color::addColor(Color* c) {
    r_ += c->getR();
    g_ += c->getG();
    b_ += c->getB();
}

void Color::multiplyColor(Color* c) {
    r_ *= c->getR();
    g_ *= c->getG();
    b_ *= c->getB();
}
