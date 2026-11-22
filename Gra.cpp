// techniczna część gry, zarżdzająca wszystkim

#include "Gra.hpp"
#include <algorithm>
#include <optional>

Gra::Gra()
    : m_okno(sf::VideoMode({SZEROKOSC_OKNA, WYSOKOSC_OKNA}), "Space Invaders"),
      m_gracz({SZEROKOSC_OKNA / 2.f - 25.f, WYSOKOSC_OKNA - 60.f},
              static_cast<float>(SZEROKOSC_OKNA))
{
    m_okno.setFramerateLimit(60);
}

void Gra::uruchom() // startuje wszystko
{
    sf::Clock zegar;
    while (m_okno.isOpen())
    {
        float dt = std::min(zegar.restart().asSeconds(), 0.05f);

        obsluzZdarzenia();
        aktualizuj(dt);
        rysuj();
    }
}

void Gra::obsluzZdarzenia() //klawisze i zmisny
{
    while (const std::optional zdarzenie = m_okno.pollEvent())
    {
        if (zdarzenie->is<sf::Event::Closed>())
            m_okno.close();

        if (const auto* klawisz = zdarzenie->getIf<sf::Event::KeyPressed>())
        {
            if (klawisz->scancode == sf::Keyboard::Scancode::Escape)
                m_okno.close();
        }
    }

    int kierunek = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        kierunek -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        kierunek += 1;

    m_gracz.ustawKierunek(kierunek);
}

void Gra::aktualizuj(float dt) //zmiana pozycji statku
{
    m_gracz.aktualizuj(dt);
}

void Gra::rysuj() //okno
{
    m_okno.clear(sf::Color::Black);
    m_gracz.rysuj(m_okno);
    m_okno.display();
}