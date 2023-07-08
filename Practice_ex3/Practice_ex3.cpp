﻿#pragma comment(lib, "libcurl.dll.a")
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
        
        if (argc > 1) {
            CURL* curl = curl_easy_init();
            if (curl) {
                CURLcode res;
                curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
                res = curl_easy_perform(curl);
                if (res != 0) {
                    cout << curl_easy_strerror(res);
                    exit(1);
                }
            }
            curl_easy_cleanup(curl);
            return 0;
        }
        curl_global_init(CURL_GLOBAL_ALL);
        Input data;
        data = read_input(cin,true);
        auto bins = make_histogram(data);  
        show_histogram_svg(bins,data.bin_count);
}