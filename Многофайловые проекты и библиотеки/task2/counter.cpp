#include "Counter.h"

Counter::Counter() : num(1) {}

Counter::Counter(int numb) : num(numb) {}

void Counter::increm() {
    ++num;
}

void Counter::decrem() {
    --num;
}

int Counter::get_num() {
    return num;
}