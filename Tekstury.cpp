#include "Tekstury.h"

Tekstury::Tekstury() {
	if (!mario_tekstura_prawa.loadFromFile("Tekstury/mario_right8.png")) {
		std::cout << "Nie udalo sie zaladowac tekstury prawej Mario.";
	}
	if (!mario_tekstura_lewa.loadFromFile("Tekstury/mario_left8.png")) {
		std::cout << "Nie udalo sie zaladowac tekstury lewej Mario.";
	}
	if (!podl_tekstura.loadFromFile("Tekstury/block1.png")) {
		std::cout << "Nie udalo sie zaladowac tekstury podlogi.";
	}
	if (!moneta_tekstura.loadFromFile("Tekstury/coin6.png")) {
		std::cout << "Nie udalo sie zaladowac tekstury monety.";
	}
	if (!tlo_tekstura.loadFromFile("Tekstury/block16.png")) {
		std::cout << "Nie udalo sie zaladowac tekstury tla.";
	}
	if (!strzal_poziomy_tekstura.loadFromFile("Tekstury/fire_rocket1_poz.png")) {
		std::cout << "Nie udalo sie zaladowac tekstury tla.";
	}
	if (!strzal_pionowy_tekstura.loadFromFile("Tekstury/fire_rocket1_pio.png")) {
		std::cout << "Nie udalo sie zaladowac tekstury tla.";
	}
	if (!strzelec_poziomy_tekstura.loadFromFile("Tekstury/red_turtle6.png")) {
		std::cout << "Nie udalo sie zaladowac tekstury tla.";
	}
	if (!strzelec_pionowy_tekstura.loadFromFile("Tekstury/red_turtle5.png")) {
		std::cout << "Nie udalo sie zaladowac tekstury tla.";
	}
	if (!bomba_tekstura.loadFromFile("Tekstury/fire_bomb.png")) {
		std::cout << "Nie udalo sie zaladowac tekstury tla.";
	}
}