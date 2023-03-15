#pragma once
#include "ConstantsAndIncludes.h"
#include "Menu.h"
#include "Plansza.h"
#include "Zapis.h"
#include "Mario.h"
/**
    Klasa Gra odpowiada za z³o¿enie trzech kluczowych fragmentów gry.
    Dziedziczy klasy Menu, Plansza i Zapis.
    Menu pozwala na wybranie iloœci punktów do zdobycia.
    W klasie Plansza znajduje siê przebieg gry.
    Natomiast Zapis odpowiada za zapis rezultatu gry.
*/
class Gra :public Menu, public Plansza, public Zapis {
protected:
    /// <summary>
    /// Konstruktor
    /// </summary>
    Gra(); 
    /// <summary>
    /// metoda realizuj¹ca przebieg ca³ej gry
    /// </summary>
    /// <param name="window">przekazywane jest jako parametr aktualnie u¿ywane okno</param>
    void przebieg(sf::RenderWindow& window); 
    /// <summary>
    /// Klasa jest wykorzystywana w klasie Mario, ma to na celu mo¿liwoœæ ponownej gry bez koniecznoœci ponownego uruchamiania programu
    /// </summary>
    friend class Mario;
};