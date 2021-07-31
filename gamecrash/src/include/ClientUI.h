#ifndef CLIENTUI_H
#define CLIENTUI_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "./GameSetting.h"

using namespace sf;

class ClientUI {
private:
    Sprite spriteBackground;
    Sprite spriteTree;
    
    // clouds
    std::vector<bool> cloudActives;
    std::vector<float> cloudSpeeds;
    std::vector<Sprite> spriteClouds;

    // bee
    Sprite spriteBee;
    bool beeActive = false;
    float beeSpeed = 0.0f;

    Text messageText;
    Text scoreText;

    int score = 0;

public:
    ClientUI();
    ClientUI(GameSetting setting);

    void setupBackground();
    void setupTree();
    void setupClouds();
    void setupBee();
    void setupText();

    void animateClouds(Time dt);
    void animateBee(Time dt);
    void updateScore();
    void drawAll(sf::RenderWindow& window, bool paused);

private:
    GameSetting setting_;
};

#endif