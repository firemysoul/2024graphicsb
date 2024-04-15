#include <GL/glut.h> ///�ϥ� GLUT�~�� 18��

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(-0.6, +0.3, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(+0.0, +0.3, 0);
        glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(+0.6, +0.3, 0);
        glutSolidSphere(0.3, 30, 30);

    glPopMatrix();
       glPushMatrix();
        glTranslatef(-0.6, -0.3, 0);
        glutWireTeapot(0.3);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(+0.0, -0.3, 0);
        glutWireCube(0.3);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(+0.6, -0.3, 0);
        glutWireSphere(0.3, 30, 30);

    glPopMatrix();
    glutSwapBuffers();
}


int main(int argc, char *argv[]) ///�ڭ̪� main�禡 138��
{
    glutInit(&argc, argv); ///��l�� GLUT 140��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///143��

    glutCreateWindow("week09-3_glutWireCube_glutWireTeapot_glutWire_Sphere!"); ///145�� �ص���

    glutDisplayFunc(display);

    glutMainLoop();
}
