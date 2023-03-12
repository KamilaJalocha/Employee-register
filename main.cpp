#include <iostream>
#include <fstream>
#include <exception>
#include "Aplikacja.h"

using namespace std;

int main(int argc, char *argv[]) {
    Aplikacja app = Aplikacja();

    if (argc > 1) {
        char* nazwa_pliku = argv[1];
        // Wczytaj komendy z pliku
        ifstream plik_wejsciowy(nazwa_pliku);
        if (!plik_wejsciowy.is_open()) {
            cout << "Blad otwarcia pliku. ";
            return 0;
        }
        plik_wejsciowy >> app;
        plik_wejsciowy.close();

        cout << "Wczytano stan aplikacji z pliku komend!" << endl;
    }

    try {
        app.main();                               //ostateczny try catch, jeśli nigdzie wcześniej wyjątek nie zostanie wyłapany
    } catch (const exception &e) {                // to zostanie on złapany tu
        cout << "Podczas wykonywania aplikacji wystapil blad:" << endl
             << e.what() << endl;
    }

    cout << "Stan aplikacji na koniec programu: "<< endl << app << endl;

    ofstream plik_wyjsciowy("najnowszy_stan.txt");
    if (!plik_wyjsciowy.is_open()) {
        cout << "Blad otwarcia pliku. ";
        return 0;
    }
    plik_wyjsciowy << app;
    plik_wyjsciowy.close();

    return 0;
}



