#include <iostream>


class smart_array {
private:
    int* data;
    int capacity;
    int size;

    // увеличиваем вместимотсь выделенной памяти
    void resize() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    smart_array(int initialCapacity)
        : data(nullptr), capacity(initialCapacity), size(0) {
        if (capacity > 0) {
            data = new int[capacity];
        }
    }

    ~smart_array() {
        delete[] data;
    }

    // добавление нового элемента
    void add_element(int value) {
        if (size >= capacity) {
            resize();
        }
        data[size] = value;
        ++size;
    }

    // получение элемента по индексу  
    int get_element(int index) const {
        if (index >= size) {
            throw std::out_of_range("index vihodit za predel massiva");
        }
        return data[index];
    }

    //получение текущего размера массива
    size_t get_size() const {
        return size;
    }

    // получение вместимости выделенной памяти 
    size_t get_capacity() const {
        return capacity;
    }

    // вывод информации о массиве
    void print_info() const {
        std::cout << "Razmer: " << size
            << ", Vmestimost: " << capacity
            << ", Element: ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    try {

        smart_array arr(5);


        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        arr.print_info();


        std::cout << "\nElement s idex 1: " << arr.get_element(1) << std::endl;


        std::cout << "\nDobavlaem element: ";
        arr.add_element(100);
        std::cout << arr.get_element(arr.get_size() - 1) << std::endl;
        arr.print_info();


        std::cout << "\nVse element s index:" << std::endl;
        for (int i = 0; i < arr.get_size(); ++i) {
            std::cout << "arr[" << i << "] = " << arr.get_element(i) << std::endl;
        }

    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}