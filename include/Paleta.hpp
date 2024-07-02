#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle(const std::string& rutaTextura, float x, float y, float velocidad);

    void actualizar();
    void dibujar(sf::RenderWindow& ventana);

    sf::FloatRect getBounds() const;

    void moverIzquierda();
    void moverDerecha();

private:
    sf::Texture textura;
    sf::Sprite sprite;
    float velocidad;
};

#endif