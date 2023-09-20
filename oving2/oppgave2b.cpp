#include <iostream>

int main() {

    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;

    std::cout << "i:" << std::endl;
    std::cout << "verdi: " << i << std::endl;
    std::cout << "adresse: " << &i << std::endl;
    std::cout << "---------------" << std::endl;

    std::cout << "j:" << std::endl;
    std::cout << "verdi: " <<j << std::endl;
    std::cout << "adresse: " << &j << std::endl;
    std::cout << "---------------" << std::endl;

    std::cout << "p (peker til i):" << std::endl;
    std::cout << "verdi: " << *p << std::endl;
    std::cout << "adresse: " << &p << std::endl;
    std::cout << "---------------" << std::endl;

    std::cout << "q (peker til j):" << std::endl;
    std::cout << "verdi: " << *q << std::endl;
    std::cout << "adresse: " << &q << std::endl;
    std::cout << "---------------" << std::endl;


    //Dette stemmer med tegningen min.

    return 0;
}
