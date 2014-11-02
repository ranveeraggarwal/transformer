#include "basics.hpp"
#include <cmath>


//The following two functions set the material of the object
void setMaterial(GLfloat spec[], GLfloat amb[], GLfloat diff[], GLfloat shin[])
{

    glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, shin);
    glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
}

void setMaterialColors(float r, float g, float b, float shin)
{
    GLfloat mat_specularRGB[] ={r*shin/128.0,g*shin/128.0,b*shin/128.0,1.0};
    GLfloat mat_ambientRGB[] ={r,g,b,1.0};
    GLfloat mat_diffuseRGB[] ={r,g,b,1.0};
    GLfloat mat_shininessRGB[] ={shin};
    setMaterial(mat_specularRGB, mat_ambientRGB, mat_diffuseRGB, mat_shininessRGB);
}

//Next on are the basic shapes required for the transformer
//Cube
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

//Line
void drawLine(float r, float g, float b) {
    glColor4f(r, g, b, 1.0);
    glBegin(GL_LINES);
        glVertex3f(-0.5f, 0.0f, 0.0f);
        glVertex3f(0.5f, 0.0f, 0.0f);
    glEnd();
}

//A box
void drawBox(float r, float g, float b) {
    glColor4f(r, g, b, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5f, 0.5f, 0.0f);
        glVertex3f(-0.5f, 0.5f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();
}

//Sphere
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

//Cylinder
void drawCylinder(float r, float g, float b) {
    setMaterialColors(r, g, b);
    glColor4f(r, g, b, 1.0);
    /* top triangle */
    double i, resolution  = 0.1;
    double height = 1, radius = 0.5;
    glPushMatrix();
    glTranslatef(0, -0.5, 0);
    glBegin(GL_TRIANGLE_FAN);
        /* center */
        glVertex3f(0, height, 0);
        for (i = 0; i <= 2 * PI; i += resolution)
            glVertex3f(radius * cos(i), height, radius * sin(i));
    glEnd();

    /* bottom triangle: note: for is in reverse order */
    glBegin(GL_TRIANGLE_FAN);
        /* center */
        glVertex3f(0, 0, 0);
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
    glPopMatrix();
}

void drawCone(float r, float g, float b) {
    setMaterialColors(r, g, b);
    glColor4f(r, g, b, 1.0);
    /* top triangle */
    double i, resolution  = 0.1;
    double height = 1, radius = 0.5;
    glPushMatrix();
    glTranslatef(0, -0.5, 0);
    glBegin(GL_TRIANGLE_FAN);
        /* center */
        glVertex3f(0, height, 0);
        for (i = 0; i <= 2 * PI; i += resolution)
            glVertex3f(radius * cos(i), height, radius * sin(i));
    glEnd();

    /* middle tube */
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, 0, 0);
        for (i = 0; i <= 2 * PI; i += resolution)
        {
            glVertex3f(radius * cos(i), height, radius * sin(i));
        }
        glVertex3f(radius, height, 0);
    glEnd();
    glPopMatrix();
}

//Next up are the textured versions of the basic shapes
void texcube(int i, float r, float g, float b, bool override)
{
    glEnable(GL_TEXTURE_2D);
    // choose the texture to use.
    glBindTexture(GL_TEXTURE_2D, texture[i]);   

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);

    // begin drawing a cube
    glBegin(GL_QUADS);                    
    if(!override)
        setMaterialColors(r, g, b, 40);
    else
        setMaterialColors(r, g, b, 0);
    // Front Face "+z"
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Top Left Of The Texture and Quad
    
    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Bottom Left Of The Texture and Quad
  
    // Top Face
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
    
    // Bottom Face       
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    
    // Right face
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    
    // Left Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
    
    glEnd();                                    
    // done with the polygon.
    glDisable(GL_TEXTURE_2D);


}

void texCylinder(float r, float g, float b, int texindex) {

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[texindex]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);

    setMaterialColors(r, g, b);
    glColor4f(r, g, b, 1.0);
    /* top triangle */
    double i, resolution  = 0.1;
    double height = 1, radius = 0.5;
    glPushMatrix();
    glTranslatef(0, -0.5, 0);
    glBegin(GL_TRIANGLE_FAN);
        /* center */
        glTexCoord2f( 0.5, 0.5 );
        glVertex3f(0, height, 0);  
        for (i = 0; i <= 2 * PI; i += resolution)
        {
            glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f ); 
            glVertex3f(radius * cos(i), height, radius * sin(i));
        }
    glEnd();

    /* bottom triangle: note: for is in reverse order */
    glBegin(GL_TRIANGLE_FAN);
        /* center */
        glTexCoord2f( 0.5, 0.5 );
        glVertex3f(0, 0, 0);  
        for (i = 2 * PI; i >= 0; i -= resolution)
        {
            glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
            glVertex3f(radius * cos(i), 0, radius * sin(i));
        }
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
    glPopMatrix();
}


//Sky requires a special u-v map, so taken as a separate case.
void skybox(float r, float g, float b, bool override, int texindex)
{

    // Enable Texture Mapping
    glEnable(GL_TEXTURE_2D);
    // choose the texture to use.
    glBindTexture(GL_TEXTURE_2D, texture[texindex]);   

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);

    // begin drawing a cube
    glBegin(GL_QUADS);                    
    if(!override)
        setMaterialColors(r, g, b, 40);
    else
        setMaterialColors(r, g, b, 0);
    // Front Face
    glTexCoord2f(0.0f, 0.33f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(0.25f, 0.33f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(0.25f, 0.66f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 0.66f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Top Left Of The Texture and Quad

    // Right face
    glTexCoord2f(0.5f, 0.33f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(0.5f, 0.66f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.25f, 0.66f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.25f, 0.33f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    
    // Back Face
    glTexCoord2f(0.75f, 0.33f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(0.75f, 0.66f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.5f, 0.66f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.5f, 0.33f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Bottom Left Of The Texture and Quad

    // Left Face
    glTexCoord2f(0.75f, 0.33f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.33f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 0.66f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.75f, 0.66f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad

    // Top Face
    glTexCoord2f(0.5f, 1.0f); glVertex3f(-0.5f,  0.5f, -0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.25f, 1.0f); glVertex3f(-0.5f,  0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(0.25f, 0.66f); glVertex3f( 0.5f,  0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    glTexCoord2f(0.5f, 0.66f); glVertex3f( 0.5f,  0.5f, -0.5f);  // Top Right Of The Texture and Quad
    
    // Bottom Face       
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, -0.5f, -0.5f);  // Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.5f, -0.5f, -0.5f);  // Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5f, -0.5f,  0.5f);  // Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f,  0.5f);  // Bottom Right Of The Texture and Quad
    
    glEnd();                                    
    // done with the polygon.
    glDisable(GL_TEXTURE_2D);
}
