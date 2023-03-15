#pragma once
#include "ConstantsAndIncludes.h"
#include "Ruchy.h"

/**
	Dziedziczy po klasie Postac. Je�li zostanie stworzony obiekt klasy Strzelec_pionowy, to b�d� wykonywane zdefiniowane tutaj ruchy i �mier�.
*/
class Strzelec_pionowy : public Postac {
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="x">po�o�enie danego przeciwnika na osi x</param>
	/// <param name="y">po�o�enie danego przeciwnika na osi y</param>
	/// <param name="tabela">jako referencja przekazywana jest ca�a tabela, poniewa� zostanie w niej umieszczony przeciwnik</param>
	Strzelec_pionowy(int x, int y, std::vector<std::vector<int>>& tabela);
	/// <summary>
	/// Wykonany zostaje ruch odpowadaj�cy Strzelcowi pionowemu.
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca�a tabela</param>
	/// <param name="koniec">referencja na pole typu bool, je�li zajdzie taka potrzeba (strza� dotknie gracza), to gra jest ko�czona</param>
	/// <param name="iloscPunktow">ca�kowita ilo�� punkt�w do zdobycia</param>
	virtual void wykonaj_ruch(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow);
	/// <summary>
	/// �mier� Strzelca pionowego, usuni�cie z planszy zajmowanych p�l oraz strza�u znajduj�cego si� w locie.
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca�a tabela</param>
	virtual void smierc(std::vector<std::vector<int>>& tabela);
};

