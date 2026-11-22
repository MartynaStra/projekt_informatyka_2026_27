// techniczna część gry, zarżdzająca wszystkim

#include <SFML/Graphics.hpp>
#include "Gracz.hpp"

class Gra
{
private:
    void obsluzZdarzenia();
    void aktualizuj(float dt);
    void rysuj();

    static constexpr unsigned SZEROKOSC_OKNA = 800;
    static constexpr unsigned WYSOKOSC_OKNA = 600;

    sf::RenderWindow m_okno;
    Gracz m_gracz;

public:
    Gra();
    void uruchom();


};