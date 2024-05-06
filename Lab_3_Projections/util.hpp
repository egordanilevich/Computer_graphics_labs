#pragma once
#include <GL/glut.h>
#include <math.h>



struct  params
{
	int alfa;
	int beta;
	//int ex;
	//int maxRad;
	//float S;
	GLint VP;
};

void Initialize() 
{
	glClearColor(0.3, 0.3, 0.3, 1.0); //задаем цвет заливки холста
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST); // включаем тест глубины. если этого не сделать видимыми будут объекты не  расположенные ближе всего к наблюдателю, а созданные последними.
	glLoadIdentity();
}

void drawAxes(float k) 
{
	glColor4f(0, 1, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); //Начальная точка
	glVertex3f(0.0, k * 2.0, 0.0); // Конечная точка
	glEnd();

	glColor4f(1, 0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(k * 2.0, 0.0, 0.0);
	glEnd();

	glColor4f(0, 0, 1, 1);
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
}

