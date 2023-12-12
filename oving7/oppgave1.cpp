#include <iostream>
#include <string>
#include "fraction.cpp"

using namespace std;

void print(const string &text, const Fraction &broek) {
    cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);
    Fraction c;
    c.set(5);
    Fraction d = a / b;

    print("a = ", a);
    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    b += a;
    ++c;
    d *= d;

    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    c = a + b - d * a;
    c = -c;

    print("c = ", c);

    if (a + b != c + d)
        cout << "a + b != c + d" << endl;
    else
        cout << " a + b == c + d" << endl;
    while (b > a)
        b -= a;
    print("b = ", b);

    cout << "\nOppgave 1 a):" << endl;
    Fraction fraction1(1,3);
    Fraction fraction2(2,5);
    print("Fraction1: ",fraction1);
    print("Fraction1 - 5: ", fraction1-5);
    print("5-fraction1: ", 5-fraction1);


    // Oppgave 1 b)
    // 5 - 3 - fraction1 - 7 - fraction2

    // 5 - 3 (int - int) -> vanlig int substrahering = int
    // int - fraction1 (int - fraction) -> friend Fraction operator-(int integer, const Fraction &other); = fraction
    // fraction - 7 (fraction - int) -> Fraction operator-(const int &other) const; = fraction
    // fraction - fraction2 (fraction - fraction) -> Fraction operator-(const Fraction &other) const; = fraction

    print("Test oppg 1b (les kommentarene i koden): ", 5 - 3 - fraction1 - 7 - fraction2);

}
