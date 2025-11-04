#pragma once

#include "Stocznia.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
        return 0;

    std::srand(static_cast< unsigned int >(std::time(nullptr)));

    Stocznia     stocznia{};
    unsigned int przetransportowano = 0;
    unsigned int liczbaZaglowcow    = 0;

    while (przetransportowano < towar) {
        Statek*      s       = stocznia();
        unsigned int ladunek = s->transportuj();
        przetransportowano += ladunek;

        if (dynamic_cast< Zaglowiec* >(s) != nullptr) {
            ++liczbaZaglowcow;
        }

        delete s; 
    }
    return liczbaZaglowcow;
};
