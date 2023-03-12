//
// Created by kamila on 03.12.2021.
//

#include <iostream>
#include "Firma.h"
#include "Stazysta.h"
#include "Administrator.h"
#include "Programista.h"
#include "Analityk.h"
#include "Ksiegowy.h"
#include "Wyjatki.h"

void Firma::zwolnij(int identyfikator) {
    Pracownik<int> *pracownik = this->pracownicy[identyfikator];
    cout << "Zwalniam pracownika " << pracownik->imie << endl;
    this->pracownicy.erase(this->pracownicy.begin() + identyfikator);
}

void Firma::wyswietl(int identyfikator) {
    Pracownik<int> *pracownik;

    try {
        pracownik = pracownicy.at(identyfikator);
    } catch (out_of_range &e) {                     // tak jakby zmiana wyjątku out of range na znany i określony przeze
        throw NieMaTakiegoPracownika();             // mnie wyjątek nie ma takiego pracownika
    }

    char wybor;

    do {
        cout << "Profil pracownika" << endl
             << "Typ pracownika: " << pracownik->nazwa() << endl
             << "Imie: " << pracownik->imie << endl
             << "Zarobki: " << pracownik->zarobki << endl;
        if (pracownik->rodzaj_umowy == UMOWA_O_PRACE)
            cout << "Jest zatrudniony na umowe o prace." << endl;
        else if (pracownik->rodzaj_umowy == UMOWA_ZLECENIE)
            cout << "Jest zatrudniony na umowe zlecenie" << endl;
        else
            cout << "Jest zatrudniony na umowe o dzielo" << endl;

        cout << "Zostalo mu " << pracownik->dostepny_urlop << " z " << pracownik->domyslny_urlop << " dni urlopu."
             << endl
             << "W tym miesiacu przepracowal " << pracownik->godziny_w_tym_miesiacu << " godzin" << endl
             << "W tym miesiacu spedzil na kawie " << pracownik->kawa_w_tym_miesiacu << " godzin" << endl
             << "W tym miesiacu byl na L4  " << pracownik->l4_w_tym_miesiacu << " dni" << endl
             << "Jezeli premia bylaby wyplaca dzis, to otrzymalby " << pracownik->premia() << " zlotych" << endl;

        cout << "[1] zaloguj czas pracy" << endl
             << "[2] zaloguj ilosc wypitej kawy" << endl
             << "[3] dodaj ilosc dni spedzonych na urlopie" << endl
             << "[4] dodaj ilosc dni spedzonych na L4" << endl
             << "[z] zwolnij" << endl
             << "[p] powrot" << endl;

        cin >> wybor;

        try {
            switch (wybor) {
                case '1' :
                    zaloguj_prace(pracownik);
                    break;

                case '2' :
                    zaloguj_kawe(pracownik);
                    break;

                case '3' :
                    zaloguj_urlop(pracownik);
                    break;

                case '4' :
                    zaloguj_l4(pracownik);
                    break;

                case 'z' :
                    zwolnij(identyfikator);
                    break;
            }
        } catch (ZlaWartosc &e) {
            cout << "Podano zla wartosc i wystapil wyjatek: " << e.what() << endl;
        }

    } while (wybor != 'p');


}


void Firma::wybierz_akcje() {
    cout << "Widok zarzadzania pracownikami. " << endl;

    char wybor;

    do {
        int ilosc_pracownikow = this->pracownicy.size();
        for (int i = 0; i < ilosc_pracownikow; i++) {
            cout << i + 1 << ". " << this->pracownicy[i]->imie << " | " << this->pracownicy[i]->zarobki << endl;
        }

        cout << "Wybierz akcje: " << endl
             << " [0] Dodaj pracownika" << endl
             << " [1-...] Wyswietl profil pracownika" << endl
             << " [m] Podsumowanie miesiaca" << endl
             << " [r] Podsumowanie roku" << endl
             << " [p] Powrot" << endl;

        cin >> wybor;

        switch (wybor) {
            case '0' :
                this->dodaj();
                break;

            case 'm':
                this->podsumuj_miesiac();
                break;

            case 'r' :
                this->podsumuj_rok();
                break;

            case 'p':
                break;

            default:
                int indeks_pracownika = wybor - '0';
                if (wybor < 0) {
                    cout << "Nieznana komenda." << endl;
                } else {
                    this->wyswietl(indeks_pracownika - 1);
                }
                break;


        }
    } while (wybor != 'p');
}

void Firma::dodaj() {
    cout << "Formularz dodania nowego pracownika" << endl;

    string imie;
    int zarobki;

    cout << "Podaj imie pracownika: ";
    cin >> imie;
    cout << "Podaj zarobki pracownika: ";
    cin >> zarobki;

    cout << "Wybierz rodzaj pracownika, ktorego chcesz dodac: " << endl
         << "[S] Stazysta" << endl
         << "[A] Administrator" << endl
         << "[P] Programista" << endl
         << "[N] Analityk" << endl
         << "[K] Ksiegowy" << endl;


    char typ_prac;
    cin >> typ_prac;
    Pracownik<int> *nowy_pracownik;

    switch (typ_prac) {
        case 'S':
            nowy_pracownik = new Stazysta(imie, zarobki);
            break;

        case 'A' :
            nowy_pracownik = new Administrator(imie, zarobki);
            break;

        case 'P' :
            nowy_pracownik = new Programista(imie, zarobki);
            break;

        case 'N' :
            nowy_pracownik = new Analityk(imie, zarobki);
            break;

        case 'K' :
            nowy_pracownik = new Ksiegowy(imie, zarobki);
            break;

    }

    cout << "Tworze pracownika o imieniu " << imie << " i zarobkach " << zarobki << endl;
    this->pracownicy.push_back(nowy_pracownik);
}

ostream &operator<<(ostream &os, const Firma &firma) {
    int ilosc_pracownikow = firma.pracownicy.size();

    os << firma.nazwa << endl;
    os << ilosc_pracownikow;

    for (int i = 0; i < ilosc_pracownikow; i++) {
        os << *firma.pracownicy[i];
    }

    return os;
}

istream &operator>>(istream &is, Firma &firma) {
    getline(is, firma.nazwa);

    int ilosc_pracownikow;
    is >> ilosc_pracownikow;

    for (int i = 0; i < ilosc_pracownikow; i++) {
        Pracownik<int> *p = new Pracownik<int>("", 0);
        is >> *p;
        firma.pracownicy.push_back(p);    //push_back dodaje nowy element na koniec wektora
    }

    return is;
}

void Firma::zaloguj_prace(Pracownik<int> *pracownik) {
    cout << "Podaj czas pracy: ";
    int godziny;
    cin >> godziny;
    if (godziny < 0) {
        throw ZlaWartosc();
    }
    pracownik->praca(godziny);
}

void Firma::zaloguj_kawe(Pracownik<int> *pracownik) {
    cout << "Podaj ilosc wypitej kawy w godzinach: ";
    int godziny;
    cin >> godziny;
    if (godziny < 0) {
        throw ZlaWartosc();
    }
    pracownik->kawa(godziny);
}

void Firma::zaloguj_urlop(Pracownik<int> *pracownik) {
    cout << "Podaj ile dni spedzil na urlopie: ";
    int dni;
    cin >> dni;
    if (dni < 0) {
        throw ZlaWartosc();
    }
    pracownik->urlop(dni);

}

void Firma::zaloguj_l4(Pracownik<int> *pracownik) {
    cout << "Podaj ile dni spedzil na L4: ";
    int dni;
    cin >> dni;
    if (dni < 0) {
        throw ZlaWartosc();
    }
    pracownik->l4(dni);
}

void Firma::podsumuj_miesiac() {
    cout << "Przedstawiam podsumowanie miesiaca: " << endl;
    for (auto p: pracownicy) {
        p->nowy_miesiac();
    }
}

void Firma::podsumuj_rok() {
    cout << "Przedstawiam podsumowanie roku: " << endl;
    for (auto p: pracownicy) {
        p->nowy_rok();
    }
}