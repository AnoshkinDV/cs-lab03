#include <iostream>
#include <vector>
#include "histogram.h"
using namespace std;
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
