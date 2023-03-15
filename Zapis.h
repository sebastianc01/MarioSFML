#pragma once
#include "ConstantsAndIncludes.h"
#include "Rekord.h"
#include "Menu.h"
#include "Plansza.h"

/**
	Klasa zajmuj�ca si� g��wnie etapem zapisu wyniku do pliku i wy�wietleniem ranking�w.
*/
class Zapis {
protected:
	/// <summary>
	/// Zawiera informacj�, czy faza wy�wietlania ranking�w zosta�a zako�czona
	/// </summary>
	bool koniec_zapisu; 
	/// <summary>
	/// Konstruktor
	/// </summary>
	Zapis();
	/// <summary>
	/// Metoda sprawdzaj�ca, czy wprowadzona nazwa gracza spe�nia narzucone wymagania, czyli zawiera tylko litery i cyfry.
	/// </summary>
	/// <param name="nazwa">przekazana jako referencja nazwa</param>
	/// <returns>zwracany zostaje wynik, je�li nazwa spe�nia wymagania to zwr�cona jest prawda, w przeciwnym przypadku fa�sz</returns>
	bool weryfikacja_nazwy(std::string& nazwa);
	/// <summary>
	/// Metoda odpowiadaj�ca za umo�liwienie u�ytkownikowi decydowania oraz wy�wietlenie tre�ci.
	/// </summary>
	/// <param name="window">przekazywane jest jako parametr przez referencj� aktualnie u�ywane okno</param>
	/// <param name="cel_punktow">przekazany zostaje ustawiony przez gracza cel punkt�w</param>
	/// <param name="uzyskane_punkty">przekazane zostaje ile punkt�w uda�o si� zdoby� graczowi</param>
	/// <param name="start">czas rozpocz�cia gry</param>
	/// <param name="koniec">czas zako�czenia gry</param>
	void wyswietl(sf::RenderWindow& window, const int cel_punktow, const int uzyskane_punkty, std::chrono::time_point<std::chrono::system_clock> start, std::chrono::time_point<std::chrono::system_clock> koniec);
};


