#pragma once
#include "Gra.h"

/**
	Klasa umo�liwiaj�ca zagranie od pocz�tku bez potrzeby ponownego w��czania programu.
*/
class Mario {
public:
	/// <summary>
	/// tworzone zostaje okno. Nast�pnie w p�tli, dop�ki okno jest otwarte tworzony zostaje obiekt klasy Gra i wywo�ywana jej metoda "przebieg".
	/// </summary>
	void przebieg();
};