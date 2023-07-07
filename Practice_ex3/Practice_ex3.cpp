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
        Input data;
        double min, max;
        data = read_input(cin);
        find_minmax(data.numbers, min, max);
        auto bins = make_histogram(data, min, max);  
        show_histogram_svg(bins,data.bin_count);
}