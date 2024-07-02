#ifndef SCREEN_MANAGER_HPP
#define SCREEN_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>

class ScreenManager {
public:
    ScreenManager(int width, int height, const std::string &title);
    void clearScreen();
    void drawText(int x, int y, const std::string &text);
    void refreshScreen();
    bool kbhit();

    sf::RenderWindow& getWindow();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;
};

#endif
