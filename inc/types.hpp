#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>   // std::string

using Ansi = std::string;

/* user input options */
enum InputEvent {
    INPUT_UP,
    INPUT_DOWN,
    INPUT_RIGHT,
    INPUT_LEFT,
    INPUT_SELECT,
    INPUT_QUIT,
};

struct GameSettings {
    int board_size = 4;
};

struct MenuItem {
    const int id;
    std::string title;
    int value = -1;
};

enum MainMenuOptions {
    MM_START,
    MM_SETTINGS,
    MM_HELP,
    MM_QUIT,
};

enum SettingsMenuOptions {
    SM_BOARD_SIZE,
    SM_BACK,
};

#endif // !TYPES_HPP
