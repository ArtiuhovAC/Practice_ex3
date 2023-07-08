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
    string stroke = "black";
    if (argc > 1) {
        string addres;
        if ((argc > 2) && (argc < 4)) {
            cout << "Вводить в формате -stroke <цвет> <адрес> или <адрес> -stroke <цвет>";
            return 0;
        }
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-stroke")== 0) {
                i++;
                if (i < argc)
                    stroke = argv[i];
                else {
                    cout << "Вводить в формате -stroke <цвет> <адрес> или <адрес> -stroke <цвет>";
                    return 0;
                }
            }
            else {
                addres = argv[i];
            }
        }
        data = download(addres);
    }
    else {
        data = read_input(cin, true);
    }
    auto bins = make_histogram(data);
    show_histogram_svg(bins, data.bin_count,stroke);
}