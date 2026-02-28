#include <iostream>
#include "complex.h"
#include "complex_poly.h"

int main(){
    Complex c;
    Complex x(1.0, 2.0);
    c += x;
    std::cout << c.getRe() << ' ' << c.getIm() << '\n';
    c *= c;
    std::cout << c.getRe() << ' ' << c.getIm() << '\n';

    // c += 1.0; // c += Complex(1.0);
    c += Complex(1.0);
    c += static_cast<Complex>(1.0);

    // If we forgot to use const ref
    // c -= x;
    // const Complex const_val;
    // c -= const_val; // 1 Compile-time error
    // c -= Complex(3.0, 2.0);

    ComplexPoly deg0(c);
    Complex coeffs[3] = {Complex(1.0), Complex(1.0), Complex(1.0)};
    ComplexPoly deg2(coeffs, 3);
    deg2[1] = Complex(2.0);
    // for (size_t idx = 0; idx < 3; ++idx)
    //     std::cout << deg2[idx] << ' ';
    // std::cout << '\n';

    Complex result = deg2(Complex(1.0, 1.0));
    std::cout << "result = " << result << '\n';

    return 0;
}