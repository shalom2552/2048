#ifndef MENU_MAIN_MENU_HPP
#define MENU_MAIN_MENU_HPP

#include "menu.hpp"

#include <cstddef>  // std::size_t

class MainMenu : public Menu {
public:
    /* constracts the menu with its items */
    MainMenu();

    /* handle the users selected option */
    void handle_select() override;

    /* Return the booard size */
    std::size_t get_selected_board_size();

    /* run the game */
    void start_game();

    /* display help page */
    void help();

    /* get board size from the user */
    void set_board_size();

private:
    int m_board_size = 2;
};

#endif // !MENU_MAIN_MENU_HPP

