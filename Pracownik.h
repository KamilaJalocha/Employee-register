//
// Created by kamila on 03.12.2021.
//

#ifndef JALOCHAKAMILA_ETAP2_PRACOWNIK_H
#define JALOCHAKAMILA_ETAP2_PRACOWNIK_H

#include <iostream>
#include <string>
#include <vector>
#include "RodzajUmowy.h"

using namespace std;

template <class T>
class Pracownik {
public:
    Pracownik(string imie, T zarobki) :             // konstruktor
        imie(imie),
        zarobki(zarobki),
        rodzaj_umowy(UMOWA_O_PRACE),
        godziny_w_tym_miesiacu(0),
        kawa_w_tym_miesiacu(0),
        l4_w_tym_miesiacu(0),
        godziny_w_miesiacu(),
        kawa_w_miesiacu(),
        l4_w_miesiacu(),
        dostepny_urlop(domyslny_urlop)
        {}

    string imie;
    // Zarobki w przeliczeniu na 160h w miesiacu
    T zarobki;
    RodzajUmowy rodzaj_umowy;
    int domyslny_urlop = 0;
    float wspolczynnik_premii = 0.0;

    int godziny_w_tym_miesiacu;  // w godzinach
    int kawa_w_tym_miesiacu;  // w godzinach
    int l4_w_tym_miesiacu;  // w dniach

    vector<int> godziny_w_miesiacu;
    vector<int> kawa_w_miesiacu;
    vector<int> l4_w_miesiacu;
    int dostepny_urlop;


public:

    float premia();
    float zarobki_w_danym_miesiacu();

    virtual string nazwa() {
        return "Pracownik";
    };

    friend ostream &operator<<(ostream &os, const Pracownik<int> &pracownik);

    friend istream &operator>>(istream &is, Pracownik<int> &pracownik);

protected:
    virtual void praca(int czas_pracy);     //deklaracja metody praca

    void kawa(int czas_przerwy);         // deklaracja metody kawa

    void l4(int dni);                     // deklaracja metody l4

    virtual void urlop(int dni);            // deklaracja metody urlop

    void nowy_miesiac();                // deklaracja metody nowy_miesiac

    void nowy_rok();                    // deklaracja metody nowy_rok

    friend class Firma;

};


#endif //JALOCHAKAMILA_ETAP2_PRACOWNIK_H
