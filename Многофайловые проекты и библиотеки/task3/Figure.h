#pragma once
#include <string>
#include <iostream>

class Figure {
protected:
    int sides_count;
    std::string name;

public:
    Figure(std::string name);
    virtual ~Figure() = default;

    virtual void print_info();
    virtual void print_sides();
    virtual void print_corn();
};
