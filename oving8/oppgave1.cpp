#include <iostream>
#include <iomanip>

using namespace std;

template <typename Type>
bool equal(Type a, Type b) {
    cout << "Vanlig utgave av equals():" << endl;
    cout << a << " og " << b << ": ";
    return a==b;
}
bool equal(double a, double b) {
    cout << "Spesiell utgave av equals(). Absolutte verdien til forskjellen er: " << abs(a-b)<< endl;
    cout << a << " og " << b << ": ";
    if (abs(a-b) < 0.00001) {
        return true;
    } else {
        return false;
    }
}


int main() {

    //Heltall
    cout << equal(1,4) << endl; // skal returnere 0
    cout << equal(2,2) << endl; // skal returnere 1

    cout << fixed;
    cout << setprecision(6);

    //Desimaltall
    cout << equal(0.500011, 0.50001) << endl;
    cout << equal(0.6754, 0.28347) << endl;
    return 0;
}