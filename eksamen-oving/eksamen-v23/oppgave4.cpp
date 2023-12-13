#include<iostream>
#include<vector>
#include <thread>

using namespace std;

vector<bool> parallell_prime(vector<int> vec) {
    auto thread_size = thread::hardware_concurrency();
    vector<bool> res(vec.size());
    vector<thread> threads;
    threads.reserve(thread_size);

    for (size_t thread_num = 0; thread_num<thread_size; ++thread_num) {
        threads.emplace_back([thread_num, thread_size, &res, &vec] {
            for (size_t i = thread_num; i<vec.size(); i+= thread_size) { // i is index!!!
                bool is_prime = true;
                for (int j = 2; j <= vec[i]/2; ++j) {
                    if (vec[i] % j == 0) {
                        is_prime = false;
                        break;
                    }
                }
                res[i] = is_prime;
            }
        });
    }

    for (auto &thread : threads) {
        thread.join();
    }

    return res;
}

ostream &operator<<(ostream &os, vector<bool> vec) {
    for (bool is_prime : vec) {
        if (is_prime == 0) {
            os << "false ";
        } else {
            os << "true ";
        }
    }
    return os; //remember this!!!
}

int main() {
    vector<int> a = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << parallell_prime(a) << endl;
    //{ true, true, false, true, false, true, false, false, false, true,
    //false }

    return 0;
}