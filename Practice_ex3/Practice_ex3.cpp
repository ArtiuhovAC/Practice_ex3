#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "histogram.h"
using namespace std;
int main() {
        srand(time(NULL));
        size_t number_count, bin_count;
        double min, max;
        cerr << "Enter number count: ";
        cin >> number_count;
        cerr << "Enter numbers: ";
        const auto numbers = input_numbers(cin,number_count);
        cerr << "Enter column count: ";
        cin >> bin_count;
        find_minmax(numbers, min, max);
        auto bins = make_histogram(number_count,bin_count, numbers, min, max);  
        show_histogram_svg(bins,bin_count);
}