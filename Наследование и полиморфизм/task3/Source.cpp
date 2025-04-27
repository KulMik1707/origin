#include <iostream>
#include <string>

class Figure {
protected:
    int sides_count;
    std::string name;

public:
    Figure(int setSide_count, std::string setName) : sides_count(setSide_count), name(setName) {}
    virtual ~Figure() = default;

    virtual void print_info() {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
    }

    virtual bool check() {
        return sides_count == 0;
    }
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : Figure(3, "Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print_info()  override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }

    bool check() override {
        return (A + B + C) == 180;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }

    bool check() override {
        return Triangle::check() && C == 90;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }

    bool check() override {
        return Triangle::check() && a == c && A == C;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }

    bool check() override {
        return Triangle::check() && a == b && b == c && A == 60 && B == 60 && C == 60;
    }
};

class Quadrilateral : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
        : Figure(4, "Четырёхугольник"), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void print_info() override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }

    bool check() override {
        return (A + B + C + D) == 360;
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }

    bool check() override {
        return Quadrilateral::check() && a == c && b == d &&
            A == 90 && B == 90 && C == 90 && D == 90;
    }
};

class Square : public Rectangle {
public:
    Square(int a) : Rectangle(a, a) {
        name = "Квадрат";
    }

    bool check() override {
        return Rectangle::check() && a == b && b == c && c == d;
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }

    bool check() override {
        return Quadrilateral::check() && a == c && b == d && A == C && B == D;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) {
        name = "Ромб";
    }

    bool check() override {
        return Parallelogram::check() && a == b && b == c && c == d;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Figure* fig[] = {
        new Figure(0, "Фигура"),
        new Triangle(10, 20, 30, 50, 60, 70),
        new RightTriangle(10, 20, 30, 50, 60),
        new RightTriangle(10, 20, 30, 50, 40),
        new IsoscelesTriangle(10, 20, 50, 60),
        new EquilateralTriangle(30),
        new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80),
        new Rectangle(10, 20),
        new Square(20),
        new Parallelogram(20, 30, 30, 40),
        new Rhombus(30, 30, 40)
    };

    for (int i = 0; i < 11; i++) {
        fig[i]->print_info();
        std::cout << "\n";
        delete fig[i];
    }

    return 0;
}