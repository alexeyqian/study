#ifndef GAMECLOUDSMANAGER_H
#define GAMECLOUDSMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "GameCloud.h"

#define DEFAULT_CLOUD_COUNT 3

class GameCloudsManager {
public:
    void setup();
    void animate();
    const std::vector<GameCloud>& getCloudsForDraw() const;

private:
    std::vector<GameCloud> clouds_;
};

#endif