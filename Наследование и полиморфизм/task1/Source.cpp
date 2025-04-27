#include <iostream>
#include <string>

class Figure {
protected:
    int sides_count;
    std::string name;

    
    Figure(int sides,  std::string set_name)
        : sides_count(sides), name(set_name) {}

public:
    
    Figure() : Figure(0, "Фигура") {}

    
    int get_sides_count()  {
        return sides_count;
    }

    
    std::string get_name()  {
        return name;
    }
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3, "Треугольник") {}
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};

int main() {
    setlocale(LC_ALL, "Rus");
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    std::cout << "Количество сторон:\n";
    std::cout << figure.get_name() << ": " << figure.get_sides_count() << "\n";
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << "\n";
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << "\n";

    return 0;
}