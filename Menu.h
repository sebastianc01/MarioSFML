#pragma once
#include "ConstantsAndIncludes.h"

/**
    Klasa zajmuj�ca si� wy�wietleniem u�ytkownikowi pocz�tkowego interfejsu z wyborem ilo�ci punkt�w do zdobycia.
*/
class Menu {
protected:
    /// <summary>
    /// Konstruktor
    /// </summary>
    Menu();
    /// <summary>
    /// zajmuje si� wy�wietleniem u�ytkownikowi pocz�tkowego interfejsu z wyborem ilo�ci punkt�w do zdobycia
    /// </summary>
    /// <param name="window">przekazywane jest jako parametr przez referencj� aktualnie u�ywane okno</param>
    /// <param name="iloscPunktow">przez referencj� przekazywana jest ilo�� punkt�w do zdobycia, kt�ra w tej metodzie zostaje przez u�ytkownika ustawiona</param>
    void wyswietl(sf::RenderWindow& window, int& iloscPunktow);
};
