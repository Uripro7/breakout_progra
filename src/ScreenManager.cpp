#include "ScreenManager.hpp"

ScreenManager::ScreenManager(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title) {}

void ScreenManager::clearScreen() {
    window.clear(sf::Color::White);
}

sf::RenderWindow& ScreenManager::getWindow() {
    return window;
}

void ScreenManager::refreshScreen() {
    window.display();
}
