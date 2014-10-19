#include "basics.hpp"
#include <cmath>

void SetMaterial(GLfloat spec[], GLfloat amb[], GLfloat diff[], GLfloat shin[])
{

  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_SHININESS, shin);
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
}

void texcube(int i, float r, float g, float b)
{

GLfloat mat_specularRGB[] ={r,g,b,1.0};
GLfloat mat_ambientRGB[] ={r,g,b,1.0};
GLfloat mat_diffuseRGB[] ={r,g,b,1.0};
GLfloat mat_shininessRGB[] ={128.0};

    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[i]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT );
    // Enable Texture Mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[i]);   // choose the texture to use.
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glColor4f(r, g, b, 1.0);

    glBegin(GL_QUADS);                    // begin drawing a cube

    SetMaterial(mat_specularRGB, mat_ambientRGB, mat_diffuseRGB, mat_shininessRGB);

    //glNormal3f( 0.0f, 0.0f, 1.0f);                              // front face points out of the screen on z.
    // Front Face (note that the texture's corners have to match the quad's corners)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(0.5f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(0.5f, 0.5f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 0.5f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Top Left Of The Texture and Quad
    
    SetMaterial(mat_specularRGB, mat_ambientRGB, mat_diffuseRGB, mat_shininessRGB);
    //glNormal3f( 0.0f, 0.0f, -1.0f);
    // Back Face
    glTexCoord2f(0.5f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(0.5f, 0.5f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 0.5f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Bottom Left Of The Texture and Quad
  
    SetMaterial(mat_specularRGB, mat_ambientRGB, mat_diffuseRGB, mat_shininessRGB);
    //glNormal3f( 0.0f, 1.0f, 0.0f);
    // Top Face
    glTexCoord2f(0.0f, 0.5f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(0.5f, 0.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(0.5f, 0.5f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
    
    SetMaterial(mat_specularRGB, mat_ambientRGB, mat_diffuseRGB, mat_shininessRGB);
    //glNormal3f( 0.0f, -1.0f, 0.0f);
    // Bottom Face       
    glTexCoord2f(0.5f, 0.5f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 0.5f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(0.5f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    
    SetMaterial(mat_specularRGB, mat_ambientRGB, mat_diffuseRGB, mat_shininessRGB);
    //glNormal3f( 1.0f, 0.0f, 0.0f);
    // Right face
    glTexCoord2f(0.5f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(0.5f, 0.5f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 0.5f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    
    SetMaterial(mat_specularRGB, mat_ambientRGB, mat_diffuseRGB, mat_shininessRGB);
    //glNormal3f( -1.0f, 0.0f, 0.0f);
    // Left Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(0.5f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(0.5f, 0.5f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 0.5f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
    
    glEnd();                                    // done with the polygon.
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);


}

void drawCube(float r, float g, float b) {
    glColor4f(r, g, b, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
}

void drawLine(float r, float g, float b) {
    glColor4f(r, g, b, 1.0);
    glBegin(GL_LINES);
        glVertex3f(-0.5f, 0.0f, 0.0f);
        glVertex3f(0.5f, 0.0f, 0.0f);
    glEnd();
}

void drawBox(float r, float g, float b) {
    glColor4f(r, g, b, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5f, 0.5f, 0.0f);
        glVertex3f(-0.5f, 0.5f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();
}

void drawSphere(int lats, int longs, float r, float g, float b) {
    glColor4f(r, g, b, 1.0);
    int i, j;
    for(i = 0; i <= lats; i++) {
        double lat0 = PI * (-0.5 + (double) (i - 1) / lats);
       double z0  = sin(lat0);
       double zr0 =  cos(lat0);

       double lat1 = PI * (-0.5 + (double) i / lats);
       double z1 = sin(lat1);
       double zr1 = cos(lat1);

       glBegin(GL_QUAD_STRIP);
       for(j = 0; j <= longs; j++) {
           double lng = 2 * PI * (double) (j - 1) / longs;
           double x = cos(lng);
           double y = sin(lng);

           glNormal3f(x * zr0, y * zr0, z0);
           glVertex3f(x * zr0, y * zr0, z0);
           glNormal3f(x * zr1, y * zr1, z1);
           glVertex3f(x * zr1, y * zr1, z1);
       }
       glEnd();
   }
}

void drawCylinder(float r, float g, float b) {
    glColor4f(r, g, b, 1.0);
    /* top triangle */
    double i, resolution  = 0.1;
    double height = 1, radius = 0.5;
    glTranslatef(0, -0.5, 0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, height, 0);  /* center */
        for (i = 0; i <= 2 * PI; i += resolution)
            glVertex3f(radius * cos(i), height, radius * sin(i));
    glEnd();

    /* bottom triangle: note: for is in reverse order */
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, 0, 0);  /* center */
        for (i = 2 * PI; i >= 0; i -= resolution)
            glVertex3f(radius * cos(i), 0, radius * sin(i));
        /* close the loop back to 0 degrees */
        glVertex3f(radius, height, 0);
    glEnd();

    /* middle tube */
    glBegin(GL_QUAD_STRIP);
        for (i = 0; i <= 2 * PI; i += resolution)
        {
            glVertex3f(radius * cos(i), 0, radius * sin(i));
            glVertex3f(radius * cos(i), height, radius * sin(i));
        }
        /* close the loop back to zero degrees */
        glVertex3f(radius, 0, 0);
        glVertex3f(radius, height, 0);
    glEnd();
}
