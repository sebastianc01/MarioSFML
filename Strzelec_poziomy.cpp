#include "Strzelec_poziomy.h"
#include "StrukturyIFunkcje.h"

Strzelec_poziomy::Strzelec_poziomy(int x, int y, std::vector<std::vector<int>>& tabela) : Postac(x, y) {
	if (y - 1 >= 0) {
		tabela.at(y - static_cast<int>(1)).at(x) = strzelec_poziomy_g;
		tabela.at(y).at(x) = strzelec_poziomy_d;
	}
}

void Strzelec_poziomy::wykonaj_ruch(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow) {
	if (tabela.at(y).at(x) == strzelec_poziomy_d) { //przeciwnik wci¹¿ ¿yje
		std::chrono::time_point<std::chrono::high_resolution_clock> aktualny_czas = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = aktualny_czas - czas;
		if (diff.count() >= static_cast<double>(minimalny_czas_przesuniecia_strzalu) * 8 / iloscPunktow) {
			czas = std::chrono::high_resolution_clock::now();
			bool wystepuje = false; //czy strza³ jest w trakcie lotu
			for (int i = 1; i <= zasieg_strzalu_poziomego; ++i) {
				if (y - 1 >= 0 && tabela.at(y - 1).at(przesuniecie(x, -i)) == strzal_poziomy) {
					if (i < zasieg_strzalu_poziomego && y - 1 >= 0 && sprawdzenie_pola(tabela.at(y - 1).at(przesuniecie(x, -i - 1)), koniec)) {
						std::swap(tabela.at(y - 1).at(przesuniecie(x, -i)), tabela.at(y - 1).at(przesuniecie(x, -i - 1)));
					}
					else {
						tabela.at(y - 1).at(przesuniecie(x, -i)) = pusta_przestrzen;
					}
					i = zasieg_strzalu_poziomego;
					wystepuje = true;
				}
			}
			if (!wystepuje && y - 1 >= 0 && tabela.at(y - 1).at(przesuniecie(x, -1)) == pusta_przestrzen) {
				tabela.at(y - 1).at(przesuniecie(x, -1)) = strzal_poziomy;
			}
		}
	}
}
void Strzelec_poziomy::smierc(std::vector<std::vector<int>>& tabela) {
	if (y - 1 >= 0) {
		tabela.at(y - 1).at(x) = pusta_przestrzen;
		tabela.at(y).at(x) = pusta_przestrzen;
		for (int i = 1; i <= zasieg_strzalu_poziomego; ++i) { //usuniêcie istniej¹cych strza³ów w przypadku œmierci przeciwnika
			if (tabela.at(y - 1).at(przesuniecie(x, -i)) == strzal_poziomy) {
				tabela.at(y - 1).at(przesuniecie(x, -i)) = pusta_przestrzen;
				i = zasieg_strzalu_poziomego + 1;
			}
		}
	}
}