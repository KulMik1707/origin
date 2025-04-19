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
    Adres(std::string setCity, std::string setStreet, int setHouse, int setApart)
        : city(setCity), street(setStreet), house(setHouse), flat(setApart) {}

    std::string get_output_address() const {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
    }

    std::string get_city() const {
        return city;
    }
};

void sort(Adres** adr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (adr[j]->get_city() > adr[j + 1]->get_city()) {
                std::swap(adr[j], adr[j + 1]);
            }
        }
    }
}

int main() {
    std::ifstream inFile("in.txt");
    std::ofstream outFile("out.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Failed to open files!" << std::endl;
        return 1;
    }

    int n;
    inFile >> n;
   

    Adres** adr = new Adres * [n];

    for (int i = 0; i < n; ++i) {
        std::string city, street;
        int house, apartment;

        inFile >> city;
        inFile >> street;
        inFile >> house;
        inFile >> apartment;
        

        adr[i] = new Adres(city, street, house, apartment);
    }

    sort(adr, n);

    outFile << n << std::endl;
    for (int i = 0; i < n; ++i) {
        outFile << adr[i]->get_output_address() << std::endl;
    }

    
    for (int i = 0; i < n; ++i) {
        delete adr[i];
    }
    delete[] adr;

    inFile.close();
    outFile.close();

    return 0;
}