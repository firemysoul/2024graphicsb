#include <GL/glut.h>

void myBody(){
    glColor3f(1, 0, 0);///紅色的身體
    glutWireCube( 0.6);///方塊
}
float angle = 0;
void myArm(){
    ///glTranslatef(+0.0, +0.3, 0);
    glPushMatrix();
        glColor3f(0, 1, 0);///綠色的手臂
        glScalef(1.5, 0.5, 0.5);///變寬1.5倍，高度半0.5倍
        glutWireCube(0.3);///方塊
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
       myBody();///程式碼移上去了
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.3, 0.3, 0);///(3)掛到肩上
        glRotatef(angle++, 0 ,0, 1);///(2)轉動
        glTranslatef(0.45/2, 0 ,0);///(1)把旋轉中心,放正中心
        myArm();///程式碼移上去了
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
