#ifndef UTILS_INPUT_HPP
#define UTILS_INPUT_HPP

#include "../types.hpp"

/* enable teminal raw mode */
void input_setup();

/* restore original terminal settings */
void cleanup();

/* trap <C-c> to call cleanup */
void handle_sigint(int sig);

/* parse user input to input type */
InputEvent get_input();

#endif // !UTILS_INPUT_HPP

