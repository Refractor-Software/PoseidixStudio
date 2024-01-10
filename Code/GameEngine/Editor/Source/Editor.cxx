#include <commonlib/math/flt16.h>

#include <iostream>

int main(int, char**)
{
    commonlib::f16 flt16;
    flt16.sign = 0;
    flt16.exponent = 12;
    flt16.mantissa = 1023;
    std::cout << "16-bit float: " << commonlib::f16_to_f32(flt16) << "\n";
    return 0;
}