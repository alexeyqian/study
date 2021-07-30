#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
static int CLOUD_COUNT = 3;

class ClientUI {
private:
    Sprite spriteBackground;
    Sprite spriteTree;
    
    // clouds
    const int CLOUD_COUNT = 3;
    bool cloudActives[CLOUD_COUNT];
    float cloudSpeeds[CLOUD_COUNT];
    Sprite spriteClouds[CLOUD_COUNT];

    // bee
    Sprite spriteBee;
    bool beeActive = false;
    float beeSpeed = 0.0f;

    Text messageText;
    Text scoreText;

    int score = 0;

public:
    ClientUI();

    void setupBackground();
    void setupTree();
    void setupClouds();
    void setupBee();
    void setupText();

    void animateClouds(Time dt);
    void animateBee(Time dt);
    void updateScore();
    void drawAll(sf::RenderWindow& window, bool paused);
};

ClientUI::ClientUI(){

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

    for(int i = 0; i < CLOUD_COUNT; i++){
        this.spriteClouds[i].setTexture(textureCloud);
        this.spriteClouds[i].setPosition(0, i * 250);
        this.cloudActives[i] = false;
        this.cloudSpeeds[i] = 0;
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
    messageText.setPosition(WINDOW_WIDTH/2.0f, WINDOW_HEIGHT / 2.0f);
    scoreText.setPosition(20,20);
}

void ClientUI::animateClouds(Time dt){
    for(int i = 0; i < CLOUD_COUNT; i++){
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
            if(spriteClouds[i].getPosition().x > WINDOW_WIDTH){
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

void ClientUI::drawAll(sf::RenderWindow& window, bool paused){
    window.draw(spriteBackground);

    for(auto spriteCloud : this->spriteClouds){
        window.draw(spriteCloud);
    }

    window.draw(spriteTree);
    window.draw(spriteBee);
    window.draw(scoreText);

    if(paused){
        window.draw(messageText);
    }
}

int main()
{
    VideoMode vm(WINDOW_WIDTH, WINDOW_HEIGHT);
    sf::RenderWindow window(vm, "Timber");//, sf::Style::Fullscreen);
    
    ClientUI clientUI;
    clientUI.setupBackground();
    clientUI.setupTree();
    clientUI.setupClouds();
    clientUI.setupBee();
    clientUI.setupText();

    Clock clock;
    bool paused = true;
    while (window.isOpen())
    {
        /////////////// handle the players input
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Return)){
            paused = false;
        }

        if(!paused){

            //////////////////////////// update the scene
            // measure time
            // it returns the amount of time that has elapsed since the last time we restarted the clock.
            // dt stands for delta time, which is the time between two updates.
            Time dt = clock.restart();
            
            clientUI.animateClouds(dt);
            clientUI.animateBee(dt);
            clientUI.updateScore();
            
        } // end if(!paused)

        //////////////////////////// draw the scene

        // clearn everything from the last frame
        window.clear();

        // Draw out game scene here
        clientUI.drawAll(window, paused);

        /////////// Show everything we just drew
        window.display();
    }

    return 0;
}