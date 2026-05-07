#include "../../inc/menu/settings_menu.hpp"
#include "../../inc/display/menu_display.hpp"
#include "../../inc/constants.hpp"

#include <cstddef>

SettingsMenu::SettingsMenu(GameSettings const& settings)
{
    add_item(MenuItem{SM_BOARD_SIZE, "Board size", settings.board_size});
    add_item(MenuItem{SM_BACK, "Back"});
}

void SettingsMenu::display()
{
    display_settings_menu(get_items(), get_menu_selection());
}

void SettingsMenu::get_settings(GameSettings& settings)
{
    settings.board_size = get_items()[SM_BOARD_SIZE].value;
}

void SettingsMenu::handle_select()
{
    std::size_t selection = get_menu_selection();
    switch (selection) {
        case SM_BOARD_SIZE:
        case SM_BACK: exit_menu(); break;
        default: return;
    }
}

void SettingsMenu::handle_right()
{
    update_setting_value(1);
}

void SettingsMenu::handle_left()
{
    update_setting_value(-1);
}

void SettingsMenu::update_setting_value(int val)
{
    std::size_t setting = get_menu_selection();
    switch (setting) {
        case SM_BOARD_SIZE: update_board_size(val);
        case SM_BACK: return;
        default: return;
    }
}

void SettingsMenu::update_board_size(int val)
{
    int board_size = val + get_items()[SM_BOARD_SIZE].value;
    if (board_size > MAX_BOARD_SIZE) {
        board_size = MAX_BOARD_SIZE;
    }
    if (board_size < MIN_BOARD_SIZE) {
        board_size = MIN_BOARD_SIZE;
    }
    set_item_value(SM_BOARD_SIZE, board_size);
}

