#pragma once
#include "ConstantsAndIncludes.h"

/**
	Klasa umo¿liwiaj¹ca zapisanie pojedynczego rekordu.
*/
class Rekord {
	/// <summary>
	/// nazwa u¿ytkownika, jej podanie jest opcjonalne
	/// </summary>
	std::string nazwa;
	/// <summary>
	/// ca³kowity czas gry w sekundach
	/// </summary>
	long long czas;
	/// <summary>
	/// iloœæ zdobytych przez gracza punktów
	/// </summary>
	int zdobyte_punkty;
	/// <summary>
	/// cel punktów ustawiony przez gracza na samym pocz¹tku
	/// </summary>
	int punkty_do_zdobycia;
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	Rekord();
	/// <summary>
	/// Konstruktor z deklaracj¹ wszystkich elementów
	/// </summary>
	/// <param name="nazwa">nazwa u¿ytkownika, jej podanie jest opcjonalne</param>
	/// <param name="czas">ca³kowity czas gry w sekundach</param>
	/// <param name="zdobyte_punkty">iloœæ zdobytych przez gracza punktów</param>
	/// <param name="punkty_do_zdobycia">cel punktów ustawiony przez gracza na samym pocz¹tku</param>
	Rekord(std::string nazwa, long long czas, int zdobyte_punkty, int punkty_do_zdobycia);
	/// <summary>
	/// Metoda zwracaj¹ca nazwê
	/// </summary>
	/// <returns>nazwa</returns>
	std::string zwroc_nazwe();
	/// <summary>
	/// Metoda zwracaj¹ca czas gry w sekundach
	/// </summary>
	/// <returns>czas</returns>
	long long zwroc_czas();
	/// <summary>
	/// metoda zwracaj¹ca iloœæ zdobytych przez gracza punktów
	/// </summary>
	/// <returns>zdobyte_punkty</returns>
	int zwroc_zdobyte_punkty();
	/// <summary>
	/// metoda zwracaj¹ca cel punktów ustawiony przez gracza na samym pocz¹tku
	/// </summary>
	/// <returns>punkty_do_zdobycia</returns>
	int zwroc_punkty_do_zdobycia();
	friend bool operator<(const Rekord& l, const Rekord& p);
	friend bool operator>(const Rekord& l, const Rekord& p);
	friend std::ostream& operator<<(std::ostream& str, const Rekord& rekord);
	friend std::istream& operator>>(std::istream& str, Rekord& rekord);
};