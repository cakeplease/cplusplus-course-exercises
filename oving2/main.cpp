#include <iostream>

int main() {

    int number;
    int *pointer;
    int test;


    pointer = &test;
    *pointer = 9;

    std::cout << pointer << std::endl;
    std::cout << &pointer << std::endl;


    std::cout << test << std::endl;
    std::cout << &test << std::endl;

    return 0;
}
