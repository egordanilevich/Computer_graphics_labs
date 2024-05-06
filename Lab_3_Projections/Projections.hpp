#pragma once
#include "util.hpp"

GLfloat pi = 3.1415926535897932;

void p_0_rotatable(const params& in) // Вращаемая
{
	glViewport(0, in.VP * 2, in.VP, in.VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(in.alfa, 0, 1, 0);
	glRotatef(in.beta, 1, 0, 0);
	draw_model();
}


//Ортографические
void p_1_side_view(const params& in)//вид сбоку
{

	glViewport(in.VP, in.VP * 2, in.VP, in.VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_model();
}

void p_2_frontal(const params& in) //фронтальная проекция
{

	glViewport(in.VP * 2, in.VP * 2, in.VP, in.VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-90, 0, 1, 0);
	draw_model();
}

void p_3_plan(const params& in)	//план
{

	glViewport(in.VP * 3, in.VP * 2, in.VP, in.VP); //область просмотра
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(90, 1, 0, 0); //(угол, x,y,z вектора)
	draw_model();
}
	

//Перспективные
void p_5_single_point(const params& in) //одноточечная
{
	glViewport(in.VP, in.VP, in.VP, in.VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.5, 0.5, -1.25, 0.75, 1, 4);
	glTranslatef(-0.5, -0.5, -2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_model();
}

void p_6_two_point(const params& in) //двухточечная
{
	glViewport(in.VP*2, in.VP, in.VP, in.VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1, 4);
	glTranslatef(0.0, 0.0, -2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-35, -1, 0, 0);
	draw_model();
}

void p_7_three_point(const params& in) //трехточечная
{
	glViewport(in.VP * 3, in.VP, in.VP, in.VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1, 4);
	glTranslatef(0.0, 0.0, -2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-50, -1, 1, 0);
	draw_model();

}


//Аксонометрические
void p_9_isometric(const params& in) //изометрическая
{
	glViewport(in.VP, 0, in.VP, in.VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-45, 0, 1, 0);
	glRotatef(15, 1, 0, 0);
	glRotatef(-15, 0, 0, 1);
	draw_model();
}

void p_10_dimetric(const params& in) //диметрическая
{
	glViewport(in.VP * 2, 0, in.VP, in.VP);
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
}

void p_11_trimetric(const params& in) //триметрическая
{
	glViewport(in.VP * 3, 0, in.VP, in.VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(29.5158, 1, 0, 0);
	glRotatef(26.227, 0, 1, 0);
	draw_model();
}

// Косоугольные
void p_8_Cavalie( params& in) // Кавалье
{
	glViewport(0, 0, in.VP, in.VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat  a[16];
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glGetFloatv(GL_MODELVIEW_MATRIX, a);
	GLfloat f = (pi / 2 - atan(45 * pi / 180));
	a[8] = -f * cos(30 * pi / 180);
	a[9] = -f * sin(30 * pi / 180);
	glLoadMatrixf(a);
	draw_model();
}

void p_4_Cabine(const params& in) // Кабине
{
	glViewport(0, in.VP, in.VP, in.VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat  b[16];
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glGetFloatv(GL_MODELVIEW_MATRIX, b);
	GLfloat f = 0.5;
	b[8] = -f * cos(30 * pi / 180);
	b[9] = -f * sin(30 * pi / 180);
	glLoadMatrixf(b);
	draw_model();
}







