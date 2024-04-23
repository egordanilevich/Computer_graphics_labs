#include "gui.h"

 gui::gui()
{
	menu_start_x = 10;		// Начальная координата X для отрисовки элементов меню
	menu_start_y = 10;		// Начальная координата Y для отрисовки элементов меню
	menu_with = 100;		// Ширина элемента
	menu_high = 80;			// Высота элемента
	menu_offset = 20;		// Отступ между элементами меню
	begin.x = menu_start_x;
	begin.y = menu_start_y + menu_high + menu_offset;
	end.x = begin.x + 600;
	end.y = begin.y + 600;
	selected_option = line;	// Выбранный элемент меню 
	
}

void gui::draw_menu(HWND hwnd)
{
	HDC hdc;
	HPEN lPen;
	HGDIOBJ hOld;
	hdc = GetDC(hwnd);
	const char* labels[] = { "line", "rect", "ellipse", "zoom" }; // Текстовые метки для каждого режима


	for (int i = 0; i < 4; i++)
	{
		if (selected_option == i)
		{
			lPen = CreatePen(PS_SOLID, 3, RGB(10, 255, 10));
			hOld = SelectObject(hdc, lPen);
		}
		else 
		{
			lPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			hOld = SelectObject(hdc, lPen);
			
		}
		Rectangle(hdc, menu_start_x + i * (menu_offset + menu_with), menu_start_y + menu_high, menu_start_x + i * (menu_offset + menu_with) + menu_with, menu_start_y);

		SetTextColor(hdc, RGB(0, 0, 0));	//  цвет текста
		SetBkMode(hdc, TRANSPARENT);		//  прозрачный фон текста
		RECT textRect = { (menu_start_x + i * (menu_offset + menu_with)),  (menu_start_y + menu_high), (menu_start_x + i * (menu_offset + menu_with) + menu_with), menu_start_y };
		DrawTextA(hdc, labels[i], -1, &textRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); // текст в центре прямоугольника
	}
	ReleaseDC(hwnd, hdc);
}

void gui::draw_window(HWND hwnd)
{
	HDC hdc;
	hdc = GetDC(hwnd);
	HPEN lPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	HGDIOBJ hOld = SelectObject(hdc, lPen);
	Rectangle(hdc, begin.x, end.y, end.x, begin.y);

	tagPOINT point_begin; 
	tagPOINT point_end;
	for (const auto& obj : objects) 
	{
		point_begin = float_to_rastr(obj.p1);
		point_end = float_to_rastr(obj.p2);
		draw_object(hwnd, point_begin, point_end,obj.type);
	}
	ReleaseDC(hwnd, hdc);
}

void gui::set_option(object_type in_option) // Метод установки выбранного элемента меню
{
	selected_option = in_option;
}

int gui::get_option() // Метод получения выбранного элемента меню
{
	return selected_option;
}
/*
int gui::check_menu_choise(HWND hwnd, LPARAM lParam) // Метод для проверки нажатия на элемент меню
{
	point point;
	point.x = lParam % 0x10000;;
	point.y = lParam / 0x10000;

	if ((begin.x < point.x) && (end.y > point.y) && (end.x > point.x) && (begin.y < point.y))
	{
		return 5;
	}
	else 
	{

		for (int i = 0; i < 4; i++)
		{
			if ((menu_start_x + i * (menu_offset + menu_with) < point.x) && (menu_start_y + menu_high > point.y) && (menu_start_x + i * (menu_offset + menu_with) + menu_with > point.x) && menu_start_y < point.y)
			{
				return i + 1;
			}
		}
	}

	return 0;
}*/

bool gui::is_point_in_rect(const tagPOINT& pt, const tagPOINT& topLeft, const tagPOINT& bottomRight) // Метод проверки попадания в прямоугольник
{
	return (topLeft.x < pt.x&& bottomRight.x > pt.x && topLeft.y < pt.y&& bottomRight.y > pt.y);
}



int gui::check_menu_choise(HWND hwnd, LPARAM lParam) // Метод для проверки нажатия на элемент меню
{
	tagPOINT temp;
	temp.x = lParam % 0x10000;
	temp.y = lParam / 0x10000;

	if (is_point_in_rect(temp, begin, end))
		return 5;

	for (int i = 0; i < 4; i++) 
	{
		tagPOINT menu_item_top_left{ menu_start_x + i * (menu_offset + menu_with), menu_start_y };
		tagPOINT menu_item_bottom_right{ menu_item_top_left.x + menu_with, menu_item_top_left.y + menu_high };

		if (is_point_in_rect(temp, menu_item_top_left, menu_item_bottom_right))
			return i;
		//if ((menu_start_x + i * (menu_offset + menu_with) < temp.x) && (menu_start_y + menu_high > temp.y) && (menu_start_x + i * (menu_offset + menu_with) + menu_with > temp.x) && menu_start_y < temp.y) {
			//return i;
		//}
	}

	return -1;
}

void gui::add_object(object new_obj)
{
	objects.push_back(new_obj);
}

void gui::clear_objects()
{
	objects.clear();
}

void gui::zoom(tagPOINT p1, tagPOINT p2)
{
	point begin, end;
	win_stack.push(Win_min);
	win_stack.push(Win_max);
	begin = rastr_to_float(p1);
	end = rastr_to_float(p2);
	Win_min = begin;
	Win_max = end;
}

void gui::unzoom()
{
	Win_max = win_stack.top();
	win_stack.pop();
	Win_min = win_stack.top();
	win_stack.pop();
}

void gui::draw_object(HWND hwnd, tagPOINT point_begin, tagPOINT point_end, object_type type)
{
	HPEN blue_pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	HDC hdc;
	hdc = GetDC(hwnd);

	SetROP2(hdc, R2_COPYPEN);
	SetBkMode(hdc, TRANSPARENT);
	HGDIOBJ hOld = SelectObject(hdc, blue_pen);


	switch (type)
	{
	case line:
		//add_object(object(, ,line));
		MoveToEx(hdc, point_begin.x, point_begin.y, NULL);
		LineTo(hdc, point_end.x, point_end.y);
		break;
	case rectangle:
		//add_object(object(, , line));
		Rectangle(hdc, point_begin.x, point_end.y, point_end.x, point_begin.y);
		break;
	case elipse:
		//add_object(object(, , line));
		Ellipse(hdc, point_begin.x, point_end.y, point_end.x, point_begin.y);
		break;
	case 4:

	default:
		break;
	}

	ReleaseDC(hwnd, hdc);
}
