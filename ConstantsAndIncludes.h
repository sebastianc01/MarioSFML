#pragma once
#include <vector>
#include <algorithm>
#include <barrier>
#include <random>
#include <thread>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <list>
#include <windows.h>
#include <sstream>
#include <memory>
#include <regex>
#include <filesystem>
#include <ranges>
#include <fstream>


#define dlugosc_planszy 210 ///ca³kowita d³ugoœæ tablicy, liczba podzielna przez 3
#define wysokosc_planszy 16 ///wysokoœæ ka¿dego pola planszy
#define bezpieczne_pola 10 ///iloœæ pól na pocz¹tku planszy, na których gracz bêdzie bezpieczny, bez zagro¿eñ
#define maksymalny_odstep_const 4 ///maksymalna odleg³oœæ, na której mo¿e nie byæ pod³ogi na planszy
#define minimalna_dlugosc_wyspy 5 ///minimalna d³ugoœæ wygenerowanych wysp
#define roznica_wysokosci_pomiedzy_wyspami 3 ///podczas generowania planszy ró¿nica wysokoœci na planszy bêdzie wynosiæ podan¹ wartoœæ
#define skok_const 4 ///wysokoœæ na jak¹ podskakuje postaæ
#define ilosc_wyswietlonych_pol 35 ///ile pól zostanie w wyœwietlonych na tablicy, zawsze mniejsze od dlugosc_planszy / 3
#define odstep_gorny 30.0f ///odstêp pomiêdzy gór¹ okna a wyœwietlan¹ plansz¹
#define odstep_boczny 30.0f ///odstêp pomiêdzy lewym bokiem okna a wyœwietlan¹ plansz¹
#define minimalny_czas_przesuniecia_strzalu 0.3 ///minimalny czas, który up³ynie pomiêdzy przesuniêciem siê strza³u przeciwnika (w s), jest on mno¿ony przez 3 oraz dzielony przez iloœæ punktów do zdobycia
#define minimalny_czas_pomiêdzy_ruchem_postaci_pion 0.06 ///w s
#define minimalny_czas_pomiêdzy_ruchem_postaci_poziom 0.09 ///w s
#define zasieg_strzalu_pionowego 5 ///wysokoœæ na jak¹ strzalaæ bêdzie strzelec pionowy
#define zasieg_strzalu_poziomego 6 ///zasiêg na jaki strzalaæ bêdzie strzelec poziomy
#define maksymalne_cofniecie_gracza 5 ///o ile pól gracz mo¿e cofn¹æ siê do ty³u, z uwagi na to, ¿e mapa jest na bie¿¹co generowana

//wszystkie wartosci z ktorych moze skladac sie plansza
#define podloga 1
#define gracz_p 10 ///pocz¹tek przedzia³u, w zale¿noœci od niego bêdzie przedstawiona inna tekstura gracza
#define gracz_k 13 ///koniec przedzia³u, w zale¿noœci od niego bêdzie przedstawiona inna tekstura gracza
#define pusta_przestrzen 0
#define gora_gracza_p 10 ///góra gracza jest zawsze parzysta
#define dol_gracza_p 11 //dó³ gracza, niezale¿nie od tekstury, musi byæ nieparzysty
#define gora_gracza_l 12
#define dol_gracza_l 13
#define punkt 2
#define strzelec_poziomy_g 20
#define strzelec_poziomy_d 21
#define strzal_poziomy 22
#define strzelec_pionowy_g 23
#define strzelec_pionowy_d 24
#define strzal_pionowy 25
#define bomba 26

///ile punktów to poszczególny tryb trudnoœci
#define latwy_punkty 5
#define sredni_punkty 12
#define trudny_punkty 25