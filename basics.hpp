#ifndef _BASICS_H
#define _BASICS_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define PI 3.14159265359

//This is an array of tetures, defined elsewhere
extern unsigned int texture[8];

//Sets the material for an object
void setMaterial(GLfloat, GLfloat, GLfloat, GLfloat);

//Gives colors to the material
void setMaterialColors(float, float, float, float = 0);

//Basic recurring shapes
void drawCube(float = 1.0, float = 1.0, float = 1.0);
void drawLine(float = 1.0, float = 1.0, float = 1.0);
void drawBox(float = 1.0, float = 1.0, float = 1.0);
void drawSphere(int = 30, int = 30, float = 1.0, float = 1.0, float = 1.0);
void drawCylinder(float = 1.0, float = 1.0, float = 1.0);
void drawCone(float = 1.0, float = 1.0, float = 1.0);

//Recurring textured shapes
void texcube(int, float = 1.0, float = 1.0, float = 1.0, bool = false);
void texCylinder(float = 1.0, float = 1.0, float = 1.0, int = 0);

//The skybox
void skybox(float = 1.0, float = 1.0, float = 1.0, bool = false, int = 6);
#endif
