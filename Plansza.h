#pragma once
#include "ConstantsAndIncludes.h"
#include "StrukturyIFunkcje.h"
#include "Przeciwnicy.h"
#include "Menu.h"
#include "Tekstury.h"
/**
	Klasa odpowiadaj¹ca g³ównie za zarz¹dzanie plansz¹ i jej wyœwietlanie, jak i umo¿liwienie sterowania graczowi.
*/
class Plansza : public Przeciwnicy {
	/// <summary>
	/// tablica dwuwymiarowa integerów, to w niej przechowywany jest aktualny stan planszy zawieraj¹cy potwory, gracza i strza³y, pod³ogê, t³o i monety.
	/// </summary>
	std::vector<std::vector<int>> tabela;
	/// <summary>
	/// gdy gracz przejdzie na konkretne pola (ich po³o¿enie jest zale¿ne od ustawionej d³ugoœci planszy) to rozpoczyna siê generowanie fragmentu (1/2) planszy,
	/// jednak gracz mo¿e staæ na tym polu d³u¿ej i ¿eby zapobiec uruchamianiu wiêkszej iloœci w¹tków fakt odbywaj¹cej siê generacji jest zawarty tutaj.
	/// </summary>
	bool generowanie;
	/// <summary>
	/// przechowuje informacje o tym, czy etap faktycznej gry zosta³ zakoñczony
	/// </summary>
	bool koniec;
	/// <summary>
	/// standardowo ustawiona na 0, gdy u¿ytkownik naciœnie klawisz skoku zmieniona zostaje na iloœæ pól, na któr¹ podskoczy postaæ z miejsca obecnego
	/// </summary>
	int skok;
	/// <summary>
	/// czas minimalny, który musi min¹æ do kolejnego ruchu w pionie
	/// </summary>
	std::chrono::time_point<std::chrono::high_resolution_clock> czas_pion;
	/// <summary>
	/// czas minimalny, który musi min¹æ do kolejnego ruchu w poziomie
	/// </summary>
	std::chrono::time_point<std::chrono::high_resolution_clock> czas_poziom;
	/// <summary>
	/// metoda zajmuj¹ca siê wype³nieniem konkretnego pola tablicy
	/// </summary>
	/// <param name="wartosc">wartoœæ "losowa" od której zale¿eæ bêdzie generowany element</param>
	/// <param name="pole">wspó³rzêdna x planszy</param>
	void wypelnienie_pola(const double wartosc, const int pole);
	/// <summary>
	/// metoda sprawdzaj¹ca, czy wszystkie pod³ogi na poprzednim polu maj¹ ju¿ wystarczaj¹c¹ d³ugoœæ, jeœli nie to wyspa zostaje przed³u¿ona
	/// </summary>
	/// <param name="wysokosc">sprawdzana wysokoœæ</param>
	/// <param name="pole">aktualna wspó³rzêdna x</param>
	/// <returns>wartoœæ true oznacza przed³u¿enie wyspy</returns>
	bool wypelnienie_mindlwys(const int wysokosc, int pole);
	/// <summary>
	/// sprawdzanie jest, czy spe³niony jest warunek wygenerowania wyspy, czyli po prostu czy na poprzednich polach by³a wystarczaj¹ca iloœæ pod³óg
	/// </summary>
	/// <param name="i">wysokoœæ</param>
	/// <param name="pole">aktualna wspó³rzêdna x</param>
	/// <returns>wartoœæ true oznacza mo¿liwoœæ stworzenia wyspy</returns>
	bool stworzenie_wyspy(const int i, const int pole);
	/// <summary>
	/// sprawdzenie, czy nie wystêpuje zbyt du¿a iloœæ pustych pól bez pod³óg
	/// </summary>
	/// <param name="pole">aktualna wspó³rzêdna x</param>
	/// <returns>wartoœæ true oznacza, ¿e wystêpowa³a pod³oga na sprawdzonych polach. W przypadku false tworzona jest pod³uga na samym dole planszy (pozycja y: wysokosc_planszy - 1)</returns>
	bool maksymalny_odstep(const int pole);
	/// <summary>
	/// wykonanie skoku, przypisuje wartoœæ polu skok
	/// </summary>
	/// <param name="pierwsze_wyswietlane_pole">pierwsze wyswietlane pole, gracz zawsze znajduje siê pomiêdzy nim lub parê pól dalej (ich iloœæ znajduje siê w pliku ConstantsAndIncludes.h i jest modyfikowalna)</param>
	void wykonanie_skoku(const int pierwsze_wyswietlane_pole);
	/// <summary>
	/// sprawdzenie pola na które bêdzie wchodzi³ gracz
	/// </summary>
	/// <param name="i">wysokoœæ</param>
	/// <param name="k">aktualna wspó³rzêdna x</param>
	/// <returns>wartoœæ true oznacza, ¿e nie ma przeciwwskazañ do wykonania ruchu</returns>
	bool sprawdzenie_pola(int i, int k);
	/// <summary>
	/// gracz poniós³ klêskê
	/// </summary>
	/// <param name="i">wysokoœæ</param>
	/// <param name="k">aktualna wspó³rzêdna x</param>
	void smierc(int i, int k);
	/// <summary>
	/// fizyka postaci (gracza) w pionie
	/// </summary>
	/// <param name="pierwsze_wyswietlane_pole">pierwsze wyswietlane pole, gracz zawsze znajduje siê pomiêdzy nim lub parê pól dalej (ich iloœæ znajduje siê w pliku ConstantsAndIncludes.h i jest modyfikowalna)</param>
	void fizyka_postaci_pion(const int pierwsze_wyswietlane_pole);
	/// <summary>
	/// postaæ zostaje przesuniêta w prawo (jeœli jest taka mo¿liwoœæ)
	/// </summary>
	/// <param name="pierwsze_wyswietlane_pole">pierwsze wyswietlane pole, gracz zawsze znajduje siê pomiêdzy nim lub parê pól dalej (ich iloœæ znajduje siê w pliku ConstantsAndIncludes.h i jest modyfikowalna)</param>
	/// <returns>zwraca wartoœæ true jeœli uda³o siê wykonaæ ruch, w przeciwnym przypadku false</returns>
	bool ruch_w_prawo(const int pierwsze_wyswietlane_pole);
	/// <summary>
	/// sprawdzenie, czy postaæ znajduje siê w danej kolumnie
	/// </summary>
	/// <param name="kolumna">wspó³rzêdna x</param>
	/// <returns>zwraca true jeœli gracz znajduje siê w przekazanej jako argument kolumnie, w przeciwnym przypadku false</returns>
	bool czy_postac_jest_w_danej_kolumnie(const int kolumna);
	/// <summary>
	/// postaæ zostaje przesuniêta w lewo (jeœli jest taka mo¿liwoœæ)
	/// </summary>
	/// <param name="pierwsze_wyswietlane_pole">pierwsze wyswietlane pole, gracz zawsze znajduje siê pomiêdzy nim lub parê pól dalej (ich iloœæ znajduje siê w pliku ConstantsAndIncludes.h i jest modyfikowalna)</param>
	/// <returns>zwraca wartoœæ true jeœli uda³o siê wykonaæ ruch, w przeciwnym przypadku false</returns>
	bool ruch_w_lewo(const int pierwsze_wyswietlane_pole);
protected:
	/// <summary>
	/// przechowuje ca³kowit¹ iloœæ punktów do zdobycia
	/// </summary>
	int iloscPunktow;
	/// <summary>
	/// przechowuje czas startu gry
	/// </summary>
	std::chrono::time_point<std::chrono::system_clock> start;
	/// <summary>
	/// u¿ywany pomocniczo w celu odczytania czasu w konkretnym momencie trwania, aktualnie tylko na koñcu, lecz w przysz³oœci najprawdopodobniej bêdzie mia³ równie¿ inne zastosowania
	/// </summary>
	std::chrono::time_point<std::chrono::system_clock> aktualny;
	/// <summary>
	/// przechowuje aktualn¹ iloœæ punktów zebran¹ przez gracza
	/// </summary>
	int aktualna_ilosc_punktow;
	/// <summary>
	/// Konstruktor
	/// </summary>
	Plansza();
	/// <summary>
	/// metoda zajmuj¹ca siê wype³nieniem czêœci tablicy
	/// </summary>
	/// <param name="gen">przekazany przez referencjê generator</param>
	/// <param name="poczatekp">wspó³rzêdna x, od niej zacznie siê generowanie planszy</param>
	/// <param name="koniecp">wspó³rzêdna x, na niej zakoñczy siê generowanie planszy</param>
	void wypelnienie_czesci_tablicy(std::mt19937& gen, const int poczatekp, const int koniecp);
	/// <summary>
	/// wype³nienie pod³ogami okreœlonej liczby pól (bezpieczne_pola) by na samym pocz¹tku na gracza nie czyha³y ¿adne niebezpieczeñstwa
	/// </summary>
	/// <param name="gen">przekazany przez referencjê generator</param>
	/// <param name="poczatekp">wspó³rzêdna x, od niej zacznie siê generowanie planszy</param>
	/// <param name="koniecp">wspó³rzêdna x, na niej zakoñczy siê generowanie planszy</param>
	void wypelnienie_poczatkowych_pol(std::mt19937& gen, const int poczatekp, const int koniecp);
	/// <summary>
	/// metoda zajmuj¹ca siê wyœwietleniem aktualnego stanu planszy
	/// </summary>
	/// <param name="start">wspó³rzêdna x, od niej zacznie siê wyœwietlanie planszy</param>
	/// <param name="window">przekazywane jest jako parametr aktualnie u¿ywane okno</param>
	/// <param name="tekstury">referencja do obiektu przechowuj¹cego wszystkie dostêpne tekstury</param>
	void Rysowanie_czesci_planszy(const int start, sf::RenderWindow& window, Tekstury& tekstury);
	/// <summary>
	/// g³ówna metoda klasy, zajmuje siê sterowaniem i koordynowaniem ca³ego przebiegu gry
	/// </summary>
	/// <param name="window">przekazywane jest jako parametr aktualnie u¿ywane okno</param>
	void wyswietlenie(sf::RenderWindow& window);
};