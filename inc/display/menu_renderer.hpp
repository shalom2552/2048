#ifndef MENU_RENDERER_HPP
#define MENU_RENDERER_HPP

#include "../types.hpp"     // MenuItem

#include <vector>           // std::vector
#include <cstddef>          // std::size_t

class MenuRenderer {
public:
    MenuRenderer() = default;
    virtual ~MenuRenderer() = default;

    /* Render single item on the menu */
    void render_item(MenuItem item);

    /* print the menu to the screen with the selected highlited */
    void render_menu(std::vector<MenuItem> const& items, std::size_t selected);

};

#endif // !MENU_RENDERER_HPP

