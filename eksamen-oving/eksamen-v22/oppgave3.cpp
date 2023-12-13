#include<iostream>
#include <cmath>
using namespace std;

template <typename Type>
class Angle {
    Type value;
public:
   Angle(int value_) : value(value_ % 360) {}
   Angle(double value_) : value(fmod(value_, 3.14159265359)) {}

   template<typename Type2>
   friend Angle<Type> operator+(const Angle<Type> &angle, Type2 value_) {
       return Angle<Type>(angle.value + static_cast<Type>(value_));
   }

   friend ostream &operator<<(ostream &os, const Angle<Type> &angle) {
       return os << angle.value;
   }
};

int main() {
    cout << Angle<int>(30) << endl;
    cout << (Angle<int>(30) + 360) << endl;
    cout << (Angle<int>(30) + 3.14159265359) << endl;
    cout << Angle<double>(3.14159265359 / 2) << endl;
    cout << (Angle<double>(3.14159265359 / 2) + 3.14159265359) << endl;
    cout << (Angle<double>(3.14159265359 / 2) + 3) << endl;
}