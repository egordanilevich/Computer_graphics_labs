#include <windows.h>
#include <windowsx.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <cmath>
#include "gui.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//using namespace std;



HDC hdc;

gui* Paint_GUI = NULL;
bool draw_line;
//tagPOINT point_curr, point_old;
tagPOINT point_down, point_move;

HPEN blue_pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); // создаем перо синие

HPEN red_pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // создаем перо красное

HGDIOBJ hOld = SelectObject(hdc, blue_pen);

int sign(int in)
{
	if (in > 0) return 1;
	else
	{
		if (in < 0) return -1;
		else return 0;
	}
}

tagPOINT make_square(tagPOINT p1, tagPOINT p2)
{
	tagPOINT out;
	out.x = p2.x;
	out.y = p1.y + abs(p1.x + p2.x) * sign(p2.y - p1.y);
	return out;
}

void mouse_down(HWND hwnd, LPARAM lParam) 
{
	hOld = SelectObject(hdc, blue_pen);
	SetROP2(hdc, R2_NOTXORPEN);
	point_down.x = lParam % 0x10000;
	point_down.y = lParam / 0x10000;
	point_move = point_down;
	MoveToEx(hdc, point_down.x, point_down.y, NULL);
	LineTo(hdc, point_move.x, point_move.y);
}

void mouse_up(HWND hwnd, LPARAM lParam)
{
	if (Paint_GUI->get_option() == zoom)
	{
		SetROP2(hdc, R2_NOTXORPEN);
		Rectangle(hdc, point_down.x, point_down.y, point_move.x, point_move.y);
	}
	else
	{
		// ------------- УДАЛЕНИЕ ----------------------
		SetROP2(hdc, R2_NOTXORPEN);
		MoveToEx(hdc, point_down.x, point_down.y, NULL);
		LineTo(hdc, point_move.x, point_move.y); //удаление красной
		// ----------------------------------------------


		// --------------- РИСОВАНИЕ ---------------------
		point p1, p2;
		p1 = Paint_GUI->rastr_to_float(point_down);
		p2 = Paint_GUI->rastr_to_float(point_move);
		SetROP2(hdc, R2_COPYPEN);
		hOld = SelectObject(hdc, blue_pen); // выбор синего
		//Paint_GUI->add_object();
		object new_obj = object(p1, p2, Paint_GUI->selected_option);
		Paint_GUI->add_object(new_obj);
		InvalidateRect(hwnd, NULL, TRUE);
		// -----------------------------------------------------
	}
	
}
void mouse_move(HWND hwnd, LPARAM lParam)
{
	if (Paint_GUI->get_option() == zoom)
	{
		//------------------- УДАЛЕНИЕ ---------------------------------
		SetROP2(hdc, R2_NOTXORPEN);
		Rectangle(hdc, point_down.x, point_down.y, point_move.x, point_move.y);
		// ------------------------------------------------------------

		// ------------------ РИСОВАНИЕ ------------------------------------
		point_move.x = lParam % 0x10000;
		point_move.y = lParam / 0x10000;
		hOld = SelectObject(hdc, red_pen); // выбор красной
		point_move = make_square(point_down, point_move);
		Rectangle(hdc, point_down.x, point_down.y, point_move.x, point_move.y);
	}
	else
	{
		//------------------- УДАЛЕНИЕ ---------------------------------
		SetROP2(hdc, R2_NOTXORPEN);
		MoveToEx(hdc, point_down.x, point_down.y, NULL);
		LineTo(hdc, point_move.x, point_move.y); // удаление красной
		// ------------------------------------------------------------

		// ------------------ РИСОВАНИЕ ------------------------------------
		point_move.x = lParam % 0x10000;
		point_move.y = lParam / 0x10000;
		hOld = SelectObject(hdc, red_pen); // выбор красной
		MoveToEx(hdc, point_down.x, point_down.y, NULL);
		LineTo(hdc, point_move.x, point_move.y); //рисование красной
	}
	
}





int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
	
	MSG  msg;
	HWND hwnd;
	WNDCLASSW wc = { 0 };

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = L"Graph";
	wc.hInstance = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(0, IDC_ARROW);

	RegisterClassW(&wc);
	hwnd = CreateWindowW(wc.lpszClassName, L"Простой редактор",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 750, 750, NULL, NULL, hInstance, NULL);

	hdc = GetDC(hwnd);


	Paint_GUI = new gui();
	Paint_GUI->draw_menu(hwnd);
	Paint_GUI->draw_window(hwnd);

	

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	delete(Paint_GUI);
	ReleaseDC(hwnd, hdc);
	return (int)msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	RECT r;
	HDC hdc;
	int select_option;
	switch (msg) {
	case WM_PAINT:
		GetClientRect(hwnd, &r);
		hdc = BeginPaint(hwnd, &ps);
		Paint_GUI->draw_menu(hwnd);
		Paint_GUI->draw_window(hwnd);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_MOUSEMOVE:
		if (draw_line)
		{
			select_option = Paint_GUI->check_menu_choise(hwnd, lParam);
			if (select_option == 5)
			{
				mouse_move(hwnd, lParam);
			}
			
		}
		break;
	case WM_LBUTTONDOWN:
		
		select_option = Paint_GUI->check_menu_choise(hwnd, lParam);
		if(select_option == -1)
			return DefWindowProcW(hwnd, msg, wParam, lParam);
		else if (select_option == 5)
		{
			draw_line = true;
			mouse_down(hwnd, lParam);
		}
		else
		{
			switch (select_option)
			{
			case 0:
				Paint_GUI->set_option(line);
				break;
			case 1:
				Paint_GUI->set_option(rectangle);
				break;
			case 2:
				Paint_GUI->set_option(elipse);
				break;
			case 3:
				Paint_GUI->set_option(zoom);
				break;
			default:
				break;
			}
			
			Paint_GUI->draw_menu(hwnd);
		}
		break;
	case WM_LBUTTONUP:
		if(draw_line)
		{ 
			draw_line = false;
			mouse_up(hwnd, lParam);
		}
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_RBUTTONUP:
		Paint_GUI->clear_objects();
		Paint_GUI->draw_menu(hwnd);
		Paint_GUI->draw_window(hwnd);
		break;
	}
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

