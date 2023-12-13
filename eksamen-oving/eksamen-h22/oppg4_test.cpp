#include <iostream>
#include <vector>
#include <thread>

using namespace std;

template <typename T>
class Matrix {
    vector<vector<T>> data;
public:
    Matrix(vector<vector<T>> vec) : data(vec) {};
    Matrix<T> operator*(Matrix<T> m_rhs) {
        int r1 = data.size();
        int c1 = data[0].size();
        int c2 = m_rhs.data[0].size();
        std::vector<thread> threads;
        threads.reserve(r1);
        Matrix<T> out(vector<vector<T>>(r1, vector<T>(c2)));
        for(int i = 0; i < r1; ++i) {
            threads.emplace_back([i, c1, c2, this, &out, m_rhs] {
                for(int j = 0; j < c2; ++j)
                    for(int k = 0; k < c1; ++k)
                        out.data[i][j] += data[i][k] * m_rhs.data[k][j];
            });
        }
        for (auto &thread : threads)
            thread.join();
        return out;
    };
    friend ostream &operator<<(ostream &os, const Matrix<T> &m) {
        for(auto row : m.data) {
            os << "[ ";
            for(auto e : row) {
                os << e << " ";
            }
            os << "]" << endl;
        }
        return os;
    }
};
int main() {
    Matrix<int> m_a({{1, 2}, {3, 4}, {5, 6}});
    Matrix<int> m_b({{1, 2, 3}, {4, 5, 6}});
    cout << m_a << endl;
    cout << m_b << endl;
    cout << m_a * m_b << endl;
    cout << m_b * m_a << endl;
    Matrix<int> m_c({{1, 2}});
    Matrix<int> m_d({{2}, {2}});
    cout << m_c * m_d << endl;
    cout << m_d * m_c << endl;
    return 0;
}