#include "control.hpp"

std::string active = "arandomstring";

void control(int key, int scancode, int action, int mods) {
    switch(key) {
        /*Activating various parts*/
        case GLFW_KEY_SPACE:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "camera";
            break;
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

        /*Increase the active component in the X direction*/
        case GLFW_KEY_Q:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Waist Movement*/
                if (active == "waist") b->move_waist_x(1);
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
            }
            break;

        /*Decrease the active component in the X direction*/
        case GLFW_KEY_A:
            
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Waist Movement*/
                if (active == "waist") b->move_waist_x(-1);
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
            }
            break;

        /*Increase the active component in the Y direction*/
        case GLFW_KEY_W:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Camera Movement*/
                if (active == "camera") b->rotate_y(5);
                /*Right Shoulder Movement*/
                else if (active == "r_shoulder") b->move_right_shoulder_y(1);
                /*Left Shoulder Movement*/
                else if (active == "l_shoulder") b->move_left_shoulder_y(1);
                /*Right Hip Movement*/
                else if (active == "r_hip") b->move_right_hip_y(1);
                /*Left Hip Movement*/
                else if (active == "l_hip") b->move_left_hip_y(1);
            }
            break;

        /*Decrease the active component in the Y direction*/
        case GLFW_KEY_S:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Camera Movement*/
                if (active == "camera") b->rotate_y(-5);
                /*Right Shoulder Movement*/
                else if (active == "r_shoulder") b->move_right_shoulder_y(-1);
                /*Left Shoulder Movement*/
                else if (active == "l_shoulder") b->move_left_shoulder_y(-1);
                /*Right Hip Movement*/
                else if (active == "r_hip") b->move_right_hip_y(-1);
                /*Left Hip Movement*/
                else if (active == "l_hip") b->move_left_hip_y(-1);
            }
            break;

        /*Increase the active component in the Z direction*/
        case GLFW_KEY_E:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Right Shoulder Movement*/
                if (active == "r_shoulder") b->move_right_shoulder_z(1);
                /*Left Shoulder Movement*/
                else if (active == "l_shoulder") b->move_left_shoulder_z(1);
                /*Right Hip Movement*/
                else if (active == "r_hip") b->move_right_hip_z(1);
                /*Left Hip Movement*/
                else if (active == "l_hip") b->move_left_hip_z(1);
            }
            break;

        /*Decrease the active component in the Z direction*/
        case GLFW_KEY_D:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Right Shoulder Movement*/
                if (active == "r_shoulder") b->move_right_shoulder_z(-1);
                /*Left Shoulder Movement*/
                else if (active == "l_shoulder") b->move_left_shoulder_z(-1);
                /*Right Hip Movement*/
                else if (active == "r_hip") b->move_right_hip_z(-1);
                /*Left Hip Movement*/
                else if (active == "l_hip") b->move_left_hip_z(-1);
            }
            break;
    }
}

