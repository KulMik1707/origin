#include "Triangle.h"

Triangle::Triangle(double a, double b, double c, double A, double B, double C)
    : Figure("�����������"), a(a), b(b), c(c), A(A), B(B), C(C) {}

void Triangle::print_sides() {
    std::cout << "�������: a=" << a << " b=" << b << " c=" << c << "\n";
}

void Triangle::print_corn() {
    std::cout << "����: A=" << A << " B=" << B << " C=" << C << "\n";
}