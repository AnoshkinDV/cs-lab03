#pragma once
#include <vector>
using namespace std;
const vector<double> input_numbers(size_t count);
const vector<size_t> make_histogram(const vector<double>& numbers, size_t& bin_count);
void find_minmax(const vector<double>& numbers, double& max, double& min);





