#include "../inc/terminal.hpp"
#include "../inc/constants.hpp"

#include <csignal>
#include <cstdlib>
#include <termios.h>    // termios
#include <unistd.h>     // read, STDIN_FILENO
#include <signal.h>     // signal, SIGINT

static struct termios s_original_termios;

Terminal::Terminal()
{
    atexit(restore_terminal);
    signal(SIGINT, handle_sigint);
    tcgetattr(STDIN_FILENO, &s_original_termios);

    // hide the cursor
    write(STDOUT_FILENO, "\033[?25l", 6);

    termios raw = s_original_termios;
    raw.c_lflag &= ~(ECHO | ICANON);    // disable echo & icanon
    raw.c_cc[VMIN]  = 1;                // wait for at least 1 input
    raw.c_cc[VTIME] = 0;                // wait indefintly
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

Terminal::~Terminal()
{
    restore_terminal();
}

void Terminal::restore_terminal()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &s_original_termios);
    write(STDOUT_FILENO, "\033[?25h", 6);
}

void Terminal::handle_sigint(int sig)
{
    (void)sig;  // just ignore
    std::exit(0);
}

InputEvent Terminal::get_input()
{
    char c;
    while (1) {
        if (read(STDIN_FILENO, &c, 1) != 1) continue;
        switch (c) {
            case KEY_UP: return InputEvent::UP;
            case KEY_DOWN: return InputEvent::DOWN;
            case KEY_RIGHT: return InputEvent::RIGHT;
            case KEY_LEFT: return InputEvent::LEFT;
            case KEY_QUIT: return InputEvent::QUIT;
            case KEY_SELECT: return InputEvent::SELECT;
        }
        // add arrows handler
        if (c == '\033') {
            char seq[2];
            read(STDIN_FILENO, &seq[0], 1);
            read(STDIN_FILENO, &seq[1], 1);
            if (seq[0] == '[') {
                switch (seq[1]) {
                    case 'A': return InputEvent::UP;
                    case 'B': return InputEvent::DOWN;
                    case 'C': return InputEvent::RIGHT;
                    case 'D': return InputEvent::LEFT;
                }
            }
        }
    }
}

