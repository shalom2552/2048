#include "../../inc/menu/main_menu.hpp"
#include "../../inc/menu/settings_menu.hpp"
#include "../../inc/display/menu_display.hpp"
#include "../../inc/input.hpp"
#include "../../inc/types.hpp"
#include "../../inc/game.hpp"

#include <cstddef>      // std::size_t
#include <cstdlib>      // exit
#include <unistd.h>

MainMenu::MainMenu()
{
    add_item(MenuItem{MM_START, "Start"});
    add_item(MenuItem{MM_SETTINGS, "Settings"});
    add_item(MenuItem{MM_HELP, "Help"});
    add_item(MenuItem{MM_QUIT, "Quit"});
}

void MainMenu::handle_select()
{
    std::size_t selection = get_menu_selection();
    switch (selection) {
        case MM_START: start_game(); break;
        case MM_SETTINGS: run_settings(); break;
        case MM_HELP: help(); break;
        case MM_QUIT: exit_menu();
        default: return;
    }
}

void MainMenu::start_game()
{
    Game game{m_settings};
    game.run();
}

void MainMenu::run_settings()
{
    SettingsMenu sm{m_settings};
    sm.run_menu();
    sm.get_settings(m_settings);
}

void MainMenu::help()
{
    display_help();
    get_input();
}

