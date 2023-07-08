#pragma comment(lib, "libcurl.dll.a")
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string.h>
#include "histogram.h"
#include "curl/curl.h"

using namespace std;
int main(int argc, char* argv[]) {
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    Input data;
    string stroke = "black", addres;;
    if (argc > 1) {
        if (choice_color(argc, argv, stroke, addres))
            data = download(addres);
        else return 0;
    }
    else {
        data = read_input(cin, true);
    }
    auto bins = make_histogram(data);
    show_histogram_svg(bins, data.bin_count,stroke);
}