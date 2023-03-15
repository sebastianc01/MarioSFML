#pragma once
#include "ConstantsAndIncludes.h"
#include "Bomba.h"
#include "Strzelec_pionowy.h"
#include "Strzelec_poziomy.h"
#include "Ruchy.h"
#include "StrukturyIFunkcje.h"

/**
	Klasa umo¿liwiaj¹ca dodanie nowych przeciwników, w jej polu jest lista zawieraj¹ca wszystkich aktualnych przeciwników.
	Po uœmierceniu danego przeciwnika znajduje siê on dalej w liœcie, zostaje usuniêty dopiero w chwili, gdy pole przez niego zajmowane stanie siê niewidoczne dla gracza.
*/
class Przeciwnicy {
	/// <summary>
	/// potwory w liscie umieszczane s¹ po kolei, w zale¿noœci od po³o¿enia x
	/// </summary>
	std::list<std::unique_ptr<Postac>> potwory;
protected:
	/// <summary>
	/// Konstruktor
	/// </summary>
	Przeciwnicy();
	/// <summary>
	/// Destruktor zwalniaj¹cy ca³¹ zajêt¹ przez listê pamiêæ
	/// </summary>
	~Przeciwnicy();
	/// <summary>
	/// po staniêciu na jakimœ polu zajmowanym przez przeciwnika znika on z planszy wraz ze swoimi strza³ami
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca³a tabela</param>
	/// <param name="x">po³o¿enie danego przeciwnika na osi x</param>
	/// <param name="y">po³o¿enie danego przeciwnika na osi y</param>
	void usmierc_przeciwnika(std::vector<std::vector<int>>& tabela, int x, int y);
	/// <summary>
	/// usuwa z listy wszystkie potwory znajduj¹ce siê na danym polu x
	/// </summary>
	/// <param name="x">wspó³rzêdna x</param>
	void usun_ewentualne_potwory(int x);
	/// <summary>
	/// wykonanie ruchów wszystkich przeciwników znajduj¹cych siê na liœcie
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca³a tabela</param>
	/// <param name="koniec">referencja na pole typu bool, jeœli zajdzie taka potrzeba (strza³ dotknie gracza), to gra jest koñczona</param>
	/// <param name="iloscPunktow">ca³kowita iloœæ punktów do zdobycia</param>
	void wykonaj_ruchy_przeciwnikow(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow);
	/// <summary>
	/// Na przekazanej jako argument pozycji x szuka pod³óg, czyli potencjalnych miejsc na stworzenie przeciwników lub monety.
	/// Gdy pod³oga zostanie znaleziona, to jest szansa na stworzenie tam przeciwnika lub postawienia monety, w zale¿noœci od "wylosowanej" wartoœci.
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca³a tabela</param>
	/// <param name="x">wspó³rzêdna x</param>
	/// <param name="gen">przekazany przez referencjê generator</param>
	void potencjalne_stworzenie_potworow(std::vector<std::vector<int>>& tabela, int x, std::mt19937& gen);
};
