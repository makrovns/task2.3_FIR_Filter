#pragma once
#include <vector>
#include <cmath>
#include <functional>
#include <algorithm>
#include <iostream>

constexpr long double PI = 3.14159265;

namespace myFIR
{
    long double Blackman_window(int filter_order, int index);
    long double Hanning_window(int filter_order, int index);
    long double Hamming_window(int filter_order, int index);

    std::vector<long double> coef_fir_filter(long double Frequency_cut, int filter_order, std::function<long double(int, int)> window);
}