//
// Created by kamila on 03.12.2021.
//

#ifndef JALOCHAKAMILA_ETAP2_FIRMA_H
#define JALOCHAKAMILA_ETAP2_FIRMA_H

#include <iostream>
#include <vector>
#include <string>
#include "Pracownik.h"

using namespace std;

class Firma {
public:
    Firma(string nazwa) : nazwa(nazwa), pracownicy() {}           //konstruktorr

    string nazwa;

    void wybierz_akcje();
    void zaloguj_prace(Pracownik<int> *pracownik);
    void zaloguj_kawe(Pracownik<int> *pracownik);
    void zaloguj_urlop(Pracownik<int> *pracownik);
    void zaloguj_l4(Pracownik<int> *pracownik);


    friend ostream &operator<<(ostream &os, const Firma &firma);

    friend istream &operator>>(istream &is, Firma &firma);

private:
    vector<Pracownik<int> *> pracownicy;

    void dodaj();                // deklaracja metody

    void wyswietl(int identyfikator);

    void zwolnij(int identyfikator);

    void podsumuj_miesiac();

    void podsumuj_rok();
};


#endif //JALOCHAKAMILA_ETAP2_FIRMA_H
