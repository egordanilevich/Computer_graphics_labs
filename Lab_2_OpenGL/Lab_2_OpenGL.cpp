#include "scenes.hpp"
#include <iostream>
params view_params;



void scene() //Выбор сцены
{
	switch (view_params.typeScene) {
	case 1:
		glRotatef(view_params.rot, 0, 1, 0);
		scene_1(view_params);
		break;
	case 2:
		glRotatef(view_params.rot, 0, 1, 0);
		scene_2(view_params);
		break;
	case 3:
		glRotatef(view_params.rot, 0, 1, 0);
		scene_3(view_params);
		break;
	case 4:
		//glRotatef(view_params.rot, 0, 1, 0);
		scene_4(view_params);
		break;
	case 5:
		glRotatef(view_params.rot, 0, 1, 0);
		scene_5(view_params);
		break;
	case 6:
		glRotatef(view_params.alfa, 1, 1, 1);
		glRotatef(view_params.rot, 0, 1, 0);
		scene_6(view_params);
		break;
	case 7:
		glTranslatef(view_params.maxRad + 0.7 * view_params.maxRad, 0.7 * view_params.maxRad, 0.0);
		glRotatef(view_params.rot, 0, 1, 0);
		glTranslatef(-(view_params.maxRad + 0.7 * view_params.maxRad), -0.7 * view_params.maxRad, 0.0);
		scene_7(view_params);
		break;
	case 8:
		scene_8(view_params);
		break;
	case 9:
		glTranslatef(view_params.maxRad + 2 * 0.7 * view_params.maxRad + 0.49 * view_params.maxRad, 0.49 * view_params.maxRad, 0.0);
		glRotatef(view_params.rot, 0, 1, 0);
		glTranslatef(-(view_params.maxRad + 2 * 0.7 * view_params.maxRad + 0.49 * view_params.maxRad), -0.49 * view_params.maxRad, 0.0);
		scene_9(view_params);
		break;
	case 10:
		scene_10(view_params);
		break;
	default:
		std::cerr << "Scene ERROR!!!";
		break;
	}
}


void specialkeys(int key, int x, int y) // Функция для обработки нажатий клавиш
{
	if (key == GLUT_KEY_F1) 
	{
		view_params.typeScene = 1;
	}
	else if (key == GLUT_KEY_F2) 
	{
		view_params.typeScene = 2;
	}
	else if (key == GLUT_KEY_F3) 
	{
		view_params.typeScene = 3;
	}
	else if (key == GLUT_KEY_F4) 
	{
		view_params.typeScene = 4;
	}
	else if (key == GLUT_KEY_F5) 
	{
		view_params.typeScene = 5;
	}
	else if (key == GLUT_KEY_F6) 
	{
		view_params.typeScene = 6;
	}
	else if (key == GLUT_KEY_F7) 
	{
		view_params.typeScene = 7;
	}
	else if (key == GLUT_KEY_F8) 
	{
		view_params.typeScene = 8;
	}
	else if (key == GLUT_KEY_F9) 
	{
		view_params.typeScene = 9;
	}
	else if (key == GLUT_KEY_F10) 
	{
		view_params.typeScene = 10;
	}
	if (key == GLUT_KEY_LEFT) 
	{
		view_params.rot = view_params.rot - 2.0;
	}
	else if (key == GLUT_KEY_RIGHT) 
	{
		view_params.rot = view_params.rot + 2.0;
	}
	else if (key == GLUT_KEY_UP) {
		view_params.alfa = view_params.alfa - 2.0;
	}
	else if (key == GLUT_KEY_DOWN) {
		view_params.alfa = view_params.alfa + 2.0;
	}
	else {
		view_params.ex = key;
		view_params.rot = 0;
		view_params.alfa = 0;
	}
	glutPostRedisplay();  // Перерисовываем окно
}

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очищаем буферы

	glViewport(0, 0, 800, 800); // Устанавливаем область вывода для первой сцены
	glLoadIdentity(); // Сбрасываем матрицу моделирования
	scene(); // Отрисовываем сцену

	glViewport(800, 0, 800, 800); // Устанавливаем область вывода для второй сцены
	glLoadIdentity();
	glRotatef(90, 1, 0, 0); // Поворачиваем сцену на 90 градусов вокруг оси x
	scene(); // Отрисовываем сцену

	glutSwapBuffers(); // Переключаем буферы, чтобы отобразить нарисованное
}

int main(int argc, char** argv) 
{
	view_params.rot = 0; // Угол поворота
	view_params.alfa = 0; // Угол альфа
	view_params.ex = 0; // Переменная для обработки клавиш
	view_params.maxRad = 1; // Максимальный радиус
	view_params.S = 0.3; // Коэффициент уменьшения
	view_params.typeScene = 1; // Тип сцены

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB); // Задаем режим отображения, включая буфер глубины и двойную буферизацию
	glutInitWindowSize(1600, 800); // Устанавливаем размеры окна
	glutInitWindowPosition(10, 20); // Устанавливаем позицию окна на экране
	glutCreateWindow("Snowman");
	
	glutDisplayFunc(display);  // Устанавливаем функцию отрисовки
	glutSpecialFunc(specialkeys); // Устанавливаем функцию обработки специальных клавиш
	Initialize(); // Выполняем инициализацию
	glutMainLoop(); // Запускаем основной цикл GLUT
	return 0;
}

