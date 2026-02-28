#ifndef COMPLEX_POLY_H
#define COMPLEX_POLY_H

#include "complex.h"

class ComplexPoly{
private:
    Complex* coeffs_;
    size_t coeff_length_;
public:
    // Default constructor + parameterized
    ComplexPoly(Complex a0 = Complex(0.0, 0.0)) :
        coeffs_(new Complex[1]),
        coeff_length_(1)
    {
        coeffs_[0] = a0;
    }

    // Parameterized constructor
    ComplexPoly(const Complex* coeffs, size_t len) :
        coeffs_(new Complex[len]),
        coeff_length_(len)
    {
        for (size_t idx = 0; idx < len; ++idx)
            coeffs_[idx] = coeffs[idx];
    }

    // Copy constructor
    ComplexPoly(const ComplexPoly& rhs) : ComplexPoly(rhs.coeffs_, rhs.coeff_length_)
    {}

    // Destructor
    ~ComplexPoly(){
        delete[] coeffs_;
        coeffs_ = nullptr;
    }

    // Assignment operator
    ComplexPoly& operator=(const ComplexPoly& rhs){
        if (this == &rhs)
            return *this;
        delete[] coeffs_;
        coeff_length_ = rhs.coeff_length_;
        for (size_t idx = 0; idx < coeff_length_; ++idx)
            coeffs_[idx] = rhs.coeffs_[idx];
        return *this;
    }

    // For non-const objects
    Complex& operator[](size_t idx) {
        return coeffs_[idx];
    };

    // For consts: prevent from changing coeffs
    const Complex& operator[](size_t idx) const {
        return coeffs_[idx];
    };

    Complex operator()(Complex x) const{
        Complex sum(0.0, 0.0);
        Complex deg(1.0, 0.0);
        for (size_t idx = 0; idx < coeff_length_; ++idx){
            sum += coeffs_[idx] * deg;
            deg *= x;
        }
        return sum;
    }
};

#endif
