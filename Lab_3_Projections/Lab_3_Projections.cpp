// Lab_3_Projections.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Projections.hpp"


int rot = 0;
int alfa = 0;
int ex = 0;
int maxRad = 1;
float S = 0.3;
GLint VP = 300;
GLfloat pi = 3.14159;
GLfloat f;


void Initialize() {
	glClearColor(0.3, 0.3, 0.3, 1.0); //задаем цвет заливки холста
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST); // включаем тест глубины. ≈сли этого не сделать видимыми будут объекты не  расположенные ближе всего к наблюдателю, а созданные последними.
	glLoadIdentity();
}

void drawAxes(float k) {
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); //Ќачальна€ точка
	glVertex3f(0.0, k * 2.0, 0.0); // онечна€ точка
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(k * 2.0, 0.0, 0.0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, k * 2.0);
	glEnd();
}

void draw_model() 
{
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1);
	glEnd();
	glColor3f(1, 1, 1);

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0.5, 0, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0, -0.5, 0.5);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0, 0.5, 0.5);
	glVertex3f(0, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.7, 0.9);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0, 0.5, -0.5);
	glVertex3f(0, 0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0, 0.5, 0.5);
	glVertex3f(0, 0.5, -0.5);
	glVertex3f(0, 0, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex3f(0, 0, -0.5);
	glVertex3f(0, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0, -0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0, -0.5, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex3f(0.5, 0, 0.5);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0, 0, -0.5);
	glVertex3f(0.5, 0, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0, 0.5);
	glVertex3f(0.5, 0, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();

	glColor3f(0, 0.7, 0.1);
	glTranslatef(0.20, 0.20, 0.20);
	glutSolidSphere(0.20, 100, 100);
}



void specialkeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) { rot = rot - 2.0; }
	else
		if (key == GLUT_KEY_RIGHT) { rot = rot + 2.0; }
		else
			if (key == GLUT_KEY_UP) { alfa = alfa - 2.0; }
			else
				if (key == GLUT_KEY_DOWN) { alfa = alfa + 2.0; }
				else {
					ex = key;
					rot = 0;
					alfa = 0;
				}
	glutPostRedisplay();  //принудительный вызов функции визуализации
}






void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//12
	glViewport(0, VP * 2, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(rot, 0, 1, 0);
	glRotatef(alfa, 1, 0, 0);
	draw_model();

	//ќ–“ќ√–ј‘»„≈— »≈

	//план
	glViewport(VP * 3, VP * 2, VP, VP); //область просмотра
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(90, 1, 0, 0); //(угол, x,y,z вектора)
	draw_model();

	//фронтальная проекция
	glViewport(VP * 2, VP * 2, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-90, 0, 1, 0);
	draw_model();

	//вид сбоку
	glViewport(VP, VP * 2, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_model();


	//ѕ≈–—ѕ≈ “»¬Ќџ≈

	//одноточечна€
	glViewport(0, VP, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.5, 0.5, -1.25, 0.75, 1, 4);
	glTranslatef(-0.5, -0.5, -2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_model();

	//двухточечна€
	glViewport(0, 0, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1, 4);
	glTranslatef(0.0, 0.0, -2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-35, -1, 0, 0);
	draw_model();

	//трЄхточечна€
	glViewport(VP, 0, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1, 4);
	glTranslatef(0.0, 0.0, -2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-50, -1, 1, 0);
	draw_model();

	// ќ—ќ”√ќЋ№Ќџ≈

	// Кавалье
	glViewport(VP * 2, 0, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat  a[16];
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glGetFloatv(GL_MODELVIEW_MATRIX, a);
	f = (pi / 2 - atan(45 * pi / 180));
	a[8] = -f * cos(30 * pi / 180);
	a[9] = -f * sin(30 * pi / 180);
	glLoadMatrixf(a);
	draw_model();

	// Кабине
	glViewport(VP * 3, 0, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat  b[16];
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glGetFloatv(GL_MODELVIEW_MATRIX, b);
	f = 0.5;
	b[8] = -f * cos(30 * pi / 180);
	b[9] = -f * sin(30 * pi / 180);
	glLoadMatrixf(b);
	draw_model();


	//ј —ќЌќћ≈“–»„≈— »≈

	//триметрическая
	glViewport(VP, VP, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(29.5158, 1, 0, 0);
	glRotatef(26.227, 0, 1, 0);
	draw_model();

	//диметрическая
	glViewport(VP * 2, VP, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat fi = 180 / 3.14 * asin(((5.0 / 8) / pow(2 - pow(5.0 / 8, 2), 0.5)));
	glRotatef(fi, 1, 0, 0);
	fi = 180 / 3.14 * asin(((5.0 / 8) / pow(2, 0.5)));
	glRotatef(-fi, 0, 1, 0);
	draw_model();

	//изометрическая
	glViewport(VP * 3, VP, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-45, 0, 1, 0);
	glRotatef(15, 1, 0, 0);
	glRotatef(-15, 0, 0, 1);
	draw_model();

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB); //используем буфер глубины, двойную буферизацию и представление цвета триадой RGB.
	glutInitWindowSize(1120, 840);
	glutInitWindowPosition(10, 20);
	glutCreateWindow("Projectsii");
	glutDisplayFunc(Display);  //назначаем функцию визуализации
	glutSpecialFunc(specialkeys); //назначаем функцию обработки нажатий специальных клавиш
	Initialize(); //дополнительные настройки конвейера
	glutMainLoop();
	return 0;
}