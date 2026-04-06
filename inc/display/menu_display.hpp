#ifndef MENU_DISPLAY_HPP
#define MENU_DISPLAY_HPP

#include "../types.hpp"     // MenuItem

#include <vector>           // std::vector
#include <cstddef>          // std::size_t

/* print the menu to the screen with the selected highlited */
void display_menu(std::vector<MenuItem> const& items, std::size_t selected);

/* display the help page */
void display_help();

#endif // !MENU_DISPLAY_HPP

