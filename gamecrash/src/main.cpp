#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

//#include "GameCrashConfig.h"
#include "./include/GameSetting.h"
#include "./include/ClientUI.h"

using namespace sf;

int main()
{
    //std::cout<<arv[0] << " Version " << GameCrash_VERSION_MAJOR << "."
    //    << GameCrash_VERSION_MINOR << std::endl;

    GameSetting setting;
    VideoMode vm(setting.windowWidth, setting.windowHeight);
    sf::RenderWindow window(vm, "Timber");//, sf::Style::Fullscreen);
    //window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);
    
    ClientUI clientUI(setting);
    clientUI.setupBackground();
    clientUI.setupClouds();
    clientUI.setupTrees();
    clientUI.setupBees();
    
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