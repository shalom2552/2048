#include "../../inc/menu/main_menu.hpp"
#include "../../inc/display/menu_display.hpp"
#include "../../inc/display/common_display.hpp"
#include "../../inc/input.hpp"
#include "../../inc/types.hpp"
#include "../../inc/game.hpp"

#include <cstddef>      // std::size_t
#include <cstdlib>      // exit
#include <iostream>

MainMenu::MainMenu()
{
    add_item(MenuItem{MM_START, "Start"});
    add_item(MenuItem{MM_SIZE, "Board Size"});
    add_item(MenuItem{MM_HELP, "Help"});
    add_item(MenuItem{MM_QUIT, "Quit"});
}

void MainMenu::handle_select()
{
    std::size_t selection = get_menu_selection();
    switch (selection) {
        case MM_START: start_game(); break;
        case MM_SIZE: set_board_size(); break;
        case MM_HELP: help(); break;
        case MM_QUIT: exit_menu();
        default: return;
    }
}

std::size_t MainMenu::get_selected_board_size()
{
    return m_board_size;
}

void MainMenu::start_game()
{
    std::size_t board_size = get_selected_board_size();
    Game game{board_size};
    game.run();

    print_padded_line(4, "Press any key...");
    get_input();
}

void MainMenu::help()
{
    display_help();
    get_input();
}

void MainMenu::set_board_size()
{
    std::cout << "insert board size (2-8): ";
}

