#include <GL/glut.h>
#include <math.h>


int rot = 0; // Угол поворота
int alfa = 0; // Угол альфа
int ex = 0; // Переменная для обработки клавиш
int maxRad = 1; // Максимальный радиус
float S = 0.3; // Коэффициент уменьшения
int typeScene = 1; // Тип сцены


void Initialize() {
	glClearColor(0.3, 0.3, 0.3, 1.0); // Устанавливаем цвет очистки экрана
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0); // Устанавливаем ортогональную проекцию и видимую область
	//left right bottom top near far Определяет область отсечения видимой области
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST); // Включаем тест глубины. Если этого не сделать изображение не будет отображаться правильно
	glLoadIdentity();
}

// Функция для отрисовки осей
void drawAxes(float k) {
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); //Начальная точка
	glVertex3f(0.0, k * 2.0, 0.0); //Конечная точка
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); //Ось x по направлению
	glVertex3f(k * 2.0, 0.0, 0.0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES); //Отрисовывает последнюю ось как не смещенную точку начала
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, k * 2.0);
	glEnd();
}

// Функция для отрисовки снеговика
void drawSnowMan(float k) {
	drawAxes(k);
	glColor3f(1, 1, 1);
	glScalef(k, k, k);
	glutSolidSphere(maxRad, 100, 100);

	glTranslatef(0.0, maxRad + S * maxRad, 0.0);
	glutSolidSphere(S * maxRad, 100,100);

	glTranslatef(0.0, 0.0, S * maxRad);
	glColor3f(1, 0.7, 0.0);
	glutSolidCone(0.1, 0.5, 100, 100);

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.1, 0.15, 0.0);
	glutSolidSphere(0.05, 100, 100);
	glTranslatef((-0.2), 0.0, 0.0);
	glutSolidSphere(0.05, 100, 100);
}

// Функции для отрисовки различных сцен
void draw1Scene() {
	drawAxes(2);

	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0.0, maxRad, 0.0);
	glutSolidSphere(maxRad, 50, 50);

	glPopMatrix();
	glTranslatef(maxRad + S * maxRad, S * maxRad, 0.0);
	glPushMatrix();
	glScalef(S, S, S);
	glutSolidSphere(maxRad, 50, 50);

	glPopMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(S * maxRad + 0.05, -S * maxRad + 0.05, 0.0);
	glutSolidSphere(0.05, 50, 50);

	glTranslatef(0.2, 0.0, 0.0);
	glutSolidSphere(0.05, 50, 50);

	glTranslatef(0.2, -0.05, 0.0);
	glColor3f(1, 0.7, 0.0);
	glRotatef(270, 1, 1, 1);
	glutSolidCone(0.1, 0.5, 50, 50);
}

// Функция отрисовки сцены №2
void draw2Scene() {
	// Вызываем функцию отрисовки снеговика с масштабом 1
	drawSnowMan(1);
}

// Функция отрисовки сцены №3
void draw3Scene() {
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	drawSnowMan(1); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(maxRad + 0.7 * maxRad, 0.0, 0.0); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.7); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(maxRad + 2 * 0.7 * maxRad + 0.49 * maxRad, 0.0, 0.0); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.49); // Отрисовываем снеговика с масштабом 0.49
}

// Функция отрисовки сцены №4
void draw4Scene() {
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	drawSnowMan(1); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(0.0, 0.0, maxRad + 0.7 * maxRad); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.7); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(0.0, 0.0, maxRad + 2 * 0.7 * maxRad + 0.49 * maxRad); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.49); // Отрисовываем снеговика с масштабом 0.49
}

// Функция отрисовки сцены №5
void draw5Scene() {
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	drawSnowMan(1); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(0.0, maxRad + 2 * S * maxRad + 0.7 * maxRad, 0.0); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.7); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(0.0, maxRad + 2 * S * maxRad + 0.7 * 2 * maxRad + 0.7 * 2 * S * maxRad + 0.49 * maxRad, 0.0); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.49); // Отрисовываем снеговика с масштабом 0.49
}

// Функция отрисовки сцены №6
void draw6Scene() {
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	drawSnowMan(1); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(maxRad / sqrt(3) + maxRad * 0.7 / sqrt(3), maxRad / sqrt(3) + maxRad * 0.7 / sqrt(3), maxRad / sqrt(3) + maxRad * 0.7 / sqrt(3)); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.7); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(maxRad / sqrt(3) + 2 * maxRad * 0.7 / sqrt(3) + 0.49 * maxRad / sqrt(3), maxRad / sqrt(3) + 2 * maxRad * 0.7 / sqrt(3) + 0.49 * maxRad / sqrt(3), maxRad / sqrt(3) + 2 * maxRad * 0.7 / sqrt(3) + 0.49 * maxRad / sqrt(3)); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.49); // Отрисовываем снеговика с масштабом 0.49
}

// Функция отрисовки сцены №7
void draw7Scene() {
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	drawAxes(1); // Отрисовываем оси координат
	glTranslatef(0, maxRad, 0); // Переносим на позицию для следующего снеговика
	drawSnowMan(1); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(maxRad + 0.7 * maxRad, 0.7 * maxRad, 0.0); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.7); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(maxRad + 2 * 0.7 * maxRad + 0.49 * maxRad, 0.49 * maxRad, 0.0); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.49); // Отрисовываем снеговика с масштабом 0.49
}

// Функция отрисовки сцены №8
void draw8Scene() {
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	drawAxes(1); // Отрисовываем оси координат
	glTranslatef(0, maxRad, 0.0); // Переносим на позицию для следующего снеговика
	glRotatef(rot, 0, 1, 0); // Поворачиваем на угол rot вокруг оси y
	drawSnowMan(1); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(maxRad + 0.7 * maxRad, 0.7 * maxRad, 0.0); // Переносим на позицию для следующего снеговика
	glRotatef(rot, 0, 1, 0); // Поворачиваем на угол rot вокруг оси y
	drawSnowMan(0.7); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(maxRad + 2 * 0.7 * maxRad + 0.49 * maxRad, 0.49 * maxRad, 0.0); // Переносим на позицию для следующего снеговика
	glRotatef(rot, 0, 1, 0); // Поворачиваем на угол rot вокруг оси y
	drawSnowMan(0.49); // Отрисовываем снеговика с масштабом 0.49
}

// Функция отрисовки сцены №9
void draw9Scene() {
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования
	glPushMatrix(); // Сохраняем текущее положение матрицы моделирования ещё раз
	drawAxes(1); // Отрисовываем оси координат
	glTranslatef(0, maxRad, 0.0); // Переносим на позицию для следующего снеговика
	drawSnowMan(1); // Отрисовываем снеговика с масштабом 1
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(maxRad + 0.7 * maxRad, 0.7 * maxRad, 0.0); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.7); // Отрисовываем снеговика с масштабом 0.7
	glPopMatrix(); // Восстанавливаем положение матрицы моделирования
	glTranslatef(maxRad + 2 * 0.7 * maxRad + 0.49 * maxRad, 0.49 * maxRad, 0.0); // Переносим на позицию для следующего снеговика
	drawSnowMan(0.49); // Отрисовываем снеговика с масштабом 0.49
}

// Функция отрисовки сцены №10
void draw10Scene() {
	drawAxes(1);
	glColor3f(1, 1, 1);
	glutSolidSphere(maxRad, 50, 50);

	glRotatef(-rot, 0, 0, 1);
	glTranslatef(0.0, maxRad + S * maxRad, 0.0);

	glPushMatrix();
	glScalef(S, S, S); //аргументы - коэффициенты масштабирования вдоль каждой из 3 осей
	glutSolidSphere(maxRad, 50, 50);
	glPopMatrix();

	glTranslatef(0.0, 0.0, S * maxRad);
	glColor3f(1, 0.7, 0.0);
	glutSolidCone(0.1, 0.5, 50, 50); //ðàäèóñîì îñíîâàíèÿ base è âûñîòîé height, ðàñïîëîæåííûé âäîëü îñè z. Îñíîâàíèå íàõîäèòñÿ â ïëîñêîñòè z=0

	glColor3f(0.0, 0.0, 0.0);
	glRotatef(rot, 0, 0, 1);
	glTranslatef(0.1, 0.15, 0.0);
	glutSolidSphere(0.05, 50, 50); //radius, slices, stacks
	glTranslatef(-0.2, 0.0, 0.0);
	glutSolidSphere(0.05, 50, 50);
}

void draw11Scene() {
	glPushMatrix();
	drawSnowMan(1);

	glPopMatrix();
	glRotatef(rot, 0, 1, 0);
	glTranslatef(maxRad + 0.7 * maxRad + 1, 0.0, 0.0);

	drawSnowMan(0.7);
	glPushMatrix();

	glTranslatef(0.0, -(maxRad + 0.7 * maxRad), 0.0);
	glRotatef(rot, 0, 0, 1);
	glTranslatef(0.0, maxRad + 0.7 * maxRad, 0.0);


	glTranslatef(0, 1.5, 0.0);
	drawSnowMan(0.49);
	glTranslatef(0, -1.5 - 2 * 0.7 * maxRad - 0.7 * maxRad, 0.0);

	glPopMatrix(); //èçâëåêàåò òåêùèé ñòåê ìàòðèöû
	glRotatef(rot, 0, 1, 0);
	glTranslatef(1.5, 0.0, 0.0);

	drawSnowMan(0.343);
}


void scene() {
	switch (typeScene) {
	case 1:
		glRotatef(rot, 0, 1, 0);
		draw1Scene();
		break;
	case 2:
		glRotatef(rot, 0, 1, 0);
		draw2Scene();
		break;
	case 3:
		glRotatef(rot, 0, 1, 0);
		draw3Scene();
		break;
	case 4:
		glRotatef(rot, 0, 1, 0);
		draw4Scene();
		break;
	case 5:
		glRotatef(rot, 0, 1, 0);
		draw5Scene();
		break;
	case 6:
		glRotatef(alfa, 1, 1, 1);
		glRotatef(rot, 0, 1, 0);
		draw6Scene();
		break;
	case 7:
		glTranslatef(maxRad + 0.7 * maxRad, 0.7 * maxRad, 0.0);
		glRotatef(rot, 0, 1, 0);
		glTranslatef(-(maxRad + 0.7 * maxRad), -0.7 * maxRad, 0.0);
		draw7Scene();
		break;
	case 8:
		draw8Scene();
		break;
	case 9:
		glTranslatef(maxRad + 2 * 0.7 * maxRad + 0.49 * maxRad, 0.49 * maxRad, 0.0);
		glRotatef(rot, 0, 1, 0);
		glTranslatef(-(maxRad + 2 * 0.7 * maxRad + 0.49 * maxRad), -0.49 * maxRad, 0.0);
		draw9Scene();
		break;
	case 10:
		draw10Scene();
		break;
	case 11:
		draw11Scene();
		break;
	}
}

// Функция для обработки нажатий клавиш
void specialkeys(int key, int x, int y) {
	if (key == GLUT_KEY_F1) {
		typeScene = 1;
	}
	else if (key == GLUT_KEY_F2) {
		typeScene = 2;
	}
	else if (key == GLUT_KEY_F3) {
		typeScene = 3;
	}
	else if (key == GLUT_KEY_F4) {
		typeScene = 4;
	}
	else if (key == GLUT_KEY_F5) {
		typeScene = 5;
	}
	else if (key == GLUT_KEY_F6) {
		typeScene = 6;
	}
	else if (key == GLUT_KEY_F7) {
		typeScene = 7;
	}
	else if (key == GLUT_KEY_F8) {
		typeScene = 8;
	}
	else if (key == GLUT_KEY_F9) {
		typeScene = 9;
	}
	else if (key == GLUT_KEY_F10) {
		typeScene = 10;
	}
	else if (key == GLUT_KEY_F11) {
		typeScene = 11;
	}

	if (key == GLUT_KEY_LEFT) {
		rot = rot - 2.0;
	}
	else if (key == GLUT_KEY_RIGHT) {
		rot = rot + 2.0;
	}
	else if (key == GLUT_KEY_UP) {
		alfa = alfa - 2.0;
	}
	else if (key == GLUT_KEY_DOWN) {
		alfa = alfa + 2.0;
	}
	else {
		ex = key;
		rot = 0;
		alfa = 0;
	}
	glutPostRedisplay();  // Перерисовываем окно
}

void Display() {
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

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB); // Задаем режим отображения, включая буфер глубины и двойную буферизацию
	glutInitWindowSize(1600, 800); // Устанавливаем размеры окна
	glutInitWindowPosition(10, 20); // Устанавливаем позицию окна на экране
	glutCreateWindow("Cyber Snowmen"); // Создаем окно с названием "Cyber Snowmen"
	glutDisplayFunc(Display);  // Устанавливаем функцию отрисовки
	glutSpecialFunc(specialkeys); // Устанавливаем функцию обработки специальных клавиш
	Initialize(); // Выполняем инициализацию
	glutMainLoop(); // Запускаем основной цикл GLUT
	return 0;
}

