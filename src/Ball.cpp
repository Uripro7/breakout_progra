#include "Bola.hpp"

Bola::Bola(const std::string& rutaTextura, float x, float y, float velX, float velY)
    : velocidad(velX, velY) {
    if (!textura.loadFromFile(rutaTextura)) {
        // Manejar el error
    }
    sprite.setTexture(textura);
    sprite.setPosition(x, y);
}

void Bola::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(sprite);
}

void Bola::actualizar() {
    sprite.move(velocidad);

    // Colisión con las paredes
    if (sprite.getPosition().x <= 0 || sprite.getPosition().x + sprite.getGlobalBounds().width >= 800) {
        rebotarHorizontalmente();
    }
    if (sprite.getPosition().y <= 0) {
        rebotarVerticalmente();
    }
}

sf::FloatRect Bola::getBounds() const {
    return sprite.getGlobalBounds();
}

void Bola::rebotarVerticalmente() {
    velocidad.y = -velocidad.y;
}

void Bola::rebotarHorizontalmente() {
    velocidad.x = -velocidad.x;
}
