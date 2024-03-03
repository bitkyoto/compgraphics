#pragma once
#include <iostream>

class TComplex {

private:
    double real = 0, imaginary = 0;
public:

    TComplex();
    TComplex(int value);
    TComplex(double value);
    TComplex(double real_value, double imaginary_value);
    void setImaginary(double imaginary_value);
    void setReal(double real_value);

    friend std::istream& operator>> (std::istream& in, TComplex& num);
    friend std::ostream& operator<< (std::ostream& out,const TComplex& num);

    bool operator== (const TComplex& other);
    TComplex operator* (const TComplex& other);
    TComplex operator+ (const TComplex& other);
    TComplex operator- (const TComplex& other);
};
