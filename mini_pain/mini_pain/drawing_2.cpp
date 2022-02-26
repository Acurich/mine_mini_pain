#include "mini_paint.h"

void fill_circ(vector <vector <char>> & a, float x, float y, float radius, char ch)
{
	x = round(x);
	y = round(y);
	radius = round(radius);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			if ((j - x)*(j - x) + (i - y)*(i - y) <= radius * radius)
				a[i][j] = ch;
		}
	}
}

void line(vector <vector <char>> & a, float x1, float y1, float x2, float y2, char ch)
{
	bool steep = abs(y2 - y1) > abs(x2 - x1);
	if (steep)
	{
		swap(x1, y1);
		swap(x2, y2);
	}
	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	int dx = x2 - x1;
	int dy = abs(y2 - y1);
	int error = dx / 2;
	int ystep = (y1 < y2) ? 1 : -1;
	int y = y1;
	for (int x = x1; x <= x2; x++)
	{
		int _x = steep ? y : x;
		int _y = steep ? x : y;
		if (_x >= 0 && _x < a[0].size() && _y >= 0 && _y < a.size())
			a[_y][_x] = ch;
		error -= dy;
		if (error < 0)
		{
			y += ystep;
			error += dx;
		}
	}
}

void set_color(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}