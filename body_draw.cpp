#include "body.hpp"
#include "environment.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

//Constraint definitions
double body::shoulder_x_min = 0;
double body::shoulder_x_max = 135;
double body::shoulder_y_min = 0;
double body::shoulder_y_max = 135;
double body::shoulder_z_min = -225;
double body::shoulder_z_max = 225;

double body::waist_x_min = 0;
double body::waist_x_max = 180;
double body::waist_y_min = -90;
double body::waist_y_max = 90;
double body::waist_z_min = -90;
double body::waist_z_max = 90;

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

double body::wrist_x_min = -45;
double body::wrist_x_max = 45;
double body::wrist_z_min = -45;
double body::wrist_z_max = 45;

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

    pos_x = 0;
    pos_y = 0;
    pos_z = 0;

    elbows_y_offset = 0;
    count_elbows_in = 0;
    count_elbows_out = 0;

    transformed = false;
    dist = 0;
    turn = 0;
    wheel_rotate_angle = 0;
    headlight = false;
    day = true;
    moon_toggle = false; 
    frames = 0;
    keyfile.open("keyframes.txt", std::fstream::out);
    playback = false;
    terminate = false;
   /* Trees */    
    for(int i = 0; i < 100; i++) {
        tree_standing[i] = true;
        tree_fall_angle[i] = 0;
        tree_y_angle[i] = 0;
        float xrand = (rand()%50);
        float zrand = (rand()%50);
        tree_x[i] = xrand - 25;
        tree_z[i] = zrand - 25;
        //std::cout << i << " " << tree_x[i] << " " << tree_z[i] << std::endl;
    }

    /*Camera*/
    count_transform = 0;
    count_revert = 0;
    camera_r = 4.0;
    camera_t = 15;
    camera_p = 0;
    camera = 1;    

    ortho_y_angle = 0;

    rotate_x_angle = 0;
    rotate_y_angle = 0;
    rotate_z_angle = 0;

    lookat_x = 0;
    lookat_y = 0;
    lookat_z = 0;

    camera_free = true; 

    //Body Parts
    /*Waist*/
    waist_x = 0;
    waist_y = 0;
    waist_z = 0;

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

    /*Right Wrist*/
    right_wrist_x = 0;
    right_wrist_z = 0;

    /*Left Wrist*/
    left_wrist_x = 0;
    left_wrist_z = 0;

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

    /*Shoulder Joints*/
    rs_joint_x = 0;
    ls_joint_x = 0;

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
    init_joints();
}


void body::render() 
{
    if(playback)
        interpolate();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(camera == 0)
    {
        glOrtho(-3, 3, -3, 3, 0.01, 100);
    }
    else if(camera == 1) 
    {
        double n = 1.0 - (0.18 / camera_r);
        glFrustum(-n, n, -n, n, n, 400);
    }
    else
    {
        glFrustum(-0.06, 0.06, -0.06, 0.06, 0.01, 400);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //The different cameras
    switch(camera) {
        case 0:
            gluLookAt(20*sin(ortho_y_angle*PI/180), 0, 20*cos(ortho_y_angle*PI/180), 0, 0, 0, 0, 1, 0);
            break;
        case 1:
            if(camera_free)
                gluLookAt(camera_r*cos(camera_t*PI/180)*sin(camera_p*PI/180) + lookat_x, camera_r*sin(camera_t*PI/180) + lookat_y, camera_r*cos(camera_t*PI/180)*cos(camera_p*PI/180) + lookat_z, lookat_x, lookat_y, lookat_z, 0, 1, 0);
            else
                gluLookAt(camera_r*cos(camera_t*PI/180)*sin(camera_p*PI/180) + pos_x, camera_r*sin(camera_t*PI/180) + pos_y, camera_r*cos(camera_t*PI/180)*cos(camera_p*PI/180) + pos_z, pos_x, pos_y, pos_z, 0, 1, 0);
            break;
        case 2:
            gluLookAt(-0.5 * sin(rotate_y_angle*PI/180) + pos_x, 0.8 + pos_y, -0.5 * cos(rotate_y_angle*PI/180) + pos_z, pos_x, pos_y, pos_z, 0, 1, 0);
            break;
        case 3:
            gluLookAt(pos_x + 0.2*sin(rotate_y_angle*PI/180), 0.5 + pos_y, pos_z + 0.2*cos(rotate_y_angle*PI/180), sin(rotate_y_angle*PI/180) + pos_x , 0.5 + pos_y, cos(rotate_y_angle*PI/180) + pos_z, 0, 1, 0);
            break;
    } 

    //The headlights definition
    GLfloat position1[] =  {0.05+pos_x, 0.075+pos_y, 0.08+pos_z, 1.0};
    GLfloat spotDir1[] = {sin(rotate_y_angle*PI/180.0), 0.0, cos(rotate_y_angle*PI/180.0)};
    glLightfv(GL_LIGHT1, GL_POSITION, position1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDir1); 

    //Switch off all the lights initially
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);

    //Switch lights on according to requiements
    if(day)
        glEnable(GL_LIGHT0);
    else if(!(day ^ moon_toggle))
        glEnable(GL_LIGHT2);
    if(headlight)
        glEnable(GL_LIGHT1);

    //Render Environment
    renderGround((!day) && headlight);
    renderSky(day, moon_toggle);

    //Place trees
    for(int i = 0; i < 100; i++) {
        renderTree(tree_x[i], tree_z[i], tree_standing[i], tree_y_angle[i], tree_fall_angle[i]);
        if(!tree_standing[i] && tree_fall_angle[i] < 77.0) 
        {
            double new_fall_angle = 1.1 * tree_fall_angle[i] + 1;
            if(new_fall_angle > 77.0)
            {
                new_fall_angle = 77.0;
            }
            tree_fall_angle[i] = new_fall_angle;
        }
        if(tree_standing[i] && std::abs(tree_x[i] - pos_x) < 0.15 && std::abs(tree_z[i] - pos_z) < 0.15) 
        {
            tree_standing[i] = false;
            tree_y_angle[i] = rotate_y_angle;
        }
    }

    //Translate/turn according to key movments
    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(rotate_y_angle, 0, 1, 0);

    //To transform the bot into car
    transform();
    //Get back to bot state
    revert();


    //Bot rendering begins
    //The pelvis
    glPushMatrix();
        glCallList(pelvis);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, 0.025, 0.0);
        glRotatef(waist_x, 1.0, 0.0, 0.0); 
        glRotatef(waist_y, 0.0, 1.0, 0.0);
        glRotatef(waist_z, 0.0, 0.0, 1.0);
        glTranslatef(0.0, -0.025, 0.0);
        
        //Torso portion
        glPushMatrix();
            glCallList(torso);            
            if(headlight) 
            {  
                GLfloat emit[] = {1.0, 1.0, 1.0, 1.0};
                glMaterialfv(GL_FRONT, GL_EMISSION, emit);
            }
            glPushMatrix();
                glTranslatef(0.05, 0.075, 0.0725);
                glScalef(0.06, 0.05, 0.01);
                texcube(0, 0.6, 0.6, 0.6);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.05, 0.075, 0.0725);
                glScalef(0.06, 0.05, 0.01);
                texcube(0, 0.6, 0.6, 0.6);
            glPopMatrix();
            GLfloat emit2[] = {0.0, 0.0, 0.0, 0.0};
            glMaterialfv(GL_FRONT, GL_EMISSION, emit2);
        glPopMatrix();

        //Head
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
            glTranslatef(-0.1, 0.0, 0.0);
            glRotatef(rs_joint_x, 0.0, 1.0, 0.0);
            glTranslatef(0.1, 0.0, 0.0);
            glPushMatrix();
                glCallList(rs_joint);
            glPopMatrix();
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
                glTranslatef(0.0, elbows_y_offset, 0.0);
                glTranslatef(-0.13, 0.125, 0.0);
                /*Rotate Elbow Joint*/
                glRotatef(right_elbow_x, 1.0, 0.0, 0.0);
                /*Move pivot up*/
                glTranslatef(0.13, -0.125, 0.0);

                glPushMatrix();
                    glCallList(right_lower_arm);
                glPopMatrix();

                glTranslatef(-0.16, -0.175, 0.0);
                glRotatef(right_wrist_x, 1.0, 0.0, 0.0);
                glRotatef(right_wrist_z, 0.0, 0.0, 1.0);
                glTranslatef(0.16, 0.175, 0.0);

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
            glTranslatef(0.1, 0.0, 0.0);
            glRotatef(ls_joint_x, 0.0, 1.0, 0.0);
            glTranslatef(-0.1, 0.0, 0.0);
            glPushMatrix();
                glCallList(ls_joint);
            glPopMatrix();
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
                glTranslatef(0.0, elbows_y_offset, 0.0);
                glTranslatef(0.13, 0.125, 0.0);
                /*Rotate Elbow Joint*/
                glRotatef(left_elbow_x, 1.0, 0.0, 0.0);
                /*Move pivot up*/
                glTranslatef(-0.13, -0.125, 0.0);

                glPushMatrix();
                    glCallList(left_lower_arm);
                glPopMatrix();

                glTranslatef(0.16, -0.175, 0.0);
                glRotatef(left_wrist_x, 1.0, 0.0, 0.0);
                glRotatef(left_wrist_z, 0.0, 0.0, 1.0);
                glTranslatef(-0.16, 0.175, 0.0);

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
            glTranslatef(-0.115, -0.145, 0.0);
            glRotatef(90-6*turn, 0, 0, 1);
            glRotatef(wheel_rotate_angle, 0, 1, 0);
            glScalef(0.15, 0.03, 0.15);
            texCylinder(0.5, 0.5, 0.5, 7);
        glPopMatrix();

        /*Leg below knees*/
        glPushMatrix();
            glTranslatef(0.06, -0.345, 0.0);
            glRotatef(right_knee_x, 1.0, 0.0, 0.0);
            glTranslatef(-0.06, 0.345, 0.0);

            glPushMatrix();
                glCallList(right_leg);
                glTranslatef(-0.125, -0.465, 0.0);
                glRotatef(90, 0, 0, 1); 
                glRotatef(wheel_rotate_angle, 0, 1, 0);
                glScalef(0.15, 0.05, 0.15);
                texCylinder(0.5, 0.5, 0.5, 7);
            glPopMatrix();

            /*Ankle*/
            glPushMatrix();
                glTranslatef(-0.06, -0.585, -0.0125);
                glRotatef(right_ankle_x, 1.0, 0.0, 0.0);
                glRotatef(right_ankle_y, 0.0, 1.0, 0.0);
                glTranslatef(0.06, 0.585, 0.0125);
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
            glTranslatef(0.115, -0.145, 0.0);
            glRotatef(90-6*turn, 0, 0, 1); 
            glRotatef(wheel_rotate_angle, 0, 1, 0);
            glScalef(0.15, 0.03, 0.15);
            texCylinder(0.5, 0.5, 0.5, 7);
        glPopMatrix();

        /*Leg below knees*/
        glPushMatrix();
            glTranslatef(0.06, -0.345, 0.0);
            glRotatef(left_knee_x, 1.0, 0.0, 0.0);
            glTranslatef(-0.06, 0.345, 0.0);

            glPushMatrix();
                glCallList(left_leg);
                glTranslatef(0.125, -0.465, 0);
                glRotatef(90, 0, 0, 1); 
                glRotatef(wheel_rotate_angle, 0, 1, 0);
                glScalef(0.15, 0.05, 0.15);
                texCylinder(0.5, 0.5, 0.5, 7);
            glPopMatrix();

            /*Ankle*/
            glPushMatrix();
                glTranslatef(0.06, -0.585, -0.0125);
                glRotatef(left_ankle_x, 1.0, 0.0, 0.0);
                glRotatef(left_ankle_y, 0.0, 1.0, 0.0);
                glTranslatef(-0.06, 0.585, 0.0125);
                glCallList(left_foot);
            glPopMatrix();
            /*Ankle Ends*/
        glPopMatrix();
        /*Leg below knees ends*/
    glPopMatrix();
    /*The left leg ends*/
}
//Body Rendering ends

//Define call lists from here
void body::init_pelvis() 
{
    glNewList(pelvis, GL_COMPILE);
        glScalef(0.2, 0.05, 0.07);
        texcube(0, 0.0, 0.0, 1.0);
    glEndList();
}

void body::init_torso() 
{
    glNewList(torso, GL_COMPILE);
        glPushMatrix();
            glTranslatef(0.0, 0.225, 0.0);
            glScalef(0.2, 0.4, 0.15);
            texcube(0, 0.6, 0.0, 0.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.225, -0.0725);
            glScalef(0.14, 0.34, 0.01);
            texcube(0, 0.6, 0.6, 0.6);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.325, 0.0725);
            glScalef(0.18, 0.15, 0.01);
            texcube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.200, 0.0725);
            glScalef(0.15, 0.04, 0.01);
            texcube(0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.160, 0.0725);
            glScalef(0.15, 0.01, 0.01);
            texcube(0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.140, 0.0725);
            glScalef(0.15, 0.01, 0.01);
            texcube(0);
        glPopMatrix();
            glEndList();
}

void body::init_head() 
{
    glNewList(head, GL_COMPILE);
        glPushMatrix();
            glTranslatef(0.0, 0.475, 0.0);
            glScalef(0.1, 0.1, 0.05);
            texcube(0, 0.0, 0.0, 1.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.515, 0.0);
            glScalef(0.11, 0.010, 0.06);
            texcube(0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.025, 0.480, 0.025);
            glScalef(0.025, 0.020, 0.005);
            texcube(0, 1.0, 1.0, 0.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.025, 0.480, 0.025);
            glScalef(0.025, 0.020, 0.005);
            texcube(0, 1.0, 1.0, 0.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.440, 0.025);
            glScalef(0.09, 0.04, 0.005);
            texcube(0);
        glPopMatrix();
    glEndList();
}

void body::init_right_upper_arm() 
{
    glNewList(right_upper_arm, GL_COMPILE);    
        glTranslatef(-0.16, 0.275, 0.0);
        glScalef(0.08, 0.3, 0.08);
        texcube(0, 0.5, 0.0, 0.0);
    glEndList();
}

void body::init_right_lower_arm() 
{
    glNewList(right_lower_arm, GL_COMPILE);
        glTranslatef(-0.16, -0.025, 0.0);
        glScalef(0.06, 0.3, 0.06);
        texcube(0, 1.0, 0.0, 0.0);
    glEndList();
}

void body::init_right_hand() 
{
    glNewList(right_hand, GL_COMPILE);
        glTranslatef(-0.16, -0.2, 0.0);
        glScalef(0.07, 0.05, 0.07);
        texcube(0, 0.0, 0.0, 1.0);
    glEndList();
}

void body::init_left_upper_arm() 
{
    glNewList(left_upper_arm, GL_COMPILE);    
        glTranslatef(0.16, 0.275, 0.0);
        glScalef(0.08, 0.3, 0.08);
        texcube(0, 0.5, 0.0, 0.0);
    glEndList();
}

void body::init_left_lower_arm() 
{
    glNewList(left_lower_arm, GL_COMPILE);
        glTranslatef(0.16, -0.025, 0.0);
        glScalef(0.06, 0.3, 0.06);
        texcube(0, 1.0, 0.0, 0.0);
    glEndList();
}

void body::init_left_hand() 
{
    glNewList(left_hand, GL_COMPILE);
        glTranslatef(0.16, -0.2, 0.0);
        glScalef(0.07, 0.05, 0.07);
        texcube(0, 0.0, 0.0, 1.0);
    glEndList();
}

void body::init_right_thigh() 
{
    glNewList(right_thigh, GL_COMPILE);
        glPushMatrix();
        glTranslatef(-0.06, -0.185, 0.0);
        glScalef(0.08, 0.32, 0.12);
        texcube(0, 0.6, 0.6, 0.6);
        glPopMatrix();
    glEndList();
}

void body::init_right_leg() 
{
    glNewList(right_leg, GL_COMPILE);
        glPushMatrix();
        glTranslatef(-0.06, -0.465, 0.0);
        glScalef(0.08, 0.24, 0.08);
        texcube(0, 0.0, 0.0, 1.0);
        glPopMatrix();
        glEndList();
}

void body::init_right_foot() 
{
    glNewList(right_foot, GL_COMPILE);
        glTranslatef(-0.06, -0.595, 0.0475);
        glScalef(0.08, 0.04, 0.12);
        texcube(0, 0.0, 0.0, 1.0);
    glEndList();
}

void body::init_left_thigh() 
{
    glNewList(left_thigh, GL_COMPILE);
        glPushMatrix();
        glTranslatef(0.06, -0.185, 0.0);
        glScalef(0.08, 0.32, 0.12);
        texcube(0, 0.6, 0.6, 0.6);
        glPopMatrix();
    glEndList();
}

void body::init_left_leg() 
{

    glNewList(left_leg, GL_COMPILE);
        glPushMatrix();
        glTranslatef(0.06, -0.465, 0.0);
        glScalef(0.08, 0.24, 0.08);
        texcube(0, 0.0, 0.0, 1.0);
        glPopMatrix();
        glEndList();
}

void body::init_left_foot() 
{
    glNewList(left_foot, GL_COMPILE);
        glTranslatef(0.06, -0.595, 0.0475);
        glScalef(0.08, 0.04, 0.12);
        texcube(0, 0.0, 0.0, 1.0);
    glEndList();
}

void body::init_joints() 
{
    glNewList(rs_joint, GL_COMPILE);
        glTranslatef(-0.115, 0.375, 0.0);
        glScalef(0.03, 0.05, 0.03);
        texcube(0, 0.0, 0.0, 1.0);
    glEndList();
    glNewList(ls_joint, GL_COMPILE);
        glTranslatef(0.115, 0.375, 0.0);
        glScalef(0.03, 0.05, 0.03);
        texcube(0, 0.0, 0.0, 1.0);
    glEndList();
}

//End Call List Definitions

void body::keyframe() {
    keyfile << frames << '\n';
    frames = 0;
    keyfile << pos_x;
    keyfile << ' ';
    keyfile << pos_y;
    keyfile << ' ';
    keyfile << pos_z;
    keyfile << ' ';
    keyfile << rotate_x_angle;
    keyfile << ' ';
    keyfile << rotate_y_angle;
    keyfile << ' ';
    keyfile << rotate_z_angle;
    keyfile << ' ';
    keyfile << ortho_y_angle;
    keyfile << ' ';
	keyfile << elbows_y_offset;
    keyfile << ' ';
    keyfile << right_shoulder_x;
    keyfile << ' ';
    keyfile << right_shoulder_y;
    keyfile << ' ';
    keyfile << right_shoulder_z;
    keyfile << ' ';
    keyfile << left_shoulder_x;
    keyfile << ' ';
    keyfile << left_shoulder_y;
    keyfile << ' ';
    keyfile << left_shoulder_z;
    keyfile << ' ';
    keyfile << waist_x;
    keyfile << ' ';
    keyfile << waist_y;
    keyfile << ' ';
    keyfile << waist_z;
    keyfile << ' ';
    keyfile << neck_x;
    keyfile << ' ';
    keyfile << neck_y;
    keyfile << ' ';
    keyfile << neck_z;
    keyfile << ' ';
    keyfile << right_ankle_x;
    keyfile << ' ';
    keyfile << right_ankle_y;
    keyfile << ' ';
    keyfile << right_wrist_x;
    keyfile << ' ';
    keyfile << right_wrist_z;
    keyfile << ' ';
    keyfile << left_ankle_x;
    keyfile << ' ';
    keyfile << left_ankle_y;
    keyfile << ' ';
    keyfile << left_wrist_x;
    keyfile << ' ';
    keyfile << left_wrist_z;
    keyfile << ' ';
    keyfile << right_hip_x;
    keyfile << ' ';
    keyfile << right_hip_y;
    keyfile << ' ';
    keyfile << right_hip_z;
    keyfile << ' ';
    keyfile << left_hip_x;
    keyfile << ' ';
    keyfile << left_hip_y;
    keyfile << ' ';
    keyfile << left_hip_z;
    keyfile << ' ';
    keyfile << right_elbow_x;
    keyfile << ' ';
    keyfile << left_elbow_x;
    keyfile << ' ';
    keyfile << right_knee_x;
    keyfile << ' ';
    keyfile << left_knee_x;
    keyfile << ' ';
    keyfile << rs_joint_x;
    keyfile << ' ';
    keyfile << ls_joint_x;
    keyfile << ' ';
    keyfile << camera;
    keyfile << ' ';
    keyfile << turn;
    keyfile << ' ';
    keyfile << wheel_rotate_angle;
    keyfile << ' ';
    keyfile << lookat_x;
    keyfile << ' ';
    keyfile << lookat_y;
    keyfile << ' ';
    keyfile << lookat_z;
    keyfile << ' ';
    keyfile << headlight;
    keyfile << ' ';
    keyfile << day;
    keyfile << ' ';
    keyfile << moon_toggle;
    keyfile << ' ';
    int i;
    for(i = 0; i < 100; i++)
    	keyfile << tree_standing[i] << ' ';
    keyfile << camera_r;
    keyfile << ' ';
    keyfile << camera_t;
    keyfile << ' ';
    keyfile << camera_p;
    keyfile << ' ';
    keyfile << camera_free;
    keyfile << ' ';    
    keyfile.flush();
    std::cout << "Keyframe saved\n";
}

void body::playback_init() {
    playback = true;
    keyfile << "-1\n";
    keyfile.close();
    keyfile.open("keyframes.txt", std::fstream::in);
    int i;
    keyfile >> i;
    std::cout << "Playing Back..." << std::endl;
    readframe();
    frames = 0;        
    for(i = 0; i < 100; i++) {
        tree_fall_angle[i] = 0;
        tree_y_angle[i] = 0;
    }
}

void body::readframe() {
    keyfile >> ip_pos_x;
    keyfile >> ip_pos_y;
    keyfile >> ip_pos_z;
    keyfile >> ip_rotate_x_angle;
    keyfile >> ip_rotate_y_angle;
    keyfile >> ip_rotate_z_angle;
    keyfile >> ip_ortho_y_angle;
	keyfile >> ip_elbows_y_offset;
    keyfile >> ip_right_shoulder_x;
    keyfile >> ip_right_shoulder_y;
    keyfile >> ip_right_shoulder_z;
    keyfile >> ip_left_shoulder_x;
    keyfile >> ip_left_shoulder_y;
    keyfile >> ip_left_shoulder_z;
    keyfile >> ip_waist_x;
    keyfile >> ip_waist_y;
    keyfile >> ip_waist_z;
    keyfile >> ip_neck_x;
    keyfile >> ip_neck_y;
    keyfile >> ip_neck_z;
    keyfile >> ip_right_ankle_x;
    keyfile >> ip_right_ankle_y;
    keyfile >> ip_right_wrist_x;
    keyfile >> ip_right_wrist_z;
    keyfile >> ip_left_ankle_x;
    keyfile >> ip_left_ankle_y;
    keyfile >> ip_left_wrist_x;
    keyfile >> ip_left_wrist_z;
    keyfile >> ip_right_hip_x;
    keyfile >> ip_right_hip_y;
    keyfile >> ip_right_hip_z;
    keyfile >> ip_left_hip_x;
    keyfile >> ip_left_hip_y;
    keyfile >> ip_left_hip_z;
    keyfile >> ip_right_elbow_x;
    keyfile >> ip_left_elbow_x;
    keyfile >> ip_right_knee_x;
    keyfile >> ip_left_knee_x;
    keyfile >> ip_rs_joint_x;
    keyfile >> ip_ls_joint_x;
    keyfile >> ip_camera;
    keyfile >> ip_turn;
    keyfile >> ip_wheel_rotate_angle;
    keyfile >> ip_lookat_x;
    keyfile >> ip_lookat_y;
    keyfile >> ip_lookat_z;
    keyfile >> ip_headlight;
    keyfile >> ip_day;
    keyfile >> ip_moon_toggle;
    int i;
    for(i = 0; i < 100; i++) {
    	keyfile >> ip_tree_standing[i];
    }
    keyfile >> ip_camera_r;
    keyfile >> ip_camera_t;
    keyfile >> ip_camera_p;
    keyfile >> ip_camera_free;
    keyfile >> ip_frames; 
}

void body::interpolate() {
if(frames == 0) {
    pos_x = ip_pos_x;
    pos_y = ip_pos_y;
    pos_z = ip_pos_z;
    rotate_x_angle = ip_rotate_x_angle;
    rotate_y_angle = ip_rotate_y_angle;
    rotate_z_angle = ip_rotate_z_angle;
    ortho_y_angle = ip_ortho_y_angle;
	elbows_y_offset = ip_elbows_y_offset;
    right_shoulder_x = ip_right_shoulder_x;
    right_shoulder_y = ip_right_shoulder_y;
    right_shoulder_z = ip_right_shoulder_z;
    left_shoulder_x = ip_left_shoulder_x;
    left_shoulder_y = ip_left_shoulder_y;
    left_shoulder_z = ip_left_shoulder_z;
    waist_x = ip_waist_x;
    waist_y = ip_waist_y;
    waist_z = ip_waist_z;
    neck_x = ip_neck_x;
    neck_y = ip_neck_y;
    neck_z = ip_neck_z;
    right_ankle_x = ip_right_ankle_x;
    right_ankle_y = ip_right_ankle_y;
    right_wrist_x = ip_right_wrist_x;
    right_wrist_z = ip_right_wrist_z;
    left_ankle_x = ip_left_ankle_x;
    left_ankle_y = ip_left_ankle_y;
    left_wrist_x = ip_left_wrist_x;
    left_wrist_z = ip_left_wrist_z;
    right_hip_x = ip_right_hip_x;
    right_hip_y = ip_right_hip_y;
    right_hip_z = ip_right_hip_z;
    left_hip_x = ip_left_hip_x;
    left_hip_y = ip_left_hip_y;
    left_hip_z = ip_left_hip_z;
    right_elbow_x = ip_right_elbow_x;
    left_elbow_x = ip_left_elbow_x;
    right_knee_x = ip_right_knee_x;
    left_knee_x = ip_left_knee_x;
    rs_joint_x = ip_rs_joint_x;
    ls_joint_x = ip_ls_joint_x;
    camera = ip_camera;
    turn = ip_turn;
    wheel_rotate_angle = ip_wheel_rotate_angle;
    lookat_x = ip_lookat_x;
    lookat_y = ip_lookat_y;
    lookat_z = ip_lookat_z;
    headlight = ip_headlight;
    day = ip_day;
    moon_toggle = ip_moon_toggle;
    int i;
    for(i = 0; i < 100; i++)
    	tree_standing[i] = ip_tree_standing[i];
    camera_r = ip_camera_r;
    camera_t = ip_camera_t;
    camera_p = ip_camera_p;
    camera_free = ip_camera_free;
    frames = ip_frames;
    if(frames < 0) {
        terminate = true;
        return;
    }    
    readframe();
}
else {
    linear_interpolate(pos_x, ip_pos_x);
    linear_interpolate(pos_y, ip_pos_y);
    linear_interpolate(pos_z, ip_pos_z);
    angular_interpolate(rotate_x_angle, ip_rotate_x_angle);
    angular_interpolate(rotate_y_angle, ip_rotate_y_angle);
    angular_interpolate(rotate_z_angle, ip_rotate_z_angle);
    angular_interpolate(ortho_y_angle, ip_ortho_y_angle);
	linear_interpolate(elbows_y_offset, ip_elbows_y_offset);
    linear_interpolate(right_shoulder_x, ip_right_shoulder_x);
    linear_interpolate(right_shoulder_y, ip_right_shoulder_y);
    linear_interpolate(right_shoulder_z, ip_right_shoulder_z);
    linear_interpolate(left_shoulder_x, ip_left_shoulder_x);
    linear_interpolate(left_shoulder_y, ip_left_shoulder_y);
    linear_interpolate(left_shoulder_z, ip_left_shoulder_z);
    linear_interpolate(waist_x, ip_waist_x);
    linear_interpolate(waist_y, ip_waist_y);
    linear_interpolate(waist_z, ip_waist_z);
    linear_interpolate(neck_x, ip_neck_x);
    linear_interpolate(neck_y, ip_neck_y);
    linear_interpolate(neck_z, ip_neck_z);
    linear_interpolate(right_ankle_x, ip_right_ankle_x);
    linear_interpolate(right_ankle_y, ip_right_ankle_y);
    linear_interpolate(right_wrist_x, ip_right_wrist_x);
    linear_interpolate(right_wrist_z, ip_right_wrist_z);
    linear_interpolate(left_ankle_x, ip_left_ankle_x);
    linear_interpolate(left_ankle_y, ip_left_ankle_y);
    linear_interpolate(left_wrist_x, ip_left_wrist_x);
    linear_interpolate(left_wrist_z, ip_left_wrist_z);
    linear_interpolate(right_hip_x, ip_right_hip_x);
    linear_interpolate(right_hip_y, ip_right_hip_y);
    linear_interpolate(right_hip_z, ip_right_hip_z);
    linear_interpolate(left_hip_x, ip_left_hip_x);
    linear_interpolate(left_hip_y, ip_left_hip_y);
    linear_interpolate(left_hip_z, ip_left_hip_z);
    linear_interpolate(right_elbow_x, ip_right_elbow_x);
    linear_interpolate(left_elbow_x, ip_left_elbow_x);
    linear_interpolate(right_knee_x, ip_right_knee_x);
    linear_interpolate(left_knee_x, ip_left_knee_x);
    linear_interpolate(rs_joint_x, ip_rs_joint_x);
    linear_interpolate(ls_joint_x, ip_ls_joint_x);
    linear_interpolate(turn, ip_turn);
    angular_interpolate(wheel_rotate_angle, ip_wheel_rotate_angle);
    linear_interpolate(lookat_x, ip_lookat_x);
    linear_interpolate(lookat_y, ip_lookat_y);
    linear_interpolate(lookat_z, ip_lookat_z);
    linear_interpolate(camera_r, ip_camera_r);
    angular_interpolate(camera_t, ip_camera_t);
    angular_interpolate(camera_p, ip_camera_p);
    frames--;
}    
}

void body::linear_interpolate(double &var, double &ip_var) {
    var = (frames * var + ip_var) / (frames + 1);   
}

void body::angular_interpolate(double &var, double &ip_var) {
    if(std::abs(ip_var - var) < 180.0)
        linear_interpolate(var, ip_var);
    else {
        double delta = (360.0 - std::abs(ip_var - var)) / (frames + 1);
        if(ip_var > var) {
            var -= delta;
            if(var < 0)
                var += 360.0;
        }
        else {
            var += delta;
            if(var >= 360.0)
                var -= 360.0;
        }
    }
}


