#pragma comment(lib, "libcurl.dll.a")
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "histogram.h"
#include "curl/curl.h"

using namespace std;
int main(int argc, char* argv[]) {
    srand(time(NULL));
    Input data;
    if (argc > 1) {
        data = download(argv[1]);
    }
    else {
        data = read_input(cin, true);
    }
    
    auto bins = make_histogram(data);
    show_histogram_svg(bins, data.bin_count);
}