#include <iostream>

using namespace std;

int main() {
    const int length = 5;
    double temp;
    int under10 = 0;
    int between10And20 = 0;
    int over20 = 0;
    cout << "Du skal skrive inn 5 temperaturer." << endl;
    for (int i = 1; i <= length; i++) {
        cout << "Temperatur " << i << ": ";
        cin >> temp;

        if (temp < 10) {
            under10++;
        } else if (temp >= 10 && temp <= 20) {
            between10And20++;
        } else {
            over20++;
        }
    }
    cout << "Antall under 10 er " << under10 << endl;
    cout << "Antall mellom 10 og 20 er " << between10And20 << endl;
    cout << "Antall over 20 er " << over20 << endl;

}