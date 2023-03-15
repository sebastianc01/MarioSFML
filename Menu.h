#pragma once
#include "ConstantsAndIncludes.h"

/**
    Klasa zajmuj¹ca siê wyœwietleniem u¿ytkownikowi pocz¹tkowego interfejsu z wyborem iloœci punktów do zdobycia.
*/
class Menu {
protected:
    /// <summary>
    /// Konstruktor
    /// </summary>
    Menu();
    /// <summary>
    /// zajmuje siê wyœwietleniem u¿ytkownikowi pocz¹tkowego interfejsu z wyborem iloœci punktów do zdobycia
    /// </summary>
    /// <param name="window">przekazywane jest jako parametr przez referencjê aktualnie u¿ywane okno</param>
    /// <param name="iloscPunktow">przez referencjê przekazywana jest iloœæ punktów do zdobycia, która w tej metodzie zostaje przez u¿ytkownika ustawiona</param>
    void wyswietl(sf::RenderWindow& window, int& iloscPunktow);
};
