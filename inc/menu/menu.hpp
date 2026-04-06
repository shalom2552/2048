#ifndef MENU_MENU_HPP
#define MENU_MENU_HPP

#include "../types.hpp"    // MenuItem

#include <cstddef>      // std::size_t
#include <vector>       // std::vector

/**
 * @class Menu
 * @brief Display menu options and get user selection
 */
class Menu {
public:
    Menu();

    /**
     * @brief Display and get user selection from the items list
     *
     * @param items Options to display and choose from
     * @param selected The deffault selection
     * @param items_count Count of items in the menu
     * @return The selected option from the menu
     */
    int run_menu(std::vector<MenuItem> const& items, std::size_t selected);

    /*
     * @brief Increment a the given selection by the boundry
     *
     * @param selected A pointer to the current index of the cursor position
     * @param count The count of items or maximum index allowed
     * @return the new cursor index position
     */
    void select_next(std::size_t& selected);

    /*
     * @brief Increment a the given selection by the boundry
     *
     * @param selected A pointer to the current index of the cursor position
     * @param count The count of items or maximum index allowed
     * @return the new cursor index position
     */
    void select_prev(std::size_t& selected);

private:
    std::vector<MenuItem> m_items;
    std::size_t m_items_count;
};

#endif // !MENU_MENU_HPP

