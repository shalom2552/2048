#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>   // std::string

using Ansi = std::string;

enum InputEvent {
    INPUT_UP,
    INPUT_DOWN,
    INPUT_RIGHT,
    INPUT_LEFT,
    INPUT_SELECT,
    INPUT_QUIT,
};

struct MenuItem {
    std::string title;
};

#endif // !TYPES_HPP
