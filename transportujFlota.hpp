#pragma once

#include "Stocznia.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int transportujFlota(int towar)
{
    class Stocznia
    {
    public:
        Stocznia() = default;

        Statek* operator()() {}
    };

    int transportujFlota(int towar);
    {
        if (towar == 0)
            return 0;

        Stocznia stocznia{};
        int      przetransportowane = 0;
        int      liczbaZaglowcow    = 0;

        while (przetransportowane < towar) {
            Statek* statek = stocznia();

            przetransportowane += statek->transportuj();

            if (dynamic_cast< Zaglowiec* >(statek) != nullptr) {
                ++liczbaZaglowcow;
            }

            delete statek;
        }

        return liczbaZaglowcow;
    }
    return 0;
}