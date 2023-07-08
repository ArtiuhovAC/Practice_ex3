#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <windows.h>
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
vector<size_t> make_histogram(const size_t& number_count, const size_t& bin_count, const vector<double>& numbers, const double& min, const double& max) {
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
vector <double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}
void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
void svg_end() {
    cout << "</svg>\n";
}
void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
    cout << "<rect x='" << x << "' y ='" << y << "' width='" << width << "' height='" << height << "' stroke=' " << stroke << "' fill='" << fill
        << "'/>" << '\n';
}
void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << " </text>" << '\n';

}
void show_histogram_svg(vector<size_t>& bins, const size_t& bin_count) {
    const auto IMAGE_WIDTH = 810;
    const auto IMAGE_HEIGHT = 745;
    const auto IMAGE_HEIGHT2 = 730;
    const auto TEXT_SDVIG = 15;
    const auto TEXT_WIDTH = 50;
    const auto MASHTAB = 10;
    const auto RANDOM_COLOR = 3;
    const size_t MAX_ASTERISK = 73;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    size_t max_count = 0;
    size_t height;
    size_t x = 0, y;
    for (size_t count : bins) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;
    for (size_t i = 0; i < bins.size(); i++)
        if (scaling_needed) {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            if (bins[i] != max_count)
                bins[i] = (size_t)(bins[i] * scaling_factor);
        }
    for (size_t i = 0; i < bins.size(); i++)
    {
        if (bins[i] != max_count)
            bins[i] *= MASHTAB;
        else {
            if (scaling_needed) {
                bins[i] = IMAGE_HEIGHT2;
                height = IMAGE_HEIGHT2;
            }
            else {
                bins[i] *= MASHTAB;
                height = bins[i];

            }
        }
    }
    for (int i = 0; i < bin_count; i++) {
        string stroke = "#", fill = "#";
        for (int j = 0; j < RANDOM_COLOR; j++) {
            stringstream stream;
            stream << hex << rand() % 256;
            string result(stream.str());
            stroke += result;
            fill += result;
        }
        y = height - bins[i];
        svg_rect(x, y, TEXT_WIDTH, bins[i], stroke, fill);
        svg_text(x + TEXT_SDVIG, height + TEXT_SDVIG, to_string(bins[i] / MASHTAB));
        x += TEXT_WIDTH;
    }
    svg_end();
}
string make_info_text() {
    stringstream buffer;
    DWORD mask = 0x0000ffff;
    DWORD info = GetVersion();
    DWORD version = info & mask;
    DWORD platform = info >> 16;
    DWORD mask_major = 0x00ff;
    DWORD version_major = version & mask_major;
    DWORD version_minor = version >> 8;
    DWORD build = 0;
    if ((info & 0b10000000'00000000'0000000'00000000) == 0) {
        build = platform;
    }
    buffer << "Windows v" << version_major << "." << version_minor 
        << "(" << build << ")";
    return buffer.str();
}