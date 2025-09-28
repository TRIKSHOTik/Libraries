#pragma once
#include <ostream>
#ifndef LIBRARY_NUMBER_H
#define LIBRARY_NUMBER_H

class Number {
private:
    double number;
public:
    explicit Number(double number);

    Number operator+(const Number &other);
    Number operator-(const Number &other);
    Number operator*(const Number &other);
    Number operator/(const Number &other);

    Number& operator+=(const Number &other);
    Number& operator-=(const Number &other);
    Number& operator*=(const Number &other);
    Number& operator/=(const Number &other);

    double getNumber() const;

    friend std::ostream& operator<<(std::ostream& os, const Number& num);
};

extern const Number ZERO;
extern const Number ONE;

Number createNumber(double number);

#endif // LIBRARY_NUMBER_H