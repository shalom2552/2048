#ifndef MENU_MAIN_MENU_HPP
#define MENU_MAIN_MENU_HPP

#include "i_menu.hpp"

class MainMenu : public IMenu {
public:
    /* constracts the menu with its items */
    MainMenu();

    /* handle the users selected option */
    void handle_select() override;

    /* run the game */
    void start_game();

    /* Run the seettings menu and store seettings */
    void run_settings();

    /* display help page */
    void help();

private:
    GameSettings m_settings;
};

#endif // !MENU_MAIN_MENU_HPP

