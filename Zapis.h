#pragma once
#include "ConstantsAndIncludes.h"
#include "Rekord.h"
#include "Menu.h"
#include "Plansza.h"

/**
	Klasa zajmuj¹ca siê g³ównie etapem zapisu wyniku do pliku i wyœwietleniem rankingów.
*/
class Zapis {
protected:
	/// <summary>
	/// Zawiera informacjê, czy faza wyœwietlania rankingów zosta³a zakoñczona
	/// </summary>
	bool koniec_zapisu; 
	/// <summary>
	/// Konstruktor
	/// </summary>
	Zapis();
	/// <summary>
	/// Metoda sprawdzaj¹ca, czy wprowadzona nazwa gracza spe³nia narzucone wymagania, czyli zawiera tylko litery i cyfry.
	/// </summary>
	/// <param name="nazwa">przekazana jako referencja nazwa</param>
	/// <returns>zwracany zostaje wynik, jeœli nazwa spe³nia wymagania to zwrócona jest prawda, w przeciwnym przypadku fa³sz</returns>
	bool weryfikacja_nazwy(std::string& nazwa);
	/// <summary>
	/// Metoda odpowiadaj¹ca za umo¿liwienie u¿ytkownikowi decydowania oraz wyœwietlenie treœci.
	/// </summary>
	/// <param name="window">przekazywane jest jako parametr przez referencjê aktualnie u¿ywane okno</param>
	/// <param name="cel_punktow">przekazany zostaje ustawiony przez gracza cel punktów</param>
	/// <param name="uzyskane_punkty">przekazane zostaje ile punktów uda³o siê zdobyæ graczowi</param>
	/// <param name="start">czas rozpoczêcia gry</param>
	/// <param name="koniec">czas zakoñczenia gry</param>
	void wyswietl(sf::RenderWindow& window, const int cel_punktow, const int uzyskane_punkty, std::chrono::time_point<std::chrono::system_clock> start, std::chrono::time_point<std::chrono::system_clock> koniec);
};


