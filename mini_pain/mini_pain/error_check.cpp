#include "mini_paint.h"

bool correct_line(string line, bool first_line)
{
	vector <string> strs = strs_in_line(line);
	if (first_line)
	{
		if (strs.size() != 3)
			return false;
		if (!correct_int(strs[0]) || !correct_int(strs[1]) || !correct_char(strs[2]))
			return false;
	}
	else
	{
		if (!(strs[0] == "r" || strs[0] == "R" ||
			strs[0] == "c" || strs[0] == "C" ||
			strs[0] == "L"))
			return false;
		if ((strs[0] == "r" && strs.size() != 6) || (strs[0] == "R" && strs.size() != 6) ||
			(strs[0] == "c" && strs.size() != 5) || (strs[0] == "C" && strs.size() != 5) ||
			(strs[0] == "L" && strs.size() != 6))
			return false;
		if ((strs[0] == "r" && (!correct_float(strs[1]) || !correct_float(strs[2]) || !correct_float(strs[3]) ||
			!correct_float(strs[4]) || !correct_char(strs[5]))))
			return false;
		if ((strs[0] == "R" && (!correct_float(strs[1]) || !correct_float(strs[2]) || !correct_float(strs[3]) ||
			!correct_float(strs[4]) || !correct_char(strs[5]))))
			return false;
		if ((strs[0] == "c" && (!correct_float(strs[1]) || !correct_float(strs[2]) ||
			!correct_float(strs[3]) || !correct_char(strs[4]))))
			return false;
		if ((strs[0] == "C" && (!correct_float(strs[1]) || !correct_float(strs[2]) ||
			!correct_float(strs[3]) || !correct_char(strs[4]))))
			return false;
		if ((strs[0] == "L" && (!correct_float(strs[1]) || !correct_float(strs[2]) || !correct_float(strs[3]) ||
			!correct_float(strs[4]) || !correct_char(strs[5]))))
			return false;
	}
	return true;
}

bool correct_file(char* path)
{
	string str;
	ifstream in(path);
	bool first = true;
	while (getline(in, str))
	{
		vector <string> strs = strs_in_line(str);
		if (strs.size() != 0)
		{
			if (!correct_line(str, first))
				return false;
			if (first)
				first = false;
		}
	}
	in.close();
	return true;
}

string str_from_chars(char* argv)
{
	string str = "";
	for (int i = 0; argv[i] != '\0'; i++)
	{
		str += argv[i];
	}
	return str;
}

int errors(int argc, char* argv[])
{
	if (argc > 2)
	{
		if (str_from_chars(argv[2]) != "--save")
			return 1;
	}
	if (argc == 1)
	{
		return 2;
	}
	string str = str_from_chars(argv[1]);
	string name = "";
	for (int i = str.size() - 1; i >= 0 && name != "noitarepo"; i--)
	{
		if (str[i] == '.')
			name = "";
		else
			name += str[i];
	}
	if (name != "noitarepo") // name must be "operation"
	{
		return 2;
	}
	if (str[str.size() - 3] != '.' ||
		str[str.size() - 2] != 'i' ||
		str[str.size() - 1] != 't') // extention must be ".it"
	{
		return 4;
	}
	ifstream test(argv[1]);
	if (!test.is_open())
	{
		return 3;
	}
	test.close();
	if (!correct_file(argv[1]))
	{
		return 5;
	}
	return 0;
}

void error_log(int argc, char* argv[])
{
	int n = errors(argc, argv);
	switch (n)
	{
	case 0:
		set_color(7, 0); // set default color
		start(argv[1], argc - 1);
		break;
	case 1:
		set_color(4, 0); // set red color
		cout << "Error: a lot of arguments\n";
		break;
	case 2:
		set_color(4, 0); // set red color
		cout << "Error: name file\n";
		break;
	case 3:
		set_color(4, 0); // set red color
		cout << "Error: Operation file corrupted\n";
		break;
	case 4:
		set_color(4, 0); // set red color
		cout << "Error: Operation file has not correct extension\n";
		break;
	case 5:
		set_color(4, 0); // set red color
		cout << "Error: Operation file has not correct command(s)\n";
		break;
	}
	set_color(7, 0); // set default color
}