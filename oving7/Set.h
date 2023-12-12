#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/**
 * Set klasse og main metoden under som tester den.
 */
class Set {
public:
    //heltallstabell
    std::vector<int> integers;
    Set();
    Set(const Set &) = default;
    Set operator|(const Set &other) const;
    Set &operator+=(int number);
    Set &operator=(const Set &other);
    friend ostream &operator<<(ostream &os, const Set &set);
};