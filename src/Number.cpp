#include "../include/Number.h"

#include <iostream>

Number::Number(double number) {this->number = number;}

Number Number::operator+(const Number &other) {
    this->number = this->number + other.number;
    return *this;
}

Number Number::operator-(const Number &other) {
    this->number = this->number - other.number;
    return *this;
}

Number Number::operator*(const Number &other) {
    this->number = this->number * other.number;
    return *this;
}

Number Number::operator/(const Number &other) {
    this->number = this->number / other.number;
    return *this;
}

Number &Number::operator+=(const Number &other) {
    this->number = this->number + other.number;
    return *this;
}

Number &Number::operator-=(const Number &other) {
    this->number = this->number - other.number;
    return *this;
}

Number &Number::operator*=(const Number &other) {
    this->number = this->number * other.number;
    return *this;
}

Number &Number::operator/=(const Number &other) {
    this->number = this->number / other.number;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Number& num) {
    os << num.number;
    return os;
}

double Number::getNumber() const {
    return this->number;
}

const Number ZERO(0.0);
const Number ONE(1.0);

Number createNumber(double number) {
    return Number(number);
}