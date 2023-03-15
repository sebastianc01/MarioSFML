#pragma once
#include "ConstantsAndIncludes.h"

/**
	Zawiera dwie metody czysto wirtualne, jest dziedziczona przez wszystkie potwory umieszczone w grze.
	O ka�dym stworzonym potworze musimy przechowywa� pewne istotne informacje, wi�c odpowiednie, s�u��ce temu pola znajduj� si� w�a�nie w tej klasie.
	@param czas czas pojawienia si� na mapie danego przeciwnika, b�dzie od niego zale�e� czas strza�u
	@param x po�o�enie danego przeciwnika na osi x
	@param y po�o�enie danego przeciwnika na osi y
*/
class Postac {
protected:
	/// <summary>
	/// czas pojawienia si� na mapie danego przeciwnika, b�dzie od niego zale�e� czas strza�u
	/// </summary>
	std::chrono::time_point<std::chrono::high_resolution_clock> czas; 
	/// <summary>
	/// po�o�enie danego przeciwnika na osi x
	/// </summary>
	int x; 
	/// <summary>
	/// po�o�enie danego przeciwnika na osi y
	/// </summary>
	int y; 
	/// <summary>
	///Sprawdza czy potencjalny strza� mo�e zosta� wykonany, w przypadku napotkania gracza przerwa r�wnie� gr�
	/// </summary>
	/// <param name="wartosc_pola">przekazywana jest warto�� sprawdzanego pola planszy, nie ma potrzeby przekazywania jej ca�ej, poniewa� i tak sprawdzany b�dzie pojedynczy element</param>
	/// <param name="koniec">referencja na pole typu bool, je�li zajdzie taka potrzeba (strza� dotknie gracza), to gra jest ko�czona</param>
	/// <returns>Zwracana jest informacja, czy potencjalny strza� mo�e zosta� wykonany</returns>
	bool sprawdzenie_pola(int wartosc_pola, bool& koniec);
	/// <summary>
	/// Konstruktor, przypisuje danemu przeciwnikowi wsp�rz�dne oraz czas stworzenia
	/// </summary>
	/// <param name="x">po�o�enie danego przeciwnika na osi x</param>
	/// <param name="y">po�o�enie danego przeciwnika na osi y</param>
	Postac(int x, int y);
	/// <summary>
	/// Metoda zwracaj�ca wsp�rz�dn� x
	/// </summary>
	/// <returns>x</returns>
	int zwroc_x() const;
	/// <summary>
	/// Metoda zwracaj�ca wsp�rz�dn� y
	/// </summary>
	/// <returns>y</returns>
	int zwroc_y() const;
	/// <summary>
	/// Metoda czysto wirtualna, wykonywany b�dzie ruch zale�ny od tego, z jakim przeciwnikiem mamy do czynienia
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca�a tabela</param>
	/// <param name="koniec">referencja na pole typu bool, je�li zajdzie taka potrzeba (strza� dotknie gracza), to gra jest ko�czona</param>
	/// <param name="iloscPunktow">ca�kowita ilo�� punkt�w do zdobycia</param>
	virtual void wykonaj_ruch(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow) = 0;
	/// <summary>
	/// Metoda czysto wirtualna, wp�yw �mierci przeciwnika na gr� jest zale�ny od tego, z jakim przeciwnikiem mamy do czynienia
	/// </summary>
	/// <param name="tabela"></param>
	virtual void smierc(std::vector<std::vector<int>>& tabela) = 0;
	/// <summary>
	/// W klasie Przeciwnicy znajduje si� lista zawieraj�ca wszystkich aktualnie znajduj�cych si� na planszy przeciwnik�w.
	/// </summary>
	friend class Przeciwnicy;
};

