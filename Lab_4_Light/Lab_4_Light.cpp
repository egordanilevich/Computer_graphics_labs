
#include <GL\glut.h>
#include "scenes.hpp"


const float a = 0.5f;

float tran = 0;
float con = 30;
float rot = 0;
int w = 350;

params view_params;

float no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
float mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
float mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
float mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
//float mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
float mat_specular[] = { 0.6, 0.6, 0.6, 1.0 };
float no_shininess = 0.0;
float low_shininess = 5.0;
float high_shininess = 100.0;
float mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };


void scene() //Выбор сцены
{
    switch (view_params.scene_num)
    {
    case 1:
        
    case 2:
       
    case 3:
        
    case 4:
       
    case 5:
       
    case 6:
       
    case 7:
        
    default:
        std::cerr << "Scene ERROR!!!";
        break;
    }
}

void specialkeys(int key, int x, int y) {
    if (key == GLUT_KEY_F1) { view_params.scene_num = 1; glutPostRedisplay(); }
    if (key == GLUT_KEY_F2) { view_params.scene_num = 2; glutPostRedisplay(); }
    if (key == GLUT_KEY_F3) { view_params.scene_num = 3; glutPostRedisplay(); }
    if (key == GLUT_KEY_F4) { view_params.scene_num = 4; glutPostRedisplay(); }
    if (key == GLUT_KEY_F5) { view_params.scene_num = 5; glutPostRedisplay(); }
    if (key == GLUT_KEY_F6) { view_params.scene_num = 6; glutPostRedisplay(); }
    if (key == GLUT_KEY_F7) { view_params.scene_num = 7; glutPostRedisplay(); }
    if (key == GLUT_KEY_LEFT) { con -= 2.0; }
    if (key == GLUT_KEY_RIGHT) { con += 2.0; }
    if (key == GLUT_KEY_PAGE_UP) { tran -= 0.1; }
    if (key == GLUT_KEY_PAGE_DOWN) { tran += 0.1; }
    if (key == GLUT_KEY_UP) { rot += 3; }
    if (key == GLUT_KEY_DOWN) { rot -= 3; }
    if (view_params.scene_num == 3 || view_params.scene_num == 2) 
    {
        if (key == GLUT_KEY_LEFT) {
            view_params.lightPosX -= 0.1f;
        }
        if (key == 'D' || key == 'd') {
            view_params.lightPosX1 -= 0.1f;
        }
        if (key == GLUT_KEY_RIGHT) {
            view_params.lightPosX += 0.1f;
        }
        if (key == 'A' || key == 'a') {
            view_params.lightPosX1 += 0.1f;
        }
        if (key == GLUT_KEY_UP) {
            view_params.lightPosY += 0.1f;
        }
        if (key == 'W' || key == 'w') {
            view_params.lightPosY1 += 0.1f;
        }
        if (key == GLUT_KEY_DOWN) {
            view_params.lightPosY -= 0.1f;
        }
        glutPostRedisplay(); // Перерисовка сцены
    }
    glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
    if ((key == 'l' || key == 'L') && view_params.scene_num == 1) {
        view_params.isDirectional = !view_params.isDirectional; // Переключение типа источника света
        glutPostRedisplay(); // Перерисовка сцены
    }
    if (view_params.scene_num == 2) {
        if (key == '1') {
            view_params.light0Enabled = !view_params.light0Enabled; // Переключение источника света 0
            glutPostRedisplay(); // Перерисовка сцены
        }
        if (key == '2') {
            view_params.light1Enabled = !view_params.light1Enabled; // Переключение источника света 1
            glutPostRedisplay(); // Перерисовка сцены
        }
        if (key == 'G' || key == 'g') {
            view_params.lightPosY1 -= 0.1f;
        }
    }
}




void draw_axis()
{
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);
    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
    glEnd();

}

float smRad = 0.38;
float smRadH = 0.125f;








void InitLight() 
{
    glShadeModel(GL_SMOOTH);
    // glShadeModel(GL_FLAT);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    //    glEnable(GL_LIGHT0);
     //   glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_NORMALIZE);
    //  glEnable(GL_CULL_FACE);


    glRotatef(rot, 0, 1, 0);
    float ambient[] = { 0.7, 0.7, 0.7, 1.0 };
    float diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    float specular[] = { 0.4, 0.4, 0.4, 1.0 };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
    GLfloat light_position[] = { 0.0, 0.0, 3.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, light_position);

    glPushMatrix();
    float fl[4];
    glRotatef(90, 1, 0, 0);
    fl[0] = 1; fl[1] = 1; fl[2] = 1; fl[3] = 0;
    glLightfv(GL_LIGHT2, GL_DIFFUSE, fl);
    if (con > 0)  glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, con);
    else   glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 180);
    fl[0] = 0; fl[1] = 0; fl[2] = -1; fl[3] = 0;
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, fl);
    fl[0] = 0; fl[1] = 0; fl[2] = 3; fl[3] = 1;
    glLightfv(GL_LIGHT2, GL_POSITION, fl);

    glLightfv(GL_LIGHT2, GL_SPECULAR, specular);

    glPopMatrix();

    if (con > 0)  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, con);
    else   glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90);
    GLfloat light0_position[] = { 0.0, 3.0, 0.0, 1.0 };
    glPushMatrix();
    glTranslatef(0, 0, tran);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glPopMatrix();
    GLfloat light0_dir[] = { 0.0, -1.0, 0.0 ,0.0 };
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_dir);
}


float dist = 0.1;
int Count = 6;
int CountZ = 4;
float s = 0.8;



void Display() {
    srand(time(0));
    InitLight();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(rot, 0, 1, 0);
    scene();
    glutSwapBuffers();
}


void Initialize() {
    //	glClearColor(1, 1, 1, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-10.0, 10.0, -10.0, 10.0, -20.0, 20.0);               // Îïðåäåëÿåì ãðàíèöû ðèñîâàíèÿ ïî ãîðèçîíòàëè è âåðòèêàëè
    glOrtho(-2, 2, -2, 2, -2, 2);
    //    glFrustum(-3.0, 3.0, -3.0, 3.0, 10.5, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Our first GLUT application!");
    glutDisplayFunc(Display);
    glutSpecialFunc(specialkeys);
    glutKeyboardFunc(processNormalKeys);
    Initialize();
    InitLight();
    glutMainLoop();
    return 0;
}