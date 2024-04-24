#pragma once
#include <GL/glut.h>
#include <math.h>

struct  params 
{
	int rot;        // Угол поворота
	int alfa;       // Угол альфа
	int ex;         // Переменная для обработки клавиш
	int maxRad;     // Максимальный радиус
	float S;        // Коэффициент уменьшения
	int typeScene;  // Тип сцены
};

void Initialize() 
{
	glClearColor(0.3, 0.3, 0.3, 1.0); // Устанавливаем цвет очистки экрана
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0); // Устанавливаем ортогональную проекцию и видимую область
	//left right bottom top near far Определяет область отсечения видимой области
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST); // Включаем тест глубины. Если этого не сделать изображение не будет отображаться правильно

	// Включаем сглаживание
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glLoadIdentity();
}

// Функция для отрисовки осей
void drawAxes(float k) {
	glColor4f(0, 1, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); //Начальная точка
	glVertex3f(0.0, k * 2.0, 0.0); //Конечная точка
	glEnd();

	glColor4f(1, 0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); //Ось x по направлению
	glVertex3f(k * 2.0, 0.0, 0.0);
	glEnd();

	glColor4f(0, 0, 1, 1);
	glBegin(GL_LINES); //Отрисовывает последнюю ось как не смещенную точку начала
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, k * 2.0);
	glEnd();
}

// Функция для отрисовки снеговика
void draw_snow_man(float k, params& in_params) 
{
	drawAxes(k);//оси
	glColor4f(1, 1, 1, 1);//цвет
	glScalef(k, k, k);//масштаб
	glutSolidSphere(in_params.maxRad, 100, 100);//тело

	glTranslatef(0.0, in_params.maxRad + in_params.S * in_params.maxRad, 0.0);
	glutSolidSphere(in_params.S * in_params.maxRad, 100, 100);//голова

	glTranslatef(0.0, 0.0, in_params.S * in_params.maxRad);
	glColor4f(1, 0.7, 0.0, 1);
	glutSolidCone(0.1, 0.5, 100, 100);//нос

	//глаза
	glColor4f(0.0, 0.0, 0.0, 1);
	glTranslatef(0.1, 0.15, 0.0);
	glutSolidSphere(0.05, 100, 100);
	glTranslatef((-0.2), 0.0, 0.0);
	glutSolidSphere(0.05, 100, 100);
}

void draw_rotate_snowman(float k, params& in_params)
{
	drawAxes(k);
	glScalef(k, k, k);
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования

	glTranslatef(0.0, in_params.maxRad + in_params.S * in_params.maxRad, 0.0);//Перемещение к оси будущего носа


	glRotatef(in_params.rot, 0, 0, 1);	// Вращаем снеговика вокруг его носа
	glTranslatef(0.0, -(in_params.maxRad + in_params.S * in_params.maxRad), 0.0); //Возвращаем
	// Масштабируем и рисуем большую сферу (тело снеговика)
	glColor4f(1, 1, 1, 1);
	
	glutSolidSphere(in_params.maxRad, 100, 100);//тело

	glTranslatef(0.0, in_params.maxRad + in_params.S * in_params.maxRad, 0.0);// Перемещаемся и масштабируемся
	glutSolidSphere(in_params.S * in_params.maxRad, 100, 100); // Рисуем голову

	glTranslatef(0.0, 0.0, in_params.S * in_params.maxRad);
	glColor4f(1, 0.7, 0.0, 1);
	glutSolidCone(0.1, 0.5, 100, 100);// Рисуем нос

	// Рисуем глаза снеговика
	glColor4f(0.0, 0.0, 0.0, 1);
	glTranslatef(0.1, 0.15, 0.0);
	glutSolidSphere(0.05, 100, 100);
	glTranslatef(-0.2, 0.0, 0.0);
	glutSolidSphere(0.05, 100, 100);

	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
}


