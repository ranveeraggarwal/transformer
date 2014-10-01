#include "body.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

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

double body::neck_x_min = -90;
double body::neck_x_max = 90;
double body::neck_y_min = -90;
double body::neck_y_max = 90;
double body::neck_z_min = -90;
double body::neck_z_max = 90;

double body::ankle_x_min = -45;
double body::ankle_x_max = 45;
double body::ankle_y_min = -45;
double body::ankle_y_max = 45;

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

double body::elbow_x_min = -150;
double body::elbow_x_max = 0;

double body::knee_x_max = 150;
double body::knee_x_min = 0;


body::body() {
    /*Variables*/
    /*Camera*/

    count_transform = 0;
    count_revert = 0;
    camera_r = 1.5;
    camera_t = 0;
    camera_p = 0;

    rotate_x_angle = 0;
    rotate_y_angle = 0;
    rotate_z_angle = 0;
 
    /*Waist*/
    waist_x = 0;

    /*Neck*/
    neck_x = 0;
    neck_y = 0;
    neck_z = 0;

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

    /*Left Ankle*/
    left_ankle_x = 0;
    left_ankle_y = 0;

    /*Right Ankle*/
    right_ankle_x = 0;
    right_ankle_y = 0;

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

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.6, 0.6, -0.6, 0.6, camera_r-0.75, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camera_r*cos(camera_t*PI/180)*sin(camera_p*PI/180), camera_r*sin(camera_t*PI/180), camera_r*cos(camera_t*PI/180)*cos(camera_p*PI/180), 0, 0, 0, 0, 1, 0);
    transform();
    revert();
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
            glTranslatef(0.0, 0.425, 0.0);
            glRotatef(neck_x, 1.0, 0.0, 0.0);
            glRotatef(neck_y, 0.0, 1.0, 0.0);
            glRotatef(neck_z, 0.0, 0.0, 1.0);
            glTranslatef(0.0, -0.425, 0.0);
            glCallList(head);
        glPopMatrix();

        /*The right arm*/
        glPushMatrix();
            /*Move pivot back*/
            glTranslatef(-0.13, 0.375, 0.0);
            /*Shoulder Y rotation*/
            glRotatef(right_shoulder_y, 0.0, 1.0, 0.0);
            /*Shoulder Z rotation*/
            glRotatef(right_shoulder_z, 0.0, 0.0, 1.0); 
            /*Shoulder X rotation*/
            glRotatef(right_shoulder_x, 1.0, 0.0, 0.0); 
            /*Get pivot to origin*/
            glTranslatef(0.13, -0.375, 0.0);

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
            glTranslatef(0.13, 0.375, 0.0);
            /*Shoulder Y rotation*/
            glRotatef(left_shoulder_y, 0.0, 1.0, 0.0);
            /*Shoulder Z rotation*/
            glRotatef(left_shoulder_z, 0.0, 0.0, 1.0); 
            /*Shoulder X rotation*/
            glRotatef(left_shoulder_x, 1.0, 0.0, 0.0); 
            /*Get pivot to origin*/
            glTranslatef(-0.13, -0.375, 0.0);

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
        glTranslatef(-0.06, -0.025, 0.0);
        glRotatef(right_hip_x, 1.0, 0.0, 0.0);
        glRotatef(right_hip_y, 0.0, 1.0, 0.0);
        glRotatef(right_hip_z, 0.0, 0.0, 1.0);
        glTranslatef(0.06, 0.025, 0.0);

        glPushMatrix();
            glCallList(right_thigh);
        glPopMatrix();

        /*Leg below knees*/
        glPushMatrix();
            glTranslatef(0.06, -0.345, 0.0);
            glRotatef(right_knee_x, 1.0, 0.0, 0.0);
            glTranslatef(-0.06, 0.345, 0.0);

            glPushMatrix();
                glCallList(right_leg);
            glPopMatrix();

            /*Ankle*/
            glPushMatrix();
                glTranslatef(0.02, -0.585, -0.0125);
                glRotatef(right_ankle_x, 1.0, 0.0, 0.0);
                glRotatef(right_ankle_y, 0.0, 1.0, 0.0);
                glTranslatef(-0.02, 0.585, 0.0125);
                glCallList(right_foot);
            glPopMatrix();
            /*Ankle Ends*/
        glPopMatrix();
        /*Leg below knees ends*/
    glPopMatrix();
    /*The right leg ends*/

    /*The left leg begins*/
    glPushMatrix();
        glTranslatef(0.06, -0.025, 0.0);
        glRotatef(left_hip_x, 1.0, 0.0, 0.0);
        glRotatef(left_hip_y, 0.0, 1.0, 0.0);
        glRotatef(left_hip_z, 0.0, 0.0, 1.0);
        glTranslatef(-0.06, 0.025, 0.0);

        glPushMatrix();
            glCallList(left_thigh);
        glPopMatrix();

        /*Leg below knees*/
        glPushMatrix();
            glTranslatef(0.06, -0.345, 0.0);
            glRotatef(left_knee_x, 1.0, 0.0, 0.0);
            glTranslatef(-0.06, 0.345, 0.0);

            glPushMatrix();
                glCallList(left_leg);
            glPopMatrix();

            /*Ankle*/
            glPushMatrix();
                glTranslatef(0.02, -0.585, -0.0125);
                glRotatef(left_ankle_x, 1.0, 0.0, 0.0);
                glRotatef(left_ankle_y, 0.0, 1.0, 0.0);
                glTranslatef(-0.02, 0.585, 0.0125);
                glCallList(left_foot);
            glPopMatrix();
            /*Ankle Ends*/
        glPopMatrix();
        /*Leg below knees ends*/
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

void body::move_camera_r(double t) {
    double new_r = camera_r + t;
    if(new_r < 0.8)
        new_r = 0.8;
    if(new_r > 7)
        new_r = 7;
    camera_r = new_r;
}

void body::move_camera_t(double t) {

    double new_t = camera_t + t;
    if(new_t > 360)
        new_t -= 360;
    else if(new_t < 0)
        new_t += 360;
    camera_t = new_t;

}

void body::move_camera_p(double t) {

    double new_t = camera_p + t;
    if(new_t > 360)
        new_t -= 360;
    else if(new_t < 0)
        new_t += 360;
    camera_p = new_t;

}


void body::init_pelvis() {
    glNewList(pelvis, GL_COMPILE);
        glScalef(0.2, 0.05, 0.07);
        drawCube();
    glEndList();
}

void body::init_torso() {
    glNewList(torso, GL_COMPILE);
        glPushMatrix();
            glTranslatef(0.0, 0.150, 0.0);
            glScalef(0.19, 0.25, 0.08);
            drawCube(1.0, 0.0, 0.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.35, 0.0);
            glScalef(0.2, 0.15, 0.1);
            drawCube(0.95, 0.0, 0.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.115, 0.375, 0.0);
            glScalef(0.03, 0.05, 0.03);
            drawCube(0.0, 0.0, 0.5);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.115, 0.375, 0.0);
            glScalef(0.03, 0.05, 0.03);
            drawCube(0.0, 0.0, 0.5);
        glPopMatrix();
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
        glPushMatrix();
            glTranslatef(-0.16, 0.275, 0.0);
            glScalef(0.08, 0.3, 0.08);
            drawCube();
        glPopMatrix();
    glEndList();
}

void body::init_right_lower_arm() {
    glNewList(right_lower_arm, GL_COMPILE);
        glTranslatef(-0.16, -0.025, 0.0);
        glScalef(0.06, 0.3, 0.06);
        drawCube(0.0, 1.0, 0.0);
    glEndList();
}

void body::init_right_hand() {
    glNewList(right_hand, GL_COMPILE);
        glTranslatef(-0.16, -0.2, 0.0);
        glScalef(0.07, 0.05, 0.07);
        drawCube();
    glEndList();
}

void body::init_left_upper_arm() {
    glNewList(left_upper_arm, GL_COMPILE);    
        glTranslatef(0.16, 0.275, 0.0);
        glScalef(0.08, 0.3, 0.08);
        drawCube();
    glEndList();
}

void body::init_left_lower_arm() {
    glNewList(left_lower_arm, GL_COMPILE);
        glTranslatef(0.16, -0.025, 0.0);
        glScalef(0.06, 0.3, 0.06);
        drawCube(0.0, 1.0, 0.0);
    glEndList();
}

void body::init_left_hand() {
    glNewList(left_hand, GL_COMPILE);
        glTranslatef(0.16, -0.2, 0.0);
        glScalef(0.07, 0.05, 0.07);
        drawCube();
    glEndList();
}

void body::init_right_thigh() {
    glNewList(right_thigh, GL_COMPILE);
        glTranslatef(-0.06, -0.185, 0.0);
        glScalef(0.08, 0.32, 0.08);
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
        glScalef(0.08, 0.04, 0.12);
        drawCube(1.0, 0.0, 0.0);
    glEndList();
}

void body::init_left_thigh() {
    glNewList(left_thigh, GL_COMPILE);
        glTranslatef(0.06, -0.185, 0.0);
        glScalef(0.08, 0.32, 0.08);
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
        glScalef(0.08, 0.04, 0.12);
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

void body::move_right_ankle_x(double t)
{
    double new_t = right_ankle_x + t;
    if(new_t > ankle_x_max)
        new_t = ankle_x_max;
    else if(new_t < ankle_x_min)
        new_t = ankle_x_min;
    right_ankle_x = new_t;
}

void body::move_right_ankle_y(double t)
{
    double new_t = right_ankle_y + t;
    if(new_t > ankle_y_max)
        new_t = ankle_y_max;
    else if(new_t < ankle_y_min)
        new_t = ankle_y_min;
    right_ankle_y = new_t;
}

void body::move_left_ankle_x(double t)
{
    double new_t = left_ankle_x + t;
    if(new_t > ankle_x_max)
        new_t = ankle_x_max;
    else if(new_t < ankle_x_min)
        new_t = ankle_x_min;
    left_ankle_x = new_t;
}

void body::move_left_ankle_y(double t)
{
    double new_t = left_ankle_y + t;
    if(new_t > ankle_y_max)
        new_t = ankle_y_max;
    else if(new_t < ankle_y_min)
        new_t = ankle_y_min;
    left_ankle_y = new_t;
}

void body::move_neck_x(double t)
{
    double new_t = neck_x + t;
    if(new_t > neck_x_max)
        new_t = neck_x_max;
    else if(new_t < neck_x_min)
        new_t = neck_x_min;
    neck_x = new_t;
}

void body::move_neck_y(double t)
{
    double new_t = neck_y + t;
    if(new_t > neck_y_max)
        new_t = neck_y_max;
    else if(new_t < neck_y_min)
        new_t = neck_y_min;
    neck_y = new_t;
}

void body::move_neck_z(double t)
{
    double new_t = neck_z + t;
    if(new_t > neck_z_max)
        new_t = neck_z_max;
    else if(new_t < neck_z_min)
        new_t = neck_z_min;
    neck_z = new_t;
}
void body::transform()
{

    if(count_transform > 0) {
     /*Waist*/
    waist_x = 90 - (90 - waist_x) * (count_transform - 1) / (double)count_transform;

    /*Neck*/
    neck_x = neck_x * (count_transform - 1) / (double)count_transform;
    neck_y = neck_y * (count_transform - 1) / (double)count_transform;
    neck_z = neck_z * (count_transform - 1) / (double)count_transform;

    /*Right Shoulder*/
    right_shoulder_x = 60 - (60 - right_shoulder_x) * (count_transform - 1) / (double)count_transform;
    right_shoulder_y = right_shoulder_y * (count_transform - 1) / (double)count_transform;
    right_shoulder_z = right_shoulder_z * (count_transform - 1) / (double)count_transform;

    /*Left Shoulder*/
    left_shoulder_x = 60 - (60 - left_shoulder_x) * (count_transform - 1) / (double)count_transform;
    left_shoulder_y = left_shoulder_y * (count_transform - 1) / (double)count_transform;
    left_shoulder_z = left_shoulder_z * (count_transform - 1) / (double)count_transform;

    /*Right Hip*/
    right_hip_x = -90 - (-90 - right_hip_x) * (count_transform - 1) / (double)count_transform;
    right_hip_y = right_hip_y * (count_transform - 1) / (double)count_transform;
    right_hip_z = right_hip_z * (count_transform - 1) / (double)count_transform;

    /*Left Hip*/
    left_hip_x = -90 - (-90 - left_hip_x) * (count_transform - 1) / (double)count_transform;
    left_hip_y = left_hip_y * (count_transform - 1) / (double)count_transform;
    left_hip_z = left_hip_z * (count_transform - 1) / (double)count_transform;

    /*Left Elbow*/
    left_elbow_x = -90 - (-90 - left_elbow_x) * (count_transform - 1) / (double)count_transform;

    /*Right Elbow*/
    right_elbow_x = -90 - (-90 - right_elbow_x) * (count_transform - 1) / (double)count_transform;

    /*Left Knee*/
    left_knee_x = left_knee_x * (count_transform - 1) / (double)count_transform;

    /*Right Knee*/
    right_knee_x = right_knee_x * (count_transform - 1) / (double)count_transform;

    /*Left Ankle*/
    left_ankle_x = left_ankle_x * (count_transform - 1) / (double)count_transform;
    left_ankle_y = left_ankle_y * (count_transform - 1) / (double)count_transform;

    /*Right Ankle*/
    right_ankle_x = right_ankle_x * (count_transform - 1) / (double)count_transform;
    right_ankle_y = right_ankle_y * (count_transform - 1) / (double)count_transform;

    count_transform--;   
    }
}
void body::revert()
{

    if(count_revert > 0) {
     /*Waist*/
    waist_x =  waist_x * (count_revert - 1) / (double)count_revert;

    /*Neck*/
    neck_x = neck_x * (count_revert - 1) / (double)count_revert;
    neck_y = neck_y * (count_revert - 1) / (double)count_revert;
    neck_z = neck_z * (count_revert - 1) / (double)count_revert;

    /*Right Shoulder*/
    right_shoulder_x = right_shoulder_x * (count_revert - 1) / (double)count_revert;
    right_shoulder_y = right_shoulder_y * (count_revert - 1) / (double)count_revert;
    right_shoulder_z = right_shoulder_z * (count_revert - 1) / (double)count_revert;

    /*Left Shoulder*/
    left_shoulder_x = left_shoulder_x * (count_revert - 1) / (double)count_revert;
    left_shoulder_y = left_shoulder_y * (count_revert - 1) / (double)count_revert;
    left_shoulder_z = left_shoulder_z * (count_revert - 1) / (double)count_revert;

    /*Right Hip*/
    right_hip_x = right_hip_x * (count_revert - 1) / (double)count_revert;
    right_hip_y = right_hip_y * (count_revert - 1) / (double)count_revert;
    right_hip_z = right_hip_z * (count_revert - 1) / (double)count_revert;

    /*Left Hip*/
    left_hip_x = left_hip_x * (count_revert - 1) / (double)count_revert;
    left_hip_y = left_hip_y * (count_revert - 1) / (double)count_revert;
    left_hip_z = left_hip_z * (count_revert - 1) / (double)count_revert;

    /*Left Elbow*/
    left_elbow_x = left_elbow_x * (count_revert - 1) / (double)count_revert;

    /*Right Elbow*/
    right_elbow_x = right_elbow_x * (count_revert - 1) / (double)count_revert;

    /*Left Knee*/
    left_knee_x = left_knee_x * (count_revert - 1) / (double)count_revert;

    /*Right Knee*/
    right_knee_x = right_knee_x * (count_revert - 1) / (double)count_revert;

    /*Left Ankle*/
    left_ankle_x = left_ankle_x * (count_revert - 1) / (double)count_revert;
    left_ankle_y = left_ankle_y * (count_revert - 1) / (double)count_revert;

    /*Right Ankle*/
    right_ankle_x = right_ankle_x * (count_revert - 1) / (double)count_revert;
    right_ankle_y = right_ankle_y * (count_revert - 1) / (double)count_revert;

    count_revert--;   
    }
}



