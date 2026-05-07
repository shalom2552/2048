#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include "types.hpp"

#include <termios.h>    // termios

class Terminal {
public:
    Terminal();
    ~Terminal();

    /* trap <C-c> to call cleanup */
    static void handle_sigint(int sig);

    /* Restore terminal settings */
    static void restore_terminal();

    /* parse user input to input type */
    static InputEvent get_input();

};

#endif // !TERMINAL_HPP

