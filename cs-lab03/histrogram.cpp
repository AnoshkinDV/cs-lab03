#include <iostream>
#include <vector>
#include "histogram.h"
using namespace std;
const vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

void find_minmax(const vector<double>& numbers, double& max, double& min) {
    if (numbers.size()) {
        max = numbers[0];
        min = numbers[0];
        if (numbers.size()) {
            for (double x : numbers) {
                if (x > max) {
                    max = x;
                }
                if (x < min) {
                    min = x;
                }
            }
        }
    }
}

const vector<size_t> make_histogram(const vector<double>& numbers, size_t& bin_count) {

    vector<size_t> bins(bin_count);
    double min, max;
    find_minmax(numbers, min, max);

    if (min == max) {
        for (double number : numbers) {
            bins[0]++;
        }
        return bins;
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
