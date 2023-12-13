#include<iostream>
#include<vector>
#include<functional>

using namespace std;

template <typename Type_IN, typename Type_OUT>
vector<Type_OUT> map_f(vector<Type_IN> vec, function<Type_OUT(Type_IN)> callback) {
    vector<Type_OUT> out;
    for (Type_IN e : vec) {
        out.emplace_back(callback(e));
    }
    return out;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) { //remember const
    if (vec.empty()) {
        os << "{}";
        return os;
    }
    os << "{ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i + 1 != vec.size())
            os << ", ";
    }
    os << " }";
    return os;
}


int main() {
    cout << map_f<int, int>({1, 2, 3}, [](int a){return a * 2;}) << endl;
    cout << map_f<float, float>({1, 2.3, 3}, [](float a){return a /2;}) << endl;
    cout << map_f<string, string>({"hello", "world"}, [](string s){return s + ".";}) << endl;
    cout << map_f<string, int>({"hello", "world"}, [](string s){return s.size();}) << endl;
}