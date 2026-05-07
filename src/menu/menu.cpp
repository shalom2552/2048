#include "../../inc/menu/menu.hpp"
#include "../../inc/terminal.hpp"
#include "../../inc/display/menu_display.hpp"

void Menu::run_menu()
{
    while (m_in_menu) {
        display();

        InputEvent input = Terminal::get_input();
        switch (input) {
            case InputEvent::DOWN: select_next(); break;
            case InputEvent::UP: select_prev(); break;
            case InputEvent::LEFT: handle_left(); break;
            case InputEvent::RIGHT: handle_right(); break;
            case InputEvent::QUIT: exit(0);
            case InputEvent::SELECT: handle_select();
            default: break;
        }
    }
}

void Menu::display()
{
    display_menu(m_items, m_selected);
}

void Menu::exit_menu()
{
    m_in_menu = false;
}

void Menu::add_item(MenuItem item)
{
    m_items.push_back(item);
}

std::size_t Menu::get_menu_selection()
{
    return m_selected;
}

void Menu::select_next()
{
    // circulate back
	if (m_selected == m_items.size() - 1) {
		m_selected = 0;
		return;
	}
	++m_selected;
}

void Menu::select_prev()
{
    // circulate to last
	if (m_selected == 0) {
		m_selected = m_items.size() - 1;
        return;
	}
	--m_selected;
}

const std::vector<MenuItem>& Menu::get_items() const
{
    return m_items;
}

void Menu::set_item_value(std::size_t idx, int val)
{
    m_items[idx].value = val;
}

