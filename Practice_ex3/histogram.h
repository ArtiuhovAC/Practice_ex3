#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;
struct Input {
    vector<double> numbers;
    size_t bin_count;
};
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(Input &data,const double& min,const double& max);
vector <double> input_numbers(istream& in,size_t count);
void svg_begin(double width, double height);
void svg_end();
void svg_rect(double x, double y, double width, double height, string stroke, string fill);
void svg_text(double left, double baseline, string text);
void show_histogram_svg(vector<size_t>& bins, const size_t& bin_count);
Input read_input(istream& in);