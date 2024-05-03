// Lab_3_Projections.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Projections.hpp"

params view_params;







void specialkeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) { view_params.rot = view_params.rot - 2.0; }
	else
		if (key == GLUT_KEY_RIGHT) { view_params.rot = view_params.rot + 2.0; }
		else
			if (key == GLUT_KEY_UP) { view_params.alfa = view_params.alfa - 2.0; }
			else
				if (key == GLUT_KEY_DOWN) { view_params.alfa = view_params.alfa + 2.0; }
				else {
					view_params.ex = key;
					view_params.rot = 0;
					view_params.alfa = 0;
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

	//Ортографические

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


	//Перспективные

	//одноточечная
	glViewport(0, VP, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.5, 0.5, -1.25, 0.75, 1, 4);
	glTranslatef(-0.5, -0.5, -2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_model();

	//двухточечная
	glViewport(0, 0, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1, 4);
	glTranslatef(0.0, 0.0, -2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-35, -1, 0, 0);
	draw_model();

	//трехточечная
	glViewport(VP, 0, VP, VP);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 1, 4);
	glTranslatef(0.0, 0.0, -2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-50, -1, 1, 0);
	draw_model();

	// Косоугольные

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


	//Аксонометрические

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

int main(int argc, char** argv) 
{
	view_params.rot = 0;
	view_params.alfa = 0;
	view_params.ex = 0;
	view_params.maxRad = 1;
	view_params.S = 0.3;
	view_params.VP = 300;
	view_params.pi = 3.14159;
	view_params.f;
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