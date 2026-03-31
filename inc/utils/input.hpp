#ifndef UTILS_INPUT_HPP
#define UTILS_INPUT_HPP

#include "../types.hpp"

void input_setup();

void cleanup();

void handle_sigint(int sig);

InputEvent get_input();

#endif // !UTILS_INPUT_HPP

