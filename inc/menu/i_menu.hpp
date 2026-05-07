#ifndef MENU_I_MENU_HPP
#define MENU_I_MENU_HPP

#include "../types.hpp"    // MenuItem

#include <cstddef>      // std::size_t
#include <vector>       // std::vector

class IMenu {
public:
    IMenu() = default;
    virtual ~IMenu() = default;

    /* Display and get user selection from the items list */
    void run_menu();

    /* Return the selected option */
    std::size_t get_menu_selection();

    /* stop the menu */
    void exit_menu();

protected:

    /* Display the menu */
    virtual void display();

    /* handle user selected item */
    virtual void handle_select() = 0;

    /* Adds an item to the menu */
    void add_item(MenuItem item);

    /* Increment a the given selection by the boundry */
    void select_next();

    /* Increment a the given selection by the boundry */
    void select_prev();

    /* Lets the derived class an option to implement right key */
    virtual void handle_right() {}

    /* Lets the derived class an option to implement left key */
    virtual void handle_left() {}

    /* Get const list of the items to print */
    const std::vector<MenuItem>& get_items() const;

    /* Set menu item value for left / right */
    void set_item_value(std::size_t idx, int val);

private:
    bool m_in_menu = true;
    std::vector<MenuItem> m_items;
    std::size_t m_selected = 0;
};

#endif // !MENU_I_MENU_HPP
