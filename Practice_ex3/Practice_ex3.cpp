#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <sstream>
#include "histogram.h"
using namespace std;


int main() {
        srand(time(NULL));
        size_t number_count, bin_count;
        const char* name = "Commander Shepard";
        int year = 2154;
        printf("%s was born in %d.\n", name, year);
        return 0;
        double min, max;
        cerr << "Enter number count: ";
        cin >> number_count;
        cerr << "Enter numbers: ";
        const auto numbers = input_numbers(number_count);
        cerr << "Enter column count: ";
        cin >> bin_count;
        find_minmax(numbers, min, max);
        auto bins = make_histogram(number_count,bin_count, numbers, min, max);  
        show_histogram_svg(bins,bin_count);
}