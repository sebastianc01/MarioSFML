#include "Gra.h"

Gra::Gra() {}

void Gra::przebieg(sf::RenderWindow& window) {
    Menu::wyswietl(window, Plansza::iloscPunktow);
    Plansza::wyswietlenie(window);
    Zapis::wyswietl(window, iloscPunktow, aktualna_ilosc_punktow, start, aktualny);
}