#include "mini_paint.h"

int parse_int(string str)
{
	int res = 0;
	int n = 1;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		res += (str[i] - '0') * n;
		n *= 10;
	}
	return res;
}

int dot_ind(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
			return i;
	}
	return -1;
}

float parse_float(string str)
{
	float res = 0;
	if (dot_ind(str) == -1)
	{
		int n = 1;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			res += (str[i] - '0') * n;
			n *= 10;
		}
	}
	else
	{
		int i = dot_ind(str) - 1;
		float n = 1;
		while (i >= 0)
		{
			res += (str[i] - '0') * n;
			n *= 10;
			i--;
		}
		i = dot_ind(str) + 1;
		n = 0.1f;
		while (i < str.size())
		{
			res += (str[i] - '0') * n;
			n /= 10;
			i++;
		}
	}
	return res;
}