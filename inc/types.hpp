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

struct MenuItem {
    int id;
    std::string title;
};

enum MainMenuOptions {
    MM_START,
    MM_SIZE,
    MM_HELP,
    MM_QUIT,
};


#endif // !TYPES_HPP
