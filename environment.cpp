#include "environment.hpp"
#include <cmath>

void renderGround() {
    glPushMatrix();
    glTranslatef(0, -50.615, 0);
    glScalef(100, 100, 100);
    texcube(2, 0.6, 0.6, 0.3, true);
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
        //glTranslatef(0, 100, 0);
        glScalef(300, 300, 300);
        skybox(1, 1, 1, true, 6);
        glPopMatrix();
        /*glPushMatrix();
        glScalef(400, 290, 400);
        texcube(3, 1, 1, 1, true);
        glPopMatrix();*/
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

/*
void renderSky(bool day) {
    if(day)
    {
        glPushMatrix();
        glTranslatef(0, 10, 0);
        glScalef(300, 300, 300);
        skybox(1, 1, 1, true);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0, 9, 0);
        glScalef(400, 300, 400);
        texcube(3, 1, 1, 1, true);
        glPopMatrix();
    }
    else
        glPushMatrix();
        glTranslatef(0, 10, 0);
        glScalef(300, 300, 300);
        texcube(5, 1, 1, 1, true);
        glPopMatrix();
}
*/
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
