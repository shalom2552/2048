#include "../../inc/menu/main_menu.hpp"
#include "../../inc/menu/settings_menu.hpp"
#include "../../inc/display/mm_renderer.hpp"
#include "../../inc/display/common_display.hpp"
#include "../../inc/terminal.hpp"
#include "../../inc/types.hpp"
#include "../../inc/game.hpp"

#include <cstddef>      // std::size_t
#include <cstdlib>      // exit
#include <memory>       // std::make_unique

MainMenu::MainMenu()
{
    m_renderer = std::make_unique<MainMenuRenderer>(MainMenuRenderer());
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
    Terminal::get_input();
}

