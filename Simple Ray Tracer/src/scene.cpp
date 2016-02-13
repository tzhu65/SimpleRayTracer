//
//  scene.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <stdio.h>

#include "color.h"
#include "light.h"
#include "point.h"
#include "scene.h"
#include "surface.h"
#include "world.h"

using namespace std;

/*
 Model of the world.
 */

Scene::Scene() {
    surface_list_ = new Surface*[0];
    light_list_ = new Light*[0];
    surface_count_ = 0;
    light_count_ = 0;
    blank_color_ = Color(0.0, 0.0, 0.0);
}

Surface** Scene::getSurfaceList() {
    return surface_list_;
}

Light** Scene::getLightList() {
    return light_list_;
}

int Scene::getSurfaceCount() {
    return surface_count_;
}

int Scene::getLightCount() {
    return light_count_;
}

Color* Scene::getBlankColor() {
    return &blank_color_;
}

Color* Scene::getIntersectColor() {
    return &intersect_color_;
}

void Scene::setSurfaceList(Surface** surface_list) {
    surface_list_ = surface_list;
}

void Scene::setLightList(Light** light_list) {
    light_list_ = light_list;
}

void Scene::setBlankColor(Color color) {
    blank_color_ = color;
}

void Scene::setIntersectColor(Color color) {
    intersect_color_ = color;
}

Surface* Scene::getSurface(int index) {
    return surface_list_[index];
}

Light* Scene::getLight(int index) {
    return light_list_[index];
}

void Scene::addSurface(Surface* surface) {
    surface_count_++;
    Surface** surface_list = new Surface*[surface_count_];
    
    // Copy over the previous surfaces
    for (int i = 0; i < surface_count_ - 1; i++) {
        surface_list[i] = surface_list_[i];
    }
    delete surface_list_;
    surface_list[surface_count_ - 1] = surface;
    surface_list_ = surface_list;
}

void Scene::addLight(Light* light) {
    light_count_++;
    Light** light_list = new Light*[light_count_];
    
    // Copy over the previous lights
    for (int i = 0; i < light_count_ - 1; i++) {
        light_list[i] = light_list_[i];
    }
    delete light_list_;
    light_list[light_count_ - 1] = light;
    light_list_ = light_list;
}

void Scene::removeAllSurfaces() {
    surface_list_ = new Surface*[0];
    surface_count_ = 0;
}

void Scene::removeSurface(Surface* surface) {
    surface_count_--;
}

void Scene::removeAllLights() {
    light_list_ = new Light*[0];
    light_count_ = 0;
}

void Scene::removeLight(Light* light) {
    light_count_--;
}

// Determine if a ray collides with any surfaces and return the surface and point of intersection
tuple<Surface*, Point> Scene::checkRayCollision(Ray* ray, Surface* ignoreSurface, bool all_collisions) {
    Point p = Point();
    Point origin = *ray->getPoint();
    World::distance(&origin, &p);
    float distance = numeric_limits<float>::max();
    bool collision = false;
    tuple<Surface*, Point> result;
    
    // Check every surface
    for (int i = 0; i < surface_count_; i++) {
        Surface& s = *(getSurface(i));
        if (s.checkCollision(ray, &p) && &s!=ignoreSurface) {
            collision = true;
            
            // Check for the closest
            if (World::distance(&origin, &p) < distance) {
                result = make_tuple(&s, p);
                if (!all_collisions) {
                    return result;
                }
            }
        }
    }
    
    if (collision) {
        return result;
    }
    
    return nullptr;
}
