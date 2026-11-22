//  Deklaracja statku - rozbudowanie funkcji

#include "Gracz.hpp"
#include <algorithm>

Gracz::Gracz(sf::Vector2f pozycja, float szerokoscPlanszy)
    : m_pozycja(pozycja),
      m_rozmiar({50.f, 30.f}),
      m_szerokoscPlanszy(szerokoscPlanszy)
{
}

void Gracz::ustawKierunek(int kierunek)
{
    m_kierunek = std::clamp(kierunek, -1, 1);
}

void Gracz::aktualizuj(float dt)
{
    m_pozycja.x += m_kierunek * PREDKOSC * dt;
   
    m_pozycja.x = std::clamp(m_pozycja.x, 0.f, m_szerokoscPlanszy - m_rozmiar.x);
}

void Gracz::rysuj(sf::RenderTarget& cel) const
{
    sf::RectangleShape ksztalt(m_rozmiar);
    ksztalt.setPosition(m_pozycja);
    ksztalt.setFillColor(sf::Color::Green);
    cel.draw(ksztalt);
}

sf::Vector2f Gracz::pobierzPozycje() const { return m_pozycja; }
sf::Vector2f Gracz::pobierzRozmiar() const { return m_rozmiar; }
float Gracz::pobierzPredkosc() const { return PREDKOSC; }

sf::FloatRect Gracz::pobierzGranice() const
{
    return sf::FloatRect(m_pozycja, m_rozmiar);
}



// test commit 2