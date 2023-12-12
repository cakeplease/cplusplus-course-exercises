#include "Set.cpp"

int main() {

    //Lag ny tom mengde
    Set set1;
    // Legg til tall inn i mengden
    set1+=1;
    set1+=2;
    set1+=3;
    //Denne lykkes ikke siden tallet 1 finnes fra før av i mengden set1
    set1+=1;
    // Skriv ut en mengde
    cout << "Set1: " << set1 << endl;

    Set set2;
    set2+= 6;
    set2+= 7;
    set2+= 8;
    cout << "Set2: " << set2 << endl;
    // Sett en mengde lik en annen
    set1=set2;

    cout << "Setter set1 lik set2: " << set1 << endl;

    // Finn unionen mellom mengde set2 og set3
    Set set3;
    set3+=6;
    set3+=5;
    set3+=8;
    cout << "Set3: " << set3 << endl;
    Set set = set2|set3;
    cout << "Unionen mellom set2 og set3: " << set << endl;

    return 0;
}