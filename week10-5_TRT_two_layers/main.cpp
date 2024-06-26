#include <GL/glut.h>

void myBody(){
    glColor3f(1, 0, 0);///紅色的身體
    glutWireCube( 0.6);///方塊
}
void myArm(){
    glPushMatrix();
        glColor3f(0, 1, 0);///綠色的手臂
        glScalef(1.5, 0.5, 0.5);///變寬1.5倍，高度半0.5倍
        glutWireCube(0.3);///方塊
    glPopMatrix();
}
float angle=0;///week10-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        ///glTranslatef(+0.3, +0.3, 0);
        myBody();///程式碼移上去了
    glPopMatrix();
    glPushMatrix();
        glTranslatef(+0.3, +0.3, 0);
        glRotated(angle++, 0, 0, 1);///week10-2
        glTranslatef(0.225, 0, 0);

        myArm();
        glPushMatrix();
            glTranslatef(0.225, 0, 0);
            glRotated(angle++, 0, 0, 1);///week10-2
            glTranslatef(0.225, 0, 0);
            myArm();///程式碼移上去了
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week10-5
                     ");

    glutDisplayFunc(display);
    glutIdleFunc(display);///week10-2
    glutMainLoop();
}
