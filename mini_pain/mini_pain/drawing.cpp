#include "mini_paint.h"

void print_vec(vector <vector <char>> & a, bool print)
{
	if (print)
	{
		ofstream out("result_operation_file.it");
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a[0].size(); j++)
			{
				out << a[i][j] << " ";
				cout << a[i][j] << " ";
			}
			out << "\n";
			cout << "\n";
		}
		out.close();
	}
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a[0].size(); j++)
			{
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}
}

void background(vector <vector <char>> & a, int width, int height, char ch)
{
	vector <vector <char>> res(height, vector <char>(width));
	a = res;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			a[i][j] = ch;
		}
	}
}

void rect(vector <vector <char>> & a, float x, float y, float width, float height, char ch)
{
	x = round(x);
	y = round(y);
	width = round(width);
	height = round(height);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			if (i == y && j >= x && j < x + width)
				a[i][j] = ch;
			if (i + 1 == y + height && j >= x && j < x + width)
				a[i][j] = ch;
			if (j == x && i >= y && i < y + height)
				a[i][j] = ch;
			if (j + 1 == x + width && i >= y && i < y + height)
				a[i][j] = ch;
		}
	}
}

void fill_rect(vector <vector <char>> & a, float x, float y, float width, float height, char ch)
{
	x = round(x);
	y = round(y);
	width = round(width);
	height = round(height);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			if (i >= y && i < y + height && j >= x && j < x + width)
				a[i][j] = ch;
		}
	}
}

void circ(vector <vector <char>> & a, float x, float y, float radius, char ch)
{
	x = round(x);
	y = round(y);
	radius = round(radius);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			if ((j - x)*(j - x) + (i - y)*(i - y) > (radius - 1)*(radius - 1) &&
				(j - x)*(j - x) + (i - y)*(i - y) <= (radius)*(radius))
				a[i][j] = ch;
		}
	}
}