#include "mini_paint.h"

vector <string> strs_in_line(string line)
{
	vector <string> res;
	line += " ";
	string str = "";
	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ' ')
		{
			if (str != "")
			{
				res.push_back(str);
				str = "";
			}
		}
		else
			str += line[i];
	}
	return res;
}

bool correct_int(string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return false;
	}
	return true;
}

bool correct_float(string str)
{
	int dots = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '.')
		{
			if (i > 0)
				dots++;
			else
				return false;
		}
		if (dots > 1)
			return false;
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return false;
	}
	return true;
}

bool correct_char(string str)
{
	if (str.size() > 1)
		return false;
	if (!(str[0] >= 0 && str[0] <= 255))
		return false;
	return true;
}