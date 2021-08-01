#include "./include/GameCloud.h"
#include <SFML/Graphics.hpp>

using namespace sf;

void GameCloud::setup() {
    Texture textureCloud;
    textureCloud.loadFromFile("../src/graphics/cloud.png");

    for(int i = 0; i < DEFAULT_CLOUD_COUNT; i++){
        Sprite cloud;
        cloud.setTexture(textureCloud);
        cloud.setPosition(0, i * 250);
        cloudActives[i] = false;
        cloudSpeeds[i] = 0;
    }
}