#include "../../inc/display/mm_renderer.hpp"
#include "../../inc/display/common_display.hpp"
#include "../../inc/types.hpp"      // MenuItem

void MainMenuRenderer::render_item(MenuItem item)
{
    print_line(item.title);
}

