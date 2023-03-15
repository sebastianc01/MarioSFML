#include "Plansza.h"

Plansza::Plansza() : koniec(false), skok(0), aktualna_ilosc_punktow(0), generowanie(false), iloscPunktow(5) {
	start = std::chrono::system_clock::now();
	aktualny = start;
	tabela.resize(wysokosc_planszy);
	for (int i = 0; i < wysokosc_planszy; ++i) {
		tabela.at(i).resize(dlugosc_planszy);
		std::fill(tabela.at(i).begin(), tabela.at(i).end(), pusta_przestrzen);
	} //rezerwowanie odpowiedniej iloœci miejsca oraz wype³nienie tablicy zerami
	czas_pion = std::chrono::high_resolution_clock::now();
	czas_poziom = std::chrono::high_resolution_clock::now();
}

void Plansza::wypelnienie_czesci_tablicy(std::mt19937& gen, const int poczatekp, const int koniecp) {
	std::normal_distribution<> nd{};
	double wartosc = nd(gen);
	for (int i = poczatekp; i <= koniecp; ++i) { //sprawdzamy caly przedzial, i to aktualna pozycja na planszy
		for (int k = 0; k < wysokosc_planszy; ++k) { //czyszczenie danego pola
			tabela.at(k).at(i) = pusta_przestrzen;
		}
		wartosc = nd(gen); //losowanie wartoœci, w zale¿nioœci od niej wygenerowane zostanie coœ innego
		wypelnienie_pola(wartosc, i);
	}
}

void Plansza::wypelnienie_pola(const double wartosc, const int pole) {
	for (int i = 0; i < wysokosc_planszy; ++i) {
		if (wypelnienie_mindlwys(i, pole)) tabela.at(i).at(pole) = podloga; //sprawdzenie, czy aktualna wyspa ma prawid³owy, minimalny rozmiar
	}

	if (wartosc > -1.1 && wartosc < 1.1) { //tworzymy droge na wysokosci drogi w polu poprzednim, w przypadku paru drog rowniez
		if (pole != 0) {
			for (int i = 0; i < wysokosc_planszy; ++i) {
				if (tabela.at(i).at(static_cast<std::vector<int, std::allocator<int>>::size_type>(pole) - 1) == podloga) tabela.at(i).at(pole) = podloga;
			}
		}
		else {
			for (int i = 0; i < wysokosc_planszy; ++i) {
				if (tabela.at(i).at(dlugosc_planszy - 1) == podloga) tabela.at(i).at(pole) = podloga; //w tym przypadku pole jest rowne 0, wiec sprawdzamy element ostatni
			}
		}
	}
	else if (wartosc > -1.7 && wartosc < 1.7) { //tworzenie platformy powy¿ej aktualnego punktu
		for (int i = 0; i < wysokosc_planszy; ++i) {
			if (stworzenie_wyspy(i, pole)) {
				if (i > skok_const + roznica_wysokosci_pomiedzy_wyspami + 1) tabela.at(static_cast<std::vector<std::vector<int, std::allocator<int>>, std::allocator<std::vector<int, std::allocator<int>>>>::size_type>(i) - roznica_wysokosci_pomiedzy_wyspami).at(pole) = podloga;
			}
		}
	}
	else if (wartosc > -2.6 && wartosc < 2.6) { //tworzenie platformy poni¿ej aktualnego punktu
		for (int i = 0; i < wysokosc_planszy; ++i) {
			if (stworzenie_wyspy(i, pole)) {
				if (i <= wysokosc_planszy - roznica_wysokosci_pomiedzy_wyspami - 1) {
					tabela.at(static_cast<std::vector<std::vector<int, std::allocator<int>>, std::allocator<std::vector<int, std::allocator<int>>>>::size_type>(i) + roznica_wysokosci_pomiedzy_wyspami).at(pole) = podloga;
				}
			}
		}
	}

	if (maksymalny_odstep(pole) == false) tabela.at(wysokosc_planszy - 1).at(pole) = podloga;

}


bool Plansza::wypelnienie_mindlwys(const int wysokosc, int pole) {
	if (tabela.at(wysokosc).at(przesuniecie(pole, -1)) != podloga) return false; //jeœli poprzednie pole nie zawiera pod³ogi, to nie ma czego sprawdzaæ
	--pole;
	for (int i = 0; i < minimalna_dlugosc_wyspy; ++i, --pole) { //sprawdzamy minimalna_dlugosc_wyspy - 1, bo jedna zosta³a sprawdzona ju¿ powy¿ej
		if (pole < 0) pole = dlugosc_planszy - 1; //jeœli wykroczyliœmy poza tablicê, to ustalamy jej wartoœæ na ostatni¹
		if (tabela.at(wysokosc).at(pole) != podloga) return true; //zwraca true gdy niewystarczajaco pol danej platformy jest wypelnionych
	}
	return false;
}

bool Plansza::stworzenie_wyspy(const int i, const int pole) {
	return ((tabela.at(i).at(przesuniecie(pole, -1)) == podloga && //sprawdzamy, czy cztery ostatnie pola nie s¹ pod³ogami
		tabela.at(i).at(przesuniecie(pole, -2)) == podloga &&
		tabela.at(i).at(przesuniecie(pole, -3)) == podloga &&
		tabela.at(i).at(przesuniecie(pole, -4)) == podloga)
		||
		(tabela.at(i).at(przesuniecie(pole, -1)) == pusta_przestrzen && //sprawdzamy, czy ostatnie pole nie jest puste, a trzy wczeœniejsze pola nie s¹ pod³ogami
			tabela.at(i).at(przesuniecie(pole, -2)) == podloga &&
			tabela.at(i).at(przesuniecie(pole, -3)) == podloga &&
			tabela.at(i).at(przesuniecie(pole, -4)) == podloga)
		||
		(tabela.at(i).at(przesuniecie(pole, -1)) == pusta_przestrzen && //sprawdzamy, czy dwa ostatnie pole nie jest puste, a dwa wczeœniejsze pola nie s¹ pod³ogami
			tabela.at(i).at(przesuniecie(pole, -2)) == pusta_przestrzen &&
			tabela.at(i).at(przesuniecie(pole, -3)) == podloga &&
			tabela.at(i).at(przesuniecie(pole, -4)) == podloga)
		);

}

bool Plansza::maksymalny_odstep(const int pole) {
	int t_pole; //przechowuje aktualnie sprawdzane pole
	for (int j = 0; j < wysokosc_planszy; ++j) {
		t_pole = pole - 1;
		for (int i = 0; i < maksymalny_odstep_const; ++i, --t_pole) {
			if (t_pole < 0) t_pole = dlugosc_planszy - 1;
			if (tabela.at(j).at(t_pole) == podloga) return true; //wystêpuje pod³oga
		}
	}
	return false; //nie ma pod³ogi na sprawdzonych polach
}

void Plansza::wypelnienie_poczatkowych_pol(std::mt19937& gen, const int poczatekp, const int koniecp) {
	for (int i = 0; i < bezpieczne_pola; ++i) {
		tabela.at(wysokosc_planszy - 1).at(i) = podloga; //wypelnienie ostatniego pola konkretnej komorki podloga
	}
	if (wysokosc_planszy > 3) {
		tabela.at(wysokosc_planszy - 3).at(0) = gora_gracza_p;
		tabela.at(wysokosc_planszy - 2).at(0) = dol_gracza_p;
		/*tabela.at(0).at(0) = gora_gracza_p;
		tabela.at(1).at(0) = dol_gracza_p;*/
	}
	else std::cout << "Zbyt mala wysokosc planszy";
	wypelnienie_czesci_tablicy(gen, bezpieczne_pola, 2 * dlugosc_planszy / 3 - 1);
}

void Plansza::Rysowanie_czesci_planszy(const int start, sf::RenderWindow& window, Tekstury& tekstury)
{
	sf::RectangleShape pole(sf::Vector2f(32.0f, 32.0f)); //kszta³t kwadratu 32.f x 32.0f
	pole.setOrigin(16.f, 16.0f);
	sf::RectangleShape bohater(sf::Vector2f(32.0f, 64.0f)); //kszta³t prostok¹ta 32.f x 64.0f
	bohater.setOrigin(16.f, 16.0f);
	for (int i = 0; i < wysokosc_planszy; ++i) {
		int p = 0; // wskazuje pole, pomocnicze do wyœwietlania tablicy
		for (int k = 0; k < ilosc_wyswietlonych_pol; ++k, ++p) {
			pole.setPosition(odstep_boczny + 16.0f + static_cast<float>(p) * 32.0f, odstep_gorny + 16.0f + 30.0f + static_cast<float>(i) * 32.0f);
			switch (tabela.at(i).at(przesuniecie(start, k))) {
			case pusta_przestrzen:
				pole.setTexture(&tekstury.tlo_tekstura);
				window.draw(pole);
				break;
			case podloga:
				pole.setTexture(&tekstury.podl_tekstura);
				window.draw(pole);
				break;
			case gora_gracza_l:
				pole.setTexture(&tekstury.tlo_tekstura);
				bohater.setPosition(odstep_boczny + 16.0f + static_cast<float>(p) * 32.0f, odstep_gorny + 16.0f + 30.0f + static_cast<float>(i) * 32.0f);
				bohater.setTexture(&tekstury.mario_tekstura_lewa);
				window.draw(pole);
				pole.setPosition(odstep_boczny + 16.0f + static_cast<float>(p) * 32.0f, odstep_gorny + 16.0f + 30.0f + static_cast<float>(i) * 32.0f + 32.0f); //+32.0f ¿eby dó³ Mario te¿ by³ na tle
				window.draw(pole);
				window.draw(bohater);
				break;
			case gora_gracza_p:
				pole.setTexture(&tekstury.tlo_tekstura);
				bohater.setPosition(odstep_boczny + 16.0f + static_cast<float>(p) * 32.0f, odstep_gorny + 16.0f + 30.0f + static_cast<float>(i) * 32.0f);
				bohater.setTexture(&tekstury.mario_tekstura_prawa);
				window.draw(pole);
				pole.setPosition(odstep_boczny + 16.0f + static_cast<float>(p) * 32.0f, odstep_gorny + 16.0f + 30.0f + static_cast<float>(i) * 32.0f + 32.0f); //+32.0f ¿eby dó³ Mario te¿ by³ na tle
				window.draw(pole);
				window.draw(bohater);
				break;
			case punkt:
				pole.setTexture(&tekstury.tlo_tekstura);
				window.draw(pole);
				pole.setTexture(&tekstury.moneta_tekstura);
				window.draw(pole);
				break;
			case strzelec_poziomy_g:
				pole.setTexture(&tekstury.tlo_tekstura);
				bohater.setPosition(odstep_boczny + 16.0f + static_cast<float>(p) * 32.0f, odstep_gorny + 16.0f + 30.0f + static_cast<float>(i) * 32.0f);
				bohater.setTexture(&tekstury.strzelec_poziomy_tekstura);
				window.draw(pole);
				pole.setPosition(odstep_boczny + 16.0f + static_cast<float>(p) * 32.0f, odstep_gorny + 16.0f + 30.0f + static_cast<float>(i) * 32.0f + 32.0f); //+32.0f ¿eby dó³ strzelca te¿ by³ na tle
				window.draw(pole);
				window.draw(bohater);
				break;
			case strzelec_pionowy_g:
				pole.setTexture(&tekstury.tlo_tekstura);
				bohater.setPosition(odstep_boczny + 16.0f + static_cast<float>(p) * 32.0f, odstep_gorny + 16.0f + 30.0f + static_cast<float>(i) * 32.0f);
				bohater.setTexture(&tekstury.strzelec_pionowy_tekstura);
				window.draw(pole);
				pole.setPosition(odstep_boczny + 16.0f + static_cast<float>(p) * 32.0f, odstep_gorny + 16.0f + 30.0f + static_cast<float>(i) * 32.0f + 32.0f); //+32.0f ¿eby dó³ strzelca te¿ by³ na tle
				window.draw(pole);
				window.draw(bohater);
				break;
			case strzal_pionowy:
				pole.setTexture(&tekstury.tlo_tekstura);
				window.draw(pole);
				pole.setTexture(&tekstury.strzal_pionowy_tekstura);
				window.draw(pole);
				break;
			case strzal_poziomy:
				pole.setTexture(&tekstury.tlo_tekstura);
				window.draw(pole);
				pole.setTexture(&tekstury.strzal_poziomy_tekstura);
				window.draw(pole);
				break;
			case bomba:
				pole.setTexture(&tekstury.tlo_tekstura);
				window.draw(pole);
				pole.setTexture(&tekstury.bomba_tekstura);
				window.draw(pole);
				break;
			}
		}
	}

	sf::Font ft;
	if (!ft.loadFromFile("Czcionki/FFF_Tusj.ttf"))
	{
		std::cout << "Nie udalo sie zaladowac czcionki.";
		window.close();
	}
	sf::Text aktualny_wynik_tekst;
	aktualny_wynik_tekst.setFont(ft);
	aktualny_wynik_tekst.setCharacterSize(20);
	aktualny_wynik_tekst.setFillColor(sf::Color{ 0xcd8500FF });
	aktualny_wynik_tekst.setString("Aktualny wynik:");
	sf::Text aktualny_wynik_liczba;
	aktualny_wynik_liczba.setFont(ft);
	aktualny_wynik_liczba.setCharacterSize(20);
	aktualny_wynik_liczba.setFillColor(sf::Color{ 0xcd8500FF });
	aktualny_wynik_liczba.setString(std::to_string(aktualna_ilosc_punktow));
	sf::Text calkowita_ilosc_punktow_tekst;
	calkowita_ilosc_punktow_tekst.setFont(ft);
	calkowita_ilosc_punktow_tekst.setCharacterSize(20);
	calkowita_ilosc_punktow_tekst.setFillColor(sf::Color{ 0xcd8500FF });
	calkowita_ilosc_punktow_tekst.setString("Do zdobycia:");
	sf::Text calkowita_ilosc_punktow_liczba;
	calkowita_ilosc_punktow_liczba.setFont(ft);
	calkowita_ilosc_punktow_liczba.setCharacterSize(20);
	calkowita_ilosc_punktow_liczba.setFillColor(sf::Color{ 0xcd8500FF });
	calkowita_ilosc_punktow_liczba.setString(std::to_string(iloscPunktow));
	sf::Text aktualny_czas_tekst;
	aktualny_czas_tekst.setFont(ft);
	aktualny_czas_tekst.setCharacterSize(20);
	aktualny_czas_tekst.setFillColor(sf::Color{ 0xcd8500FF });
	aktualny_czas_tekst.setString("Czas:");
	sf::Text aktualny_czas_liczba;
	aktualny_czas_liczba.setFont(ft);
	aktualny_czas_liczba.setCharacterSize(20);
	aktualny_czas_liczba.setFillColor(sf::Color{ 0xcd8500FF });
	std::chrono::time_point<std::chrono::system_clock> aktualny_czas = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = aktualny_czas - Plansza::start;
	std::chrono::hh_mm_ss<std::chrono::duration<double>> czas_w{ diff };
	std::stringstream tymczasowyss;
	std::string tymczasowys;
	tymczasowyss << czas_w;
	tymczasowyss >> tymczasowys;
	aktualny_czas_liczba.setString(tymczasowys);
	aktualny_wynik_tekst.setOrigin(aktualny_wynik_tekst.getGlobalBounds().width / 2, aktualny_wynik_tekst.getGlobalBounds().height / 2);
	aktualny_wynik_liczba.setOrigin(aktualny_wynik_liczba.getGlobalBounds().width / 2, aktualny_wynik_liczba.getGlobalBounds().height / 2);
	calkowita_ilosc_punktow_tekst.setOrigin(calkowita_ilosc_punktow_tekst.getGlobalBounds().width / 2, calkowita_ilosc_punktow_tekst.getGlobalBounds().height / 2);
	calkowita_ilosc_punktow_liczba.setOrigin(calkowita_ilosc_punktow_liczba.getGlobalBounds().width / 2, calkowita_ilosc_punktow_liczba.getGlobalBounds().height / 2);
	aktualny_czas_tekst.setOrigin(aktualny_czas_tekst.getGlobalBounds().width / 2, aktualny_czas_tekst.getGlobalBounds().height / 2);
	aktualny_czas_liczba.setOrigin(aktualny_czas_liczba.getGlobalBounds().width / 2, aktualny_czas_liczba.getGlobalBounds().height / 2);
	aktualny_wynik_tekst.setPosition(odstep_boczny + 82.0f, odstep_gorny + 12.5f);
	window.draw(aktualny_wynik_tekst);
	aktualny_wynik_liczba.setPosition(odstep_boczny + 200.0f, odstep_gorny + 12.5f);
	window.draw(aktualny_wynik_liczba);
	calkowita_ilosc_punktow_tekst.setPosition(odstep_boczny + 500.0f, odstep_gorny + 12.5f);
	window.draw(calkowita_ilosc_punktow_tekst);
	calkowita_ilosc_punktow_liczba.setPosition(odstep_boczny + 600.0f, odstep_gorny + 12.5f);
	window.draw(calkowita_ilosc_punktow_liczba);
	aktualny_czas_tekst.setPosition(odstep_boczny + 965.0f, odstep_gorny + 12.5f);
	window.draw(aktualny_czas_tekst);
	aktualny_czas_liczba.setPosition(odstep_boczny + 1070.0f, odstep_gorny + 12.5f);
	window.draw(aktualny_czas_liczba);
}

void Plansza::wykonanie_skoku(const int pierwsze_wyswietlane_pole) {
		if (skok == 0) {
			for (int i = 0; i < wysokosc_planszy - 1; ++i) { //na ostatnim polu i tak nie da siê wykonaæ skoku
			int pole = pierwsze_wyswietlane_pole;
			for (int k = 0; k < maksymalne_cofniecie_gracza + 1; ++k, pole = przesuniecie(pole, 1)) {
				if (tabela.at(i).at(pole) >= gracz_p && tabela.at(i).at(pole) <= gracz_k && //czy na aktualnie sprawdzanym polu jest gracz
					tabela.at(i).at(pole) % 2 == 1 && //szukamy dolnego pola gracza
					tabela.at(i + 1).at(pole) == podloga) {
					skok = skok_const;
					i = wysokosc_planszy;
					k = maksymalne_cofniecie_gracza + 1;
				}
			}
		}
	}
}

bool Plansza::sprawdzenie_pola(int i, int k) {

	if (tabela.at(i).at(k) == pusta_przestrzen)
		return true;
	else if (tabela.at(i).at(k) == podloga)
		return false;
	else if (tabela.at(i).at(k) >= gracz_p && tabela.at(i).at(k) <= gracz_k)
		return true;
	else if (tabela.at(i).at(k) == strzelec_pionowy_g ||
		tabela.at(i).at(k) == strzelec_poziomy_g) {
		if (i + 1 < wysokosc_planszy) usmierc_przeciwnika(tabela, k, i + 1);
		return true;
	}
	else if (tabela.at(i).at(k) == strzelec_pionowy_d ||
		tabela.at(i).at(k) == strzelec_poziomy_d) {
		usmierc_przeciwnika(tabela, k, i);
		return true;
	}
	else if (tabela.at(i).at(k) == bomba || tabela.at(i).at(k) == strzal_pionowy || tabela.at(i).at(k) == strzal_poziomy) {
		smierc(i, k);
		return false;
	}
	else if (tabela.at(i).at(k) == punkt) {
		++aktualna_ilosc_punktow;
		if (aktualna_ilosc_punktow == iloscPunktow) {
			koniec = true;
		}
		tabela.at(i).at(k) = pusta_przestrzen;
		return true;
	}
	else return false;
}

void Plansza::smierc(int i, int k) {
	koniec = true;
	//dodaæ animacjê œmierci
}

void Plansza::fizyka_postaci_pion(const int pierwsze_wyswietlane_pole) {
	std::chrono::time_point<std::chrono::high_resolution_clock> aktualny_czas = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = aktualny_czas - czas_pion;
	if (diff.count() >= static_cast<double>(minimalny_czas_pomiêdzy_ruchem_postaci_pion)) {
		for (int i = 0; i < wysokosc_planszy; ++i) {
			int pole = pierwsze_wyswietlane_pole;
			for (int k = 0; k < maksymalne_cofniecie_gracza + 1; ++k, pole = przesuniecie(pole, 1)) {
				if (tabela.at(i).at(pole) >= gracz_p && tabela.at(i).at(pole) <= gracz_k) { //czy na aktualnie sprawdzanym polu jest gracz
					if (skok > 0 && //sprawdzamy czy postaæ nie jest w trakcie skoku
						tabela.at(i).at(pole) % 2 == 0 && //szukamy górnego pola gracza
						i > 0 &&
						sprawdzenie_pola(i - 1, pole)) {
						std::swap(tabela.at(i).at(pole), tabela.at(i - 1).at(pole));
						std::swap(tabela.at(i).at(pole), tabela.at(i + 1).at(pole));
						--skok;
						i = wysokosc_planszy;
						k = maksymalne_cofniecie_gracza + 1;
						czas_pion = std::chrono::high_resolution_clock::now();
					}
					else if (tabela.at(i).at(pole) % 2 == 1 && //szukamy dolnego pola gracza
						skok == 0)//sprawdzamy czy postaæ nie jest w trakcie skoku
					{
						if (i < wysokosc_planszy - 1 && sprawdzenie_pola(i + 1, pole)) {
							std::swap(tabela.at(i).at(pole), tabela.at(i + 1).at(pole));
							std::swap(tabela.at(i).at(pole), tabela.at(i - 1).at(pole));
						}
						else if (i == wysokosc_planszy - 1) smierc(i, k);
						i = wysokosc_planszy;
						k = maksymalne_cofniecie_gracza + 1;
						czas_pion = std::chrono::high_resolution_clock::now();
					}
					else if (tabela.at(i).at(pole) % 2 == 1 && //szukamy dolnego pola gracza
						skok > 0 && // lub postaæ jest w trakcie skoku, lecz nie jest w stanie wzlecieæ
						i > 0 && !sprawdzenie_pola(i - 2, pole)) { //skok zostaje przerwany
						skok = 0;
						i = wysokosc_planszy;
						k = maksymalne_cofniecie_gracza + 1;
					}
				}
			}
		}
	}
}

bool Plansza::ruch_w_prawo(const int pierwsze_wyswietlane_pole) {
	std::chrono::time_point<std::chrono::high_resolution_clock> aktualny_czas = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = aktualny_czas - czas_poziom;
	if (diff.count() >= static_cast<double>(minimalny_czas_pomiêdzy_ruchem_postaci_poziom)) {
		for (int i = 0; i < wysokosc_planszy; ++i) {
			int pole = pierwsze_wyswietlane_pole;
			for (int k = 0; k < maksymalne_cofniecie_gracza + 2; ++k, pole = przesuniecie(pole, 1)) {
				if (tabela.at(i).at(pole) >= gracz_p && tabela.at(i).at(pole) <= gracz_k && //sprawdza czy znaleziona zosta³a postaæ
					tabela.at(i).at(pole) % 2 == 0 && //szukamy jej górnej czêœci
					i <= wysokosc_planszy - 2 && //czy postaæ znajduje siê w przeznaczonym do tego polu (poza nim i tak powinna zgin¹æ)
					sprawdzenie_pola(i, przesuniecie(pole, 1)) && //sprawdzenie czy pola na których ma siê znaleŸæ s¹ odpowiednie
					sprawdzenie_pola(i + 1, przesuniecie(pole, 1))) {
					tabela.at(i).at(pole) = pusta_przestrzen;
					tabela.at(i + 1).at(pole) = pusta_przestrzen;
					tabela.at(i).at(przesuniecie(pole, 1)) = gora_gracza_p;
					tabela.at(i + 1).at(przesuniecie(pole, 1)) = dol_gracza_p;
					czas_poziom = std::chrono::high_resolution_clock::now();
					return true;
				}
			}
		}
	}
	return false;
}

bool Plansza::ruch_w_lewo(const int pierwsze_wyswietlane_pole) {
	std::chrono::time_point<std::chrono::high_resolution_clock> aktualny_czas = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = aktualny_czas - czas_poziom;
	if (diff.count() >= static_cast<double>(minimalny_czas_pomiêdzy_ruchem_postaci_poziom)) {
		for (int i = 0; i < wysokosc_planszy; ++i) {
			int pole = pierwsze_wyswietlane_pole;
			for (int k = 0; k < maksymalne_cofniecie_gracza + 2; ++k, pole = przesuniecie(pole, 1)) {
				if (tabela.at(i).at(pole) >= gracz_p && tabela.at(i).at(pole) <= gracz_k &&
					tabela.at(i).at(pole) % 2 == 0 &&
					i <= wysokosc_planszy - 2 &&
					pole > pierwsze_wyswietlane_pole &&
					sprawdzenie_pola(i, przesuniecie(pole, -1)) &&
					sprawdzenie_pola(i + 1, przesuniecie(pole, -1))) {
					tabela.at(i).at(pole) = pusta_przestrzen;
					tabela.at(i + 1).at(pole) = pusta_przestrzen;
					tabela.at(i).at(przesuniecie(pole, -1)) = gora_gracza_l;
					tabela.at(i + 1).at(przesuniecie(pole, -1)) = dol_gracza_l;
					czas_poziom = std::chrono::high_resolution_clock::now();
					return true;
				}
			}
		}
	}
	return false;
}

bool Plansza::czy_postac_jest_w_danej_kolumnie(const int kolumna) {
	for (int i = 0; i < wysokosc_planszy; ++i) {
		if (tabela.at(i).at(kolumna) >= gracz_p && tabela.at(i).at(kolumna) <= gracz_k)
			return true;
	}
	return false;
}

void Plansza::wyswietlenie(sf::RenderWindow& window) {
	std::jthread generowanie_mapy;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::jthread watek_wypelnianie(&Plansza::wypelnienie_poczatkowych_pol, this, std::ref(gen), bezpieczne_pola, dlugosc_planszy / 2 - 1);
	int pierwsze_wyswietlane_pole = 0;
	Tekstury tekstury;
	watek_wypelnianie.join();
	start = std::chrono::system_clock::now();
	while (window.isOpen() && !koniec) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			wykonanie_skoku(pierwsze_wyswietlane_pole);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (ruch_w_prawo(pierwsze_wyswietlane_pole)) {
				if (czy_postac_jest_w_danej_kolumnie(przesuniecie(pierwsze_wyswietlane_pole, maksymalne_cofniecie_gracza))) {
					usun_ewentualne_potwory(pierwsze_wyswietlane_pole); //pierwsze wyœwietlane pole siê zwiêkszy, wiêc z dotychczasowego usuniête zostan¹ wszyscy przeciwnicy
					pierwsze_wyswietlane_pole = przesuniecie(pierwsze_wyswietlane_pole, 1);
					potencjalne_stworzenie_potworow(tabela, przesuniecie(pierwsze_wyswietlane_pole, ilosc_wyswietlonych_pol + zasieg_strzalu_poziomego / 2), gen);
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (!czy_postac_jest_w_danej_kolumnie(pierwsze_wyswietlane_pole)) {
				ruch_w_lewo(pierwsze_wyswietlane_pole);
			}
		}
		if (!generowanie) { //jeœli generowanie nie trwa, to rozpoczynamy je
			if (pierwsze_wyswietlane_pole == 0) {
				generowanie_mapy = std::jthread(&Plansza::wypelnienie_czesci_tablicy, this, std::ref(gen), dlugosc_planszy / 2, dlugosc_planszy - 1);
				generowanie = true;
			}
			else if (pierwsze_wyswietlane_pole == dlugosc_planszy / 2) {
				generowanie_mapy = std::jthread(&Plansza::wypelnienie_czesci_tablicy, this, std::ref(gen), 0, dlugosc_planszy / 2 - 1);
				generowanie = true;
			}
		}
		else {
			if (pierwsze_wyswietlane_pole == dlugosc_planszy - 1 - ilosc_wyswietlonych_pol - 1 ||
				pierwsze_wyswietlane_pole == dlugosc_planszy / 2 - 1 - ilosc_wyswietlonych_pol - 1) {
				generowanie_mapy.join();
				generowanie = false;
			}
		}
		fizyka_postaci_pion(pierwsze_wyswietlane_pole);
		wykonaj_ruchy_przeciwnikow(tabela, koniec, iloscPunktow);
		window.clear(sf::Color{ 0xC0C0C0F0 }); //wype³nienie ca³ej planszy szarym kolorem

		Rysowanie_czesci_planszy(pierwsze_wyswietlane_pole, window, tekstury);
		window.display();
	}
	aktualny = std::chrono::system_clock::now();
}
