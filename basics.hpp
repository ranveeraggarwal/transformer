#ifndef _BASICS_H
#define _BASICS_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define PI 3.14159265359

extern unsigned int texture[3];

void texcube(int, float = 1.0, float = 1.0, float = 1.0);
void drawCube(float = 1.0, float = 1.0, float = 1.0);
void drawLine(float = 1.0, float = 1.0, float = 1.0);
void drawBox(float = 1.0, float = 1.0, float = 1.0);
void drawSphere(int = 30, int = 30, float = 1.0, float = 1.0, float = 1.0);
void drawCylinder(float = 1.0, float = 1.0, float = 1.0);
void drawCone(float = 1.0, float = 1.0, float = 1.0);
#endif
