#ifndef LADRILLO_HPP
#define LADRILLO_HPP

#include <SFML/Graphics.hpp>

class Ladrillo {
public:
    Ladrillo(const std::string& rutaTextura, float x, float y);

    void dibujar(sf::RenderWindow& ventana) const;
    sf::FloatRect getBounds() const;

    bool operator==(const Ladrillo& otro) const;

private:
    sf::Texture textura;
    sf::Sprite sprite;
};

#endif
