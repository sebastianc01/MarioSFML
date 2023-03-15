#include "Ruchy.h"

int Postac::zwroc_x() const {
	return x;
}

int Postac::zwroc_y() const {
	return y;
}

Postac::Postac(int x, int y){
	this->x = x;
	this->y = y;
	czas = std::chrono::high_resolution_clock::now();
}

bool Postac::sprawdzenie_pola(int wartosc_pola, bool& koniec) {
	if (wartosc_pola == pusta_przestrzen)
		return true;
	else if (wartosc_pola >= gracz_p && wartosc_pola <= gracz_k) {
		koniec = true;
		return false;
	}
	else if (wartosc_pola == strzal_pionowy || wartosc_pola == strzal_poziomy)
		return true;
	else
		return false;
}