//
// Created by kamil on 21.12.2021.
//

#ifndef JALOCHAKAMILA_ETAP2_KSIEGOWY_H
#define JALOCHAKAMILA_ETAP2_KSIEGOWY_H

#include <string>
#include "Pracownik.h"

class Ksiegowy : public Pracownik<int> {
public:
    Ksiegowy(string imie, int zarobki) : Pracownik(imie, zarobki) {
        rodzaj_umowy = UMOWA_O_PRACE;
        domyslny_urlop = 26;
        dostepny_urlop = domyslny_urlop;
        wspolczynnik_premii = 0.4;
    }

    string nazwa() {
        return "Ksiegowy";
    }
};


#endif //JALOCHAKAMILA_ETAP2_KSIEGOWY_H
