//
// Created by kamil on 21.12.2021.
//

#include "Programista.h"

void Programista::praca(int czas_pracy) {
    Pracownik<int>::praca(czas_pracy);
    cout << "Tak naprawde to pracuje sobie zdalnie. " <<endl;
}
