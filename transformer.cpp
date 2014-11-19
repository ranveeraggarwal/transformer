#include "gl_framework.hpp"
#include <stdlib.h>
#include <sstream>
unsigned int texture[8];

body* b;
bool recording = false;
int fps = 60;
void renderGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //if(b->transformed)
        b->move(b->dist, b->turn);
    b->render(); 
}

int main(int argc, char** argv)
{

  if(argc == 2) {
    std::stringstream(argv[1]) >> fps;
  }
  double step = 1.0 / (double) fps;
  //! The pointer to the GLFW window
  GLFWwindow* window;
  int height = 750;
  int width = 1000;
  //! Setting up the GLFW Error callback
  glfwSetErrorCallback(transpace::error_callback);

  //! Initialize GLFW
  if (!glfwInit())
    return -1;

  //! Create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(width, height, "Transformer!", NULL, NULL);
  if (!window)
    {
      glfwTerminate();
      return -1;
    }
  
  //! Make the window's context current 
  glfwMakeContextCurrent(window);

  //Initialize GLEW
  GLenum err = glewInit();
  if (GLEW_OK != err)
    {
      //Problem: glewInit failed, something is seriously wrong.
      std::cerr<<"GLEW Init Failed : %s"<<std::endl;
    }
  glViewport(0, 0, width, height);
  std::cout << "\n";
  std::cout << "▀▀█▀▀ ▒█▀▀█ ░█▀▀█ ▒█▄░▒█ ▒█▀▀▀█ ▒█▀▀▀ ▒█▀▀▀█ ▒█▀▀█ ▒█▀▄▀█ ▒█▀▀▀ ▒█▀▀█\n";
  std::cout << "░▒█░░ ▒█▄▄▀ ▒█▄▄█ ▒█▒█▒█ ░▀▀▀▄▄ ▒█▀▀▀ ▒█░░▒█ ▒█▄▄▀ ▒█▒█▒█ ▒█▀▀▀ ▒█▄▄▀\n";
  std::cout << "░▒█░░ ▒█░▒█ ▒█░▒█ ▒█░░▀█ ▒█▄▄▄█ ▒█░░░ ▒█▄▄▄█ ▒█░▒█ ▒█░░▒█ ▒█▄▄▄ ▒█░▒█\n";
  std::cout << "\n";

  //Keyboard Callback
  glfwSetKeyCallback(window, transpace::key_callback);
  //Framebuffer resize callback
  glfwSetFramebufferSizeCallback(window, transpace::framebuffer_size_callback);

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  //Initialize GL state
  transpace::initGL();

  // Loop until the user closes the window
  b = new body();
  double time; 
  while (glfwWindowShouldClose(window) == 0)
    {
      time = glfwGetTime();
      // Render here
      renderGL();
      
      // Swap front and back buffers
      glfwSwapBuffers(window);
      
      // Poll for and process events
      glfwPollEvents();
      if(b->terminate)
        glfwSetWindowShouldClose(window, GL_TRUE);
      while(glfwGetTime() < time + step);
      std::cout << "FPS: " << 1.0 / (glfwGetTime() - time) << "     \r";
      std::cout.flush();
    }
  glfwTerminate();
  return 0;
}

