#include "Bomba.h"

Bomba::Bomba(int x, int y, std::vector<std::vector<int>>& tabela) : Postac(x, y) {
	tabela.at(y).at(x) = bomba;
}

void Bomba::wykonaj_ruch(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow) {}

void Bomba::smierc(std::vector<std::vector<int>>& tabela) {
	tabela.at(y).at(x) = pusta_przestrzen;
}