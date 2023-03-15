#pragma once
#include "ConstantsAndIncludes.h"

/**
	Klasa umo�liwiaj�ca zapisanie pojedynczego rekordu.
*/
class Rekord {
	/// <summary>
	/// nazwa u�ytkownika, jej podanie jest opcjonalne
	/// </summary>
	std::string nazwa;
	/// <summary>
	/// ca�kowity czas gry w sekundach
	/// </summary>
	long long czas;
	/// <summary>
	/// ilo�� zdobytych przez gracza punkt�w
	/// </summary>
	int zdobyte_punkty;
	/// <summary>
	/// cel punkt�w ustawiony przez gracza na samym pocz�tku
	/// </summary>
	int punkty_do_zdobycia;
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	Rekord();
	/// <summary>
	/// Konstruktor z deklaracj� wszystkich element�w
	/// </summary>
	/// <param name="nazwa">nazwa u�ytkownika, jej podanie jest opcjonalne</param>
	/// <param name="czas">ca�kowity czas gry w sekundach</param>
	/// <param name="zdobyte_punkty">ilo�� zdobytych przez gracza punkt�w</param>
	/// <param name="punkty_do_zdobycia">cel punkt�w ustawiony przez gracza na samym pocz�tku</param>
	Rekord(std::string nazwa, long long czas, int zdobyte_punkty, int punkty_do_zdobycia);
	/// <summary>
	/// Metoda zwracaj�ca nazw�
	/// </summary>
	/// <returns>nazwa</returns>
	std::string zwroc_nazwe();
	/// <summary>
	/// Metoda zwracaj�ca czas gry w sekundach
	/// </summary>
	/// <returns>czas</returns>
	long long zwroc_czas();
	/// <summary>
	/// metoda zwracaj�ca ilo�� zdobytych przez gracza punkt�w
	/// </summary>
	/// <returns>zdobyte_punkty</returns>
	int zwroc_zdobyte_punkty();
	/// <summary>
	/// metoda zwracaj�ca cel punkt�w ustawiony przez gracza na samym pocz�tku
	/// </summary>
	/// <returns>punkty_do_zdobycia</returns>
	int zwroc_punkty_do_zdobycia();
	friend bool operator<(const Rekord& l, const Rekord& p);
	friend bool operator>(const Rekord& l, const Rekord& p);
	friend std::ostream& operator<<(std::ostream& str, const Rekord& rekord);
	friend std::istream& operator>>(std::istream& str, Rekord& rekord);
};