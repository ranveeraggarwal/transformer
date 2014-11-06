#include "environment.hpp"
#include <cmath>

void renderGround(bool tesselate) {
    //Ground
    glPushMatrix();
    glTranslatef(0, -50.615, 0);
    int i, j;
    if(tesselate) {
    for(i = 0; i < 50; i++) {
        for(j = 0; j < 50; j++) {
            glPushMatrix();
            glTranslatef((2*i)-49, 0, (2*j)-49);
            glScalef(2, 100, 2);
            texcube(2, 0.6, 0.6, 0.3, true);
            glPopMatrix();
        }
    }
    }
    else {
    for(i = 0; i < 1; i++) {
        for(j = 0; j < 1; j++) {
            glPushMatrix();
            glScalef(100, 100, 100);
            texcube(2, 0.6, 0.6, 0.3, true);
            glPopMatrix();
        }
    }
    }
    glPopMatrix();
    //Sea
    glPushMatrix();
    glTranslatef(0, -51, 0);
    glScalef(300, 100, 300);
    texcube(4, 1, 1, 1, true);
    glPopMatrix();
}

void renderSky(bool day, bool moon_toggle) {
    if (day)
    {
        glPushMatrix();
        glScalef(300, 300, 300);
        skybox(1, 1, 1, true, 6);
        glPopMatrix();
    }
    else
    {
        if (!moon_toggle)
        {
            glPushMatrix();
            glScalef(300, 300, 300);
            skybox(1, 1, 1, true, 5);
            glPopMatrix();
        }
        else
        {
            glPushMatrix();
            glScalef(300, 300, 300);
            texcube(3, 1, 1, 1, true);
            glPopMatrix();
        }
    }  
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
