#ifndef BOLA_HPP
#define BOLA_HPP

#include <SFML/Graphics.hpp>

class Bola {
public:
    Bola(const std::string& rutaTextura, float x, float y, float velX, float velY);

    void dibujar(sf::RenderWindow& ventana);
    void actualizar();
    sf::FloatRect getBounds() const;

    void rebotarVerticalmente();
    void rebotarHorizontalmente();

private:
    sf::Texture textura;
    sf::Sprite sprite;
    sf::Vector2f velocidad;
};

#endif