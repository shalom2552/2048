#include "../../inc/menu/i_menu.hpp"
#include "../../inc/terminal.hpp"

void IMenu::run_menu()
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

void IMenu::display()
{
    m_renderer->render_menu(get_items(), m_selected);
}

void IMenu::exit_menu()
{
    m_in_menu = false;
}

void IMenu::add_item(MenuItem item)
{
    m_items.push_back(item);
}

std::size_t IMenu::get_menu_selection()
{
    return m_selected;
}

void IMenu::select_next()
{
    // circulate back
	if (m_selected == m_items.size() - 1) {
		m_selected = 0;
		return;
	}
	++m_selected;
}

void IMenu::select_prev()
{
    // circulate to last
	if (m_selected == 0) {
		m_selected = m_items.size() - 1;
        return;
	}
	--m_selected;
}

const std::vector<MenuItem>& IMenu::get_items() const
{
    return m_items;
}

void IMenu::set_item_value(std::size_t idx, int val)
{
    m_items[idx].value = val;
}
