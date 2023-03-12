//
// Created by kamila on 04.01.2022.
//

#ifndef JALOCHAKAMILA_ETAP2_WYJATKI_H
#define JALOCHAKAMILA_ETAP2_WYJATKI_H

#include <exception>

struct ZlaWartosc : public exception {
    const char* what() const throw() {
        return "Podana wartosc jest niepoprawna.";
    }
};

struct NieMaTakiegoPracownika : public exception {
    const char* what() const throw()  {
        return "Podany identyfikator pracownika nie istnieje.";
    }
};
#endif //JALOCHAKAMILA_ETAP2_WYJATKI_H
