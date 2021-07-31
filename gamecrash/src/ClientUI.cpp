#include "./include/ClientUI.h"

#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;

ClientUI::ClientUI(){
    ClientUI(GameSetting{});
}

ClientUI::ClientUI(GameSetting setting) {
    setting_ = setting;
}

void ClientUI::setupBackground(){
    Texture textureBackground;
    textureBackground.loadFromFile("../src/graphics/background.png");
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);
}

void ClientUI::setupTree(){
    Texture textureTree;
    textureTree.loadFromFile("../src/graphics/tree.png");
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);
}

void ClientUI::setupClouds(){
    Texture textureCloud;
    textureCloud.loadFromFile("../src/graphics/cloud.png");

    for(int i = 0; i < setting_.cloudCount; i++){
        spriteClouds[i].setTexture(textureCloud);
        spriteClouds[i].setPosition(0, i * 250);
        cloudActives[i] = false;
        cloudSpeeds[i] = 0;
    }
}

void ClientUI::setupBee(){
    Texture textureBee;
    textureBee.loadFromFile("../src/graphics/bee.png");
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);
}

void ClientUI::setupText(){
    Font font;
    font.loadFromFile("../src/fonts/KOMIKAP_.ttf");
    messageText.setFont(font);
    scoreText.setFont(font);
    messageText.setString("Press enter to start!");
    scoreText.setString("Score = 0");
    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(100);
    messageText.setFillColor(Color::White);
    scoreText.setFillColor(Color::White);

    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    messageText.setPosition(setting_.windowWidth/2.0f, setting_.windowHeight / 2.0f);
    scoreText.setPosition(20,20);
}

void ClientUI::animateClouds(Time dt){
    for(int i = 0; i < setting_.cloudCount; i++){
        if (!cloudActives[i]){
            srand((int)time(0)*10+i);
            cloudSpeeds[i] = rand() % 200;
            srand((int)time(0)*10);
            float height = rand() % 150;
            spriteClouds[i].setPosition(-200, height);
            cloudActives[i] = true;
        } else {
            int x = this->spriteClouds[i].getPosition().x + (this->cloudSpeeds[i] * dt.asSeconds());
            spriteClouds[i].setPosition(x, spriteClouds[i].getPosition().y);
            if(spriteClouds[i].getPosition().x > setting_.windowWidth){
                cloudActives[i] = false;
            }
        }
    }
}

void ClientUI::animateBee(Time dt){
    if(!beeActive){
        srand((int)time(0));
        beeSpeed = (rand() % 200) + 200;
        srand((int)time(0) * 10);
        float height = (rand() % 500) + 500;
        spriteBee.setPosition(2000, height); // set x to off screen
        beeActive = true;
    } else {
        int x = spriteBee.getPosition().x - (beeSpeed * dt.asSeconds());
        int y = spriteBee.getPosition().y;
        spriteBee.setPosition(x, y);

        // reached the left-hand edge of the screen
        if(spriteBee.getPosition().x < -100){
            beeActive = false;
        }
    }
}

void ClientUI::updateScore(){
    std::stringstream ss;
    ss << "Score="<<score;
    scoreText.setString(ss.str());
}

void ClientUI::setupTimeBar(){
    timeBar.setSize(Vector2f(timeBarStartWith, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((setting_.windowWidth / 2) - timeBarStartWith/2, setting_.windowHeight);
}

void ClientUI::resetTimeAndScore(){
    score = 0;
    timeRemaining = 6;
}

void ClientUI::drawAll(sf::RenderWindow& window){
    window.draw(spriteBackground);

    for(auto spriteCloud : this->spriteClouds){
        window.draw(spriteCloud);
    }

    window.draw(spriteTree);
    window.draw(spriteBee);
    window.draw(scoreText);
    window.draw(timeBar);
    
    if(paused){
        window.draw(messageText);
    }
}

void ClientUI::pauseGame() {
    paused = true;
}

void ClientUI::resumeGame(){
    paused = false;
}

bool ClientUI::isGamePaused(){
    return paused;
}

void ClientUI::updateTimeBar(Time dt){
    timeRemaining -= dt.asSeconds();
    float timeBarWidthPerSecond = timeBarStartWith/timeRemaining;
    timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

    if(timeRemaining <= 0.0f) {
        pauseGame();
        showOutOfTimeMessage();
    }
}

void ClientUI::showOutOfTimeMessage(){
    messageText.setString("Out of time!");
    // re-position the text based on its new size
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    messageText.setPosition(setting_.windowWidth / 2.0f, setting_.windowHeight / 2.0f);
}