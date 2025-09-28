#include "../include/Vector.h"
#include <cmath>
Vector::Vector(Number x, Number y) : x(x), y(y) {}

Number Vector::toPolarCoordRho() {
    double sqr = std::sqrt(x.getNumber() * x.getNumber() + y.getNumber() * y.getNumber());
    return Number(sqr);
}

Number Vector::toPolarCoordPhi() {
    double phi = std::atan2(y.getNumber(), x.getNumber());
    return Number(phi);
}

Vector Vector::operator+( Vector &other) const {
    Number a = other.x + this->x;
    Number b = other.y + this->y;
    return Vector(a, b);
}

Vector& Vector::operator+=(Vector &other) {
    this->x = other.x + this->x;
    this->y = other.y + this->y;
    return *this;
}

VECTOR_API const Vector NULL_VECTOR(Number(0.0),Number(0.0));
VECTOR_API const Vector UNIT_VECTOR(Number(1.0),Number(1.0));

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    return  os << "(" << vec.x << ", " << vec.y << ")";;
}
