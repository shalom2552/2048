#include "../../inc/menu/settings_menu.hpp"
#include "../../inc/display/menu_display.hpp"
#include "../../inc/constants.hpp"

#include <cstddef>

SettingsMenu::SettingsMenu(GameSettings const& settings)
    : m_board_size(settings.board_size)
{
    add_item(MenuItem{SM_BOARD_SIZE, "Board size", settings.board_size});
    add_item(MenuItem{SM_BACK, "Back"});
}

void SettingsMenu::display()
{
    display_settings_menu(m_items, m_selected);
}

void SettingsMenu::get_settings(GameSettings& settings)
{
    settings.board_size = m_board_size;
}

void SettingsMenu::handle_select()
{
    std::size_t selection = get_menu_selection();
    switch (selection) {
        case SM_BOARD_SIZE: save_board_size(); break;
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

void SettingsMenu::update_setting_value(int value)
{
    std::size_t setting = get_menu_selection();
    switch (setting) {
        case SM_BOARD_SIZE: update_board_size(value);
        case SM_BACK: return;
        default: return;
    }
}

void SettingsMenu::update_board_size(int value)
{
    m_board_size += value;
    if (m_board_size > MAX_BOARD_SIZE) {
        m_board_size = MAX_BOARD_SIZE;
    }
    if (m_board_size < MIN_BOARD_SIZE) {
        m_board_size = MIN_BOARD_SIZE;
    }
    m_items[SM_BOARD_SIZE].value = m_board_size;
}

void SettingsMenu::save_board_size()
{
    m_board_size = m_items[SM_BOARD_SIZE].value;
    exit_menu();
}
