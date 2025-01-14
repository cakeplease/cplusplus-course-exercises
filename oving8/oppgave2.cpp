#include <iostream>

using namespace std;

template<typename Type1, typename Type2>
class Pair {
public:
    Type1 first;
    Type2 second;
    Pair(Type1 first, Type2 second) : first(first), second(second) {}

    Pair operator+(const Pair &other) {
        Pair pair = *this;
        pair.first += other.first;
        pair.second += other.second;
        return pair;
    }

    //Jeg antar at type1 og type2 er kompatible, de må kunne legges sammen for å utføre denne sammenligningen.
    //Derfor må operator+ allerede ta hensyn til det.
    bool operator>(const Pair &other) {
        Pair pair = *this;
        return pair.first+pair.second > other.first+other.second;
    }
};

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 er størst" << endl;
    else
        cout << "p2 er størst" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;
}
