#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    //Opprett en vektor av double
    vector<double> numbers = {1,2,3,4,5};
    cout << "Numbers vector:" << endl;
    for (size_t i = 0; i<numbers.size(); i++) {
        cout << numbers[i] << " ";
    }

    //Prøv ut medlemsfunksjonene front() og back()
    cout << "\nFront: " << numbers.front() << " Back: " << numbers.back() << "\n" << endl;
    numbers.emplace(numbers.begin()+1,0);

    //Bruk emplace() til å sette inn et tall etter det første elementet.
    cout << "Adding \"0\" after \"1\" in numbers:" << endl;
    for (size_t i = 0; i<numbers.size(); i++) {
        cout << numbers[i] << " ";
    }

    //Prøv ut STL-algoritmen find().
    double numberToFind = 4;
    auto it = find(numbers.begin(), numbers.end(), numberToFind);
    if (it != numbers.end()) {
        cout << "\nElement found in \"numbers\": " << *it << '\n';
    } else {
        cout << "Element not found in \"numbers\"\n";
    }

    return 0;
}