#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>       // std::string
#include <vector>

// colors
const std::string ANSI_COLOR_RESET      = "\033[0m";
const std::string ANSI_COLOR_BOLD       = "\033[1;38;5;194m";
const std::string ANSI_COLOR_BG_BLUE    = "\033[44m";

const std::string CELL_COLOR_2    = "\033[1;38;5;255m";
const std::string CELL_COLOR_4    = "\033[1;38;5;120m";
const std::string CELL_COLOR_8    = "\033[1;38;5;46m";
const std::string CELL_COLOR_16   = "\033[1;38;5;154m";
const std::string CELL_COLOR_32   = "\033[1;38;5;226m";
const std::string CELL_COLOR_64   = "\033[1;38;5;214m";
const std::string CELL_COLOR_128  = "\033[1;38;5;208m";
const std::string CELL_COLOR_256  = "\033[1;38;5;202m";
const std::string CELL_COLOR_512  = "\033[1;38;5;196m";
const std::string CELL_COLOR_1024 = "\033[1;38;5;201m";
const std::string CELL_COLOR_2048 = "\033[1;38;5;51m";

// map cell colors
const std::vector<std::string> CELL_COLORS = {
    CELL_COLOR_2,
    CELL_COLOR_4,
    CELL_COLOR_8,
    CELL_COLOR_16,
    CELL_COLOR_32,
    CELL_COLOR_64,
    CELL_COLOR_128,
    CELL_COLOR_256,
    CELL_COLOR_512,
    CELL_COLOR_1024,
    CELL_COLOR_2048,
};

//input keys
const char KEY_UP        = 'w';
const char KEY_DOWN      = 's';
const char KEY_RIGHT     = 'd';
const char KEY_LEFT      = 'a';
const char KEY_QUIT      = 'q';
const char KEY_SELECT    = '\r';

// padding
const int SCORE_PADDING  = 25;
const int FOOTER_PADDING = 28;
const int HEADER_PAADING = 20;
const int BOX_LEFT_PADNG = 20;
const int BOX_CELL_WIDTH = 7;

// Box unicodes
const std::string ANSI_BOX_TR  = "┓";
const std::string ANSI_BOX_TL  = "┏";
const std::string ANSI_BOX_TM  = "┳";

const std::string ANSI_BOX_BR  = "┛";
const std::string ANSI_BOX_BL  = "┗";
const std::string ANSI_BOX_BM  = "┻";

const std::string ANSI_BOX_VR  = "┃";
const std::string ANSI_BOX_CR  = "╋";
const std::string ANSI_BOX_HZ  = "━";

const std::string ANSI_BOX_MR  = "┫";
const std::string ANSI_BOX_ML  = "┣";

// clear screen
const std::string ANSI_CLEAR     = "\033[H\033[2J\033[3J";

// menu
const int MENU_TITLE_PADDING    = 8;
const int MENU_ITEM_PADDING     = 8;

#endif // !CONSTANTS_HPP

