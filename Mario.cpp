#include "Mario.h"

void Mario::przebieg() {
	sf::RenderWindow window(sf::VideoMode(1200, 700), "Zmodyfikowana wersja Mario");
	while (window.isOpen()) {
		Gra A;
		A.przebieg(window);
	}
}