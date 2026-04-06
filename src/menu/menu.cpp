#include "../../inc/menu/menu.hpp"
#include "../../inc/input.hpp"
#include "../../inc/display/menu_display.hpp"

void Menu::run_menu()
{
    while (m_in_menu) {
        display_menu(m_items, m_selected);

        InputEvent input = get_input();
        switch (input) {
            case INPUT_DOWN: select_next(); break;
            case INPUT_UP: select_prev(); break;
            case INPUT_QUIT: exit(0);
            case INPUT_SELECT: handle_select();
            default: break;
        }
    }
}

void Menu::exit_menu()
{
    m_in_menu = false;
}

void Menu::add_item(MenuItem item)
{
    m_items.push_back(item);
    ++m_items_count;
}

std::size_t Menu::get_menu_selection()
{
    return m_selected;
}

void Menu::select_next()
{
    // circulate back
	if (m_selected == m_items_count - 1) {
		m_selected = 0;
		return;
	}
	++m_selected;
}

void Menu::select_prev()
{
    // circulate to last
	if (m_selected == 0) {
		m_selected = m_items_count - 1;
        return;
	}
	--m_selected;
}
