#pragma once
#include "ConstantsAndIncludes.h"
#include "StrukturyIFunkcje.h"
#include "Przeciwnicy.h"
#include "Menu.h"
#include "Tekstury.h"
/**
	Klasa odpowiadaj�ca g��wnie za zarz�dzanie plansz� i jej wy�wietlanie, jak i umo�liwienie sterowania graczowi.
*/
class Plansza : public Przeciwnicy {
	/// <summary>
	/// tablica dwuwymiarowa integer�w, to w niej przechowywany jest aktualny stan planszy zawieraj�cy potwory, gracza i strza�y, pod�og�, t�o i monety.
	/// </summary>
	std::vector<std::vector<int>> tabela;
	/// <summary>
	/// gdy gracz przejdzie na konkretne pola (ich po�o�enie jest zale�ne od ustawionej d�ugo�ci planszy) to rozpoczyna si� generowanie fragmentu (1/2) planszy,
	/// jednak gracz mo�e sta� na tym polu d�u�ej i �eby zapobiec uruchamianiu wi�kszej ilo�ci w�tk�w fakt odbywaj�cej si� generacji jest zawarty tutaj.
	/// </summary>
	bool generowanie;
	/// <summary>
	/// przechowuje informacje o tym, czy etap faktycznej gry zosta� zako�czony
	/// </summary>
	bool koniec;
	/// <summary>
	/// standardowo ustawiona na 0, gdy u�ytkownik naci�nie klawisz skoku zmieniona zostaje na ilo�� p�l, na kt�r� podskoczy posta� z miejsca obecnego
	/// </summary>
	int skok;
	/// <summary>
	/// czas minimalny, kt�ry musi min�� do kolejnego ruchu w pionie
	/// </summary>
	std::chrono::time_point<std::chrono::high_resolution_clock> czas_pion;
	/// <summary>
	/// czas minimalny, kt�ry musi min�� do kolejnego ruchu w poziomie
	/// </summary>
	std::chrono::time_point<std::chrono::high_resolution_clock> czas_poziom;
	/// <summary>
	/// metoda zajmuj�ca si� wype�nieniem konkretnego pola tablicy
	/// </summary>
	/// <param name="wartosc">warto�� "losowa" od kt�rej zale�e� b�dzie generowany element</param>
	/// <param name="pole">wsp�rz�dna x planszy</param>
	void wypelnienie_pola(const double wartosc, const int pole);
	/// <summary>
	/// metoda sprawdzaj�ca, czy wszystkie pod�ogi na poprzednim polu maj� ju� wystarczaj�c� d�ugo��, je�li nie to wyspa zostaje przed�u�ona
	/// </summary>
	/// <param name="wysokosc">sprawdzana wysoko��</param>
	/// <param name="pole">aktualna wsp�rz�dna x</param>
	/// <returns>warto�� true oznacza przed�u�enie wyspy</returns>
	bool wypelnienie_mindlwys(const int wysokosc, int pole);
	/// <summary>
	/// sprawdzanie jest, czy spe�niony jest warunek wygenerowania wyspy, czyli po prostu czy na poprzednich polach by�a wystarczaj�ca ilo�� pod��g
	/// </summary>
	/// <param name="i">wysoko��</param>
	/// <param name="pole">aktualna wsp�rz�dna x</param>
	/// <returns>warto�� true oznacza mo�liwo�� stworzenia wyspy</returns>
	bool stworzenie_wyspy(const int i, const int pole);
	/// <summary>
	/// sprawdzenie, czy nie wyst�puje zbyt du�a ilo�� pustych p�l bez pod��g
	/// </summary>
	/// <param name="pole">aktualna wsp�rz�dna x</param>
	/// <returns>warto�� true oznacza, �e wyst�powa�a pod�oga na sprawdzonych polach. W przypadku false tworzona jest pod�uga na samym dole planszy (pozycja y: wysokosc_planszy - 1)</returns>
	bool maksymalny_odstep(const int pole);
	/// <summary>
	/// wykonanie skoku, przypisuje warto�� polu skok
	/// </summary>
	/// <param name="pierwsze_wyswietlane_pole">pierwsze wyswietlane pole, gracz zawsze znajduje si� pomi�dzy nim lub par� p�l dalej (ich ilo�� znajduje si� w pliku ConstantsAndIncludes.h i jest modyfikowalna)</param>
	void wykonanie_skoku(const int pierwsze_wyswietlane_pole);
	/// <summary>
	/// sprawdzenie pola na kt�re b�dzie wchodzi� gracz
	/// </summary>
	/// <param name="i">wysoko��</param>
	/// <param name="k">aktualna wsp�rz�dna x</param>
	/// <returns>warto�� true oznacza, �e nie ma przeciwwskaza� do wykonania ruchu</returns>
	bool sprawdzenie_pola(int i, int k);
	/// <summary>
	/// gracz poni�s� kl�sk�
	/// </summary>
	/// <param name="i">wysoko��</param>
	/// <param name="k">aktualna wsp�rz�dna x</param>
	void smierc(int i, int k);
	/// <summary>
	/// fizyka postaci (gracza) w pionie
	/// </summary>
	/// <param name="pierwsze_wyswietlane_pole">pierwsze wyswietlane pole, gracz zawsze znajduje si� pomi�dzy nim lub par� p�l dalej (ich ilo�� znajduje si� w pliku ConstantsAndIncludes.h i jest modyfikowalna)</param>
	void fizyka_postaci_pion(const int pierwsze_wyswietlane_pole);
	/// <summary>
	/// posta� zostaje przesuni�ta w prawo (je�li jest taka mo�liwo��)
	/// </summary>
	/// <param name="pierwsze_wyswietlane_pole">pierwsze wyswietlane pole, gracz zawsze znajduje si� pomi�dzy nim lub par� p�l dalej (ich ilo�� znajduje si� w pliku ConstantsAndIncludes.h i jest modyfikowalna)</param>
	/// <returns>zwraca warto�� true je�li uda�o si� wykona� ruch, w przeciwnym przypadku false</returns>
	bool ruch_w_prawo(const int pierwsze_wyswietlane_pole);
	/// <summary>
	/// sprawdzenie, czy posta� znajduje si� w danej kolumnie
	/// </summary>
	/// <param name="kolumna">wsp�rz�dna x</param>
	/// <returns>zwraca true je�li gracz znajduje si� w przekazanej jako argument kolumnie, w przeciwnym przypadku false</returns>
	bool czy_postac_jest_w_danej_kolumnie(const int kolumna);
	/// <summary>
	/// posta� zostaje przesuni�ta w lewo (je�li jest taka mo�liwo��)
	/// </summary>
	/// <param name="pierwsze_wyswietlane_pole">pierwsze wyswietlane pole, gracz zawsze znajduje si� pomi�dzy nim lub par� p�l dalej (ich ilo�� znajduje si� w pliku ConstantsAndIncludes.h i jest modyfikowalna)</param>
	/// <returns>zwraca warto�� true je�li uda�o si� wykona� ruch, w przeciwnym przypadku false</returns>
	bool ruch_w_lewo(const int pierwsze_wyswietlane_pole);
protected:
	/// <summary>
	/// przechowuje ca�kowit� ilo�� punkt�w do zdobycia
	/// </summary>
	int iloscPunktow;
	/// <summary>
	/// przechowuje czas startu gry
	/// </summary>
	std::chrono::time_point<std::chrono::system_clock> start;
	/// <summary>
	/// u�ywany pomocniczo w celu odczytania czasu w konkretnym momencie trwania, aktualnie tylko na ko�cu, lecz w przysz�o�ci najprawdopodobniej b�dzie mia� r�wnie� inne zastosowania
	/// </summary>
	std::chrono::time_point<std::chrono::system_clock> aktualny;
	/// <summary>
	/// przechowuje aktualn� ilo�� punkt�w zebran� przez gracza
	/// </summary>
	int aktualna_ilosc_punktow;
	/// <summary>
	/// Konstruktor
	/// </summary>
	Plansza();
	/// <summary>
	/// metoda zajmuj�ca si� wype�nieniem cz�ci tablicy
	/// </summary>
	/// <param name="gen">przekazany przez referencj� generator</param>
	/// <param name="poczatekp">wsp�rz�dna x, od niej zacznie si� generowanie planszy</param>
	/// <param name="koniecp">wsp�rz�dna x, na niej zako�czy si� generowanie planszy</param>
	void wypelnienie_czesci_tablicy(std::mt19937& gen, const int poczatekp, const int koniecp);
	/// <summary>
	/// wype�nienie pod�ogami okre�lonej liczby p�l (bezpieczne_pola) by na samym pocz�tku na gracza nie czyha�y �adne niebezpiecze�stwa
	/// </summary>
	/// <param name="gen">przekazany przez referencj� generator</param>
	/// <param name="poczatekp">wsp�rz�dna x, od niej zacznie si� generowanie planszy</param>
	/// <param name="koniecp">wsp�rz�dna x, na niej zako�czy si� generowanie planszy</param>
	void wypelnienie_poczatkowych_pol(std::mt19937& gen, const int poczatekp, const int koniecp);
	/// <summary>
	/// metoda zajmuj�ca si� wy�wietleniem aktualnego stanu planszy
	/// </summary>
	/// <param name="start">wsp�rz�dna x, od niej zacznie si� wy�wietlanie planszy</param>
	/// <param name="window">przekazywane jest jako parametr aktualnie u�ywane okno</param>
	/// <param name="tekstury">referencja do obiektu przechowuj�cego wszystkie dost�pne tekstury</param>
	void Rysowanie_czesci_planszy(const int start, sf::RenderWindow& window, Tekstury& tekstury);
	/// <summary>
	/// g��wna metoda klasy, zajmuje si� sterowaniem i koordynowaniem ca�ego przebiegu gry
	/// </summary>
	/// <param name="window">przekazywane jest jako parametr aktualnie u�ywane okno</param>
	void wyswietlenie(sf::RenderWindow& window);
};