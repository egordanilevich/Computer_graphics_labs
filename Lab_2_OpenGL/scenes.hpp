#pragma once
#include "util.hpp"

// Функции для отрисовки различных сцен
void scene_1(params& in_params)
{
	drawAxes(2);

	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0.0, in_params.maxRad, 0.0);
	glutSolidSphere(in_params.maxRad, 50, 50);

	glPopMatrix();
	glTranslatef(in_params.maxRad + in_params.S * in_params.maxRad, in_params.S * in_params.maxRad, 0.0);
	glPushMatrix();
	glScalef(in_params.S, in_params.S, in_params.S);
	glutSolidSphere(in_params.maxRad, 50, 50);

	glPopMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(in_params.S * in_params.maxRad + 0.05, -in_params.S * in_params.maxRad + 0.05, 0.0);
	glutSolidSphere(0.05, 50, 50);

	glTranslatef(0.2, 0.0, 0.0);
	glutSolidSphere(0.05, 50, 50);

	glTranslatef(0.2, -0.05, 0.0);
	glColor3f(1, 0.7, 0.0);
	glRotatef(270, 1, 1, 1);
	glutSolidCone(0.1, 0.5, 50, 50);
}


void scene_2(params& in_params) // Функция отрисовки сцены №2
{
	
	draw_snow_man(1,in_params); // Вызываем функцию отрисовки снеговика с масштабом 1
}


void scene_3(params& in_params) // Функция отрисовки сцены №3
{
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	draw_snow_man(1, in_params); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(in_params.maxRad + 0.7 * in_params.maxRad, 0.0, 0.0); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.7, in_params); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(in_params.maxRad + 2 * 0.7 * in_params.maxRad + 0.49 * in_params.maxRad, 0.0, 0.0); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.49, in_params); // Отрисовываем снеговика с масштабом 0.49
}


void scene_4(params& in_params) // Функция отрисовки сцены №4
{
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	draw_snow_man(1, in_params); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(0.0, 0.0, in_params.maxRad + 0.7 * in_params.maxRad); // Переносим на позицию для следующего снеговика
	
	draw_rotate_snowman(0.7, in_params); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(0.0, 0.0, in_params.maxRad + 2 * 0.7 * in_params.maxRad + 0.49 * in_params.maxRad); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.49, in_params); // Отрисовываем снеговика с масштабом 0.49
}


void scene_5(params& in_params) // Функция отрисовки сцены №5
{
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	draw_snow_man(1, in_params); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(0.0, in_params.maxRad + 2 * in_params.S * in_params.maxRad + 0.7 * in_params.maxRad, 0.0); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.7, in_params); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(0.0, in_params.maxRad + 2 * in_params.S * in_params.maxRad + 0.7 * 2 * in_params.maxRad + 0.7 * 2 * in_params.S * in_params.maxRad + 0.49 * in_params.maxRad, 0.0); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.49, in_params); // Отрисовываем снеговика с масштабом 0.49
}


void scene_6(params& in_params)// Функция отрисовки сцены №6
{
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	draw_snow_man(1, in_params); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(in_params.maxRad / sqrt(3) + in_params.maxRad * 0.7 / sqrt(3), in_params.maxRad / sqrt(3) + in_params.maxRad * 0.7 / sqrt(3), in_params.maxRad / sqrt(3) + in_params.maxRad * 0.7 / sqrt(3)); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.7, in_params); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(in_params.maxRad / sqrt(3) + 2 * in_params.maxRad * 0.7 / sqrt(3) + 0.49 * in_params.maxRad / sqrt(3), in_params.maxRad / sqrt(3) + 2 * in_params.maxRad * 0.7 / sqrt(3) + 0.49 * in_params.maxRad / sqrt(3), in_params.maxRad / sqrt(3) + 2 * in_params.maxRad * 0.7 / sqrt(3) + 0.49 * in_params.maxRad / sqrt(3)); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.49, in_params); // Отрисовываем снеговика с масштабом 0.49
}


void scene_7(params& in_params) // Функция отрисовки сцены №7
{
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	drawAxes(1); // Отрисовываем оси координат
	glTranslatef(0, in_params.maxRad, 0); // Переносим на позицию для следующего снеговика
	draw_snow_man(1, in_params); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(in_params.maxRad + 0.7 * in_params.maxRad, 0.7 * in_params.maxRad, 0.0); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.7, in_params); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(in_params.maxRad + 2 * 0.7 * in_params.maxRad + 0.49 * in_params.maxRad, 0.49 * in_params.maxRad, 0.0); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.49, in_params); // Отрисовываем снеговика с масштабом 0.49
}


void scene_8(params& in_params) // Функция отрисовки сцены №8
{
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	drawAxes(1); // Отрисовываем оси координат
	glTranslatef(0, in_params.maxRad, 0.0); // Переносим на позицию для следующего снеговика
	glRotatef(in_params.rot, 0, 1, 0); // Поворачиваем на угол rot вокруг оси y
	draw_snow_man(1, in_params); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(in_params.maxRad + 0.7 * in_params.maxRad, 0.7 * in_params.maxRad, 0.0); // Переносим на позицию для следующего снеговика
	glRotatef(in_params.rot, 0, 1, 0); // Поворачиваем на угол rot вокруг оси y
	draw_snow_man(0.7, in_params); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(in_params.maxRad + 2 * 0.7 * in_params.maxRad + 0.49 * in_params.maxRad, 0.49 * in_params.maxRad, 0.0); // Переносим на позицию для следующего снеговика
	glRotatef(in_params.rot, 0, 1, 0); // Поворачиваем на угол rot вокруг оси y
	draw_snow_man(0.49, in_params); // Отрисовываем снеговика с масштабом 0.49
}


void scene_9(params& in_params) // Функция отрисовки сцены №9
{
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	drawAxes(1); // Отрисовываем оси координат
	glTranslatef(0, in_params.maxRad, 0.0); // Переносим на позицию для следующего снеговика
	draw_snow_man(1, in_params); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(in_params.maxRad + 0.7 * in_params.maxRad, 0.7 * in_params.maxRad, 0.0); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.7, in_params); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(in_params.maxRad + 2 * 0.7 * in_params.maxRad + 0.49 * in_params.maxRad, 0.49 * in_params.maxRad, 0.0); // Переносим на позицию для следующего снеговика
	draw_snow_man(0.49, in_params); // Отрисовываем снеговика с масштабом 0.49
}


void scene_10(params& in_params) // Функция отрисовки сцены №10
{
	glPushMatrix();
	draw_snow_man(1, in_params);

	glPopMatrix();
	glRotatef(in_params.rot, 0, 1, 0);
	glTranslatef(in_params.maxRad + 0.7 * in_params.maxRad + 1, 0.0, 0.0);

	draw_snow_man(0.7, in_params);
	glPushMatrix();

	glTranslatef(0.0, -(in_params.maxRad + 0.7 * in_params.maxRad), 0.0);
	glRotatef(in_params.rot, 0, 0, 1);
	glTranslatef(0.0, in_params.maxRad + 0.7 * in_params.maxRad, 0.0);


	glTranslatef(0, 1.5, 0.0);
	draw_snow_man(0.49, in_params);
	glTranslatef(0, -1.5 - 2 * 0.7 * in_params.maxRad - 0.7 * in_params.maxRad, 0.0);

	glPopMatrix(); //èçâëåêàåò òåêùèé ñòåê ìàòðèöû
	glRotatef(in_params.rot, 0, 1, 0);
	glTranslatef(1.5, 0.0, 0.0);

	draw_snow_man(0.343, in_params);
}
