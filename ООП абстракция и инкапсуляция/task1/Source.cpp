#include <iostream>
#include <fstream>
#include <string>

class Adres {
private:
    std::string city;
    std::string street;
    int house;
    int flat;

public:
    Adres(std::string city, std::string street, int house, int apartment)
        : city(city), street(street), house(house), flat(apartment) {}

    std::string get_output_adres() const {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
    }
};

int main() {
    std::ifstream input("in.txt");
    std::ofstream output("out.txt");

    if (!input.is_open()) {
        std::cerr << "Failed to open input file!" << std::endl;
        return 1;
    }

    if (!output.is_open()) {
        std::cerr << "Failed to open output file!" << std::endl;
        return 1;
    }

    int N;
    input >> N;
    Adres** adr = new Adres * [N];

    for (int i = 0; i < N; ++i) {
        std::string city, street;
        int house, apartment;

        input >> city;
        input >> street;
        input >> house;
        input >> apartment;

        adr[i] = new Adres(city, street, house, apartment);
    }

    output << N << std::endl;
    for (int i = N - 1; i >= 0; --i) {
        output << adr[i]->get_output_adres() << std::endl;
        delete adr[i]; 
    }

    delete[] adr; 
    input.close();
    output.close();

    return 0;
}