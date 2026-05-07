#include "../../inc/display/i_menu_renderer.hpp"
#include "../../inc/display/common_display.hpp"

#include "../../inc/constants.hpp"
#include "../../inc/types.hpp"      // MenuItem

#include <string>
#include <vector>           // std::vector
#include <cstddef>          // std::size_t


void IMenuRenderer::render_menu(std::vector<MenuItem> const& items, std::size_t selected)
{
    clear_screen();
    print_header();

    print_padded_line(MENU_TITLE_PADDING, "Select option:");
    print_empty_lines(2);
    for (std::size_t i = 0; i < items.size(); ++i) {
        print_padding(MENU_ITEM_PADDING);
        if (i == selected) {
            print_char("> ");
            print_char(ANSI_COLOR_BG_BLUE + ANSI_COLOR_BOLD);
        }
        render_item(items[i]);
        print_char(ANSI_COLOR_RESET);
    }

    print_footer();
}

