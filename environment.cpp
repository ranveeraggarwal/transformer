#include "environment.hpp"
#include <cmath>

void renderGround() {
    glPushMatrix();
    glTranslatef(0, -50.615, 0);
    glScalef(100, 100, 100);
    texcube(2, 0.6, 0.6, 0.3);
    glPopMatrix();
}

void renderTree(double x, double z, bool standing, double y_angle, double fall_angle) {

    glPushMatrix();
    if(!standing) {
        glTranslatef(x+0.2*sin(y_angle * PI / 180), -0.565, z+0.2*cos(y_angle * PI / 180)); 
        glRotatef(fall_angle, cos(y_angle * PI / 180), 0, -sin(y_angle * PI / 180));
        glTranslatef(-x, 0.615, -z);
    }    

    glPushMatrix();
    glTranslatef(x, -0.365, z);
    glScalef(0.1, 0.5, 0.1);
    drawCylinder(0.32, 0.21, 0.04);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x, 0.135, z);
    glScalef(0.3, -0.5, 0.3);
    drawCone(0.23, 0.37, 0.04);
    glPopMatrix();
    glPopMatrix();
}
