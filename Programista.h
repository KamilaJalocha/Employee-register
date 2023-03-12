//
// Created by kamila on 21.12.2021.
//

#ifndef JALOCHAKAMILA_ETAP2_PROGRAMISTA_H
#define JALOCHAKAMILA_ETAP2_PROGRAMISTA_H

#include "Pracownik.h"

class Programista: public Pracownik<int> {
public:
    Programista(string imie, int zarobki) : Pracownik(imie, zarobki) {
        rodzaj_umowy = UMOWA_O_DZIELO;
        domyslny_urlop = 26;
        dostepny_urlop = domyslny_urlop;
        wspolczynnik_premii = 0.4;
    }

    string nazwa() {
        return "Programista";
    }

protected:

    void praca(int czas_pracy) override;
};


#endif //JALOCHAKAMILA_ETAP2_PROGRAMISTA_H
