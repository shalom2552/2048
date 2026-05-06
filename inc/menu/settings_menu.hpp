
#ifndef MENU_SETTINGS_MENU_HPP
#define MENU_SETTINGS_MENU_HPP

#include "menu.hpp"

class SettingsMenu : public Menu {
public:
    /* constracts the menu with its items */
    SettingsMenu(GameSettings const& settings);

    /* display the menu as changeable values */
    void display() override;

    /* update a given settings struct with the current settings */
    void get_settings(GameSettings& settings);

    /* handle the users selected option */
    void handle_select() override;

    /* Increment the selected setting in the range */
    void handle_right() override;

    /* Decrement the selected setting in the range */
    void handle_left() override;

    /* Dispacher to update a setting by the given value */
    void update_setting_value(int value);

    /* update the board size value by the given value */
    void update_board_size(int value);

    /* store the selected board size */
    void save_board_size();

private:
    int m_board_size = 4;
};

#endif // !MENU_SETTINGS_MENU_HPP

