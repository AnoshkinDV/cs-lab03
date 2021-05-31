#pragma once
#include <vector>
using namespace std;
struct Input {
    vector<double> numbers;
    size_t bin_count;

};
const vector<double> input_numbers(size_t count);
const vector<size_t> make_histogram(const Input data);
void find_minmax(const vector<double>& numbers, double& max, double& min);
Input read_input(istream& in, bool prompt);





