#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string.h>
#include <sstream>
#include <fstream>
#include "curl/curl.h"

using namespace std;
struct Input {
    vector<double> numbers;
    size_t bin_count;
};
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(Input &data);
vector <double> input_numbers(istream& in,size_t count);
void svg_begin(double width, double height);
void svg_end();
void svg_rect(double x, double y, double width, double height, string stroke, string fill);
void svg_text(double left, double baseline, string text);
void show_histogram_svg(vector<size_t>& bins, const size_t& bin_count,string stroke);
Input read_input(istream& in, bool prompt);
Input download(const string& address);
size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx);
bool choice_color(int argc, char* argv[], string& stroke, string& addres);