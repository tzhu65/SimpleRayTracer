//
//  ray_tracer.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef ray_tracer_h
#define ray_tracer_h

#include "camera.h"
#include "point.h"
#include "ray.h"
#include "scene.h"
#include "surface.h"

/*
 Main ray tracer that has a scene and camera to calculate an image
 */

class RayTracer {
    
private:
    Camera camera_;
    Scene scene_;
    float gamma_;
    int antialias_amount_;
    float ambient_shadow_;
    
public:
    RayTracer();
    RayTracer(Camera* camera, Scene* scene);
    
    Camera* getCamera();
    Scene* getScene();
    float getGamma();
    int getAntialiasAmount();
    float getAmbientShadow();
    
    void setCamera(Camera* camera);
    void setScene(Scene* scene);
    void setGamma(float gamma);
    void setAntialiasAmount(int antialias_amount);
    void setAmbientShadow(float ambient_shadow);
    
    void calculateImage(int imageType);
    Color* calculateColor(Surface* surface, Point* point, Ray* ray);
    void gammaCorrect(Color* color);
    bool checkIfShade(Point*, Surface* ignoreSurface, Light* light);
    int checkShadow(Point* point, Surface* ignoreSurface);
    Color* antialiasBox(Surface* surface, int samples, float x, float y);
    
};

#endif /* ray_tracer_h */
