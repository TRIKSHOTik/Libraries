#pragma once
#include "Number.h"
#ifndef LIBRARY_VECTOR_H
#define LIBRARY_VECTOR_H

#ifdef VECTOR_EXPORTS
    #define VECTOR_API __declspec(dllexport)
#else
    #define VECTOR_API __declspec(dllimport)
#endif

class VECTOR_API Vector {
private:
    Number x;
    Number y;
public:
    explicit Vector(Number x, Number y);

    Number toPolarCoordRho();
    Number toPolarCoordPhi();
    Vector operator+( Vector &other) const;

    Vector& operator+=( Vector &other);

    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
};

extern VECTOR_API const Vector NULL_VECTOR;
extern VECTOR_API const Vector UNIT_VECTOR;

#endif //LIBRARY_VECTOR_H