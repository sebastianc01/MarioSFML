#include "Zapis.h"

Zapis::Zapis(): koniec_zapisu(false) {}

bool Zapis::weryfikacja_nazwy(std::string& nazwa) {
    std::regex poprawne("[a-zA-Z0-9]*");
    if (std::regex_match(nazwa, poprawne)) {
        return true;
    }
    return false;
}

void Zapis::wyswietl(sf::RenderWindow& window, const int cel_punktow, const int uzyskane_punkty, std::chrono::time_point<std::chrono::system_clock> start, std::chrono::time_point<std::chrono::system_clock> koniec) {
    sf::Font ft;
    if (!ft.loadFromFile("Czcionki/FFF_Tusj.ttf"))
    {
        std::cout << "Nie udalo sie zaladowac czcionki.";
        window.close();
    }
    sf::Text tx;
    tx.setFont(ft);
    tx.setCharacterSize(30);
    tx.setFillColor(sf::Color{ 0xFFFFFFFF });
    tx.setString("Czy chcesz zapisac swoja gre?");
    tx.setOrigin(tx.getGlobalBounds().width / 2, tx.getGlobalBounds().height / 2);
    tx.setPosition(600.0f, 350.0f);
    sf::Text rezultat;
    rezultat.setFont(ft);
    rezultat.setCharacterSize(50);
    rezultat.setFillColor(sf::Color{ 0xcd8500FF });
    if (cel_punktow == uzyskane_punkty) {
        rezultat.setString("ZWYCIESTWO!");
    }
    else {
        rezultat.setString("PORAZKA!");
    }
    rezultat.setPosition(600.0f, 150.0f);
    rezultat.setOrigin(rezultat.getGlobalBounds().width / 2, rezultat.getGlobalBounds().height / 2);
    sf::Text tekst_tak;
    tekst_tak.setFont(ft);
    tekst_tak.setCharacterSize(30); 
    tekst_tak.setFillColor(sf::Color{ 0xFFFFFFFF });
    tekst_tak.setString("TAK");
    tekst_tak.setOrigin(tekst_tak.getGlobalBounds().width / 2, tekst_tak.getGlobalBounds().height / 2);
    tekst_tak.setPosition(530.0f, 400.0f);
    sf::Text tekst_nie;
    tekst_nie.setFont(ft);
    tekst_nie.setCharacterSize(30);
    tekst_nie.setFillColor(sf::Color{ 0xFFFFFFFF });
    tekst_nie.setString("NIE");
    tekst_nie.setOrigin(tekst_nie.getGlobalBounds().width / 2, tekst_nie.getGlobalBounds().height / 2);
    tekst_nie.setPosition(670.0f, 400.0f);
    bool czy_zapisac = false;
    bool wybor = true;
    while (wybor && window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed) {
                window.close();
            }
            else if (evnt.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i PozycjaMyszki = sf::Mouse::getPosition(window);
                sf::Vector2f PozycjaMyszkiF(static_cast<float>(PozycjaMyszki.x), static_cast<float>(PozycjaMyszki.y));
                if (tekst_tak.getGlobalBounds().contains(PozycjaMyszkiF)) {
                    czy_zapisac = true;
                    wybor = false;
                }
                else if (tekst_nie.getGlobalBounds().contains(PozycjaMyszkiF)) {
                    wybor = false;
                }
            }
        }
        window.clear(sf::Color{ 0xC0C0C0F0 }); //wype³nienie ca³ej planszy szarym kolorem
        window.draw(rezultat);
        window.draw(tekst_tak);
        window.draw(tekst_nie);
        window.draw(tx);
        window.display();
    }

    std::string nazwa;
    if (czy_zapisac) {
        sf::Text podaj;
        podaj.setFont(ft);
        podaj.setCharacterSize(30);
        podaj.setFillColor(sf::Color{ 0xcd8500FF });
        podaj.setString("Podaj nazwe:");
        podaj.setOrigin(podaj.getGlobalBounds().width / 2, podaj.getGlobalBounds().height / 2);
        podaj.setPosition(600.0f, 250.0f);
        sf::Text nazwa_gracza;
        nazwa_gracza.setFont(ft);
        nazwa_gracza.setCharacterSize(30);
        nazwa_gracza.setFillColor(sf::Color{ 0xcd8500FF });
        nazwa_gracza.setPosition(600.0f, 350.0f);
        sf::Text ok;
        ok.setFont(ft);
        ok.setCharacterSize(30);
        ok.setFillColor(sf::Color{ 0xcd8500FF });
        ok.setString("AKCEPTUJ");
        ok.setOrigin(ok.getGlobalBounds().width / 2, ok.getGlobalBounds().height / 2);
        ok.setPosition(600.0f, 450.0f);
        sf::Text uwaga;
        uwaga.setFont(ft);
        uwaga.setCharacterSize(20);
        uwaga.setFillColor(sf::Color{ 0xcd8500FF });
        uwaga.setString("Nazwa moze miec do 10 znakow i zawierac wylacznie litery oraz cyfry.");
        uwaga.setOrigin(uwaga.getGlobalBounds().width / 2, uwaga.getGlobalBounds().height / 2);
        uwaga.setPosition(600.0f, 550.0f);
        wybor = true;
        while (window.isOpen() && wybor) {
            sf::Event evnt;
            while (window.pollEvent(evnt)) {
                if (evnt.type == sf::Event::Closed) {
                    window.close();
                }
                else if (evnt.type == sf::Event::TextEntered) {
                    if (evnt.text.unicode == '\b' && nazwa.size() > 0) { //usuniêty zostaje ostatni znak
                        nazwa.erase(nazwa.size() - 1, 1);
                        nazwa_gracza.setString(nazwa);
                        nazwa_gracza.setOrigin(nazwa_gracza.getGlobalBounds().width / 2, nazwa_gracza.getGlobalBounds().height / 2);
                    }
                    else { //wprowadzony zostaje znak
                        if (nazwa.size() < 10) {
                            nazwa += static_cast<char>(evnt.text.unicode);
                        }
                        nazwa_gracza.setString(nazwa);
                        nazwa_gracza.setOrigin(nazwa_gracza.getGlobalBounds().width / 2, nazwa_gracza.getGlobalBounds().height / 2);
                    }
                }
                else if (evnt.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i PozycjaMyszki = sf::Mouse::getPosition(window);
                    sf::Vector2f PozycjaMyszkiF(static_cast<float>(PozycjaMyszki.x), static_cast<float>(PozycjaMyszki.y));
                    if (ok.getGlobalBounds().contains(PozycjaMyszkiF) && weryfikacja_nazwy(nazwa) && nazwa.size() > 0) {
                        wybor = false;
                    }
                }
            }
            window.clear(sf::Color{ 0xC0C0C0F0 }); //wype³nienie ca³ej planszy szarym kolorem
            window.draw(podaj);
            window.draw(nazwa_gracza);
            window.draw(ok);
            window.draw(uwaga);
            window.display();
        }
    }
    std::filesystem::path sciezka = std::filesystem::current_path();
    sciezka = sciezka / "Ranking";
    if (cel_punktow == latwy_punkty) {
        sciezka = sciezka / "Latwy";
    }
    else if (cel_punktow == sredni_punkty) {
        sciezka = sciezka / "Sredni";
    }
    else if (cel_punktow == trudny_punkty) {
        sciezka = sciezka / "Trudny";
    }
    else {
        sciezka = sciezka / "Niestandardowy";
    }
    
    
    std::vector<Rekord> Rekordy_nieukonczone;
    std::vector<Rekord> Rekordy_ukonczone;
    std::ifstream plik_n(sciezka / "Nieukonczone.txt");
    std::string wiersz;
    if (plik_n.is_open()) {
        while (getline(plik_n, wiersz)) {
            std::stringstream ss(wiersz);
            Rekord t;
            ss >> t;
            Rekordy_nieukonczone.push_back(t);
        }
        plik_n.close();
    }
    std::ifstream plik_u(sciezka / "Ukonczone.txt");
    if (plik_u.is_open()) {
        while (getline(plik_u, wiersz)) {
            std::stringstream ss(wiersz);
            Rekord t;
            ss >> t;
            Rekordy_ukonczone.push_back(t);
        }
        plik_u.close();
    }
    auto roznica = std::chrono::duration_cast<std::chrono::seconds>(koniec - start);
    Rekord t(nazwa, roznica.count(), uzyskane_punkty, cel_punktow);
    if (t.zwroc_czas() != 0.0) { //jeœli czas wynosi 0, to nie zapisujemy do pliku
        if (cel_punktow == uzyskane_punkty) { //uda³o siê wygraæ
            sciezka.append("Ukonczone.txt");
            if (czy_zapisac == true) {
                Rekordy_ukonczone.push_back(t);
                std::ranges::sort(Rekordy_ukonczone, [](Rekord& l, Rekord& p) {return l < p; });
            }
            std::ofstream plik_o(sciezka);
            if (plik_o.is_open()) {
                for (auto i : Rekordy_ukonczone) {
                    plik_o << i << std::endl;
                }
                plik_o.close();
            }
        }
        else {
            sciezka.append("Nieukonczone.txt");
            if (czy_zapisac == true) {
                Rekordy_nieukonczone.push_back(t);
                std::ranges::sort(Rekordy_nieukonczone, [](Rekord& l, Rekord& p) {return l < p; });
            }
            std::ofstream plik_o(sciezka);
            if (plik_o.is_open()) {
                for (auto i : Rekordy_nieukonczone) {
                    plik_o << i << std::endl;
                }
                plik_o.close();
            }
        }
    }
    std::stringstream tymczasowyss;
    std::string tymczasowy;
    sf::Text wynik_komunikat;
    wynik_komunikat.setFont(ft);
    wynik_komunikat.setCharacterSize(30);
    wynik_komunikat.setFillColor(sf::Color{ 0xcd8500FF });
    wynik_komunikat.setString("Wynik:");
    wynik_komunikat.setOrigin(wynik_komunikat.getGlobalBounds().width / 2, wynik_komunikat.getGlobalBounds().height / 2);
    wynik_komunikat.setPosition(600.0f, 50.0f);
    sf::Text nazwa_tekst;
    nazwa_tekst.setFont(ft);
    nazwa_tekst.setFillColor(sf::Color{ 0xcd8500FF });
    sf::Text czas_tekst;
    czas_tekst.setFont(ft);
    czas_tekst.setFillColor(sf::Color{ 0xcd8500FF });
    sf::Text uzyskane_punkty_tekst;
    uzyskane_punkty_tekst.setFont(ft);
    uzyskane_punkty_tekst.setFillColor(sf::Color{ 0xcd8500FF });
    sf::Text punkty_do_zdobycia_tekst;
    punkty_do_zdobycia_tekst.setFont(ft);
    punkty_do_zdobycia_tekst.setFillColor(sf::Color{ 0xcd8500FF });
    sf::Text numer_tekst;
    numer_tekst.setFont(ft);
    numer_tekst.setFillColor(sf::Color{ 0xcd8500FF });
    numer_tekst.setString("Wynik");
    numer_tekst.setPosition(600.0f, 250.0f);
    sf::Text opis_rankingu;
    opis_rankingu.setFont(ft);
    opis_rankingu.setFillColor(sf::Color{ 0xFFFFFFFF });
    opis_rankingu.setPosition(600.0f, 250.0f);
    sf::Text opis_nazwy;
    opis_nazwy.setFont(ft);
    opis_nazwy.setFillColor(sf::Color{ 0xcd8500FF });
    opis_nazwy.setString("Nazwa");
    sf::Text opis_czasu;
    opis_czasu.setFont(ft);
    opis_czasu.setFillColor(sf::Color{ 0xcd8500FF });
    opis_czasu.setString("Czas");
    sf::Text opis_zdobytych_punktow;
    opis_zdobytych_punktow.setFont(ft);
    opis_zdobytych_punktow.setFillColor(sf::Color{ 0xcd8500FF });
    opis_zdobytych_punktow.setString("Zdobyte punkty");
    sf::Text opis_celu_punktow;
    opis_celu_punktow.setFont(ft);
    opis_celu_punktow.setFillColor(sf::Color{ 0xcd8500FF });
    opis_celu_punktow.setString("Cel punktow");
    sf::Text zamknij_komunikat;
    zamknij_komunikat.setFont(ft);
    zamknij_komunikat.setFillColor(sf::Color{ 0xcd8500FF });
    zamknij_komunikat.setString("ZAGRAJ PONOWNIE");
    zamknij_komunikat.setCharacterSize(30);
    zamknij_komunikat.setOrigin(zamknij_komunikat.getGlobalBounds().width / 2, zamknij_komunikat.getGlobalBounds().height / 2);
    zamknij_komunikat.setPosition(600.0f, 650.0f);
    while (window.isOpen() && !koniec_zapisu) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed) {
                window.close();
            }
            else if (evnt.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i PozycjaMyszki = sf::Mouse::getPosition(window);
                sf::Vector2f PozycjaMyszkiF(static_cast<float>(PozycjaMyszki.x), static_cast<float>(PozycjaMyszki.y));
                if (zamknij_komunikat.getGlobalBounds().contains(PozycjaMyszkiF)) {
                    koniec_zapisu = true;
                }
            }
        }
        window.clear(sf::Color{ 0xC0C0C0F0 }); //wype³nienie ca³ej planszy szarym kolorem
        opis_celu_punktow.setCharacterSize(30);
        opis_zdobytych_punktow.setCharacterSize(30);
        opis_czasu.setCharacterSize(30);
        opis_nazwy.setCharacterSize(30);
        opis_rankingu.setCharacterSize(30);
        numer_tekst.setCharacterSize(30);
        punkty_do_zdobycia_tekst.setCharacterSize(30);
        uzyskane_punkty_tekst.setCharacterSize(30);
        czas_tekst.setCharacterSize(30);
        nazwa_tekst.setCharacterSize(30);
        opis_celu_punktow.setOrigin(opis_celu_punktow.getGlobalBounds().width / 2, opis_celu_punktow.getGlobalBounds().height / 2);
        opis_zdobytych_punktow.setOrigin(opis_zdobytych_punktow.getGlobalBounds().width / 2, opis_zdobytych_punktow.getGlobalBounds().height / 2);
        opis_czasu.setOrigin(opis_czasu.getGlobalBounds().width / 2, opis_czasu.getGlobalBounds().height / 2);
        opis_nazwy.setOrigin(opis_nazwy.getGlobalBounds().width / 2, opis_nazwy.getGlobalBounds().height / 2);
        opis_rankingu.setOrigin(opis_rankingu.getGlobalBounds().width / 2, opis_rankingu.getGlobalBounds().height / 2);
        numer_tekst.setOrigin(numer_tekst.getGlobalBounds().width / 2, numer_tekst.getGlobalBounds().height / 2);
        punkty_do_zdobycia_tekst.setOrigin(punkty_do_zdobycia_tekst.getGlobalBounds().width / 2, punkty_do_zdobycia_tekst.getGlobalBounds().height / 2);
        czas_tekst.setOrigin(czas_tekst.getGlobalBounds().width / 2, czas_tekst.getGlobalBounds().height / 2);
        nazwa_tekst.setOrigin(nazwa_tekst.getGlobalBounds().width / 2, nazwa_tekst.getGlobalBounds().height / 2);
        uzyskane_punkty_tekst.setOrigin(uzyskane_punkty_tekst.getGlobalBounds().width / 2, uzyskane_punkty_tekst.getGlobalBounds().height / 2);
        window.draw(wynik_komunikat);
        opis_nazwy.setPosition(250.0f, 90.0f);
        window.draw(opis_nazwy);
        opis_czasu.setPosition(450.0f, 90.0f);
        window.draw(opis_czasu);
        opis_zdobytych_punktow.setPosition(650.0f, 90.0f);
        window.draw(opis_zdobytych_punktow);
        opis_celu_punktow.setPosition(900.0f, 90.0f);
        window.draw(opis_celu_punktow);
        nazwa_tekst.setString(nazwa);
        nazwa_tekst.setOrigin(nazwa_tekst.getGlobalBounds().width / 2, nazwa_tekst.getGlobalBounds().height / 2);
        nazwa_tekst.setPosition(250.0f, 125.0f);
        window.draw(nazwa_tekst);
        std::chrono::hh_mm_ss<std::chrono::seconds> czas_aktualnego_podejscia{ roznica };
        std::stringstream tymczasowyss;
        tymczasowyss << czas_aktualnego_podejscia;
        std::string tymczasowy;
        tymczasowyss >> tymczasowy;
        czas_tekst.setString(tymczasowy);
        czas_tekst.setOrigin(czas_tekst.getGlobalBounds().width / 2, czas_tekst.getGlobalBounds().height / 2);
        czas_tekst.setPosition(450.0f, 125.0f);
        window.draw(czas_tekst);
        tymczasowyss.clear();
        tymczasowy.clear();
        tymczasowyss << uzyskane_punkty;
        tymczasowyss >> tymczasowy;
        uzyskane_punkty_tekst.setString(tymczasowy);
        uzyskane_punkty_tekst.setOrigin(uzyskane_punkty_tekst.getGlobalBounds().width / 2, uzyskane_punkty_tekst.getGlobalBounds().height / 2);
        uzyskane_punkty_tekst.setPosition(650.0f, 125.0f);
        window.draw(uzyskane_punkty_tekst);
        tymczasowyss.clear();
        tymczasowy.clear();
        tymczasowyss << cel_punktow;
        tymczasowyss >> tymczasowy;
        punkty_do_zdobycia_tekst.setString(tymczasowy);
        punkty_do_zdobycia_tekst.setOrigin(punkty_do_zdobycia_tekst.getGlobalBounds().width / 2, punkty_do_zdobycia_tekst.getGlobalBounds().height / 2);
        punkty_do_zdobycia_tekst.setPosition(900.0f, 125.0f);
        window.draw(punkty_do_zdobycia_tekst);
        opis_celu_punktow.setCharacterSize(20);
        opis_zdobytych_punktow.setCharacterSize(20);
        opis_czasu.setCharacterSize(20);
        opis_nazwy.setCharacterSize(20);
        opis_rankingu.setCharacterSize(25);
        numer_tekst.setCharacterSize(20);
        punkty_do_zdobycia_tekst.setCharacterSize(20);
        uzyskane_punkty_tekst.setCharacterSize(20);
        czas_tekst.setCharacterSize(20);
        nazwa_tekst.setCharacterSize(20);
        opis_celu_punktow.setOrigin(opis_celu_punktow.getGlobalBounds().width / 2, opis_celu_punktow.getGlobalBounds().height / 2);
        opis_zdobytych_punktow.setOrigin(opis_zdobytych_punktow.getGlobalBounds().width / 2, opis_zdobytych_punktow.getGlobalBounds().height / 2);
        opis_czasu.setOrigin(opis_czasu.getGlobalBounds().width / 2, opis_czasu.getGlobalBounds().height / 2);
        opis_nazwy.setOrigin(opis_nazwy.getGlobalBounds().width / 2, opis_nazwy.getGlobalBounds().height / 2);
        opis_rankingu.setOrigin(opis_rankingu.getGlobalBounds().width / 2, opis_rankingu.getGlobalBounds().height / 2);
        numer_tekst.setOrigin(numer_tekst.getGlobalBounds().width / 2, numer_tekst.getGlobalBounds().height / 2);
        punkty_do_zdobycia_tekst.setOrigin(punkty_do_zdobycia_tekst.getGlobalBounds().width / 2, punkty_do_zdobycia_tekst.getGlobalBounds().height / 2);
        czas_tekst.setOrigin(czas_tekst.getGlobalBounds().width / 2, czas_tekst.getGlobalBounds().height / 2);
        nazwa_tekst.setOrigin(nazwa_tekst.getGlobalBounds().width / 2, nazwa_tekst.getGlobalBounds().height / 2);
        uzyskane_punkty_tekst.setOrigin(uzyskane_punkty_tekst.getGlobalBounds().width / 2, uzyskane_punkty_tekst.getGlobalBounds().height / 2);
        opis_rankingu.setString("Ranking gier nieukonczonych");
        opis_rankingu.setOrigin(opis_rankingu.getGlobalBounds().width / 2, opis_rankingu.getGlobalBounds().height / 2);
        opis_rankingu.setPosition(300.0f, 190.0f);
        window.draw(opis_rankingu);
        opis_nazwy.setPosition(95.0f, 230.0f);
        window.draw(opis_nazwy);
        opis_czasu.setPosition(230.0f, 230.0f);
        window.draw(opis_czasu);
        opis_zdobytych_punktow.setPosition(370.0f, 230.0f);
        window.draw(opis_zdobytych_punktow);
        opis_celu_punktow.setPosition(530.0f, 230.0f);
        window.draw(opis_celu_punktow);
        for (int i = 0; i < 10; ++i) {
            tymczasowyss.clear();
            tymczasowy.clear();
            tymczasowyss << i + 1;
            tymczasowyss >> tymczasowy;
            numer_tekst.setString(tymczasowy);
            numer_tekst.setOrigin(numer_tekst.getGlobalBounds().width / 2, numer_tekst.getGlobalBounds().height / 2);
            numer_tekst.setPosition(15.0f, 270.0f + 30.0f * i);
            window.draw(numer_tekst);
            if (Rekordy_nieukonczone.size() > i) {
                nazwa_tekst.setString(Rekordy_nieukonczone.at(i).zwroc_nazwe());
            }
            else {
                nazwa_tekst.setString("...");
            }
            nazwa_tekst.setOrigin(nazwa_tekst.getGlobalBounds().width / 2, nazwa_tekst.getGlobalBounds().height / 2);
            nazwa_tekst.setPosition(95.0f, 270.0f + 30.0f * i);
            window.draw(nazwa_tekst);
            if (Rekordy_nieukonczone.size() > i) {
                std::chrono::seconds czas_podejscia_s(Rekordy_nieukonczone.at(i).zwroc_czas());
                std::chrono::hh_mm_ss<std::chrono::seconds> czas_w{ czas_podejscia_s };
                tymczasowyss.clear();
                tymczasowy.clear();
                tymczasowyss << czas_w;
                tymczasowyss >> tymczasowy;
                czas_tekst.setString(tymczasowy);
            }
            else {
                czas_tekst.setString("...");
            }
            czas_tekst.setOrigin(czas_tekst.getGlobalBounds().width / 2, czas_tekst.getGlobalBounds().height / 2);
            czas_tekst.setPosition(230.0f, 270.0f + 30.0f * i);
            window.draw(czas_tekst);
            if (Rekordy_nieukonczone.size() > i) {
                tymczasowyss.clear();
                tymczasowy.clear();
                tymczasowyss << Rekordy_nieukonczone.at(i).zwroc_zdobyte_punkty();
                tymczasowyss >> tymczasowy;
                uzyskane_punkty_tekst.setString(tymczasowy);
            }
            else {
                uzyskane_punkty_tekst.setString("...");
            }
            uzyskane_punkty_tekst.setOrigin(uzyskane_punkty_tekst.getGlobalBounds().width / 2, uzyskane_punkty_tekst.getGlobalBounds().height / 2);
            uzyskane_punkty_tekst.setPosition(370.0f, 270.0f + 30.0f * i);
            window.draw(uzyskane_punkty_tekst);
            if (Rekordy_nieukonczone.size() > i) {
                tymczasowyss.clear();
                tymczasowy.clear();
                tymczasowyss << Rekordy_nieukonczone.at(i).zwroc_punkty_do_zdobycia();
                tymczasowyss >> tymczasowy;
                punkty_do_zdobycia_tekst.setString(tymczasowy);
            }
            else {
                punkty_do_zdobycia_tekst.setString("...");
            }
            punkty_do_zdobycia_tekst.setOrigin(punkty_do_zdobycia_tekst.getGlobalBounds().width / 2, punkty_do_zdobycia_tekst.getGlobalBounds().height / 2);
            punkty_do_zdobycia_tekst.setPosition(530.0f, 270.0f + 30.0f * i);
            window.draw(punkty_do_zdobycia_tekst);
        }


        opis_rankingu.setString("Ranking gier ukonczonych");
        opis_rankingu.setOrigin(opis_rankingu.getGlobalBounds().width / 2, opis_rankingu.getGlobalBounds().height / 2);
        opis_rankingu.setPosition(900.0f, 190.0f);
        window.draw(opis_rankingu);
        opis_nazwy.setPosition(695.0f, 230.0f);
        window.draw(opis_nazwy);
        opis_czasu.setPosition(830.0f, 230.0f);
        window.draw(opis_czasu);
        opis_zdobytych_punktow.setPosition(970.0f, 230.0f);
        window.draw(opis_zdobytych_punktow);
        opis_celu_punktow.setPosition(1130.0f, 230.0f);
        window.draw(opis_celu_punktow);
        for (int i = 0; i < 10; ++i) {
            tymczasowyss.clear();
            tymczasowy.clear();
            tymczasowyss << i + 1;
            tymczasowyss >> tymczasowy;
            numer_tekst.setString(tymczasowy);
            numer_tekst.setOrigin(numer_tekst.getGlobalBounds().width / 2, numer_tekst.getGlobalBounds().height / 2);
            numer_tekst.setPosition(615.0f, 270.0f + 30.0f * i);
            window.draw(numer_tekst);
            if (Rekordy_ukonczone.size() > i) {
                nazwa_tekst.setString(Rekordy_ukonczone.at(i).zwroc_nazwe());
            }
            else {
                nazwa_tekst.setString("...");
            }
            nazwa_tekst.setOrigin(nazwa_tekst.getGlobalBounds().width / 2, nazwa_tekst.getGlobalBounds().height / 2);
            nazwa_tekst.setPosition(695.0f, 270.0f + 30.0f * i);
            window.draw(nazwa_tekst);
            if (Rekordy_ukonczone.size() > i) {
                std::chrono::seconds czas_podejscia_s(Rekordy_ukonczone.at(i).zwroc_czas());
                std::chrono::hh_mm_ss<std::chrono::seconds> czas_w{ czas_podejscia_s };
                tymczasowyss.clear();
                tymczasowy.clear();
                tymczasowyss << czas_w;
                tymczasowyss >> tymczasowy;
                czas_tekst.setString(tymczasowy);
            }
            else {
                czas_tekst.setString("...");
            }
            czas_tekst.setOrigin(czas_tekst.getGlobalBounds().width / 2, czas_tekst.getGlobalBounds().height / 2);
            czas_tekst.setPosition(830.0f, 270.0f + 30.0f * i);
            window.draw(czas_tekst);
            if (Rekordy_ukonczone.size() > i) {
                tymczasowyss.clear();
                tymczasowy.clear();
                tymczasowyss << Rekordy_ukonczone.at(i).zwroc_zdobyte_punkty();
                tymczasowyss >> tymczasowy;
                uzyskane_punkty_tekst.setString(tymczasowy);
            }
            else {
                uzyskane_punkty_tekst.setString("...");
            }
            uzyskane_punkty_tekst.setOrigin(uzyskane_punkty_tekst.getGlobalBounds().width / 2, uzyskane_punkty_tekst.getGlobalBounds().height / 2);
            uzyskane_punkty_tekst.setPosition(970.0f, 270.0f + 30.0f * i);
            window.draw(uzyskane_punkty_tekst);
            if (Rekordy_ukonczone.size() > i) {
                tymczasowyss.clear();
                tymczasowy.clear();
                tymczasowyss << Rekordy_ukonczone.at(i).zwroc_punkty_do_zdobycia();
                tymczasowyss >> tymczasowy;
                punkty_do_zdobycia_tekst.setString(tymczasowy);
            }
            else {
                punkty_do_zdobycia_tekst.setString("...");
            }
            punkty_do_zdobycia_tekst.setOrigin(punkty_do_zdobycia_tekst.getGlobalBounds().width / 2, punkty_do_zdobycia_tekst.getGlobalBounds().height / 2);
            punkty_do_zdobycia_tekst.setPosition(1130.0f, 270.0f + 30.0f * i);
            window.draw(punkty_do_zdobycia_tekst);
        }
        window.draw(zamknij_komunikat);
        window.display();
    }
}