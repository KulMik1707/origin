#include <iostream>



class smart_array {
private:
    int* data;
    int capacity;
    int size;

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

    
    void cleanup() {
        delete[] data;
        data = nullptr;
        capacity = 0;
        size = 0;
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

    
    smart_array(const smart_array& other)
        : data(nullptr), capacity(other.capacity), size(other.size) {
        if (capacity > 0) {
            data = new int[capacity];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
    }

    
    smart_array& operator=(const smart_array& other) {
        
        if (this == &other) {
            return *this;
        }

       
        int* newData = nullptr;
        if (other.capacity > 0) {
            newData = new int[other.capacity];  
            for (int i = 0; i < other.size; ++i) {
                newData[i] = other.data[i];
            }
        }

        
        delete[] data;

        
        data = newData;
        capacity = other.capacity;
        size = other.size;

        return *this;
    }

    
    void add_element(int value) {
        if (size >= capacity) {
            resize();
        }
        data[size] = value;
        ++size;
    }

    
    int get_element(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("index vihodit za predel massiva");
        }
        return data[index];
    }

    
    size_t get_size() const {
        return size;
    }

    
    size_t get_capacity() const {
        return capacity;
    }

    
    void print_info(const std::string& name = "") const {
        if (!name.empty()) {
            std::cout << name << ": ";
        }
        std::cout << "Razmer: " << size
            << ", Vmestimost: " << capacity
            << ", Elementy: ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    try {
        // 1 ���������
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.print_info("arr (do prisvoeniya)");

        // 2 ���������
        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);
        new_array.print_info("new_array (do prisvoeniya)");

        // ������������ ������ ���������� �������
        std::cout << "\nPrisvaivaem arr = new_array\n";
        arr = new_array;

        // ��������� ���������
        arr.print_info("arr (posle prisvoeniya)");
        new_array.print_info("new_array (posle prisvoeniya)");

        // ��������� ����������������
        std::cout << "\nProverka samoprisvaivaniya:\n";
        arr = arr;
        arr.print_info("arr (posle arr = arr)");

        // ��������� ������������� ��������
        std::cout << "\nDobavlaem element v arr:\n";
        arr.add_element(100);
        arr.print_info("arr (posle dobavleniya 100)");
        new_array.print_info("new_array (bez izmeneniy)");

        // ��������� ����������� �����������
        std::cout << "\nSozdaem kopiyu arr:\n";
        smart_array arr_copy = arr;
        arr_copy.print_info("arr_copy");

    }
    catch (const std::exception& ex) {
        std::cout << "Oshibka: " << ex.what() << std::endl;
    }

    return 0;
}