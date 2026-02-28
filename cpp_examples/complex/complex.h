#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex{
private:
    double re_;
    double im_;
public:
    explicit Complex(double re = 0.0, double im = 0.0) : re_(re), im_(im)
    {}
    double getRe() const{
        return re_;
    }
    double getIm() const{
        return im_;
    }

    void print() const;

    Complex& operator+=(const Complex& rhs);
    Complex& operator*=(const Complex& rhs);

    Complex& operator-=(Complex& rhs){
        return *this;
    }

    Complex& operator++(){
        ++re_;
        return *this;
    }

    Complex operator++(int){
        Complex oldval = *this;
        ++re_;
        return oldval;
    }

    // friend std::ostream& operator<<(std::ostream& out, Complex const& val);
    friend std::ostream& operator<<(std::ostream& out, const Complex& val);
};

inline void Complex::print() const {
    std::cout << re_ << ',' << im_ << '\n';
}

inline std::ostream& operator<<(std::ostream& out, const Complex& val){
    out << val.re_ << ',' << val.im_ << '\n';
    return out;
}

// Complex& operator+=(Complex& lhs, const Complex rhs);
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);
bool operator>(const Complex& lhs, const Complex& rhs);
bool operator<(const Complex& lhs, const Complex& rhs);
bool operator>=(const Complex& lhs, const Complex& rhs);
bool operator<=(const Complex& lhs, const Complex& rhs);

#endif