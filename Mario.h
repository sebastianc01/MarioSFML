#pragma once
#include "Gra.h"

/**
	Klasa umo¿liwiaj¹ca zagranie od pocz¹tku bez potrzeby ponownego w³¹czania programu.
*/
class Mario {
public:
	/// <summary>
	/// tworzone zostaje okno. Nastêpnie w pêtli, dopóki okno jest otwarte tworzony zostaje obiekt klasy Gra i wywo³ywana jej metoda "przebieg".
	/// </summary>
	void przebieg();
};