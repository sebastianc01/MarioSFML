#pragma once
#include "ConstantsAndIncludes.h"
#include "Menu.h"
#include "Plansza.h"
#include "Zapis.h"
#include "Mario.h"
/**
    Klasa Gra odpowiada za z�o�enie trzech kluczowych fragment�w gry.
    Dziedziczy klasy Menu, Plansza i Zapis.
    Menu pozwala na wybranie ilo�ci punkt�w do zdobycia.
    W klasie Plansza znajduje si� przebieg gry.
    Natomiast Zapis odpowiada za zapis rezultatu gry.
*/
class Gra :public Menu, public Plansza, public Zapis {
protected:
    /// <summary>
    /// Konstruktor
    /// </summary>
    Gra(); 
    /// <summary>
    /// metoda realizuj�ca przebieg ca�ej gry
    /// </summary>
    /// <param name="window">przekazywane jest jako parametr aktualnie u�ywane okno</param>
    void przebieg(sf::RenderWindow& window); 
    /// <summary>
    /// Klasa jest wykorzystywana w klasie Mario, ma to na celu mo�liwo�� ponownej gry bez konieczno�ci ponownego uruchamiania programu
    /// </summary>
    friend class Mario;
};