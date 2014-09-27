#include "body.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

double body::shoulder_x_min = 0;
double body::shoulder_x_max = 135;
double body::shoulder_y_min = 0;
double body::shoulder_y_max = 135;
double body::shoulder_z_min = -225;
double body::shoulder_z_max = 0;

double body::waist_x_min = 0;
double body::waist_x_max = 180;
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

double body::hip_x_min = -90;
double body::hip_x_max = 90;
double body::hip_y_min = 0;
double body::hip_y_max = 90;
double body::hip_z_min = -90;
double body::hip_z_max = 0;

double body::elbow_x_min = 0;
double body::elbow_x_max = 180;

double body::knee_x_max = 90;
double body::knee_x_min = 0;

body::body() {
    /*Variables*/
    /*Camera*/
    rotate_x_angle = 0;
    rotate_y_angle = 0;
    rotate_z_angle = 0;

    /*Waist*/
    waist_x = 0;

    /*Right Shoulder*/
    right_shoulder_x = 0;
    right_shoulder_y = 0;
    right_shoulder_z = 0;

    /*Left Shoulder*/
    left_shoulder_x = 0;
    left_shoulder_y = 0;
    left_shoulder_z = 0;

    /*Right Hip*/
    right_hip_x = 0;
    right_hip_y = 0;
    right_hip_z = 0;

    /*Left Hip*/
    left_hip_x = 0;
    left_hip_y = 0;
    left_hip_z = 0;

    /*Left Elbow*/
    left_elbow_x = 0;

    /*Right Elbow*/
    right_elbow_x = 0;

    /*Left Knee*/
    left_knee_x = 0;

    /*Right Knee*/
    right_knee_x = 0;

    /*Number of Lists to Display*/
    glGenLists(15);

    /*Initialise Display Lists*/
    init_pelvis();
    init_torso();
    init_head();
    init_right_upper_arm();
    init_right_lower_arm();
    init_right_hand();
    init_left_upper_arm();
    init_left_lower_arm();
    init_left_hand();
    init_right_thigh();
    init_right_leg();
    init_right_foot();
    init_left_thigh();
    init_left_leg();
    init_left_foot();
}


void body::render() {

    glLoadIdentity();

    //glRotatef(rotate_x_angle, 1.0, 0.0, 0.0);
    glRotatef(rotate_y_angle, 0.0, 1.0, 0.0);
    //glRotatef(rotate_z_angle, 0.0, 0.0, 1.0);

    glPushMatrix();
        glCallList(pelvis);
    glPopMatrix();

    glPushMatrix();
  
        glTranslatef(0.0, 0.025, 0.0);
        glRotatef(waist_x, 1.0, 0.0, 0.0); 
        glTranslatef(0.0, -0.025, 0.0);

        glPushMatrix();
            glCallList(torso);
        glPopMatrix();

        glPushMatrix();
            glCallList(head);
        glPopMatrix();

        /*The right arm*/
        glPushMatrix();
            /*Move pivot back*/
            glTranslatef(-0.13, 0.425, 0.0);
            /*Shoulder Y rotation*/
            glRotatef(right_shoulder_y, 0.0, 1.0, 0.0);
            /*Shoulder Z rotation*/
            glRotatef(right_shoulder_z, 0.0, 0.0, 1.0); 
            /*Shoulder X rotation*/
            glRotatef(right_shoulder_x, 1.0, 0.0, 0.0); 
            /*Get pivot to origin*/
            glTranslatef(0.13, -0.425, 0.0);

            glPushMatrix();
                glCallList(right_upper_arm);
            glPopMatrix();

            /*Forearm*/
            glPushMatrix();
                /*Move pivot back*/
                glTranslatef(-0.13, 0.125, 0.0);
                /*Rotate Elbow Joint*/
                glRotatef(right_elbow_x, 1.0, 0.0, 0.0);
                /*Move pivot up*/
                glTranslatef(0.13, -0.125, 0.0);

                glPushMatrix();
                    glCallList(right_lower_arm);
                glPopMatrix();

                /*Wrist*/
                glPushMatrix();
                    glCallList(right_hand);
                glPopMatrix();
                /*Wrist Ends*/
            glPopMatrix();
            /*Forearm Ends*/
        glPopMatrix();
        /*The right arm ends */

        /*The left arm*/
        glPushMatrix();
            /*Move pivot back*/
            glTranslatef(0.13, 0.425, 0.0);
            /*Shoulder Y rotation*/
            glRotatef(left_shoulder_y, 0.0, 1.0, 0.0);
            /*Shoulder Z rotation*/
            glRotatef(left_shoulder_z, 0.0, 0.0, 1.0); 
            /*Shoulder X rotation*/
            glRotatef(left_shoulder_x, 1.0, 0.0, 0.0); 
            /*Get pivot to origin*/
            glTranslatef(-0.13, -0.425, 0.0);

            glPushMatrix();
                glCallList(left_upper_arm);
            glPopMatrix();

            /*Forearm*/
            glPushMatrix();
                /*Move pivot back*/
                glTranslatef(0.13, 0.125, 0.0);
                /*Rotate Elbow Joint*/
                glRotatef(left_elbow_x, 1.0, 0.0, 0.0);
                /*Move pivot up*/
                glTranslatef(-0.13, -0.125, 0.0);

                glPushMatrix();
                    glCallList(left_lower_arm);
                glPopMatrix();

                /*Wrist*/
                glPushMatrix();
                    glCallList(left_hand);
                glPopMatrix();
                /*Wrist Ends*/
            glPopMatrix();
            /*Forearm Ends*/
        glPopMatrix();
        /*The left arm ends */

    glPopMatrix();

    /*The right leg begins*/
    glPushMatrix();
        glTranslatef(0.06, -0.025, 0.0);
        glRotatef(right_hip_x, 1.0, 0.0, 0.0);
        glRotatef(right_hip_y, 0.0, 1.0, 0.0);
        glRotatef(right_hip_z, 0.0, 0.0, 1.0);
        glTranslatef(-0.06, 0.025, 0.0);

        glPushMatrix();
            glCallList(right_thigh);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.06, -0.345, 0.0);
            glRotatef(right_knee_x, 1.0, 0.0, 0.0);
            glTranslatef(-0.06, 0.345, 0.0);

            glPushMatrix();
                glCallList(right_leg);
            glPopMatrix();

            glPushMatrix();
                glCallList(right_foot);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    /*The right leg ends*/

    /*The left leg begins*/
    glPushMatrix();
        glTranslatef(-0.06, -0.025, 0.0);
        glRotatef(left_hip_x, 1.0, 0.0, 0.0);
        glRotatef(left_hip_y, 0.0, 1.0, 0.0);
        glRotatef(left_hip_z, 0.0, 0.0, 1.0);
        glTranslatef(0.06, 0.025, 0.0);

        glPushMatrix();
            glCallList(left_thigh);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.06, -0.345, 0.0);
            glRotatef(left_knee_x, 1.0, 0.0, 0.0);
            glTranslatef(-0.06, 0.345, 0.0);

            glPushMatrix();
                glCallList(left_leg);
            glPopMatrix();

            glPushMatrix();
                glCallList(left_foot);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    /*The left leg ends*/
}

void body::rotate_y(double t) {

    double new_t = rotate_y_angle + t;
    if(new_t > 360)
        new_t -= 360;
    else if(new_t < 0)
        new_t += 360;
    rotate_y_angle = new_t;

}

void body::init_pelvis() {
    glNewList(pelvis, GL_COMPILE);
        glScalef(0.2, 0.05, 0.05);
        drawCube();
    glEndList();
}

void body::init_torso() {
    glNewList(torso, GL_COMPILE);
        glTranslatef(0.0, 0.225, 0.0);
        glScalef(0.2, 0.4, 0.05);
        drawCube(1.0, 0.0, 0.0);
    glEndList();
}

void body::init_head() {
    glNewList(head, GL_COMPILE);
        glTranslatef(0.0, 0.475, 0.0);
        glScalef(0.1, 0.1, 0.05);
        drawCube(0.0, 0.0, 1.0);
    glEndList();
}

void body::init_right_upper_arm() {
    glNewList(right_upper_arm, GL_COMPILE);    
        glTranslatef(-0.13, 0.275, 0.0);
        glScalef(0.06, 0.3, 0.05);
        drawCube();
    glEndList();
}

void body::init_right_lower_arm() {
    glNewList(right_lower_arm, GL_COMPILE);
        glTranslatef(-0.13, -0.025, 0.0);
        glScalef(0.06, 0.3, 0.05);
        drawCube(0.0, 1.0, 0.0);
    glEndList();
}

void body::init_right_hand() {
    glNewList(right_hand, GL_COMPILE);
        glTranslatef(-0.13, -0.2, 0.0);
        glScalef(0.06, 0.05, 0.05);
        drawCube();
    glEndList();
}

void body::init_left_upper_arm() {
    glNewList(left_upper_arm, GL_COMPILE);    
        glTranslatef(0.13, 0.275, 0.0);
        glScalef(0.06, 0.3, 0.05);
        drawCube();
    glEndList();
}

void body::init_left_lower_arm() {
    glNewList(left_lower_arm, GL_COMPILE);
        glTranslatef(0.13, -0.025, 0.0);
        glScalef(0.06, 0.3, 0.05);
        drawCube(0.0, 1.0, 0.0);
    glEndList();
}

void body::init_left_hand() {
    glNewList(left_hand, GL_COMPILE);
        glTranslatef(0.13, -0.2, 0.0);
        glScalef(0.06, 0.05, 0.05);
        drawCube();
    glEndList();
}

void body::init_right_thigh() {
    glNewList(right_thigh, GL_COMPILE);
        glTranslatef(-0.06, -0.185, 0.0);
        glScalef(0.08, 0.32, 0.05);
        drawCube(1.0, 0.0, 0.0);
    glEndList();
}

void body::init_right_leg() {
    glNewList(right_leg, GL_COMPILE);
        glTranslatef(-0.06, -0.465, 0.0);
        glScalef(0.08, 0.24, 0.05);
        drawCube();
    glEndList();
}

void body::init_right_foot() {
    glNewList(right_foot, GL_COMPILE);
        glTranslatef(-0.06, -0.595, 0.0475);
        glScalef(0.08, 0.02, 0.12);
        drawCube(1.0, 0.0, 0.0);
    glEndList();
}

void body::init_left_thigh() {
    glNewList(left_thigh, GL_COMPILE);
        glTranslatef(0.06, -0.185, 0.0);
        glScalef(0.08, 0.32, 0.05);
        drawCube(1.0, 0.0, 0.0);
    glEndList();
}

void body::init_left_leg() {

    glNewList(left_leg, GL_COMPILE);
        glTranslatef(0.06, -0.465, 0.0);
        glScalef(0.08, 0.24, 0.05);
        drawCube();
    glEndList();
}

void body::init_left_foot() {
    glNewList(left_foot, GL_COMPILE);
        glTranslatef(0.06, -0.595, 0.0475);
        glScalef(0.08, 0.02, 0.12);
        drawCube(1.0, 0.0, 0.0);
    glEndList();
}

void body::move_waist_x(double t) {
    double new_t = waist_x + t;
    if(new_t > waist_x_max)
        new_t = waist_x_max;
    else if(new_t < waist_x_min)
        new_t = waist_x_min;
    waist_x = new_t;
}

void body::move_right_shoulder_x(double t)
{
    double new_t = right_shoulder_x + t;
    if(new_t > 360)
        new_t = 360-new_t;
    right_shoulder_x = new_t;
}

void body::move_right_shoulder_y(double t)
{
    double new_t = right_shoulder_y + t;
    if(new_t > shoulder_y_max)
        new_t = shoulder_y_max;
    else if(new_t < shoulder_y_min)
        new_t = shoulder_y_min;
    right_shoulder_y = new_t;
}

void body::move_right_shoulder_z(double t)
{
    double new_t = right_shoulder_z + t;
    if(new_t > shoulder_z_max)
        new_t = shoulder_z_max;
    else if(new_t < shoulder_z_min)
        new_t = shoulder_z_min;
    right_shoulder_z = new_t;
}

void body::move_left_shoulder_x(double t)
{
    double new_t = left_shoulder_x + t;
    if(new_t > 360)
        new_t = 360-new_t;
    left_shoulder_x = new_t;
}

void body::move_left_shoulder_y(double t)
{
    double new_t = left_shoulder_y + t;
    if(new_t > shoulder_y_max)
        new_t = shoulder_y_max;
    else if(new_t < shoulder_y_min)
        new_t = shoulder_y_min;
    left_shoulder_y = new_t;
}

void body::move_left_shoulder_z(double t)
{
    double new_t = left_shoulder_z + t;
    if(new_t > shoulder_z_max)
        new_t = shoulder_z_max;
    else if(new_t < shoulder_z_min)
        new_t = shoulder_z_min;
    left_shoulder_z = new_t;
}

void body::move_right_elbow_x(double t)
{
    double new_t = right_elbow_x + t;
    if(new_t > elbow_x_max)
        new_t = elbow_x_max;
    else if(new_t < elbow_x_min)
        new_t = elbow_x_min;
    right_elbow_x = new_t;
}

void body::move_left_elbow_x(double t)
{
    double new_t = left_elbow_x + t;
    if(new_t > elbow_x_max)
        new_t = elbow_x_max;
    else if(new_t < elbow_x_min)
        new_t = elbow_x_min;
    left_elbow_x = new_t;
}

void body::move_right_hip_x(double t)
{
    double new_t = right_hip_x + t;
    if(new_t > hip_x_max)
        new_t = hip_x_max;
    else if(new_t < hip_x_min)
        new_t = hip_x_min;
    right_hip_x = new_t;
}

void body::move_right_hip_y(double t)
{
    double new_t = right_hip_y + t;
    if(new_t > hip_y_max)
        new_t = hip_y_max;
    else if(new_t < hip_y_min)
        new_t = hip_y_min;
    right_hip_y = new_t;
}

void body::move_right_hip_z(double t)
{
    double new_t = right_hip_z + t;
    if(new_t > hip_z_max)
        new_t = hip_z_max;
    else if(new_t < hip_z_min)
        new_t = hip_z_min;
    right_hip_z = new_t;
}

void body::move_left_hip_x(double t)
{
    double new_t = left_hip_x + t;
    if(new_t > hip_x_max)
        new_t = hip_x_max;
    else if(new_t < hip_x_min)
        new_t = hip_x_min;
    left_hip_x = new_t;
}

void body::move_left_hip_y(double t)
{
    double new_t = left_hip_y + t;
    if(new_t > hip_y_max)
        new_t = hip_y_max;
    else if(new_t < hip_y_min)
        new_t = hip_y_min;
    left_hip_y = new_t;
}

void body::move_left_hip_z(double t)
{
    double new_t = left_hip_z + t;
    if(new_t > hip_z_max)
        new_t = hip_z_max;
    else if(new_t < hip_z_min)
        new_t = hip_z_min;
    left_hip_z = new_t;
}

void body::move_right_knee_x(double t)
{
    double new_t = right_knee_x + t;
    if(new_t > knee_x_max)
        new_t = knee_x_max;
    else if(new_t < knee_x_min)
        new_t = knee_x_min;
    right_knee_x = new_t;
}

void body::move_left_knee_x(double t)
{
    double new_t = left_knee_x + t;
    if(new_t > knee_x_max)
        new_t = knee_x_max;
    else if(new_t < knee_x_min)
        new_t = knee_x_min;
    left_knee_x = new_t;
}
