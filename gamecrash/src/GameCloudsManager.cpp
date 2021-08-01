#include "./include/GameCloudsManager.h"

#include<SFML/Graphics.hpp>

using sf;

void GameCloudsManager::setup() {
    Texture textureCloud;
    textureCloud.loadFromFile("../src/graphics/cloud.png");

    clouds_.reserve(DEFAULT_CLOUD_COUNT);
    for(int i = 0; i < DEFAULT_CLOUD_COUNT; i++){
        Sprite sprite;
        sprite.setTexture(textureCloud);
        sprite.setPosition(0, i * 250);

        GameCloud cloud(sprite, false, 0);
        clouds_.push_back(cloud);
    }
}

void GameCloudsManager::animate() {
    int i = 0;
    for(auto& cloud : clouds_){
        if (!cloud.isActive){
            srand((int)time(0) * 10 + i);
            cloud.speed = rand() % 200;
            srand((int)time(0) * 10 + i);
            float height = rand() % 150;
            spriteClouds[i].setPosition(-200, height);
            cloud.isActive = true;
        } else {
            int x = this->spriteClouds[i].getPosition().x + (this->cloudSpeeds[i] * dt.asSeconds());
            spriteClouds[i].setPosition(x, spriteClouds[i].getPosition().y);
            if(spriteClouds[i].getPosition().x > setting_.windowWidth){
                cloudActives[i] = false;
            }
        }

        i++;
    }
}