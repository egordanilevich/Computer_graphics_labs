#pragma once
#include <GL/glut.h>
#include <math.h>
#include <GL\gl.h>

struct params
{
	int scene_num = 1;
	float dist = 0.1;
	int Count = 6;
	int CountZ = 4;
	float s = 0.8;

	bool isDirectional = true; // Переменная для переключения типа источника света
	bool light0Enabled = true; // Переменная для включения/выключения источника света 0
	bool light1Enabled = true; // Переменная для включения/выключения источника света 1
	float lightPosX = 0.0f; // Позиция источника света по оси X
	float lightPosY = 0.0f; // Позиция источника света по оси Y
	float lightPosX1 = 0.0f; // Позиция источника света по оси X
	float lightPosY1 = 0.0f; // Позиция источника света по оси Y

};

void plate(GLfloat minx, GLfloat miny, GLfloat minz, GLfloat dx, GLfloat dy, GLfloat dz, GLenum n) {
    GLfloat kx, ky, kz;
    if (n > 1) {
        kx = dx / 2.0; ky = dy / 2.0; kz = dz / 2.0;
        plate(minx, miny, minz, kx, ky, kz, n / 2);
        plate(minx + kx, miny, minz + kz, kx, ky, kz, n / 2);
        plate(minx + kx, miny - ky, minz + kz, kx, ky, kz, n / 2);
        plate(minx, miny - ky, minz, kx, ky, kz, n / 2);
    }
    else
    {
        glNormal3f(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3f(minx, miny, minz);
        glVertex3f(minx, miny - dy, minz);
        glVertex3f(minx + dx, miny - dy, minz + dz);
        glVertex3f(minx + dx, miny, minz + dz);
        glEnd();
    }
}