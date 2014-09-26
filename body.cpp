#include "body.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

double body::shoulder_x_min = 0;
double body::shoulder_x_max = 0;
double body::shoulder_y_min = 0;
double body::shoulder_y_max = 0;
double body::shoulder_z_min = 0;
double body::shoulder_z_max = 0;

double body::waist_x_min = 0;
double body::waist_x_max = 0;
double body::waist_y_min = 0;
double body::waist_y_max = 0;
double body::waist_z_min = 0;
double body::waist_z_max = 0;

double body::neck_x_min = 0;
double body::neck_x_max = 0;
double body::neck_y_min = 0;
double body::neck_y_max = 0;
double body::neck_z_min = 0;
double body::neck_z_max = 0;

double body::ankle_x_min = 0;
double body::ankle_x_max = 0;
double body::ankle_y_min = 0;
double body::ankle_y_max = 0;

double body::wrist_x_min = 0;
double body::wrist_x_max = 0;
double body::wrist_z_min = 0;
double body::wrist_z_max = 0;

double body::hip_x_min = 0;
double body::hip_x_max = 0;
double body::hip_y_min = 0;
double body::hip_y_max = 0;
double body::hip_z_min = 0;
double body::hip_z_max = 0;

double body::elbow_x_min = 0;

body::body() {
    glGenLists(15);
    init_pelvis();

}

void body::render() {

    glCallList(pelvis);    

}

void body::init_pelvis() {
    glNewList(pelvis, GL_COMPILE);
        glLoadIdentity();        
        glScalef(0.1, 0, 0);
        drawLine();
    glEndList();
}
