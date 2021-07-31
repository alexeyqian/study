#ifndef GAMESETTING_H
#define GAMESETTING_H

struct GameSetting {
public:
    static GameSetting getDefaultSetting() {
        GameSetting setting;

        return setting;
    }

    int windowWidth = 1000;
    int windowHeight = 800;
    int cloudCount = 3;
};

#endif