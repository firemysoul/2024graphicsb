#include <GL/glut.h>

void myBody(){
    glColor3f(1, 0, 0);///���⪺����
    glutWireCube( 0.6);///���
}
void myArm(){
        glColor3f(0, 1, 0);///��⪺���u
        glScalef(1.5, 0.5, 0.5);///�ܼe1.5���A���ץb0.5��
        glutWireCube(0.3);///���
}
float angle=0;///week10-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        ///glTranslatef(+0.3, +0.3, 0);
        myBody();///�{���X���W�h�F
    glPopMatrix();
    glPushMatrix();
        glTranslatef(+0.3, +0.3, 0);
        glRotated(angle++, 0, 0, 1);///week10-2
        glTranslatef(0.225, 0, 0);
        myArm();///�{���X���W�h�F
    glPopMatrix();
    glutSwapBuffers();

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week10-4");

    glutDisplayFunc(display);
    glutIdleFunc(display);///week10-2
    glutMainLoop();
}
