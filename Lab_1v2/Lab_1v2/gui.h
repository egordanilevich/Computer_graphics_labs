#pragma once
#include <windows.h>
#include <windowsx.h>
#include <vector>
#include <stack>
#include "utilty.h"

class gui
{
	// Параметры меню
	int menu_with;		// Ширина элемента 
	int menu_high;		// Высота элемента 
	int menu_offset;	// Отступ между элементами меню
	int menu_start_x;	// Начальная координата X для отрисовки элементов меню
	int menu_start_y;	// Начальная координата Y для отрисовки элементов меню

	tagPOINT Vp_min = { 10, 10 };
	tagPOINT Vp_max = { 610,610 };
	point Win_min = point(0.0, 0.0);
	point Win_max = point(1.0, 1.0);
	std::stack<point> win_stack;
public:
	std::vector<object> objects;	// Список примитивов

	tagPOINT begin, end;				// Начальная и конечная точки окна меню
	object_type selected_option;			// Выбранный элемент меню


	gui();							// Конструктор для инициализации параметров 
	void draw_menu(HWND hwnd);		// Метод для отрисовки элементов меню
	void draw_window(HWND hwnd);	// Метод для отрисовки окна

	void set_option(object_type in_option); // Метод установки выбранного элемента меню
	int get_option();				// Метод получения выбранного элемента меню

	bool is_point_in_rect(const tagPOINT& pt, const tagPOINT& topLeft, const tagPOINT& bottomRight); // Метод проверки попадания в прямоугольник
	int check_menu_choise(HWND hwnd, LPARAM lParam);	// Метод для проверки нажатия на элемент меню
	void add_object(object new_obj);									// Метод для добавления объекта в список
	void clear_objects();
	void zoom(tagPOINT p1, tagPOINT p2);
	void unzoom();
	void draw_object(HWND hwnd, tagPOINT point_begin, tagPOINT point_end, object_type type); // Метод для отрисовки примитива в зависимости от выбранного элемента меню
	inline tagPOINT float_to_rastr(point in)
	{
		tagPOINT out;
		// x
		out.x = roundf((double)Vp_min.x + ((double)Vp_max.x - (double)Vp_min.x) / (Win_max.x - Win_min.x) * (in.x - Win_min.x));
		// y
		out.y = roundf((double)Vp_min.y + ((double)Vp_max.y - (double)Vp_min.y) / (Win_max.y - Win_min.y) * (in.y - Win_min.y));
		return out;
	}

	/*point rastr_to_float(tagPOINT in)
	{
		point out;
		// x
		out.x = (Win_min.x + (Win_max.x - Win_min.x) / ((double)Vp_max.x - (double)Vp_min.x) )
		// y
		return out;
	}*/
	inline point rastr_to_float(tagPOINT in)
	{
		point out;
		// x
		out.x = Win_min.x + (double)(in.x - Vp_min.x) * (Win_max.x - Win_min.x) / (double)(Vp_max.x - Vp_min.x);
		// y
		out.y = Win_min.y + (double)(in.y - Vp_min.y) * (Win_max.y - Win_min.y) / (double)(Vp_max.y - Vp_min.y);
		return out;
	}
};





