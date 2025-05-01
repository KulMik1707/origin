
#include <iostream>
#include <string>

class Figure {
protected:
    int sides_count;
    std::string name;

public:
    Figure(int setsSides_count, std::string name) : sides_count(setsSides_count), name(name) {}
    virtual ~Figure() = default;

    virtual void print_info() {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
        print_sides();
        print_corn();

    }

    virtual bool check() {
        return sides_count == 0;
    }

    virtual void print_sides() {}
    virtual void print_corn() {}

};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : Figure(3, "Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print_sides() override {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
    }

    void print_corn() override {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }

    bool check() override {
        return (A + B + C) == 180;
    }
  
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }
    bool check()  override {
        return Triangle::check() && C == 90;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }
    bool check() override {
        return Triangle::check() && a == c && A == C;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a)
        : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }
    bool check()  override {
        return Triangle::check() && a == b && b == c && A == 60 && B == 60 && C == 60;
    }
};

class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d,
        double A, double B, double C, double D)
        : Figure(4, "Четырёхугольник"), a(a), b(b), c(c), d(d),
        A(A), B(B), C(C), D(D) {}

    void print_sides()  override {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
    }

    void print_corn()  override {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }

    bool check() override {
        return (A + B + C + D) == 360;
    }
   
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }
    bool check()  override {
        return Quadrilateral::check() && a == c && b == d &&
            A == 90 && B == 90 && C == 90 && D == 90;
    }
};

class Square : public Rectangle {
public:
    Square(double a)
        : Rectangle(a, a) {
        name = "Квадрат";
    }
    bool check() override {
        return Rectangle::check() && a == b && b == c && c == d;
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }
    bool check() override {
        return Quadrilateral::check() && a == c && b == d && A == C && B == D;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double A, double B)
        : Parallelogram(a, a, A, B) {
        name = "Ромб";
    }
    bool check()  override {
        return Parallelogram::check() && a == b && b == c && c == d;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Figure* figures[11];

    figures[0] = new Figure(0, "Фигура");
    figures[1] = new Triangle(10, 20, 30, 50, 60, 70);
    figures[2] = new RightTriangle(10, 20, 30, 50, 60);
    figures[3] = new RightTriangle(10, 20, 30, 50, 40);
    figures[4] = new IsoscelesTriangle(10, 20, 50, 60);
    figures[5] = new EquilateralTriangle(30);
    figures[6] = new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    figures[7] = new Rectangle(10, 20);
    figures[8] = new Square(20);
    figures[9] = new Parallelogram(20, 30, 30, 40);
    figures[10] = new Rhombus(30, 30, 40);

    for (int i = 0; i < 11; i++) {
        figures[i]->print_info();
        std::cout << "\n";
        delete figures[i];
    }

    return 0;
}