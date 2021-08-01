#include "include/GameBackground.h"

#include <SFML/Graphics.hpp>

using namespace sf;

void GameBackground::setup(){
    Texture textureBackground;
    // TODO: update path to use cmake cp
    textureBackground.loadFromFile("../src/graphics/background.png");
    
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);
}

Sprite& GameBackground::getBackgroundForDraw(){
    return spriteBackground;
}