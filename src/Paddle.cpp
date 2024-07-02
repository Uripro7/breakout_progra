#include "Paleta.hpp"

Paddle::Paddle(const std::string& rutaTextura, float x, float y, float velX) 
    : velocidad(velX) {
    if (!textura.loadFromFile(rutaTextura)) {
        // Manejar el error
    }
    sprite.setTexture(textura);
    sprite.setPosition(x, y);
}

void Paddle::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(sprite);
}

void Paddle::moverIzquierda() {
    sprite.move(-velocidad, 0);
    if (sprite.getPosition().x < 0) {
        sprite.setPosition(0, sprite.getPosition().y);
    }
}

void Paddle::moverDerecha() {
    sprite.move(velocidad, 0);
    if (sprite.getPosition().x + sprite.getGlobalBounds().width > 800) {
        sprite.setPosition(800 - sprite.getGlobalBounds().width, sprite.getPosition().y);
    }
}

sf::FloatRect Paddle::getBounds() const {
    return sprite.getGlobalBounds();
}
