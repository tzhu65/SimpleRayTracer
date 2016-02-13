//
//  material.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <stdio.h>

#include "material.h"

/*
 Describes the color/shading of a surface
 */

Material::Material() {
    ka_ = Color(0.0, 0.0, 0.0);
    kd_ = Color(0.0, 0.0, 0.0);
    ks_ = Color(0.0, 0.0, 0.0);
    specular_power_ = 0.0;
}

Material::Material(Color ka, Color kd, Color ks, float specular_power) {
    ka_ = ka;
    kd_ = kd;
    ks_ =ks;
    specular_power = specular_power;
}

Color* Material::getKa() {
    return &ka_;
}

Color* Material::getKd() {
    return &kd_;
}

Color* Material::getKs() {
    return &ks_;
}

float Material::getSpecularPower() {
    return specular_power_;
}

void Material::setKa(Color ka) {
    ka_ = ka;
}

void Material::setKd(Color kd) {
    kd_ = kd;
}

void Material::setKs(Color ks) {
    ks_ = ks;
}

void Material::setSpecularPower(float specular_power) {
    specular_power_ = specular_power;
}

void Material::setValues(Color ka, Color kd, Color ks, float specular_power) {
    ka_ = ka;
    kd_ = kd;
    ks_ = ks;
    specular_power_ = specular_power;
}
