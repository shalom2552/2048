#ifndef TYPES_HPP
#define TYPES_HPP

#include "../inc/constants.hpp"

#include <optional>
#include <string>   // std::string

using Ansi = std::string;

/* Game settings */
struct GameSettings {
    int board_size = DEFAULT_BOARD_SIZE;
};

/* Menu items struct */
struct MenuItem {
    const int id;
    std::string title;
    std::optional<int> value;
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

/* Board direction */
enum class Direction {

    UP,
    DOWN,
    RIGHT,
    LEFT,
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
