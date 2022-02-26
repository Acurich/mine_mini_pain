#include "mini_paint.h"

void start(char* path, int argc)
{
	vector <vector <char>> a;
	string str;
	ifstream in(path);
	vector <string> strs = strs_in_line(str);
	char bg = '.';
	bool first = true;
	while (getline(in, str))
	{
		vector <string> strs = strs_in_line(str);
		if (strs.size() != 0)
		{
			if (first)
			{
				int width = parse_int(strs[0]);
				int height = parse_int(strs[1]);
				char bg = strs[2][0];
				if (width > 300)
					width = 300;
				if (height > 300)
					height = 300;
				background(a, width, height, bg);
				first = false;
			}
			else
			{
				set_function(a, strs, bg);
			}
		}
	}
	bool print = argc == 2;
	print_vec(a, print);
	in.close();
}

int main(int argc, char* argv[])
{
	error_log(argc, argv);
	system("pause");
	return 0;
}