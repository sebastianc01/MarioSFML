#include "Przeciwnicy.h"

//void Przeciwnicy::dodaj_potwora(std::unique_ptr<Postac> przeciwnik) {
//	//potwory.push_back(std::move(przeciwnik));
//}


void Przeciwnicy::usun_ewentualne_potwory(int x) {
	while (!potwory.empty() && (*potwory.front()).zwroc_x() == x) { //bierzemy pod uwagê sytuacjê gdy na danym polu znajduje siê paru przeciwników
		potwory.front() = nullptr; //ustawianie wskaŸnika na nullptr, zwolnienie pamiêci
		potwory.pop_front(); //usuniêcie pierwszego elementu
	}
}

void Przeciwnicy::wykonaj_ruchy_przeciwnikow(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow) {
	for (std::list<std::unique_ptr<Postac>>::iterator it = potwory.begin(); it != potwory.end(); ++it) {
		(**it).wykonaj_ruch(tabela, koniec, iloscPunktow);
	}
}

void Przeciwnicy::potencjalne_stworzenie_potworow(std::vector<std::vector<int>>& tabela, int x, std::mt19937& gen) {
	std::uniform_int_distribution<> uid(1, 200);
	for (int i = 0; i < wysokosc_planszy; ++i) {
		if (tabela.at(i).at(x) == podloga && i - 1 >= 0 && tabela.at(i - 1).at(x) == pusta_przestrzen) {
			int wartosc = uid(gen);
			if (wartosc > 194) { ///stworzenie Strzelca pionowego
				potwory.push_back(std::make_unique<Strzelec_pionowy>(x, i - 1, tabela));
			}
			else if (wartosc > 188) { ///stworzenie Strzelca poziomego
				potwory.push_back(std::make_unique<Strzelec_poziomy>(x, i - 1, tabela));
			}
			else if (wartosc >= 184 && tabela.at(i).at(przesuniecie(x, -1)) == podloga) { ///stworzenie Bomby
				potwory.push_back(std::make_unique<Bomba>(x, i - 1, tabela));
			}
			else if (wartosc > 166 && wartosc < 170) { ///umieszczenie monety
				tabela.at(i - 1).at(x) = punkt;
			}
		}
	}
}

void Przeciwnicy::usmierc_przeciwnika(std::vector<std::vector<int>>& tabela, int x, int y) {
	for (std::list<std::unique_ptr<Postac>>::iterator it = potwory.begin(); it != potwory.end(); ++it) {
		if ((**it).zwroc_x() == x && (**it).zwroc_y() == y) {
			(**it).smierc(tabela);
		}
	}
}

Przeciwnicy::Przeciwnicy() {}

Przeciwnicy::~Przeciwnicy() {
	while (!potwory.empty()) { //zwalnia zajêt¹ pamiêæ, bez usuwania ich z planszy
		potwory.pop_front();
	}
}