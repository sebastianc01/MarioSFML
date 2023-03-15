#pragma once
#include "ConstantsAndIncludes.h"
#include "Ruchy.h"

/**
	Dziedziczy po klasie Postac. Jeœli zostanie stworzony obiekt klasy Bomba, to bêd¹ wykonywane zdefiniowane tutaj ruchy i œmieræ.
*/
class Bomba : public Postac {
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="x">po³o¿enie danego przeciwnika na osi x</param>
	/// <param name="y">po³o¿enie danego przeciwnika na osi y</param>
	/// <param name="tabela">jako referencja przekazywana jest ca³a tabela, poniewa¿ zostanie w niej umieszczony przeciwnik</param>
	Bomba(int x, int y, std::vector<std::vector<int>>& tabela); 
	/// <summary>
	/// Wykonany zostaje ruch odpowadaj¹cy Bombie.
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca³a tabela</param>
	/// <param name="koniec">referencja na pole typu bool, jeœli zajdzie taka potrzeba (strza³ dotknie gracza), to gra jest koñczona</param>
	/// <param name="iloscPunktow">ca³kowita iloœæ punktów do zdobycia</param>
	virtual void wykonaj_ruch(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow);
	/// <summary>
	/// Œmieræ Bomby, usuniêcie z planszy zajmowanych pól.
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca³a tabela</param>
	virtual void smierc(std::vector<std::vector<int>>& tabela); 
};

