#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <windows.h>
using namespace std;
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(const size_t& number_count,const size_t& bin_count, const vector<double>& numbers,const double& min,const double& max);
vector <double> input_numbers(size_t count);
void svg_begin(double width, double height);
void svg_end();
void svg_rect(double x, double y, double width, double height, string stroke, string fill);
void svg_text(double left, double baseline, string text);
void show_histogram_svg(vector<size_t>& bins, const size_t& bin_count);
string make_info_text();