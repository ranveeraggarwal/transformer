#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define PI 3.14159265359

extern unsigned int texture[1];

void texcube(void);
void drawCube(float = 1.0, float = 1.0, float = 1.0);
void drawLine(float = 1.0, float = 1.0, float = 1.0);
void drawBox(float = 1.0, float = 1.0, float = 1.0);
void drawSphere(int = 30, int = 30, float = 1.0, float = 1.0, float = 1.0);
void drawCylinder(float = 1.0, float = 1.0, float = 1.0);
