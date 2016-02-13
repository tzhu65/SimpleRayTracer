//
//  scene.h
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#ifndef scene_h
#define scene_h

#include "color.h"
#include "light.h"
#include "surface.h"

/*
 Model of the world.
 */

class Scene {
    
private:
    Surface** surface_list_;
    Light** light_list_;
    int surface_count_;
    int light_count_;
    Color blank_color_;
    Color intersect_color_;
    
public:
    Scene();
    
    Surface** getSurfaceList();
    Light** getLightList();
    int getSurfaceCount();
    int getLightCount();
    Color* getBlankColor();
    Color* getIntersectColor();
    
    void setSurfaceList(Surface** surface_list);
    void setLightList(Light** light_list);
    void setBlankColor(Color color);
    void setIntersectColor(Color color);
    
    Surface* getSurface(int index);
    Light* getLight(int index);
    void addSurface(Surface* surface);
    void addLight(Light* light);
    void removeAllSurfaces();
    void removeSurface(Surface* surface);
    void removeAllLights();
    void removeLight(Light* light);
    std::tuple<Surface*, Point> checkRayCollision(Ray* ray, Surface* ignoreSurface, bool all_collisions);
    
};

#endif /* scene_h */
