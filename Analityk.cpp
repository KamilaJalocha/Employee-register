//
// Created by kamil on 21.12.2021.
//

#include "Analityk.h"

void Analityk::praca(int czas_pracy) {
    Pracownik<int>::praca(czas_pracy);
    cout << "Tak naprawde to pracuje sobie zdalnie. " << endl;
}