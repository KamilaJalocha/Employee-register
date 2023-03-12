//
// Created by kamila on 03.12.2021.
//

#ifndef JALOCHAKAMILA_ETAP2_APLIKACJA_H
#define JALOCHAKAMILA_ETAP2_APLIKACJA_H


#include "Firma.h"
#include <vector>

class Aplikacja {
public:
    Aplikacja() : firmy() {}  //konstruktor
    void main();

    friend ostream &operator<<(ostream &os, const Aplikacja &aplikacja);

    friend istream &operator>>(istream &is,  Aplikacja &aplikacja);

private:

    void dodaj_firme();

    vector<Firma*> firmy;



};


#endif //JALOCHAKAMILA_ETAP2_APLIKACJA_H
