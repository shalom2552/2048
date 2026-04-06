#include "../../inc/display/menu_display.hpp"
#include "../../inc/display/common_display.hpp"

#include "../../inc/constants.hpp"
#include "../../inc/types.hpp"      // MenuItem

#include <vector>           // std::vector
#include <cstddef>          // std::size_t


void display_menu(std::vector<MenuItem> const& items, std::size_t selected)
{
    clear_screen();
    print_header();

    print_padded_line(MENU_TITLE_PADDING, "Select option:");
    for (std::size_t i = 0; i < items.size(); ++i) {
        if (i == selected) {
            print_line(ANSI_COLOR_BG_BLUE + ANSI_COLOR_BOLD);
            print_padded_line(MENU_ITEM_PADDING, items[i].title);
            print_line(ANSI_COLOR_RESET);
        }
    }

    print_footer();
}
