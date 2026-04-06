#ifndef MENU_DISPLAY_HPP
#define MENU_DISPLAY_HPP

#include "../types.hpp"     // MenuItem

#include <vector>           // std::vector
#include <cstddef>          // std::size_t

void display_menu(std::vector<MenuItem> const& items, std::size_t selected);

#endif // !MENU_DISPLAY_HPP

