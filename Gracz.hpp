// Deklaracja statku 

#include <SFML/Graphics.hpp>

class Gracz
{
private:
    static constexpr float PREDKOSC = 300.f;
    sf::Vector2f m_pozycja;
    sf::Vector2f m_rozmiar;
    int m_kierunek = 0;
    float m_szerokoscPlanszy;

public:
    Gracz(sf::Vector2f pozycja, float szerokoscPlanszy);

    void aktualizuj(float dt);              // przesuwa statek
    void rysuj(sf::RenderTarget& cel) const; //rysuje statek

    void ustawKierunek(int kierunek);       // -1 = lewo, 0= stoi, 1 = prawo

    sf::Vector2f pobierzPozycje() const;
    sf::Vector2f pobierzRozmiar() const;
    sf::FloatRect pobierzGranice() const;  
    float pobierzPredkosc() const;


};