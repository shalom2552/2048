#ifndef UTILS_INPUT_HPP
#define UTILS_INPUT_HPP

enum InputEvent {
    INPUT_UP,
    INPUT_DOWN,
    INPUT_RIGHT,
    INPUT_LEFT,
    INPUT_QUIT,
};

void input_steup();

void cleanup();

void handle_sigint(int sig);

InputEvent get_input();

#endif // !UTILS_INPUT_HPP

