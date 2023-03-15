#pragma once
#include "ConstantsAndIncludes.h"
/// <summary>
/// W klasie Tekstury polami s¹ wszystkie u¿ywane tekstury, w konstruktorze polom tej klasy wczytywane s¹ tekstury.
/// </summary>
class Tekstury {
public:
	sf::Texture mario_tekstura_prawa;
	sf::Texture mario_tekstura_lewa;
	sf::Texture podl_tekstura;
	sf::Texture moneta_tekstura;
	sf::Texture tlo_tekstura;
	sf::Texture strzal_poziomy_tekstura;
	sf::Texture strzal_pionowy_tekstura;
	sf::Texture strzelec_poziomy_tekstura;
	sf::Texture strzelec_pionowy_tekstura;
	sf::Texture bomba_tekstura;
	Tekstury();
};