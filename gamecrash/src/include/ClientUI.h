#ifndef CLIENTUI_H
#define CLIENTUI_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "./GameSetting.h"

using namespace sf;

class ClientUI {
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
    void setupTimeBar();
    void drawAll(sf::RenderWindow& window);

    void updateTimeBar(Time dt);
    void resetTimeAndScore();
    void pauseGame();
    void resumeGame();
    bool isGamePaused();
    void showOutOfTimeMessage();

    float timeRemaining = 6.0f;
private:
    GameSetting setting_;
    bool paused = true;
    RectangleShape timeBar;

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
    float timeBarStartWith = 400;
    float timeBarHeight = 80;
};

#endif