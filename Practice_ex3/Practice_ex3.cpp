#include <iostream>
#include <vector>
using namespace std;
// сделать контроль ширины
const size_t SCREEN_WIDTH = 80;
const size_t IMAGE_HEIGHT = 20;
vector <double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}
void find_minmax(const vector<double> &numbers, double& min, double& max) {
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
vector<size_t> make_histogram(size_t &number_count,size_t &bin_count,const vector<double>& numbers, double& min, double& max) {
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
void show_histogram_text(vector<size_t> &bins) {
    size_t max_count = 0;
    for (size_t count : bins) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > IMAGE_HEIGHT;
    for (size_t i = 0; i < bins.size();i++)
    if (scaling_needed) {
        const double scaling_factor = (double)IMAGE_HEIGHT / max_count;
        if (bins[i] == max_count)
            bins[i] = IMAGE_HEIGHT;
        else
            bins[i] = (size_t)(bins[i] * scaling_factor);
    }
    size_t height;
    if (scaling_needed) {
        height = IMAGE_HEIGHT;
    }
    else height = max_count;
    for (size_t i = height; i > 0; i--) {
        for (size_t j = 0; j < bins.size(); j++) {
            if (bins[j] > 9) {
                cout << " ";
            }
            if (bins[j] >= i) {
                cout << "*";
            }
            else {
                cout << " ";
            }
            cout << " ";
        }
        cout << '\n';
    }
    for (size_t i = 0; i < bins.size(); i++) {
        if (bins[i] > 9)
            cout << "__";
        else
            cout << "_";
        cout << " ";
    }
    cout << '\n';
    for (size_t i = 0; i < bins.size(); i++)
        cout << bins[i]<<" ";
    cout << '\n';
}
int main() {
    
    char decision;
    do {
        size_t number_count, bin_count;
        double min, max;
        cerr << "Enter number count: ";
        cin >> number_count;
        cerr << "Enter numbers: ";
        const auto numbers = input_numbers(number_count);
        cerr << "Enter column count: ";
        cin >> bin_count;
        find_minmax(numbers, min, max);
        auto bins = make_histogram(number_count,bin_count, numbers, min, max);
        show_histogram_text(bins);
        cerr << "Enter '1' if you arent satisfied, else enter other symbols: ";
        cin >> decision;
        if (decision == '1')
            cout << "\n";

    } while (decision == '1');
}