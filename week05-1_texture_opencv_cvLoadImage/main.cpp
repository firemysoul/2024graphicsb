#include <GL/glut.h>
#include <opencv/highgui.h>
void display()
{
    glColor3f(1,1,0);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    IplImage * img = cvLoadImage("c:/dio.jpg");

    cvShowImage("opencv", img);
    ///cvWaitKey(0);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05-1 texture opencv");
    glutDisplayFunc(display);

    glutMainLoop();
}
