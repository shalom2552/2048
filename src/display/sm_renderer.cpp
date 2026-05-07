#include "../../inc/display/sm_renderer.hpp"
#include "../../inc/display/common_display.hpp"
#include "../../inc/constants.hpp"
#include "../../inc/types.hpp"      // MenuItem

void SettingsMenuRenderer::render_item(MenuItem item)
{
    print_char(item.title);
    print_char(ANSI_COLOR_RESET);
    if (item.value != -1) {
        print_char("\t< ");
        print_char(std::to_string(item.value));
        print_line(" >");
    }
}
