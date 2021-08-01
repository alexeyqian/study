#ifndef GAMESETTING_H
#define GAMESETTING_H

#define DEFAULT_WINDOW_WIDTH 1920
#define DEFAULT_WINDOW_HEIGHT 1080

struct GameSetting {
public:
    static GameSetting getDefaultSetting() {
        GameSetting setting;

        return setting;
    }

    int windowWidth = DEFAULT_WINDOW_WIDTH;
    int windowHeight = DEFAULT_WINDOW_HEIGHT;
};

#endif