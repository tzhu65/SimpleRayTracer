//
//  ray_tracer.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/13/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <OpenGl/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

#include "camera.h"
#include "color.h"
#include "point.h"
#include "ray.h"
#include "ray_tracer.h"
#include "scene.h"
#include "surface.h"
#include "world.h"

using namespace std;

/*
 Main ray tracer that has a scene and camera to calculate an image
 */

RayTracer::RayTracer() {
    camera_ = Camera();
    scene_ = Scene();
    gamma_ = 0;
    antialias_amount_ = 1;
    ambient_shadow_ = 1;
}

RayTracer::RayTracer(Camera* camera, Scene* scene) {
    camera_ = *camera;
    scene_ = *scene;
    gamma_ = 0;
    antialias_amount_ = 1;
    ambient_shadow_ = 1;
}

Camera* RayTracer::getCamera() {
    return &camera_;
}

Scene* RayTracer::getScene() {
    return &scene_;
}

float RayTracer::getGamma() {
    return gamma_;
}

int RayTracer::getAntialiasAmount() {
    return antialias_amount_;
}

float RayTracer::getAmbientShadow() {
    return ambient_shadow_;
}

void RayTracer::setCamera(Camera* camera) {
    camera_ = *camera;
}

void RayTracer::setScene(Scene* scene) {
    scene_ = *scene;
}

void RayTracer::setGamma(float gamma) {
    gamma_ = gamma;
}

void RayTracer::setAntialiasAmount(int antialias_amount) {
    antialias_amount_ = antialias_amount;
}

void RayTracer::setAmbientShadow(float ambient_shadow) {
    ambient_shadow_ = ambient_shadow_;
}

// Generate an image based on the scene and camera
void RayTracer::calculateImage(int imageType) {
    bool coloredImage = false;
    bool antialiasImage = false;
    
    if (imageType == 0) {           // Intersect only
        coloredImage = false;
        antialiasImage = false;
    } else if (imageType == 1) {    // Colors and shadows
        coloredImage = true;
        antialiasImage = false;
    } else if (imageType == 2) {    // Antialiased
        coloredImage = true;
        antialiasImage = true;
    }
    
    int width = camera_.getPixelWidth();
    int height = camera_.getPixelHeight();
    
    // Initialize
    float pixels[height][width][3];
    Color c = Color();
    
    for (int y = height/2; y > -height/2; y--) {
        for (int x = -width/2; x < width/2; x++) {
            
            // Calculate the ray
            Ray r = camera_.getPixelRay(x, y);
            
            // Check for intersections
            std::tuple<Surface*, Point> result = scene_.checkRayCollision(&r, nullptr, true);
            Surface* s = std::get<0>(result);
            Point* p = &std::get<1>(result);

            // Intersection image
            if (!coloredImage) {
                if (s) {
                    c.setColor(scene_.getIntersectColor());
                } else {
                    c.setColor(scene_.getBlankColor());
                }
            } else {
                
                // Color image
                if (!antialiasImage) {
                    if (s) {
                        c = *calculateColor(s, p, &r);
                    } else {
                        c.setColor(scene_.getBlankColor());
                    }
                    
                }
                
                // Antialias image
                else {
                    c = *antialiasBox(s, antialias_amount_, x, y);
                }
            }
            
            // Store the calculated color
            int x2 = x + 256;
            int y2 = y + 255;
            
            pixels[y2][x2][0] = c.getR();
            pixels[y2][x2][1] = c.getG();
            pixels[y2][x2][2] = c.getB();
        }
    }
    
    glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
}

// Determines the color given the material properties and lighting
Color* RayTracer::calculateColor(Surface* ignoreSurface, Point* point, Ray* ray) {
    Color* l_total = new Color(0.0, 0.0 ,0.0);
    
    // Ambient term
    Color la = *ignoreSurface->getMaterial()->getKa();
    l_total->addColor(&la);
    
    Vector N = ignoreSurface->calculateNormal(point);
    N.normalize();
    
    // Iterate over each light
    for (int i = 0; i < scene_.getLightCount(); i++) {
        Light light = *scene_.getLight(i);
        if (!checkIfShade(point, ignoreSurface, &light)) {
            
            // Diffuse term
            Point l = World::subtractPoints(light.getPosition(), point);
            Vector L = World::pointToVector(&l);
            L.normalize();
            
            float dp = World::dotProduct(&N, &L);
            dp = dp > 0 ? dp : 0;
            Color ld = *ignoreSurface->getMaterial()->getKd();
            ld.multiply(dp);
            ld.multiplyColor(light.getColor());
            
            // Specular term
            float rx = -ray->getDirection()->getX();
            float ry = -ray->getDirection()->getY();
            float rz = -ray->getDirection()->getZ();
            Vector V = Vector(rx, ry, rz);
            V.normalize();
            
            Vector H = World::addVectors(&V, &L);
            H.normalize();

            double dp2 = World::dotProduct(&N, &H);
            dp2 = dp2 > 0 ? dp2 : 0;
            dp2 = pow(dp2, ignoreSurface->getMaterial()->getSpecularPower());
            Color ls = *ignoreSurface->getMaterial()->getKs();
            ls.multiply(dp2);
            ls.multiplyColor(light.getColor());
            
            l_total->addColor(&ld);
            l_total->addColor(&ls);
        }
    }
    gammaCorrect(l_total);
    return l_total;
}

// Check if a point lies in the shade. Note this does not take into account
// the transparency of objects in the way.
int RayTracer::checkShadow(Point* point, Surface* ignoreSurface) {
    int shadowCount = 0;
    
    // Check every light to see if the point is in the shade
    for (int i = 0; i < scene_.getLightCount(); i++) {
        Light* light = scene_.getLight(0);
        cout <<"shade?"<< endl;
        if (checkIfShade(point, ignoreSurface, light)) {
            shadowCount++;
        }
    }
    return shadowCount;
}

// Check if a point is shaded from a certain light
bool RayTracer::checkIfShade(Point* point, Surface* ignoreSurface, Light* light) {

    // Construct the ray from the point to the light
    Ray r = World::createRay(point, light->getPosition());
    float lightDistance = World::distance(point, light->getPosition());

    // Check if there is an object in the way
    std::tuple<Surface*, Point> result = scene_.checkRayCollision(&r, ignoreSurface, false);
    Surface* s = std::get<0>(result);
    Point p = std::get<1>(result);
    
    if (s) {
        
        // Check if the surface is between the the light and point
        float surfaceDistance = World::distance(point, &p);
        if (surfaceDistance < lightDistance) {
            return true;
        }
    }
    return false;
}

//
Color* RayTracer::antialiasBox(Surface* surface, int samples, float x, float y) {
    Color c = Color();
    Color* color_result = new Color(0.0, 0.0, 0.0);
    for (int i = 0; i < samples; i++) {
        
        // Create random pixel rays
        float x_random = ((float) rand() / (float) RAND_MAX) - 0.5;
        float y_random = ((float) rand() / (float) RAND_MAX) - 0.5;
        float x_new = x + x_random;
        float y_new = y + y_random;
        
        // Calculate the ray
        Ray r = camera_.getPixelRay(x_new, y_new);
        
        // Check for intersections
        std::tuple<Surface*, Point> result = scene_.checkRayCollision(&r, nullptr, true);
        Surface* s = std::get<0>(result);
        Point* p = &std::get<1>(result);
        
        if (s) {
            c = *calculateColor(s, p, &r);
        } else {
            c = *scene_.getBlankColor();
        }
        color_result->addColor(&c);
    }
    color_result->multiply(1.0 / samples);
    
    return color_result;
}

void RayTracer::gammaCorrect(Color* color) {
    double r = pow(color->getR(), 1.0/gamma_);
    double g = pow(color->getG(), 1.0/gamma_);
    double b = pow(color->getB(), 1.0/gamma_);
    color->setValues(r, g, b);
}

