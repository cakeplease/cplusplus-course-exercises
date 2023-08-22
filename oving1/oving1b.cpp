#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
    double temperatures[5];
    int length = 5;
    read_temperatures(temperatures, length);

    int under10 = 0;
    int between10And20 = 0;
    int over20 = 0;

    for (int i = 0; i<length; i++) {
        if (temperatures[i] < 10) {
            under10++;
        } else if (temperatures[i] >= 10 && temperatures[i] <= 20) {
            between10And20++;
        } else {
            over20++;
        }
    }

    cout << "Antall under 10 er " << under10 << endl;
    cout << "Antall mellom 10 og 20 er " << between10And20 << endl;
    cout << "Antall over 20 er " << over20 << endl;
}

void read_temperatures(double temperatures[], int length) {
    ifstream file;
    file.open("temperatures.txt");
    if (!file) {
        cout << "Feil ved åpning av filen." << endl;
        exit(EXIT_FAILURE);
    }

    for (int i=0; i < length; i++) {
        file >> temperatures[i];
    }

    file.close();
}