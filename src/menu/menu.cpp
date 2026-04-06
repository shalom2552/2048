#include "../../inc/menu/menu.hpp"
#include "../../inc/input.hpp"
#include "../../inc/display/menu_display.hpp"

#include <cstddef>      // std::size_t

int Menu::run_menu(std::vector<MenuItem> const& items, std::size_t selected)
{
    for (;;) {
        display_menu(items, selected);

        InputEvent input = get_input();
        switch (input) {
            case INPUT_DOWN: select_next(selected); break;
            case INPUT_UP: select_prev(selected); break;
            case INPUT_SELECT: return selected;
            default: break;
        }
    }
}

void Menu::select_next(std::size_t& selected)
{
    // circulate back
	if (selected == m_items_count - 1) {
		selected = 0;
		return;
	}
	++selected;
}

void Menu::select_prev(std::size_t& selected)
{
    // circulate to last
	if (selected == 0) {
		selected = m_items_count - 1;
        return;
	}
	--selected;
}
