#include <iostream>
using namespace std;
int find_sum(const int *table, int length);
int main() {
    int table[20];
    for (int i=0; i<20; i++) {
        table[i] = i+1;
    }

    int sumFirst10 = find_sum(table, 5) + find_sum(&table[5], 5);
    int sumNext5 = find_sum(&table[10], 5);
    int sumLast5 = find_sum(&table[15], 5);

    std::cout << sumFirst10 << std::endl;
    std::cout << sumNext5 << std::endl;
    std::cout << sumLast5 << std::endl;

    return 0;
}
int find_sum(const int *table, int length) {
    int sum = 0;
    for (int i = 0; i<length; i++) {
        sum += *table;
        table++;
    }
    return sum;
}

