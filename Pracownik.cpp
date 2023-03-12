//
// Created by kamila on 03.12.2021.
//

#include <iostream>
#include "Pracownik.h"


template<class T>
void Pracownik<T>::praca(int czas_pracy) {             //definicja metody praca
    cout << "Pracuje sobie." << endl;
    godziny_w_tym_miesiacu = czas_pracy + godziny_w_tym_miesiacu;

}

template<class T>
void Pracownik<T>::kawa(int czas_przerwy) {                    //definicja metody kawa
    cout << "Poszedlem na kawe, zaraz wracam." << endl;
    kawa_w_tym_miesiacu = czas_przerwy + kawa_w_tym_miesiacu;
}

template<class T>
void Pracownik<T>::l4(int dni) {
    cout << "Obecnie przebywam na l4." << endl;
    l4_w_tym_miesiacu = dni + l4_w_tym_miesiacu;
}

template<class T>
void Pracownik<T>::urlop(int dni) {
    if (dostepny_urlop >= dni) {
        cout << "Aktualnie, wybieram sie na urlop." << endl;
        dostepny_urlop = dostepny_urlop - dni;
    } else
        cout << "Niestety nie masz tyle dni urlopu." << endl;
}

template<class T>
void Pracownik<T>::nowy_miesiac() {
    cout << "Podsumowanie dla pracownika " << imie << " za biezacy miesiac:" << endl
         << "Przepracowales: " << godziny_w_tym_miesiacu << " godzin, nalezy ci sie " << zarobki_w_danym_miesiacu()
         << " zlotych" << endl
         << "Spedziles na L4 " << l4_w_tym_miesiacu << " dni." << endl
         << "Spedziles na kawie " << kawa_w_tym_miesiacu << " godzin." << endl;
    godziny_w_miesiacu.push_back(godziny_w_tym_miesiacu);
    godziny_w_tym_miesiacu = 0;
    kawa_w_miesiacu.push_back(kawa_w_tym_miesiacu);
    kawa_w_tym_miesiacu = 0;
    l4_w_miesiacu.push_back(l4_w_tym_miesiacu);
    l4_w_tym_miesiacu = 0;
}

template<class T>
void Pracownik<T>::nowy_rok() {
    nowy_miesiac();
    dostepny_urlop = domyslny_urlop;
}


ostream &operator<<(ostream &os, const Pracownik<int> &pracownik) {
    os << pracownik.imie << endl
       << pracownik.zarobki << " "
       << static_cast<int>(pracownik.rodzaj_umowy) << " "
       << pracownik.domyslny_urlop << " "
       << pracownik.wspolczynnik_premii << " "
       << pracownik.godziny_w_tym_miesiacu << " "
       << pracownik.kawa_w_tym_miesiacu << " "
       << pracownik.l4_w_tym_miesiacu << " "
       << pracownik.dostepny_urlop << " ";

    int godziny_w_miesiacu_size = pracownik.godziny_w_miesiacu.size();
    os << godziny_w_miesiacu_size << " ";
    for (int i = 0; i < pracownik.godziny_w_miesiacu.size(); i++) {
        os << pracownik.godziny_w_miesiacu[i] << " ";
    }

    int kawa_w_miesiacu_size = pracownik.kawa_w_miesiacu.size();
    os << kawa_w_miesiacu_size << " ";
    for (int i = 0; i < pracownik.kawa_w_miesiacu.size(); i++) {
        os << pracownik.kawa_w_miesiacu[i] << " ";
    }

    int l4_w_miesiacu_size = pracownik.l4_w_miesiacu.size();
    os << l4_w_miesiacu_size << " ";
    for (int i = 0; i < pracownik.l4_w_miesiacu.size(); i++) {
        os << pracownik.l4_w_miesiacu[i] << " ";
    }

    return os;
}

istream &operator>>(istream &is, Pracownik<int> &pracownik) {
    getline(is, pracownik.imie);
    int rodzaj_umowy;
    is >> pracownik.zarobki
       >> rodzaj_umowy
       >> pracownik.domyslny_urlop
       >> pracownik.wspolczynnik_premii
       >> pracownik.godziny_w_tym_miesiacu
       >> pracownik.kawa_w_tym_miesiacu
       >> pracownik.l4_w_tym_miesiacu
       >> pracownik.dostepny_urlop;
    pracownik.rodzaj_umowy = RodzajUmowy(rodzaj_umowy);

    int godziny_w_miesiacu_size;
    is >> godziny_w_miesiacu_size;
    int godziny_w_miesiacu;
    for (int i = 0; i < godziny_w_miesiacu_size; i++) {
        is >> godziny_w_miesiacu;
        pracownik.godziny_w_miesiacu.push_back(godziny_w_miesiacu);
    }

    int kawa_w_miesiacu_size;
    is >> kawa_w_miesiacu_size;
    int kawa_w_miesiacu;
    for (int i = 0; i < kawa_w_miesiacu_size; i++) {
        is >> kawa_w_miesiacu;
        pracownik.kawa_w_miesiacu.push_back(kawa_w_miesiacu);
    }

    int l4_w_miesiacu_size;
    is >> l4_w_miesiacu_size;
    int l4_w_miesiacu;
    for (int i = 0; i < l4_w_miesiacu_size; i++) {
        is >> l4_w_miesiacu;
        pracownik.l4_w_miesiacu.push_back(l4_w_miesiacu);
    }

    return is;
}

template<class T>
float Pracownik<T>::premia() {
    float premia = wspolczynnik_premii *
                   (static_cast<float>(zarobki) * static_cast<float>(godziny_w_tym_miesiacu) / 160 -
                    kawa_w_tym_miesiacu);
    return premia;
}

template<class T>
float Pracownik<T>::zarobki_w_danym_miesiacu() {
    float zarobki_w_danym_miesiacu =
            (static_cast<float>(zarobki) * godziny_w_tym_miesiacu) / 160 - static_cast<float>(0.7 * l4_w_tym_miesiacu);
    return zarobki_w_danym_miesiacu;
}

template
class Pracownik<int>;