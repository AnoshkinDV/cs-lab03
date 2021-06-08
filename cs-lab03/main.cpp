#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <windows.h>

using namespace std;


int main() {
    DWORD info = GetVersion();
    DWORD mask = 0b00000000'00000000'11111111'11111111;
    DWORD version = info & mask;
    printf("Windows version is %08x\n", version);
    return 0;
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;

    const auto bins = make_histogram(numbers, bin_count);
    show_histogram_svg(bins);
    DWORD WINAPI GetVersion(void);
    printf("Windows (decimal) version is %u.\n", GetVersion());
    printf("WINDOWS (16x) version is %x. \n",GetVersion());
    return 0;
}
