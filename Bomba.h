#pragma once
#include "ConstantsAndIncludes.h"
#include "Ruchy.h"

/**
	Dziedziczy po klasie Postac. Je�li zostanie stworzony obiekt klasy Bomba, to b�d� wykonywane zdefiniowane tutaj ruchy i �mier�.
*/
class Bomba : public Postac {
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="x">po�o�enie danego przeciwnika na osi x</param>
	/// <param name="y">po�o�enie danego przeciwnika na osi y</param>
	/// <param name="tabela">jako referencja przekazywana jest ca�a tabela, poniewa� zostanie w niej umieszczony przeciwnik</param>
	Bomba(int x, int y, std::vector<std::vector<int>>& tabela); 
	/// <summary>
	/// Wykonany zostaje ruch odpowadaj�cy Bombie.
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca�a tabela</param>
	/// <param name="koniec">referencja na pole typu bool, je�li zajdzie taka potrzeba (strza� dotknie gracza), to gra jest ko�czona</param>
	/// <param name="iloscPunktow">ca�kowita ilo�� punkt�w do zdobycia</param>
	virtual void wykonaj_ruch(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow);
	/// <summary>
	/// �mier� Bomby, usuni�cie z planszy zajmowanych p�l.
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca�a tabela</param>
	virtual void smierc(std::vector<std::vector<int>>& tabela); 
};

