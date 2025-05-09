#include <iostream>
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

int main() {
    setlocale(LC_ALL, "Rus");
    Figure* figures[9];

    figures[0] = new Triangle(10, 20, 30, 50, 60, 70);
    figures[1] = new RightTriangle(10, 20, 30, 50, 40);
    figures[2] = new IsoscelesTriangle(10, 20, 50, 60);
    figures[3] = new EquilateralTriangle(30);
    figures[4] = new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    figures[5] = new Rectangle(10, 20);
    figures[6] = new Square(20);
    figures[7] = new Parallelogram(20, 30, 30, 40);
    figures[8] = new Rhombus(30, 30, 40);

    for (int i = 0; i < 9; i++) {
        figures[i]->print_info();
        std::cout << "\n";
        delete figures[i];
    }

    return 0;
}