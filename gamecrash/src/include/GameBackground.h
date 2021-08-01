#ifndef GAMEBACKGROUND_H
#define GAMEBACKGROUND_H

#include <SFML/Graphics.hpp>

class GameBackground {
public:
    void setup();
    const sf::Sprite& getBackgroundForDraw() const;
private:
    sf::Sprite spriteBackground;
};

#endif