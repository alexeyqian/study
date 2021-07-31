#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "./include/GameSetting.h"
#include "./include/ClientUI.h"

using namespace sf;

int main()
{
    GameSetting setting;
    VideoMode vm(setting.windowWidth, setting.windowHeight);
    sf::RenderWindow window(vm, "Timber");//, sf::Style::Fullscreen);
    //window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);
    
    ClientUI clientUI(setting);
    clientUI.setupBackground();
    clientUI.setupTree();
    clientUI.setupClouds();
    clientUI.setupBee();
    clientUI.setupText();
    clientUI.setupTimeBar();

    Clock clock;
    
    while (window.isOpen())
    {
        /////////////// handle the players input
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Return)){
            clientUI.resumeGame();
            clientUI.resetTimeAndScore();
        }

        if(!clientUI.isGamePaused()){

            //////////////////////////// update the scene
            // measure time
            // it returns the amount of time that has elapsed since the last time we restarted the clock.
            // dt stands for delta time, which is the time between two updates.
            Time dt = clock.restart();
            
            clientUI.updateTimeBar(dt);
            
            clientUI.animateClouds(dt);
            clientUI.animateBee(dt);
            clientUI.updateScore();
            
        } // end if(!paused)

        //////////////////////////// draw the scene

        // clearn everything from the last frame
        window.clear();

        // Draw out game scene here
        clientUI.drawAll(window);

        /////////// Show everything we just drew
        window.display();
    }

    return 0;
}