#include "gl_framework.hpp"

// Load Bitmaps And Convert To Textures
int LoadGLTextures()       
{
    /* load an image file directly as a new OpenGL texture */
    texture[0] = SOIL_load_OGL_texture
        (
        "texture0.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    texture[1] = SOIL_load_OGL_texture
        (
        "texture1.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    texture[2] = SOIL_load_OGL_texture
        (
        "texture_ground.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    texture[3] = SOIL_load_OGL_texture
        (
        "texture_night.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    texture[4] = SOIL_load_OGL_texture
        (
        "texture_sea.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    texture[5] = SOIL_load_OGL_texture
        (
        "night.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    texture[6] = SOIL_load_OGL_texture
        (
        "cmap.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
    texture[7] = SOIL_load_OGL_texture
        (
        "tyre.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[0] == 0 || texture[1] == 0 || texture[2] == 0 || texture[3] == 0 || texture[4] == 0 || texture[5] == 0 || texture[6] == 0 || texture[7] == 0)
        return false;
    
    // Return Success
    return true;
}

void loadLightings()
{

    /* Sun */
    GLfloat LightAmbient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat LightDiffuse[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat LightSpecular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat light_position[] = { 50.0, 50.0, 50.0, 0.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);  
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    /*Headlights*/
    GLfloat LightAmbient1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat LightDiffuse1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat LightSpecular1[] = {0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat position1[] =  {0.05, 0.075, 0.08, 1.0};
    GLfloat spotDir1[] = {0.0, 0.0, -1.0};

    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient1);      
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular1);
    glLightfv(GL_LIGHT1, GL_POSITION, position1);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDir1);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0);
    glEnable(GL_LIGHT1);
    glDisable(GL_LIGHT1);

    /*Moon*/
    GLfloat LightAmbient2[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat LightDiffuse2[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat LightSpecular2[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat position2[] =  {50.0, 50.0, 50.0, 0.0};

    glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmbient2);      
    glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpecular2);
    glLightfv(GL_LIGHT2, GL_POSITION, position2);
    glEnable(GL_LIGHT2);
    glDisable(GL_LIGHT2);
}

namespace transpace
{
  //! Initialize GL State
  void initGL(void)
  {
    LoadGLTextures();
    //Set framebuffer clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //Set depth buffer furthest depth
    glClearDepth(1.0);
    //Set depth test to less-than
    glDepthFunc(GL_LESS);
    //Enable depth testing
    glEnable(GL_DEPTH_TEST); 
    //Enable Gourard shading
    glShadeModel(GL_SMOOTH);
    //Initialise lights
    loadLightings();
  }
  
  //!GLFW Error Callback
  void error_callback(int error, const char* description)
  {
    std::cerr<<description<<std::endl;
  }
  
  //!GLFW framebuffer resize callback
  void framebuffer_size_callback(GLFWwindow* window, int width, int height)
  {
    //!Resize the viewport to fit the window size - draw to entire window
    glViewport(0, 0, width, height);
  }
  
  //!GLFW keyboard callback
  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
  {
    //printf("%d, %d, %d, %d\n", key, scancode, action, mods);
    //!Close the window if the ESC key was pressed
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
    else
        control(key, scancode, action, mods);
    }
};  
  


