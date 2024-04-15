#include <GL/glut.h> ///使用 GLUT外掛 18行

void display() ///自己寫
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
        glTranslatef(+0.6, +0.3, 30);
        glutSolidSphere(0.3, 30, 30);
    glPopMatrix();
    glutSwapBuffers();
}


int main(int argc, char *argv[]) ///我們的 main函式 138行
{
    glutInit(&argc, argv); ///初始化 GLUT 140行
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///143行

    glutCreateWindow("我自己寫的哦!"); ///145行 建視窗

    glutDisplayFunc(display);

    glutMainLoop();
}
