#include "../inc/input.hpp"
#include "../inc/constants.hpp"

#include <termios.h>
#include <cstdlib>      // atexit
#include <unistd.h>     // read, STDIN_FILENO
#include <signal.h>     // signal, SIGINT

static termios original_termios;

void input_setup()
{
    atexit(cleanup);
    signal(SIGINT, handle_sigint);
    tcgetattr(STDIN_FILENO, &original_termios);

    // hide the cursor
    write(STDOUT_FILENO, "\033[?25l", 6);


    termios raw = original_termios;
    raw.c_lflag &= ~(ECHO | ICANON);    // disable echo & icanon
    raw.c_cc[VMIN]  = 1;                // wait for at least 1 input
    raw.c_cc[VTIME] = 0;                // wait indefintly
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void cleanup()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
    write(STDOUT_FILENO, "\033[?25h", 6);
}

void handle_sigint(int sig)
{
    (void)sig;  // just ignore
    exit(0);
}

InputEvent get_input()
{
    char c;
    while (1) {
        if (read(STDIN_FILENO, &c, 1) != 1) continue;
        switch (c) {
            case KEY_UP: return INPUT_UP;
            case KEY_DOWN: return INPUT_DOWN;
            case KEY_RIGHT: return INPUT_RIGHT;
            case KEY_LEFT: return INPUT_LEFT;
            case KEY_QUIT: return INPUT_QUIT;
            case KEY_SELECT: return INPUT_SELECT;
        }
        // add arrows handler
        if (c == '\033') {
            char seq[2];
            read(STDIN_FILENO, &seq[0], 1);
            read(STDIN_FILENO, &seq[1], 1);
            if (seq[0] == '[') {
                switch (seq[1]) {
                    case 'A': return INPUT_UP;
                    case 'B': return INPUT_DOWN;
                    case 'C': return INPUT_RIGHT;
                    case 'D': return INPUT_LEFT;
                }
            }
        }
    }
}

