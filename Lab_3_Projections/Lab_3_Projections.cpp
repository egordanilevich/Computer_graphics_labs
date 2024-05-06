// Lab_3_Projections.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Projections.hpp"

params view_params;







void specialkeys(int key, int x, int y) 
{
	if (key == GLUT_KEY_LEFT) { view_params.alfa = view_params.alfa - 2.0; }
	else
		if (key == GLUT_KEY_RIGHT) { view_params.alfa = view_params.alfa + 2.0; }
		else
			if (key == GLUT_KEY_UP) { view_params.beta = view_params.beta - 2.0; }
			else
				if (key == GLUT_KEY_DOWN) { view_params.beta = view_params.beta + 2.0; }
				else {
					//view_params.ex = key;
					view_params.alfa = 0;
					view_params.beta = 0;
				}
	glutPostRedisplay();  //принудительный вызов функции визуализации
}






void Display() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	p_0_rotatable(view_params);// Вращаемая
	// Ортографические
	p_1_side_view(view_params);
	p_2_frontal(view_params);
	p_3_plan(view_params);
	// Перспективные
	p_5_single_point(view_params);
	p_6_two_point(view_params);
	p_7_three_point(view_params);
	// Аксонометрические
	p_9_isometric(view_params);
	p_10_dimetric(view_params);
	p_11_trimetric(view_params);
	// Косоугольные
	p_4_Cabine(view_params);
	p_8_Cavalie(view_params);
	
	
	
	glutSwapBuffers();
}

int main(int argc, char** argv) 
{
	view_params.alfa = 0;
	view_params.beta = 0;
	//view_params.ex = 0;
	//view_params.maxRad = 1;
	//view_params.S = 0.3;
	view_params.VP = 280;
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