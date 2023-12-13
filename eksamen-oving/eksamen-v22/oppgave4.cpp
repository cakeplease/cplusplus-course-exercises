#include<thread>
#include<iostream>
#include<vector>
#include<functional>
using namespace std;

vector<int> parallell_transform(const vector<int> &a, const vector<int> &b, const function<int(int, int)> &callback) {
    auto thread_size = thread::hardware_concurrency();
    vector<int> result(a.size());
    vector<thread> threads;

    threads.reserve(thread_size);

    for (size_t thread_num = 0; thread_num < thread_size; ++thread_num) {
        threads.emplace_back([thread_num, thread_size, &result, &a, &b, &callback] {
            for (size_t i = thread_num; i<a.size(); i+= thread_size) {
                result[i] = callback(a[i], b[i]);
            }
        });
    }
    for (auto &thread : threads) {
        thread.join();
    }
    return result;
}
//Function to print vector values
template <typename Type>
ostream& operator<<(std::ostream& os, const std::vector<Type>& vec) {
    os << "{ ";
    if (!vec.empty()) {
        os << vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            os << ", " << vec[i];
        }
    }
    os << " }";
    return os;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 5, 6};
    cout << parallell_transform(a, b, [](int a_element, int b_element) {
        return a_element + b_element;
    }) << endl;
    cout << parallell_transform(a, b, [](int a_element, int b_element) {
        return a_element * b_element;
    }) << endl;
}
