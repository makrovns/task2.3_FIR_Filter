#include "FIR_coef_library.hpp"

namespace 
{
    long double sinc(int index, long double Frequency_cut)
    {
        long double Impulse_response_ideal = 0;

        if (index == 0)
            Impulse_response_ideal = 2 * Frequency_cut;
        else
            Impulse_response_ideal = 2 * sinl(index * Frequency_cut) / (index);

        return Impulse_response_ideal;
    }
}

long double myFIR::Blackman_window(int filter_order, int index)
{
    long double W = 0.42 - 0.5 * cosl(2 * PI * index / (filter_order - 1)) + 0.08 * cosl(4 * PI * index / (filter_order - 1));

    return W;
}

long double myFIR::Hanning_window(int filter_order, int index)
{
    long double W = 0.5 - 0.5 * cosl(2 * PI * index / (filter_order - 1));

    return W;
}

long double myFIR::Hamming_window(int filter_order, int index)
{
    long double W = 0.54 - 0.46 * cosl(2 * PI * index / (filter_order - 1));

    return W;
}

std::vector<long double> myFIR::coef_fir_filter(long double Frequency_cut, int filter_order, std::function<long double(int, int)> window)
{
    if(Frequency_cut == 0.0 || filter_order <= 2)
    {
        throw std::invalid_argument("invalid input");
    }

    std::vector<long double> Impulse_response_ideal(filter_order), Window_coef(filter_order), Impulse_response_real(filter_order);
    long double coef_normaliz = 0;

    for(int index = 0; index != filter_order; ++index)
    {
        Impulse_response_ideal[index] = sinc( index - (filter_order / 2), Frequency_cut);

        Window_coef[index] = window(filter_order, index);
        Impulse_response_real[index] = Impulse_response_ideal[index] * Window_coef[index];

        coef_normaliz += Impulse_response_real[index];
    }

    for_each(Impulse_response_real.begin(), Impulse_response_real.end(), [&coef_normaliz](long double& sample)
        {
            sample /= coef_normaliz;
        });

    return Impulse_response_real;
}