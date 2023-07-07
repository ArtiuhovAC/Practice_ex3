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
        data = read_input(cin,true);
        auto bins = make_histogram(data);  
        show_histogram_svg(bins,data.bin_count);
}