#include <iostream>
#include <vector>

using namespace std;

string concat(string a, string b) {
    return a+b;
}
string concat(int a, int b) {
    return to_string(a)+to_string(b);
}
string concat(vector<string> vec) {
    string result = "";
    for(string letter : vec) {
        result += letter;
    }
    return result;
}

int main() {
    cout << concat("hello", "world") << endl;
    cout << concat(1, 2) << endl;
    cout << concat({"a", "b", "c"}) << endl;

    //skal gi:
    //helloworld
    //12
    //abc

    return 0;
}