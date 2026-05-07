#ifndef I_MENU_RENDERER_HPP
#define I_MENU_RENDERER_HPP

#include "../types.hpp"     // MenuItem

#include <vector>           // std::vector
#include <cstddef>          // std::size_t

class IMenuRenderer {
public:
    IMenuRenderer() = default;
    virtual ~IMenuRenderer() = default;

    /* Render single item on the menu */
    virtual void render_item(MenuItem item) = 0;

    /* print the menu to the screen with the selected highlited */
    void render_menu(std::vector<MenuItem> const& items, std::size_t selected);

};

#endif // !I_MENU_RENDERER_HPP

