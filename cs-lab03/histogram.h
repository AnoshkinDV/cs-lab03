#pragma once
#include <vector>
using namespace std;
struct Input {
    vector<double> numbers;
    size_t bin_count;

};
vector<double> input_numbers(size_t count);
const vector<size_t> make_histogram(Input data);
void find_minmax(const vector<double> &numbers, double& max, double& min);
Input read_input(istream& in, bool prompt);
void show_histogram_text(const vector<size_t>& bins);
