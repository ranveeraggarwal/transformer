#include "environment.hpp"
void renderGround() {
    glPushMatrix();
    glTranslatef(0, -50.615, 0);
    glScalef(100, 100, 100);
    texcube(2, 0.6, 0.6, 0.3);
    glPopMatrix();
}
