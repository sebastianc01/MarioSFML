#include "Strzelec_pionowy.h"
#include "StrukturyIFunkcje.h"

Strzelec_pionowy::Strzelec_pionowy(int x, int y, std::vector<std::vector<int>>& tabela) : Postac(x, y) {
	if (y - 1 >= 0) {
		tabela.at(y - 1).at(x) = strzelec_pionowy_g;
		tabela.at(y).at(x) = strzelec_pionowy_d;
	}
}

void Strzelec_pionowy::wykonaj_ruch(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow) {
	if (tabela.at(y).at(x) == strzelec_pionowy_d) { //przeciwnik wci¹¿ ¿yje
		std::chrono::time_point<std::chrono::high_resolution_clock> aktualny_czas = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = aktualny_czas - czas;
		if (diff.count() >= static_cast<double>(minimalny_czas_przesuniecia_strzalu) * 8 / iloscPunktow) {
			czas = std::chrono::high_resolution_clock::now();
			bool wystepuje = false; //czy strza³ jest w trakcie lotu
			for (int i = 1; i <= zasieg_strzalu_pionowego; ++i) {
				if (y - 1 - i >= 0 && tabela.at(y - 1 - i).at(x) == strzal_pionowy) {
					if (i < zasieg_strzalu_pionowego && y - 1 - i - 1 >= 0 && sprawdzenie_pola(tabela.at(y - 1 - i - 1).at(x), koniec)) {
						std::swap(tabela.at(y - 1 - i).at(x), tabela.at(y - 1 - i - 1).at(x));
					}
					else {
						tabela.at(y - 1 - i).at(x) = pusta_przestrzen;
					}
					i = zasieg_strzalu_pionowego;
					wystepuje = true;
				}
			}
			if (!wystepuje && y - 2 >= 0 && tabela.at(y - 2).at(x) == pusta_przestrzen) {
				tabela.at(y - 2).at(x) = strzal_pionowy;
			}
		}
	}
}

void Strzelec_pionowy::smierc(std::vector<std::vector<int>>& tabela) {
	if (y - 1 >= 0) {
		tabela.at(y - 1).at(x) = pusta_przestrzen;
		tabela.at(y).at(x) = pusta_przestrzen;
	}
	for (int i = 1; i <= zasieg_strzalu_pionowego; ++i) { //usuniêcie istniej¹cych strza³ów w przypadku œmierci przeciwnika
		if (y - 1 - i >= 0 && tabela.at(y - 1 - i).at(x) == strzal_pionowy) {
			tabela.at(y - 1 - i).at(x) = pusta_przestrzen;
			i = zasieg_strzalu_poziomego + 1;
		}
	}
}