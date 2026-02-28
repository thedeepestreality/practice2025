#include "complex.h"

Complex& Complex::operator+=(const Complex& rhs){
    re_ += rhs.re_;
    im_ += rhs.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs){
    *this = Complex(
        re_*rhs.re_ - im_*rhs.im_,
        re_*rhs.im_ + im_*rhs.re_
    );
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs){
    Complex result = lhs;
    result += rhs;
    return result;
}

Complex operator*(const Complex& lhs, const Complex& rhs){
    Complex result = lhs;
    result *= rhs;
    return result;
}

bool operator==(const Complex& lhs, const Complex& rhs){
    return (lhs.getRe() == rhs.getRe()) && (lhs.getIm() == rhs.getIm());
}

bool operator>(const Complex& lhs, const Complex& rhs){
    return lhs.getRe() > rhs.getRe();
}

bool operator!=(const Complex& lhs, const Complex& rhs){
    return !(lhs == rhs);
}

bool operator<(const Complex& lhs, const Complex& rhs){
     return !(lhs > rhs) && !(lhs == rhs);
}

bool operator>=(const Complex& lhs, const Complex& rhs){
    return (lhs > rhs) || (lhs == rhs);
}

bool operator<=(const Complex& lhs, const Complex& rhs){
    return !(lhs > rhs);
}

// Complex& operator+=(Complex& lhs, const Complex rhs){
//     // lhs.re_ += rhs.re_;
//     // lhs.im_ += rhs.im_;
//     lhs = Complex(lhs.getRe() + rhs.getRe(), lhs.getIm() + rhs.getIm());
//     return lhs;
// }