#include<iostream>
#include <utility>
#include<vector>
#include <thread>

using namespace std;

template <typename Type>
class Matrix {
    vector<vector<Type>> data;
public:
    Matrix(vector<vector<Type>> vec) : data(move(vec)) {}; // move vec pointer to data var

    Matrix<Type> &operator*(Matrix<Type> otherMatrix) {
        int m1Row = data.size();
        int m1Col = data[0].size();
        int m2Col = otherMatrix.data[0].size();

        vector<thread> threads; // create threads
        threads.reserve(m1Row); // reserve threads for each row in matrix

        //create empty matrix of correct size
        Matrix<Type> out(vector<vector<Type>>(m1Row, vector<Type>(m2Col)));

        for (int i = 0; i < m1Row; ++i) {
            threads.emplace_back([i, m1Col, m2Col, this, &out, otherMatrix] {
                for (int j=0; j<m2Col; ++j) {
                    for (int k=0;k<m1Col; ++k) {
                        out.data[i][j] += data[i][k] * otherMatrix.data[k][j];
                    }
                }
            });
        }
        for (auto &thread : threads)
            thread.join();
        return out;
    }

    friend ostream &operator<<(ostream &os, const Matrix<Type> &m) {
        for (auto row : m.data) {
            os << "[ ";
            for (auto e : row) {
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
}