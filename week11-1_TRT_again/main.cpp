#include <GL/glut.h>

void myBody(){
    glColor3f(1, 0, 0);///���⪺����
    glutWireCube( 0.6);///���
}
float angle = 0;
void myArm(){
    ///glTranslatef(+0.0, +0.3, 0);
    glPushMatrix();
        glColor3f(0, 1, 0);///��⪺���u
        glScalef(1.5, 0.5, 0.5);///�ܼe1.5���A���ץb0.5��
        glutWireCube(0.3);///���
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
       myBody();///�{���X���W�h�F
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.3, 0.3, 0);///(3)����ӤW
        glRotatef(angle++, 0 ,0, 1);///(2)���
        glTranslatef(0.45/2, 0 ,0);///(1)����त��,�񥿤���
        myArm();///�{���X���W�h�F
    glPopMatrix();

    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week11-1");
    glutIdleFunc(display);
    glutDisplayFunc(display);

    glutMainLoop();
}
