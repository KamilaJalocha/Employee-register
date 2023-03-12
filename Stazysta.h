//
// Created by kamila on 21.12.2021.
//

#ifndef JALOCHAKAMILA_ETAP2_STAZYSTA_H
#define JALOCHAKAMILA_ETAP2_STAZYSTA_H

#include "Pracownik.h"

class Stazysta: public Pracownik<int> {
public:
    Stazysta(string imie, int zarobki) : Pracownik(imie, zarobki) {
        rodzaj_umowy = UMOWA_ZLECENIE;
        domyslny_urlop = 0;
        dostepny_urlop = domyslny_urlop;
        wspolczynnik_premii = 0.0;
    }

    string nazwa() {
        return "Stazysta";
    }

protected:
    void urlop(int dni) override;
};


#endif //JALOCHAKAMILA_ETAP2_STAZYSTA_H
