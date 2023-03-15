#include "Rekord.h"

std::string Rekord::zwroc_nazwe() {
	return nazwa;
}
long long Rekord::zwroc_czas() {
	return czas;
}
int Rekord::zwroc_zdobyte_punkty() {
	return zdobyte_punkty;
}
int Rekord::zwroc_punkty_do_zdobycia() {
	return punkty_do_zdobycia;
}

std::ostream& operator<<(std::ostream& str, const Rekord& rekord) {
	str << rekord.nazwa << " " << rekord.czas << " " << rekord.zdobyte_punkty << " " << rekord.punkty_do_zdobycia;
	return str;
}

std::istream& operator>>(std::istream& str, Rekord& rekord) {
	str >> rekord.nazwa >> rekord.czas >> rekord.zdobyte_punkty >> rekord.punkty_do_zdobycia;
	return str;
}

bool operator<(const Rekord& l, const Rekord& p) {
	if (l.zdobyte_punkty == 0) return false;
	if (p.zdobyte_punkty == 0) return true;
	return l.czas / (l.zdobyte_punkty) < p.czas / (p.zdobyte_punkty);
}

bool operator>(const Rekord& l, const Rekord& p) {
	if (l.zdobyte_punkty == 0) return true;
	if (p.zdobyte_punkty == 0) return false;
	return l.czas / (l.zdobyte_punkty) > p.czas / (p.zdobyte_punkty);
}

Rekord::Rekord(std::string nazwa, long long czas, int zdobyte_punkty, int punkty_do_zdobycia) {
	this->nazwa = nazwa;
	this->czas = czas;
	this->zdobyte_punkty = zdobyte_punkty;
	this->punkty_do_zdobycia = punkty_do_zdobycia;
}

Rekord::Rekord() {}