#include "../../inc/display/menu_display.hpp"
#include "../../inc/display/common_display.hpp"

#include "../../inc/constants.hpp"
#include "../../inc/types.hpp"      // MenuItem

#include <string>
#include <vector>           // std::vector
#include <cstddef>          // std::size_t


void display_menu(std::vector<MenuItem> const& items, std::size_t selected)
{
    clear_screen();
    print_header();

    print_padded_line(MENU_TITLE_PADDING, "Select option:");
    print_empty_lines(2);
    for (std::size_t i = 0; i < items.size(); ++i) {
        print_padding(MENU_ITEM_PADDING);
        if (i == selected) {
            print_char("> ");
            print_char(ANSI_COLOR_BG_BLUE + ANSI_COLOR_BOLD);
        }
        print_line(items[i].title);
        print_char(ANSI_COLOR_RESET);
    }

    print_footer();
}

void display_settings_menu(std::vector<MenuItem> const& items, std::size_t selected)
{
    clear_screen();
    print_header();

    print_padded_line(MENU_TITLE_PADDING, "Select option:");
    print_empty_lines(2);
    for (std::size_t i = 0; i < items.size(); ++i) {
        print_padding(MENU_ITEM_PADDING);
        if (i == selected) {
            print_char("> ");
            print_char(ANSI_COLOR_BG_BLUE + ANSI_COLOR_BOLD);
        }
        print_char(items[i].title);
        print_char(ANSI_COLOR_RESET);
        if (items[i].value != -1) {
            print_char("\t< ");
            print_char(std::to_string(items[i].value));
            print_line(" >");
        }
    }

    print_footer();
}

void display_help()
{

    const char* help_text = R"(
            HOW TO PLAY

            Goal: merge tiles to reach 2048

            Controls:
              W / ↑   Move up
              S / ↓   Move down
              A / ←   Move left
              D / →   Move right
              Q       Quit game

            Rules:
              Tiles with equal values merge when they collide
              Each merge adds the new tile's value to your score
              Game ends when no moves remains.
    )";

    clear_screen();
    print_header();
    print_padded_line(3, help_text);
    print_padded_line(3, "Press any key...");

    print_footer();
}

