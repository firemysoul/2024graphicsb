///先把 week08-1_glm_gundam 的程式貼上來
///等一下, 要再加貼圖的 18行程式
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;
GLMmodel * upper = NULL;
GLMmodel * lower = NULL;
GLMmodel * body = NULL;
void drawUpper(void)
{
    if (!upper) {
	upper = glmReadOBJ("upper.obj");
	if (!upper) exit(0);
	glmUnitize(upper);
	glmFacetNormals(upper);
	glmVertexNormals(upper, 90.0);
    }

    glmDraw(upper, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLower(void)
{
    if (!lower) {
	lower = glmReadOBJ("lower.obj");
	if (!lower) exit(0);
	glmUnitize(lower);
	glmFacetNormals(lower);
	glmVertexNormals(lower, 90.0);
    }

    glmDraw(lower, GLM_SMOOTH | GLM_TEXTURE);
}
void drawBody(void)
{
    if (!body) {
	body = glmReadOBJ("body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}
void drawhand2(void)
{
    if (!hand2) {
	hand2 = glmReadOBJ("hand2.obj");
	if (!hand2) exit(0);
	glmUnitize(hand2);
	glmFacetNormals(hand2);
	glmVertexNormals(hand2, 90.0);
    }

    glmDraw(hand2, GLM_SMOOTH | GLM_TEXTURE);
}
///float angle = 0, da=-1; ///加這行, 讓它轉動
int angleID = 0;
float angle[20] = {};
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///glutWireCube(0.6);
    ///glutSolidSphere( 0.1, 30, 30);
    glPushMatrix();
        glRotatef(180, 0 , 1, 0);
        drawBody();
        glPushMatrix();
            glTranslatef(-0.15, 0 ,0);
            glRotatef(angle[0], 1, 0, 0);
            glTranslatef(-0.025, -0.05, 0);
            drawUpper();
            glPushMatrix(); ///加這行, 讓它轉動
                glTranslatef(0, -0.1, 0);///(3)把旋轉中的手掛到肩上
                glRotatef(angle[1], 1, 0, 0);///(2)旋轉
                glTranslatef(0, -0.2, 0);///(1)把旋轉中心,放到正中心(有個球在正中心)
                drawLower();
            glPopMatrix(); ///加這行, 讓它轉動
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    ///if(angle<-90) da = +1;
    ///if(angle>0) da = -1;
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void keyboard(unsigned char key , int x ,int y){
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
}
int oldX = 0 ,oldY = 0;
void mouse(int button, int state, int x, int y){
    oldX = x;
    oldY = y;
}
void motion(int x, int y){
    angle[angleID] += y - oldY;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week13_keyboard__angleID_mouse_motion_angle");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutKeyboardFunc(keyboard);
    glutMotionFunc(motion);
    myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
