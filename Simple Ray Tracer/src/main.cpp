//
//  main.cpp
//  Simple Ray Tracer
//
//  Created by Tony Zhu on 2/12/16.
//  Copyright © 2016 Tony Zhu. All rights reserved.
//

#include <iostream>
#include <OpenGl/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

#include "camera.h"
#include "color.h"
#include "light.h"
#include "plane.h"
#include "point.h"
#include "ray_tracer.h"
#include "scene.h"
#include "sphere.h"
#include "vector.h"
#include "world.h"

using namespace std;

/*
 Determine the type of image to be displayed
    IMAGE_TYPE = 0 -> Intersection only
    IMAGE_TYPE = 1 -> Color and lighting
    IMAGE_TYPE = 2 -> Antialiasing
 */
int IMAGE_TYPE = 1;


// Create the scene that consists of three spheres and a plane
Scene* sceneSetup() {
    
    Scene* scene = new Scene();
    scene->setBlankColor(Color(0.0, 0.0, 0.0));
    scene->setIntersectColor(Color(1.0, 1.0, 1.0));
    
    // Set up surfaces
    Plane* p1 = new Plane(Point(0, -2, 0), Vector(0, 1, 0));
    Sphere* s1 = new Sphere(-4, 0, -7, 1);
    Sphere* s2 = new Sphere( 0, 0, -7, 2);
    Sphere* s3 = new Sphere( 4, 0, -7, 1);
    
    p1->getMaterial()->setValues(Color(0.2, 0.2, 0.2), Color(1,   1, 1), Color(  0,   0,   0),  0);
    s1->getMaterial()->setValues(Color(0.2,   0,   0), Color(1,   0, 0), Color(  0,   0,   0),  0);
    s2->getMaterial()->setValues(Color(  0, 0.2,   0), Color(0, 0.5, 0), Color(0.5, 0.5, 0.5), 32);
    s3->getMaterial()->setValues(Color(  0,   0, 0.2), Color(0,   0, 1), Color(  0,   0,   0),  0);
    
    scene->addSurface(p1);
    scene->addSurface(s1);
    scene->addSurface(s2);
    scene->addSurface(s3);

    // Set up lights
    Light* l1 = new Light(Point(-4, 4, -3), Color(1.0, 1.0, 1.0), 0);
    
    scene->addLight(l1);
    
    return scene;
}

// Set up the camera
Camera* cameraSetup() {
    Camera* camera = new Camera(Point(0, 0, 0), Vector(0, 0, -1), 0.1);
    camera->setDimensions(512, 512);
    camera->setViewPlane(-0.1, 0.1, 0.1, -0.1);
    camera->calculateScales();
    return camera;
}

// Display function that sets up the ray tracer
void generateImage() {
    RayTracer* ray_tracer = new RayTracer();
    ray_tracer->setCamera(cameraSetup());
    ray_tracer->setScene(sceneSetup());
    ray_tracer->setGamma(2.2);
    ray_tracer->setAntialiasAmount(64);
    ray_tracer->setAmbientShadow(0.6);
    
    ray_tracer->calculateImage(IMAGE_TYPE);
}

// Image rendering function
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)  ;
    glClearColor(0, 0, 0, 0);
    
    // Time the image generation time
    clock_t begin = clock();
    generateImage();
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Image generation time: " << elapsed_secs << "s" << endl;

    glutSwapBuffers();
    
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Simple Ray Tracer");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
