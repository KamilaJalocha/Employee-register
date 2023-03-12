//
// Created by kamila on 21.12.2021.
//

#ifndef JALOCHAKAMILA_ETAP2_ADMINISTRATOR_H
#define JALOCHAKAMILA_ETAP2_ADMINISTRATOR_H

#include "Pracownik.h"

class Administrator: public Pracownik<int> {
public:
    Administrator(string imie, int zarobki) : Pracownik(imie, zarobki) {
        rodzaj_umowy = UMOWA_O_PRACE;
        domyslny_urlop = 30;
        dostepny_urlop = domyslny_urlop;
        wspolczynnik_premii = 0.4;
    }

    string nazwa() {
        return "Administrator";
    }

protected:
    void urlop(int dni) override;
};



#endif //JALOCHAKAMILA_ETAP2_ADMINISTRATOR_H
