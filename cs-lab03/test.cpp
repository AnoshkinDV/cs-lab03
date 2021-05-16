#include <cassert>
#include <iostream>
#include "histogram.h"

using namespace std;

void test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({ 1, 2, 3 }, max, min);
    assert(min == 1);
    assert(max == 3);
}
void test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({ -1, -2, -3 }, max, min);
    assert(min == -3);
    assert(max == -1);
}
void test_constant() {
    double min = 0;
    double max = 0;
    find_minmax({ 99,99,99 }, max, min);
    assert(min == 99);
    assert(max == 99);
}
void test_onenumber() {
    double min = 0;
    double max = 0;
    find_minmax({ 1 }, max, min);
    assert(min == 1);
    assert(max == 1);
}
void test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, max, min);
    assert(min == 0);
    assert(max == 0);
}

int main() {

    // Тесты для функции find_minmax
    test_positive();
    test_negative();
    test_constant();
    test_onenumber();
    test_empty();
    return 0;
}
