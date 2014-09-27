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
        case GLFW_KEY_G:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "r_shoulder";
            break;
        case GLFW_KEY_T:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
                active = "l_shouler";
            break;

        /*Increase the active component in the X direction*/
        case GLFW_KEY_Q:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Waist Movements*/
                if (active == "waist") b->move_waist_x(1);
                /*Right Shoulder Movements*/
                else if (active == "r_shoulder") b->move_right_shoulder_x(1);
            }
            break;

        /*Decrease the active component in the X direction*/
        case GLFW_KEY_A:
            
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Waist Movements*/
                if (active == "waist") b->move_waist_x(-1);
                /*Right Shoulder Movements*/
                else if (active == "r_shoulder") b->move_right_shoulder_x(-1);
            }
            break;

        /*Increase the active component in the Y direction*/
        case GLFW_KEY_W:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Camera Movements*/
                if (active == "camera") b->rotate_y(5);
            }
            break;

        /*Decrease the active component in the Y direction*/
        case GLFW_KEY_S:
            if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            {
                /*Camera Movements*/
                if (active == "camera") b->rotate_y(-5);
            }
            break;
    }
}

