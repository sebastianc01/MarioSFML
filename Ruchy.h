#pragma once
#include "ConstantsAndIncludes.h"

/**
	Zawiera dwie metody czysto wirtualne, jest dziedziczona przez wszystkie potwory umieszczone w grze.
	O ka¿dym stworzonym potworze musimy przechowywaæ pewne istotne informacje, wiêc odpowiednie, s³u¿¹ce temu pola znajduj¹ siê w³aœnie w tej klasie.
	@param czas czas pojawienia siê na mapie danego przeciwnika, bêdzie od niego zale¿eæ czas strza³u
	@param x po³o¿enie danego przeciwnika na osi x
	@param y po³o¿enie danego przeciwnika na osi y
*/
class Postac {
protected:
	/// <summary>
	/// czas pojawienia siê na mapie danego przeciwnika, bêdzie od niego zale¿eæ czas strza³u
	/// </summary>
	std::chrono::time_point<std::chrono::high_resolution_clock> czas; 
	/// <summary>
	/// po³o¿enie danego przeciwnika na osi x
	/// </summary>
	int x; 
	/// <summary>
	/// po³o¿enie danego przeciwnika na osi y
	/// </summary>
	int y; 
	/// <summary>
	///Sprawdza czy potencjalny strza³ mo¿e zostaæ wykonany, w przypadku napotkania gracza przerwa równie¿ grê
	/// </summary>
	/// <param name="wartosc_pola">przekazywana jest wartoœæ sprawdzanego pola planszy, nie ma potrzeby przekazywania jej ca³ej, poniewa¿ i tak sprawdzany bêdzie pojedynczy element</param>
	/// <param name="koniec">referencja na pole typu bool, jeœli zajdzie taka potrzeba (strza³ dotknie gracza), to gra jest koñczona</param>
	/// <returns>Zwracana jest informacja, czy potencjalny strza³ mo¿e zostaæ wykonany</returns>
	bool sprawdzenie_pola(int wartosc_pola, bool& koniec);
	/// <summary>
	/// Konstruktor, przypisuje danemu przeciwnikowi wspó³rzêdne oraz czas stworzenia
	/// </summary>
	/// <param name="x">po³o¿enie danego przeciwnika na osi x</param>
	/// <param name="y">po³o¿enie danego przeciwnika na osi y</param>
	Postac(int x, int y);
	/// <summary>
	/// Metoda zwracaj¹ca wspó³rzêdn¹ x
	/// </summary>
	/// <returns>x</returns>
	int zwroc_x() const;
	/// <summary>
	/// Metoda zwracaj¹ca wspó³rzêdn¹ y
	/// </summary>
	/// <returns>y</returns>
	int zwroc_y() const;
	/// <summary>
	/// Metoda czysto wirtualna, wykonywany bêdzie ruch zale¿ny od tego, z jakim przeciwnikiem mamy do czynienia
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca³a tabela</param>
	/// <param name="koniec">referencja na pole typu bool, jeœli zajdzie taka potrzeba (strza³ dotknie gracza), to gra jest koñczona</param>
	/// <param name="iloscPunktow">ca³kowita iloœæ punktów do zdobycia</param>
	virtual void wykonaj_ruch(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow) = 0;
	/// <summary>
	/// Metoda czysto wirtualna, wp³yw œmierci przeciwnika na grê jest zale¿ny od tego, z jakim przeciwnikiem mamy do czynienia
	/// </summary>
	/// <param name="tabela"></param>
	virtual void smierc(std::vector<std::vector<int>>& tabela) = 0;
	/// <summary>
	/// W klasie Przeciwnicy znajduje siê lista zawieraj¹ca wszystkich aktualnie znajduj¹cych siê na planszy przeciwników.
	/// </summary>
	friend class Przeciwnicy;
};

