#include <vector>
#include <algorithm>
#include <iostream>
#include "Set.h"

using namespace std;

/**
 * Konstruktør. Lager ny tom mengde
 */
Set::Set() : integers(vector<int>()) {}
/**
 * Finner unionen mellom to mengder
 * @param other
 * @return Set
 */
Set Set::operator|(const Set &other) const {
    Set ans;
    //Gå gjennom begge mengder for å finne tall som er like, deretter sjekk om dette tallet allerede eksiterer i ans-mengden.
    for (int integer : integers) {
        for (int integer2 : other.integers) {
            if ((integer == integer2) && find(ans.integers.begin(), ans.integers.end(), integer) != integers.end()) {
                ans.integers.push_back(integer);
            }
        }
    }
    return ans;
}
/**
 * Legger et tall inn i mengden
 * @param number
 * @return  Set
 */
Set &Set::operator+=(int number) {
    if (find(integers.begin(), integers.end(), number) == integers.end()) {
        integers.push_back(number);
    }
    return *this;
}
/**
 * Setter en mengde lik annen mengde
 * @param other
 * @return Set
 */
Set &Set::operator=(const Set &other) {
    this->integers = other.integers;
    return *this;
}
/**
 * Skriver ut mengden
 * @param os
 * @param set
 * @return ostream
 */
ostream &operator<<(ostream &os, const Set &set) {
    os << "{ ";
    for (int integer : set.integers) {
        os << integer << " ";
    }
    os << "}";
    return os;
}
