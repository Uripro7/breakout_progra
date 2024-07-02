#include "Juego.hpp"
#include <iostream>
#include <algorithm> // Para std::remove
#include <SFML/Audio.hpp>


Juego::Juego()
    : ventana(sf::VideoMode(800, 600), "breakout"), 
      bola("assets/images/Zombie2.jpg", 400, 300, 0.1f, 0.1f), 
      paddle("assets/images/Laton.jpg", 350, 500, 0.2f) {
    ventana.clear(sf::Color::Blue);
    inicializarLadrillos();
}

void Juego::run() {
    while (ventana.isOpen()) {
        procesarEventos();
        actualizar();
        dibujar();
    }
}

void Juego::procesarEventos() {
    sf::Event event;
    while (ventana.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            ventana.close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        paddle.moverIzquierda();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        paddle.moverDerecha();
    }
}

void Juego::actualizar() {
    bola.actualizar();

    // Detectar colisiones con el paddle
    if (bola.getBounds().intersects(paddle.getBounds())) {
        bola.rebotarVerticalmente();
    }

    // Detectar colisiones con los ladrillos
    for (auto it = ladrillos.begin(); it != ladrillos.end(); ) {
        if (bola.getBounds().intersects(it->getBounds())) {
            bola.rebotarVerticalmente();
            it = ladrillos.erase(it);
        } else {
            ++it;
        }
    }
}

void Juego::dibujar() {
    ventana.clear(sf::Color::Black);
    bola.dibujar(ventana);
    paddle.dibujar(ventana);
    for (const auto& ladrillo : ladrillos) {
        ladrillo.dibujar(ventana);
    }
    ventana.display();
}

void Juego::inicializarLadrillos() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            ladrillos.push_back(Ladrillo("assets/images/Laton.jpg", i * 80, j * 30));
        }
    }
}
