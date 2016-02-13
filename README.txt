Tony Zhu
Programming Assignment 1 - Simple Ray Tracer

=================================================================

INSTRUCTIONS

If possible, use this on OS X with Xcode installed.

(1) Open up the Xcode project

(2) In the main.cpp file, change the IMAGE_TYPE variable (line 33)
	int IMAGE_TYPE = 0; // Intersection only for image 1
	int IMAGE_TYPE = 1; // Color and lighting for image 2
	int IMAGE_TYPE = 2; // Antialiasing for image 3

(3) Run the project with Xcode (command + r or arrow at top left)

(4) Wait a bit (antialiasing will take some time)

(5) Resulting image should be in the GLUT window

Note, only one image is displayed at a time, so you’ll have to 
run the program multiple times with different values for
IMAGE_TYPE


=================================================================

PACKAGES NEEDED

OpenGl
GLUT

(Both should come preinstalled on a macbook)


=================================================================

RUNNING TIME

Intersection only -> 0.6s
Color and lighting -> 0.9s
Antialiasing -> 54s

These benchmarks were taken on a Late 2013 MacBook Pro with an
intel i5-4258U.


=================================================================

IMAGE LOCATION

The image will be shown in the GLUT window.


=================================================================

ABOUT

Inside here is a simple ray tracer written in c++ with Xcode. 
There should be a “Simple Ray Tracer.xcodeproj” file that will 
open the file in Xcode.

World
The 3D coordinate system is defined in the “World” folder and 
contains definitions for objects like points, vectors, rays, 
colors, and helper math functions.

Objects
Surfaces and lights are defined in the “Objects” folder. All 
surfaces (spheres and planes) contain a material that will 
determine its color based on lighting. The surfaces also have
their own collision detection function given a ray. In addition,
surfaces also have a method to determine the surface normal given
a point on the surface, which is used for the Phong shading model.

Scene
The scene class holds the data of all the surfaces. It is
essentially the model of the world. Surfaces are added to it, 
and it also detects collisions given a ray, returning the 
point of intersection and the surface the ray collided with.
Lights are also included in the scene. A blank color is provided
for when a ray does not collide with any surfaces.

Camera
To provide a perspective camera, a camera class is defined. It 
holds all the perspective data such as the view point, the
viewing plane, and the resulting image dimensions. Given those 
parameters, the camera class can also calculate a ray, given a
pixel position.

RayTracer
The concept of ray tracing is defined in the ray tracer class.
A scene and camera are defined for the ray tracer to use. The
calculateImage function is called to calculate an image through
ray tracing. After finding the ray, it uses the scene to check
if the ray collides with any surfaces. If wanted, the color can
be calculated for that surface in the calculateColor function.
To check if a point is shaded, the checkShadow function is
called. For antialiasing, random samples are taken for each
pixel and averaged to determine the color.


