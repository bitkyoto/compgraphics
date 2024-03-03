#include "TComplex.h"

TComplex::TComplex() {
    this->real = 0;
    this->imaginary = 0;
}

TComplex::TComplex(int value) {
    this->real = value;
    this->imaginary = 0;
}

TComplex::TComplex(double value) {
    this->real = value;
    this->imaginary = 0;
}

TComplex::TComplex(double real_value, double imaginary_value)
{
    this->real = real_value;
    this->imaginary = imaginary_value;
}

void TComplex::setImaginary(double imaginary_value) {
    this->imaginary = imaginary_value;
}

void TComplex::setReal(double real_value) {
    this->real = real_value;
}


std::ostream& operator<< (std::ostream& out, const TComplex& num) {
    out << num.real << " + " << num.imaginary << "i";
    return out;
}

std::istream& operator>>(std::istream& in, TComplex& num) {
    double value;
    in >> value;
    num.setReal(value);
    in >> value;
    num.setImaginary(value);
    return in;
}

bool TComplex::operator== (const TComplex& other) {
    if (this->real == other.real && this->imaginary == other.imaginary) return true;
    else return false;
}
TComplex TComplex::operator*(const TComplex& other) {
    TComplex res;
    res.real = real * other.real - imaginary * other.imaginary;
    res.imaginary = real * other.imaginary + imaginary * other.real;
    return res;
}


TComplex TComplex::operator+(const TComplex& other) {
    TComplex res;
    res.real = real + other.real;
    res.imaginary = imaginary + other.imaginary;
    return res;
}

TComplex TComplex::operator-(const TComplex& other) {
    TComplex res;
    res.real = real - other.real;
    res.imaginary = imaginary - other.imaginary;
    return res;
}
