#include "Ladrillo.hpp"

Ladrillo::Ladrillo(const std::string& rutaTextura, float x, float y) {
    if (!textura.loadFromFile(rutaTextura)) {
        // Manejar el error
    }
    sprite.setTexture(textura);
    sprite.setPosition(x, y);
}

void Ladrillo::dibujar(sf::RenderWindow& ventana) const {
    ventana.draw(sprite);
}

sf::FloatRect Ladrillo::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Ladrillo::operator==(const Ladrillo& otro) const {
    return this->sprite.getPosition() == otro.sprite.getPosition();
}