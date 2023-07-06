#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <sstream>
using namespace std;
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(const size_t& number_count,const size_t& bin_count, const vector<double>& numbers,const double& min,const double& max);