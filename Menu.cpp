#include "Menu.h"

Menu::Menu() {}


void Menu::wyswietl(sf::RenderWindow& window, int& iloscPunktow) {
    sf::Font ft;
    if (!ft.loadFromFile("Czcionki/FFF_Tusj.ttf"))
    {
        std::cout << "Nie udalo sie zaladowac czcionki.";
        window.close();
    }
    sf::Text tx;
    tx.setFont(ft); //wszystkie napisy w menu maj¹ tak¹ sam¹ czcionkê
    tx.setCharacterSize(30); //wszystkie napisy w menu maj¹ taki sam rozmiar
    tx.setFillColor(sf::Color{ 0xcd8500FF }); //wszystkie napisy w menu maj¹ taki sam kolor

    std::list<std::string> poziom{ "LATWY", "SREDNI", "TRUDNY", "NIESTANDARDOWY" }; //lista poziomów
    std::list<std::string>::iterator poziomIterator = poziom.begin(); //iterator listy
    sf::Text tryb; //tworzenie i ustalanie kluczowych parametrów wyœwietlanego trybu
    tryb.setFont(ft);
    tryb.setCharacterSize(30);
    tryb.setFillColor(sf::Color{ 0xcd8500FF });
    tryb.setPosition(705.0f, 250.0f);

    sf::Text pkt; //tworzenie i ustalanie kluczowych parametrów wyœwietlanych punktów
    pkt.setFont(ft);
    pkt.setCharacterSize(30);
    pkt.setFillColor(sf::Color{ 0xcd8500FF });
    pkt.setPosition(705.0f, 350.0f);
     
    sf::Text rozp; //tworzenie i ustalanie kluczowych parametrów wyœwietlanej opcji rozpoczêcia gry
    rozp.setFont(ft);
    rozp.setCharacterSize(30);
    rozp.setFillColor(sf::Color{ 0xcd8500FF });
    rozp.setString("ROZPOCZNIJ");
    rozp.setOrigin(rozp.getGlobalBounds().width / 2, rozp.getGlobalBounds().height / 2);
    rozp.setPosition(560.0f, 450.0f);
    
    sf::RectangleShape lewa_strzalkaTryb(sf::Vector2f(60.0f, 60.0f));
    sf::RectangleShape lewa_strzalkaPunkty(sf::Vector2f(60.0f, 60.0f));
    sf::Texture lewa_strzalka_tekstura;
    lewa_strzalka_tekstura.loadFromFile("Tekstury/leftarrow.png");
    lewa_strzalkaTryb.setTexture(&lewa_strzalka_tekstura);
    lewa_strzalkaPunkty.setTexture(&lewa_strzalka_tekstura);

    sf::RectangleShape prawa_strzalkaTryb(sf::Vector2f(60.0f, 60.0f));
    sf::RectangleShape prawa_strzalkaPunkty(sf::Vector2f(60.0f, 60.0f));
    sf::Texture prawa_strzalka_tekstura;
    prawa_strzalka_tekstura.loadFromFile("Tekstury/rightarrow.png");
    prawa_strzalkaTryb.setTexture(&prawa_strzalka_tekstura);
    prawa_strzalkaPunkty.setTexture(&prawa_strzalka_tekstura);

    sf::Vector2u ArrowsSize = lewa_strzalka_tekstura.getSize();
    lewa_strzalkaTryb.setOrigin(30.0f, 30.0f);
    prawa_strzalkaTryb.setOrigin(30.0f, 30.0f);
    lewa_strzalkaPunkty.setOrigin(30.0f, 30.0f);
    prawa_strzalkaPunkty.setOrigin(30.0f, 30.0f);

    lewa_strzalkaTryb.setPosition(430.0f, 250.0f);
    prawa_strzalkaTryb.setPosition(980.0f, 250.0f);
    lewa_strzalkaPunkty.setPosition(430.0f, 350.0f);
    prawa_strzalkaPunkty.setPosition(980.0f, 350.0f);
    bool wybrano = false;
	while (wybrano == false && window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    sf::Vector2i PozycjaMyszki = sf::Mouse::getPosition(window);
                    sf::Vector2f PozycjaMyszkiF(static_cast<float>(PozycjaMyszki.x), static_cast<float>(PozycjaMyszki.y));
                    if (lewa_strzalkaTryb.getGlobalBounds().contains(PozycjaMyszkiF)) {
                        if (poziomIterator == poziom.begin())
                            poziomIterator = poziom.end();
                        --poziomIterator;
                    }
                    else if (prawa_strzalkaTryb.getGlobalBounds().contains(PozycjaMyszkiF)) {
                        if (*poziomIterator == "NIESTANDARDOWY")
                            poziomIterator = poziom.begin();
                        else ++poziomIterator;
                    }
                    else if (lewa_strzalkaPunkty.getGlobalBounds().contains(PozycjaMyszkiF) && *poziomIterator == "NIESTANDARDOWY") {
                        if (iloscPunktow > 1) --iloscPunktow;
                    }
                    else if (prawa_strzalkaPunkty.getGlobalBounds().contains(PozycjaMyszkiF) && *poziomIterator == "NIESTANDARDOWY") {
                        ++iloscPunktow;
                    }
                    else if (rozp.getGlobalBounds().contains(PozycjaMyszkiF)) {
                        wybrano = true;
                    }
                    break;
            }
        }
        window.clear(sf::Color{ 0xC0C0C0F0 }); //wype³nienie ca³ej planszy szarym kolorem
        if (*poziomIterator == "LATWY") iloscPunktow = latwy_punkty;
        else if (*poziomIterator == "SREDNI") iloscPunktow = sredni_punkty;
        else if (*poziomIterator == "TRUDNY") iloscPunktow = trudny_punkty;
        tryb.setString(*poziomIterator);
        tryb.setOrigin(tryb.getGlobalBounds().width / 2, tryb.getGlobalBounds().height / 2);
        window.draw(tryb);
        tx.setString("TRYB");
        tx.setOrigin(tx.getGlobalBounds().width / 2, tx.getGlobalBounds().height / 2);
        tx.setPosition(280.0f, 250.0f);
        window.draw(tx);
        window.draw(lewa_strzalkaTryb);
        window.draw(prawa_strzalkaTryb);

        
        tx.setString("PUNKTY");
        tx.setOrigin(tx.getGlobalBounds().width / 2, tx.getGlobalBounds().height / 2);
        tx.setPosition(280.0f, 350.0f);
        window.draw(tx);
        window.draw(lewa_strzalkaPunkty);
        window.draw(prawa_strzalkaPunkty);
        pkt.setString(std::to_string(iloscPunktow));
        if (*poziomIterator == "NIESTANDARDOWY") pkt.setFillColor(sf::Color{ 0xcd8500FF });
        else pkt.setFillColor(sf::Color{ 0x373737FF });
        window.draw(pkt);
        window.draw(rozp);
        window.display();
	}
}