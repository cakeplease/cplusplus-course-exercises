#include <iostream>

int main() {
    double number;
    //Definer en peker som skal peke til number.
    double *pointer = &number;
    //Definer en referanse som skal referere til number.
    double &ref = number;


    //Vis tre måter å få tilordnet verdi til number på:
    number = 0.8;

    std::cout << number << std::endl;

    *pointer = 6.5;

    std::cout << number << std::endl;

    ref = 8.3;

    std::cout << number << std::endl;

    return 0;
}