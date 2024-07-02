#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bola.hpp"
#include "Paleta.hpp"
#include <SFML/Audio.hpp>
#include "Ladrillo.hpp"

class Juego {
public:
    Juego();
    void run();

private:
    void procesarEventos();
    void actualizar();
    void dibujar();

    sf::RenderWindow ventana;
    Bola bola;
    Paddle paddle;
    std::vector<Ladrillo> ladrillos;

    void inicializarLadrillos();
};

#endif
