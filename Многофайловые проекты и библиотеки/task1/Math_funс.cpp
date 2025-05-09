#include "math_func.h"
#include <cmath>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        return 0; 
    }
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}