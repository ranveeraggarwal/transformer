#include "control.hpp"

void control(int key, int scancode, int action, int mods) {

switch(key) {

    case GLFW_KEY_LEFT:
        if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            b->rotate_y(5);
        break;
    case GLFW_KEY_RIGHT:
        if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            b->rotate_y(-5);
        break;
    case GLFW_KEY_Q:
        if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            b->move_waist_x(1);
        break;
    case GLFW_KEY_W:
        if((action == GLFW_PRESS || action == GLFW_REPEAT) && mods == 0)
            b->move_waist_x(-1);
        break;
}
   
}

