#include "StrukturyIFunkcje.h"

int przesuniecie(int pole, int przes) { //zwraca wartosc po przesunieciu, pole przesuniete zostaje o wartosc przes, pilnuje czy wartosc zawiera sie w tablicy
	int temp = pole + przes;
	if (temp < 0) return temp + dlugosc_planszy;
	else if (temp >= dlugosc_planszy) return temp - dlugosc_planszy;
	else return temp;
}