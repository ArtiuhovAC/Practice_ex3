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
int main() {
        srand(time(NULL));
        curl_global_init(CURL_GLOBAL_ALL);
        Input data;
        data = read_input(cin,true);
        auto bins = make_histogram(data);  
        show_histogram_svg(bins,data.bin_count);
}