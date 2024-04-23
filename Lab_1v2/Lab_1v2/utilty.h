#pragma once

struct point 
{
	double x, y;
	point(double in_x, double in_y)
	{
		x = in_x;
		y = in_y;
	}
	point(){}
};


enum object_type // типы фигур
{ 
	line, rectangle, elipse, zoom 
};

struct object
{
	point p1, p2; // точки фигуры
	object_type type; // тип фигуры
	object(point in_p1, point in_p2, object_type in_type)
	{
		p1 = in_p1;
		p2 = in_p2;
		type = in_type;
	}
};


