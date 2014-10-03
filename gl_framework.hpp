#ifndef _GL_FRAMEWORK_HPP_
#define _GL_FRAMEWORK_HPP_
#include <iostream>
#include "./SOIL/SOIL.h"
#include "control.hpp"

extern body* b;

extern unsigned int texture[2];

int LoadGLTextures();

namespace transpace
{
  //! Initialize GL State
  void initGL(void);
 
  //!GLFW Error Callback
  void error_callback(int error, const char* description);
  //!GLFW framebuffer resize callback
  void framebuffer_size_callback(GLFWwindow* window, int width, int height);
  //!GLFW keyboard callback
  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif
