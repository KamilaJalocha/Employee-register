//
// Created by kamila on 03.12.2021.
//

#include <iostream>
#include "Aplikacja.h"

using namespace std;

void Aplikacja::main() {
    cout << "System zarzadzania firmami." << endl;

    char wybor;

    do {
        int ilosc_firm = this->firmy.size();
        for (int i = 0; i < ilosc_firm; i++) {
            cout << i + 1 << ". " << this->firmy[i]->nazwa << " | " << endl;
        }

        cout << "Wybierz akcje: " << endl
             << " [0] Dodaj firme" << endl
             << " [1-...] Wyswietl profil firmy" << endl
             << " [w] Wyjscie z programu" << endl;

        cin >> wybor;

        switch (wybor) {
            case '0' :
                this->dodaj_firme();
                break;

            case 'w':
                break;

            default:
                int indeks_firmy = wybor - '0';
                if (wybor < 0) {
                    cout << "Nieznana komenda." << endl;
                } else {
                    firmy[indeks_firmy - 1]->wybierz_akcje();
                }
                break;



        }
    } while (wybor != 'w');
}

ostream &operator<<(ostream &os, const Aplikacja &aplikacja) {
    int ilosc_firm = aplikacja.firmy.size();
    os << ilosc_firm;

    cout << "Jest " << ilosc_firm << " firm" << endl;

    for (int i = 0; i < ilosc_firm; i++) {
        os << *aplikacja.firmy[i];
    }
    return os;
}

istream &operator>>(istream &is, Aplikacja &aplikacja) {

    int ilosc_firm;
    is >> ilosc_firm;

    for (int i = 0; i < ilosc_firm; i++) {
        Firma *f = new Firma("");
        is >> *f;
        aplikacja.firmy.push_back(f);
    }
    return is;
}

void Aplikacja:: dodaj_firme() {
    cout << "Formularz dodania nowej firmy: " << endl;

    string nazwa;
    cout << "Podaj nazwe firmy: " << endl;
    cin >> nazwa;

    Firma* firma = new Firma(nazwa);
    firmy.push_back(firma);
}
