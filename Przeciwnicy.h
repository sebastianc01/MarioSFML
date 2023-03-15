#pragma once
#include "ConstantsAndIncludes.h"
#include "Bomba.h"
#include "Strzelec_pionowy.h"
#include "Strzelec_poziomy.h"
#include "Ruchy.h"
#include "StrukturyIFunkcje.h"

/**
	Klasa umo�liwiaj�ca dodanie nowych przeciwnik�w, w jej polu jest lista zawieraj�ca wszystkich aktualnych przeciwnik�w.
	Po u�mierceniu danego przeciwnika znajduje si� on dalej w li�cie, zostaje usuni�ty dopiero w chwili, gdy pole przez niego zajmowane stanie si� niewidoczne dla gracza.
*/
class Przeciwnicy {
	/// <summary>
	/// potwory w liscie umieszczane s� po kolei, w zale�no�ci od po�o�enia x
	/// </summary>
	std::list<std::unique_ptr<Postac>> potwory;
protected:
	/// <summary>
	/// Konstruktor
	/// </summary>
	Przeciwnicy();
	/// <summary>
	/// Destruktor zwalniaj�cy ca�� zaj�t� przez list� pami��
	/// </summary>
	~Przeciwnicy();
	/// <summary>
	/// po stani�ciu na jakim� polu zajmowanym przez przeciwnika znika on z planszy wraz ze swoimi strza�ami
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca�a tabela</param>
	/// <param name="x">po�o�enie danego przeciwnika na osi x</param>
	/// <param name="y">po�o�enie danego przeciwnika na osi y</param>
	void usmierc_przeciwnika(std::vector<std::vector<int>>& tabela, int x, int y);
	/// <summary>
	/// usuwa z listy wszystkie potwory znajduj�ce si� na danym polu x
	/// </summary>
	/// <param name="x">wsp�rz�dna x</param>
	void usun_ewentualne_potwory(int x);
	/// <summary>
	/// wykonanie ruch�w wszystkich przeciwnik�w znajduj�cych si� na li�cie
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca�a tabela</param>
	/// <param name="koniec">referencja na pole typu bool, je�li zajdzie taka potrzeba (strza� dotknie gracza), to gra jest ko�czona</param>
	/// <param name="iloscPunktow">ca�kowita ilo�� punkt�w do zdobycia</param>
	void wykonaj_ruchy_przeciwnikow(std::vector<std::vector<int>>& tabela, bool& koniec, const int iloscPunktow);
	/// <summary>
	/// Na przekazanej jako argument pozycji x szuka pod��g, czyli potencjalnych miejsc na stworzenie przeciwnik�w lub monety.
	/// Gdy pod�oga zostanie znaleziona, to jest szansa na stworzenie tam przeciwnika lub postawienia monety, w zale�no�ci od "wylosowanej" warto�ci.
	/// </summary>
	/// <param name="tabela">jako referencja przekazywana jest ca�a tabela</param>
	/// <param name="x">wsp�rz�dna x</param>
	/// <param name="gen">przekazany przez referencj� generator</param>
	void potencjalne_stworzenie_potworow(std::vector<std::vector<int>>& tabela, int x, std::mt19937& gen);
};
