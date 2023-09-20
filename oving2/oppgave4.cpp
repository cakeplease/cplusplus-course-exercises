#include <iostream>

int main() {
   /*
    int a = 5;
    int &b; // vi kan ikke lage referansen b uten å si hva den refererer til
    int *c;
    c = &b;
    *a = *b + *c; // pekeren a er ikke initialisert, den kan heller ikke peke til en annen peker, men heller en adresse. Man kan heller ikke legge sammen to pekere.
    &b = 2; // referansen b kan bare referere til en annen variabel
    */

    int a = 5;
    int &b = a; // vi lar b referere til a
    int *c;
    c = &b;
    b = 2;

    printf("a: %d og b: %d er like siden b refererer til a \n", a,b);
    printf("c peker til b, mens b refererer til a som vil si at c ogsaa peker til a:\nc adresse: %p, b adresse: %p, a adresse: %p \n", c, &b, &a);

    return 0;
}


