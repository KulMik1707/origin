#pragma once
#include <iostream>

class Counter {
private:
    int num;

public:
    Counter();
    Counter(int numb);
    void increm();
    void decrem();
    int get_num();
};