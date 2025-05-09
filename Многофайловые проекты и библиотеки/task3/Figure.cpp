#include "Figure.h"

Figure::Figure(std::string name) : name(name) {}

void Figure::print_info() {
    std::cout << name << ":\n";
    print_sides();
    print_corn();
}

void Figure::print_sides() {}
void Figure::print_corn() {}