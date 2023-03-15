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


#define dlugosc_planszy 210 ///ca�kowita d�ugo�� tablicy, liczba podzielna przez 3
#define wysokosc_planszy 16 ///wysoko�� ka�dego pola planszy
#define bezpieczne_pola 10 ///ilo�� p�l na pocz�tku planszy, na kt�rych gracz b�dzie bezpieczny, bez zagro�e�
#define maksymalny_odstep_const 4 ///maksymalna odleg�o��, na kt�rej mo�e nie by� pod�ogi na planszy
#define minimalna_dlugosc_wyspy 5 ///minimalna d�ugo�� wygenerowanych wysp
#define roznica_wysokosci_pomiedzy_wyspami 3 ///podczas generowania planszy r�nica wysoko�ci na planszy b�dzie wynosi� podan� warto��
#define skok_const 4 ///wysoko�� na jak� podskakuje posta�
#define ilosc_wyswietlonych_pol 35 ///ile p�l zostanie w wy�wietlonych na tablicy, zawsze mniejsze od dlugosc_planszy / 3
#define odstep_gorny 30.0f ///odst�p pomi�dzy g�r� okna a wy�wietlan� plansz�
#define odstep_boczny 30.0f ///odst�p pomi�dzy lewym bokiem okna a wy�wietlan� plansz�
#define minimalny_czas_przesuniecia_strzalu 0.3 ///minimalny czas, kt�ry up�ynie pomi�dzy przesuni�ciem si� strza�u przeciwnika (w s), jest on mno�ony przez 3 oraz dzielony przez ilo�� punkt�w do zdobycia
#define minimalny_czas_pomi�dzy_ruchem_postaci_pion 0.06 ///w s
#define minimalny_czas_pomi�dzy_ruchem_postaci_poziom 0.09 ///w s
#define zasieg_strzalu_pionowego 5 ///wysoko�� na jak� strzala� b�dzie strzelec pionowy
#define zasieg_strzalu_poziomego 6 ///zasi�g na jaki strzala� b�dzie strzelec poziomy
#define maksymalne_cofniecie_gracza 5 ///o ile p�l gracz mo�e cofn�� si� do ty�u, z uwagi na to, �e mapa jest na bie��co generowana

//wszystkie wartosci z ktorych moze skladac sie plansza
#define podloga 1
#define gracz_p 10 ///pocz�tek przedzia�u, w zale�no�ci od niego b�dzie przedstawiona inna tekstura gracza
#define gracz_k 13 ///koniec przedzia�u, w zale�no�ci od niego b�dzie przedstawiona inna tekstura gracza
#define pusta_przestrzen 0
#define gora_gracza_p 10 ///g�ra gracza jest zawsze parzysta
#define dol_gracza_p 11 //d� gracza, niezale�nie od tekstury, musi by� nieparzysty
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

///ile punkt�w to poszczeg�lny tryb trudno�ci
#define latwy_punkty 5
#define sredni_punkty 12
#define trudny_punkty 25