#include "FIR_coef_library.hpp"
#include <gtest/gtest.h>

TEST(FIR_coef_test, blackman_test_even_coef)
{
    auto out_even = myFIR::coef_fir_filter(0.0175, 12, myFIR::Blackman_window);
    size_t size = out_even.size();

    //Odds were calculated in matlab:
    std::vector<long double> out_matlab_even = {0, 0.006996724233786, 0.034451313421130, 0.089553015882586, 0.159383342792759, 0.209615603669739,
    0.209615603669739, 0.159383342792759, 0.089553015882586, 0.034451313421130, 0.006996724233786, 0};
    
    for(size_t i = 0; i != size; ++i)
    {
        ASSERT_NEAR(out_even[i], out_matlab_even[i], 1e-3);
    }
}

TEST(FIR_coef_test, blackman_test_odd_coef)
{
    auto out_odd  = myFIR::coef_fir_filter(0.00875, 19, myFIR::Blackman_window);
    size_t size = out_odd.size();

    //Odds were calculated in matlab:
    std::vector<long double> out_matlab_odd = {0, 0.001502256427839, 0.006694282228181, 0.017135679594556, 0.034055017214814, 0.057040554132221,
    0.083325317371076, 0.108115104303080, 0.125925567717750, 0.132412442020966, 0.125925567717750, 0.108115104303080, 0.083325317371076, 
    0.057040554132221, 0.034055017214814, 0.017135679594556, 0.006694282228181, 0.001502256427839, 0};

    for(size_t i = 0; i != size; ++i)
    {
        ASSERT_NEAR(out_odd[i], out_matlab_odd[i], 1e-3);
    }
}

TEST(FIR_coef_test, hanning_test_even_coef)
{
    auto out_even = myFIR::coef_fir_filter(0.0075, 16, myFIR::Hanning_window);
    size_t size = out_even.size();

    //Odds were calculated in matlab:
    std::vector<long double> out_matlab_even = {0, 0.005745035947469, 0.022011233880315, 0.046010544958608, 0.073601826174593, 0.100010160644916, 
    0.120658042339699, 0.131963156054399, 0.131963156054399, 0.120658042339699, 0.100010160644916, 0.073601826174593, 0.046010544958608, 
    0.022011233880315, 0.005745035947469, 0};
    
    for(size_t i = 0; i != size; ++i)
    {
        ASSERT_NEAR(out_even[i], out_matlab_even[i], 1e-3);
    }
}

TEST(FIR_coef_test, hanning_test_odd_coef)
{
    auto out_odd = myFIR::coef_fir_filter(0.0138, 11, myFIR::Hanning_window);
    size_t size = out_odd.size();

    //Odds were calculated in matlab:
    std::vector<long double> out_matlab_odd = {0, 0.019075798926247, 0.069061625806737, 0.130892778278641, 0.180939594062857, 0.200060405851036, 
    0.180939594062857, 0.130892778278641, 0.069061625806737, 0.019075798926247, 0};

    for(size_t i = 0; i != size; ++i)
    {
        ASSERT_NEAR(out_odd[i], out_matlab_odd[i], 1e-3);
    }
}

TEST(FIR_coef_test, hamming_test_even_coef)
{
    auto out_even = myFIR::coef_fir_filter(0.0195, 18, myFIR::Hamming_window);
    size_t size = out_even.size();

    //Odds were calculated in matlab:
    std::vector<long double> out_matlab_even = {0.008317025791088, 0.011664454220063, 0.021198152135132, 0.035762655029736, 0.053457982781050, 
    0.071903723447900, 0.088576908824221, 0.101174211990950, 0.107944885779860, 0.107944885779860, 0.101174211990950, 0.088576908824221, 
    0.071903723447900, 0.053457982781050, 0.035762655029736, 0.021198152135132, 0.011664454220063, 0.008317025791088};

    for(size_t i = 0; i != size; ++i)
    {
        ASSERT_NEAR(out_even[i], out_matlab_even[i], 1e-3);
    }
}

TEST(FIR_coef_test, hamming_test_odd_coef)
{
    auto out_odd = myFIR::coef_fir_filter(0.0054, 8, myFIR::Hamming_window);
    size_t size = out_odd.size();

    //Odds were calculated in matlab:
    std::vector<long double> out_matlab_odd = {0.020715398802703, 0.065581737427203, 0.166414013346240, 0.247288850423855, 0.247288850423855, 
    0.166414013346240, 0.065581737427203, 0.020715398802703};

    for(size_t i = 0; i != size; ++i)
    {
        ASSERT_NEAR(out_odd[i], out_matlab_odd[i], 1e-3);
    }
}

TEST(FIR_coef_test, test_for_invalid_fc)
{
    try
    {
        auto out = myFIR::coef_fir_filter(0, 4, myFIR::Hamming_window);
    }
    catch (const std::exception& ex)
    {
        ASSERT_EQ(std::string(ex.what()), "invalid input");
    }
}

TEST(FIR_coef_test, test_for_invalid_number_of_coef)
{
    try
    {
        auto out = myFIR::coef_fir_filter(0.0125, 2, myFIR::Hamming_window);
    }
    catch (const std::exception& ex)
    {
        ASSERT_EQ(std::string(ex.what()), "invalid input");
    }
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}