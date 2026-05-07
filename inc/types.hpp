#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>   // std::string

using Ansi = std::string;

/* Game settings */
struct GameSettings {
    int board_size = 4;
};

/* Menu items struct */
struct MenuItem {
    const int id;
    std::string title;
    int value = -1;
};

/* User input options */
enum class InputEvent {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    SELECT,
    QUIT,
};

/* Main menu options */
enum MainMenuOptions {
    MM_START,
    MM_SETTINGS,
    MM_HELP,
    MM_QUIT,
};

/* Settings menu options */
enum SettingsMenuOptions {
    SM_BOARD_SIZE,
    SM_BACK,
};

#endif // !TYPES_HPP
