#include <iostream>
#include <functional>

using namespace std;

template<typename T1, typename T2, typename T3>
T1 pipe(function<T2(T3)> a, function<T1(T2)> b, T3 c) {
    return b(a(c));
}


int main() {
    cout << pipe<int, int, int>([](int x) { return x * 10; }, [](int x) { return x - 1; }, 4) << endl;
    cout << pipe<int, string, string>([](string x) { return x + x; }, [](string x) { return x.length(); },"hello")<< endl;
    //skal gi:
    //39
    //10
}