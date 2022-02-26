#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <Windows.h>

using namespace std;

//additional
void swap(int & a, int & b);
bool correct_int(string str);
bool correct_float(string str);
bool correct_char(string str);
vector <string> strs_in_line(string line);
// parsing
int parse_int(string str);
float parse_float(string str);
// errors
bool correct_line(string line, bool first_line);
bool correct_file(char* path);
int errors(int argc, char* argv[]);
void error_log(int argc, char* argv[]);
// drawing
void print_vec(vector <vector <char>> & a, bool print);
void background(vector <vector <char>> & a, int width, int height, char ch);
void rect(vector <vector <char>> & a, float x, float y, float width, float height, char ch);
void fill_rect(vector <vector <char>> & a, float x, float y, float width, float height, char ch);
void circ(vector <vector <char>> & a, float x, float y, float radius, char ch);
void fill_circ(vector <vector <char>> & a, float x, float y, float radius, char ch);
void line(vector <vector <char>> & a, float x1, float y1, float x2, float y2, char ch);
void set_color(int text, int background);
// start
void start(char* path, int argc);
void set_function(vector <vector <char>> & a, vector <string> & strs, char bg);