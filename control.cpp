#include "control.hpp"
#include <iostream>
#include <cmath>

std::string active = "arandomstring";
int multiplier = 1;
void control(int key, int scancode, int action, int mods) {
    switch(key) {
        case GLFW_KEY_B:
            if(action == GLFW_PRESS && mods == 0)
                b->keyframe();
            if(action == GLFW_PRESS && mods == 1)
                b->playback_init();
            break;
        case GLFW_KEY_F:
            if(action == GLFW_PRESS || action == GLFW_REPEAT) {
                if(mods == 0)
                    b->frames += multiplier;
                else if(mods == 1)
                    b->frames -= multiplier;
                if(b->frames < 0)
                    b->frames = 0;
                std::cout << "Frames: " << b->frames << std::endl;
            }
            break;
        case GLFW_KEY_PERIOD:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 1) {
                multiplier++;
                std::cout << "Multiplier: " << multiplier << std::endl;
            }
            break;
        case GLFW_KEY_COMMA:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 1 && multiplier > 1) {
                multiplier--;
                std::cout << "Multiplier: " << multiplier << std::endl;
            }
            break;
        case GLFW_KEY_LEFT:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0) {
                if(b->camera == 0)
                    b->rotate_y_ortho(-5);
                if(b->camera == 1)
                    b->move_camera_p(-5);
            }
            else if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 1)
                if(b->camera == 1) {
                    b->lookat_x -= cos(b->camera_p*PI/180.0);
                    b->lookat_z += sin(b->camera_p*PI/180.0);
                }
            break;

        case GLFW_KEY_RIGHT:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0) {
                if(b->camera == 0)
                    b->rotate_y_ortho(5);
                if(b->camera == 1)
                    b->move_camera_p(5);
            }
            else if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 1)
                if(b->camera == 1) {
                    b->lookat_x += cos(b->camera_p*PI/180.0);
                    b->lookat_z -= sin(b->camera_p*PI/180.0);
                }
            break;

        case GLFW_KEY_UP:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0 && b->camera == 1)
                b->move_camera_t(5);
            else if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 1)
                if(b->camera == 1) {
                    b->lookat_z -= cos(b->camera_p*PI/180.0);
                    b->lookat_x -= sin(b->camera_p*PI/180.0);
                }
            break;

        case GLFW_KEY_DOWN:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0 && b->camera == 1)
                b->move_camera_t(-5);
            else if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 1)
                if(b->camera == 1) {
                    b->lookat_z += cos(b->camera_p*PI/180.0);
                    b->lookat_x += sin(b->camera_p*PI/180.0);
                }            
            break;

        case GLFW_KEY_N:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0 && b->camera == 1)
                b->move_camera_r(-0.1);
            break;

        case GLFW_KEY_M:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0 && b->camera == 1)
                b->move_camera_r(0.1);
            break;

        case GLFW_KEY_V:
            if((action == GLFW_PRESS) && mods == 0 && b->camera == 1)
                b->camera_free = !b->camera_free;
            break;


        case GLFW_KEY_0:
            if((action == GLFW_PRESS) && mods == 0)
                b->camera = 0;
            break;

        case GLFW_KEY_1:
            if((action == GLFW_PRESS) && mods == 0)
                b->camera = 1;
            break;

        case GLFW_KEY_2:
            if((action == GLFW_PRESS) && mods == 0)
                b->camera = 2;
            break;

        case GLFW_KEY_R:
            if((action == GLFW_PRESS) && mods == 0)
                b->day = !b->day;
            break;

        case GLFW_KEY_C:
            if((action == GLFW_PRESS) && mods == 0)
                b->moon_toggle = !b->moon_toggle;
            break;

       /*Activating various parts*/
        case GLFW_KEY_SPACE:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0) {
                b->transformed = !b->transformed;
                if(b->transformed) {
                    b->count_transform = 200;
                    b->count_elbows_in = 100;
                }
                else {
                    if(b->camera == 3)
                        b->camera = 1;
                    b->count_revert = 200;
                    b->count_elbows_out = 100;
                }
            }
            break;
    }

    if(b->transformed) {
        switch(key) {
            case GLFW_KEY_3:
                if(action == GLFW_PRESS && mods == 0)
                    b->camera = 3;
                break;
            case GLFW_KEY_W:
                if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                    b->dist = 0.1;
                else
                    b->dist = 0;
                break;
            case GLFW_KEY_S:
                if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                    b->dist = -0.025;
                else
                    b->dist = 0;
                break;
            case GLFW_KEY_A:
                if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                    b->turn = 5;
                else
                    b->turn = 0;
                break;
            case GLFW_KEY_D:
                if(( action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                    b->turn = -5;
                else
                    b->turn = 0;
                break;
            case GLFW_KEY_H:
                if(( action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                    b->headlight = !b->headlight;
                break;

        }
        return;
    } 
    
    switch(key) {
        case GLFW_KEY_Z:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "waist";
            break;
        case GLFW_KEY_T:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "l_shoulder";
            break;        
        case GLFW_KEY_G:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "r_shoulder";
            break;
        case GLFW_KEY_Y:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "l_elbow";
            break;
        case GLFW_KEY_H:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "r_elbow";
            break;
        case GLFW_KEY_U:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "l_wrist";
            break;
        case GLFW_KEY_J:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "r_wrist";
            break;
        case GLFW_KEY_I:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "l_hip";
            break;
        case GLFW_KEY_K:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "r_hip";
            break;
        case GLFW_KEY_O:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "l_knee";
            break;
        case GLFW_KEY_L:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "r_knee";
            break;
        case GLFW_KEY_P:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "l_ankle";
            break;
        case GLFW_KEY_SEMICOLON:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "r_ankle";
            break;
        case GLFW_KEY_X:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "neck";
            break;

        /*Increase the active component in the X direction*/
        case GLFW_KEY_Q:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Waist Movement*/
                if (active == "waist") b->move_waist_x(1);
                /*Neck Movement*/
                else if (active == "neck") b->move_neck_x(1);
                /*Right Shoulder Movement*/
                else if (active == "r_shoulder") b->move_right_shoulder_x(1);
                /*Right Elbow Movement*/
                else if (active == "r_elbow") b->move_right_elbow_x(1);
                /*Left Shoulder Movement*/
                else if (active == "l_shoulder") b->move_left_shoulder_x(1);
                /*Left Elbow Movement*/
                else if (active == "l_elbow") b->move_left_elbow_x(1);
                /*Right Hip Movement*/
                else if (active == "r_hip") b->move_right_hip_x(1);
                /*Left Hip Movement*/
                else if (active == "l_hip") b->move_left_hip_x(1);
                /*Right Knee Movement*/
                else if (active == "r_knee") b->move_right_knee_x(1);
                /*Left Knee Movement*/
                else if (active == "l_knee") b->move_left_knee_x(1);
                /*Right Ankle Movement*/
                else if (active == "r_ankle") b->move_right_ankle_x(1);
                /*Left Ankle Movement*/
                else if (active == "l_ankle") b->move_left_ankle_x(1);
                /*Right Wrist Movement*/
                else if (active == "r_wrist") b->move_right_wrist_x(1);
                /*Left Wrist Movement*/
                else if (active == "l_wrist") b->move_left_wrist_x(1);
            }
            break;

        /*Decrease the active component in the X direction*/
        case GLFW_KEY_A:
            
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Waist Movement*/
                if (active == "waist") b->move_waist_x(-1);
                /*Neck Movement*/
                else if (active == "neck") b->move_neck_x(-1);
                /*Right Shoulder Movement*/
                else if (active == "r_shoulder") b->move_right_shoulder_x(-1);
                /*Right Elbow Movement*/
                else if (active == "r_elbow") b->move_right_elbow_x(-1);
                /*Left Shoulder Movement*/
                else if (active == "l_shoulder") b->move_left_shoulder_x(-1);
                /*Left Elbow Movement*/
                else if (active == "l_elbow") b->move_left_elbow_x(-1);
                /*Right Hip Movement*/
                else if (active == "r_hip") b->move_right_hip_x(-1);
                /*Left Hip Movement*/
                else if (active == "l_hip") b->move_left_hip_x(-1);
                /*Right Knee Movement*/
                else if (active == "r_knee") b->move_right_knee_x(-1);
                /*Left Knee Movement*/
                else if (active == "l_knee") b->move_left_knee_x(-1);
                /*Right Ankle Movement*/
                else if (active == "r_ankle") b->move_right_ankle_x(-1);
                /*Left Ankle Movement*/
                else if (active == "l_ankle") b->move_left_ankle_x(-1);
                /*Right Wrist Movement*/
                else if (active == "r_wrist") b->move_right_wrist_x(-1);
                /*Left Wrist Movement*/
                else if (active == "l_wrist") b->move_left_wrist_x(-1);
            }
            break;

        /*Increase the active component in the Y direction*/
        case GLFW_KEY_W:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Waist Movement*/
                if (active == "waist") b->move_waist_y(1);
                /*Camera Movement*/
                else if (active == "camera") b->rotate_y(5);
                /*Neck Movement*/
                else if (active == "neck") b->move_neck_y(1);
                /*Right Shoulder Movement*/
                else if (active == "r_shoulder") b->move_right_shoulder_y(1);
                /*Left Shoulder Movement*/
                else if (active == "l_shoulder") b->move_left_shoulder_y(1);
                /*Right Hip Movement*/
                else if (active == "r_hip") b->move_right_hip_y(1);
                /*Left Hip Movement*/
                else if (active == "l_hip") b->move_left_hip_y(1);
                /*Right Ankle Movement*/
                else if (active == "r_ankle") b->move_right_ankle_y(1);
                /*Left Ankle Movement*/
                else if (active == "l_ankle") b->move_left_ankle_y(1);
            }
            break;

        /*Decrease the active component in the Y direction*/
        case GLFW_KEY_S:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Waist Movement*/
                if (active == "waist") b->move_waist_y(-1);
                /*Camera Movement*/
                else if (active == "camera") b->rotate_y(-5);
                /*Neck Movement*/
                else if (active == "neck") b->move_neck_y(-1);
                /*Right Shoulder Movement*/
                else if (active == "r_shoulder") b->move_right_shoulder_y(-1);
                /*Left Shoulder Movement*/
                else if (active == "l_shoulder") b->move_left_shoulder_y(-1);
                /*Right Hip Movement*/
                else if (active == "r_hip") b->move_right_hip_y(-1);
                /*Left Hip Movement*/
                else if (active == "l_hip") b->move_left_hip_y(-1);
                /*Right Ankle Movement*/
                else if (active == "r_ankle") b->move_right_ankle_y(-1);
                /*Left Ankle Movement*/
                else if (active == "l_ankle") b->move_left_ankle_y(-1);
            }
            break;

        /*Increase the active component in the Z direction*/
        case GLFW_KEY_E:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Waist Movement*/
                if (active == "waist") b->move_waist_z(1);
                /*Right Shoulder Movement*/
                else if (active == "r_shoulder") b->move_right_shoulder_z(1);
                /*Left Shoulder Movement*/
                else if (active == "l_shoulder") b->move_left_shoulder_z(1);
                /*Right Hip Movement*/
                else if (active == "r_hip") b->move_right_hip_z(1);
                /*Left Hip Movement*/
                else if (active == "l_hip") b->move_left_hip_z(1);
                /*Neck Movement*/
                else if (active == "neck") b->move_neck_z(1);
                /*Right Wrist Movement*/
                else if (active == "r_wrist") b->move_right_wrist_z(1);
                /*Left Wrist Movement*/
                else if (active == "l_wrist") b->move_left_wrist_z(1);
            }
            break;

        /*Decrease the active component in the Z direction*/
        case GLFW_KEY_D:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Waist Movement*/
                if (active == "waist") b->move_waist_z(-1);
                /*Right Shoulder Movement*/
                else if (active == "r_shoulder") b->move_right_shoulder_z(-1);
                /*Left Shoulder Movement*/
                else if (active == "l_shoulder") b->move_left_shoulder_z(-1);
                /*Right Hip Movement*/
                else if (active == "r_hip") b->move_right_hip_z(-1);
                /*Left Hip Movement*/
                else if (active == "l_hip") b->move_left_hip_z(-1);
                /*Neck Movement*/
                else if (active == "neck") b->move_neck_z(-1);
                /*Right Wrist Movement*/
                else if (active == "r_wrist") b->move_right_wrist_z(-1);
                /*Left Wrist Movement*/
                else if (active == "l_wrist") b->move_left_wrist_z(-1);
            }
            break;
    }
}

