#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <sstream>
using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max) {
    if (numbers.size() != 0) {
        min = numbers[0];
        max = numbers[0];
        for (double number : numbers) {
            if (number < min) {
                min = number;
            }
            if (number > max) {
                max = number;
            }
        }
    }
    else { min = 0; max = 0; }
}
vector<size_t> make_histogram(const size_t& number_count, const size_t& bin_count, const vector<double>& numbers,const double& min,const double& max) {
    vector<size_t> bins(bin_count);
    if (max == min) {
        bins[0] = number_count;
    }
    else {
        for (double number : numbers) {
            size_t bin = (size_t)((number - min) / (max - min) * bin_count);
            if (bin == bin_count) {
                bin--;
            }
            bins[bin]++;
        }
        return bins;
    }
}