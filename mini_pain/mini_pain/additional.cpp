#include "mini_paint.h"

void swap(int & a, int & b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void set_function(vector <vector <char>> & a, vector <string> & strs, char bg)
{
	if ((strs[0][0] == 'r' || strs[0][0] == 'R' || strs[0][0] == 'L') && strs[5][0] == bg ||
		(strs[0][0] == 'c' || strs[0][0] == 'C') && strs[4][0] == bg)
	{
		cout << "Your symbol matches the background symbol, change it or repeat (bg symbol is: " << bg << ")\n";
		if (strs[0][0] == 'r' || strs[0][0] == 'R' || strs[0][0] == 'L')
			cin >> strs[5][0];
		else
			cin >> strs[4][0];
	}
	if (strs[0][0] == 'r')
	{
		rect(a, parse_float(strs[1]), parse_float(strs[2]), parse_float(strs[3]), parse_float(strs[4]), strs[5][0]);
	}
	else if (strs[0][0] == 'R')
	{
		fill_rect(a, parse_float(strs[1]), parse_float(strs[2]), parse_float(strs[3]), parse_float(strs[4]), strs[5][0]);
	}
	else if (strs[0][0] == 'c')
	{
		circ(a, parse_float(strs[1]), parse_float(strs[2]), parse_float(strs[3]), strs[4][0]);
	}
	else if (strs[0][0] == 'C')
	{
		fill_circ(a, parse_float(strs[1]), parse_float(strs[2]), parse_float(strs[3]), strs[4][0]);
	}
	else if (strs[0][0] == 'L')
	{
		line(a, parse_float(strs[1]), parse_float(strs[2]), parse_float(strs[3]), parse_float(strs[4]), strs[5][0]);
	}
}