#include "gl_framework.hpp"

int LoadGLTextures()       // Load Bitmaps And Convert To Textures
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
        "texture_sky.jpg",
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


    if(texture[0] == 0 || texture[1] == 0 || texture[2] == 0 || texture[3] == 0)
        return false;
 
    return true;                                        // Return Success
}

void loadLightings()
{

    GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = { 100.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);  
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    //glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDisable(GL_LIGHT0);

    /*Headlights*/
    GLfloat LightAmbient1[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat LightDiffuse1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat position1[] =  {0.05, 0.075, 0.08, 1.0}; //Add pos_x to x coordinate and pos_z to z coordinate
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient1);      
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse1);
    glLightfv(GL_LIGHT1, GL_POSITION, position1);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);
    glEnable(GL_LIGHT1);
    //if (!b->headlight) glDisable(GL_LIGHT1);
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
  


