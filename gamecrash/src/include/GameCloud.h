#ifndef GAMECLOUD_H
#define GAMECLOUD_H

#include <vector>
#include <SFML/Graphics.hpp>

#define DEFAULT_CLOUD_COUNT 3

class GameCloud {
public:
    GameCloud(sf::Sprite sprite, bool isActive, float speed):
        sprite_(sprite), isActive_(isActive), speed_(speed){}
        
    void setup();

private:   
    sf::Sprite sprite_;
    bool isActive_;
    float speed_;
};

#endif