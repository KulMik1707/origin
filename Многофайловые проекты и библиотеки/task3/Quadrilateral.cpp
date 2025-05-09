#include "Quadrilateral.h"

Quadrilateral::Quadrilateral(double a, double b, double c, double d,
    double A, double B, double C, double D)
    : Figure("Четырёхугольник"), a(a), b(b), c(c), d(d),
    A(A), B(B), C(C), D(D) {}

void Quadrilateral::print_sides() {
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
}

void Quadrilateral::print_corn() {
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
}