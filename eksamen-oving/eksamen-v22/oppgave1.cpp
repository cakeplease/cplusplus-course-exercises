#include <iostream>
#include <vector>

using namespace std;

int times_two(int a) {
    return a*2;
}
double times_two(double a) {
    return a*2;
}
string times_two(string a) {
    return a+a;
}
vector<int> times_two(vector<int> vec) {
    vector<int> newVec;
    for(int num : vec) {
        newVec.push_back(num*2);
    }
    return newVec;
}

ostream &operator<<(ostream &stream, const vector<int> &vec) {
    stream << "{ ";
    for (size_t i=0; i<vec.size(); i++) {
        if (i != 0) {
            stream << ", ";
        }
        stream << vec[i];
    }
    return stream << " }";
}

int main() {
    cout << times_two(2) << endl;
    cout << times_two(2.25) << endl;
    cout << times_two("test") << endl;
    cout << times_two(vector<int>{1, 2, 3}) << endl;
}