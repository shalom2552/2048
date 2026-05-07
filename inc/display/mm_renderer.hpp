#ifndef MM_RENDERER_HPP
#define MM_RENDERER_HPP

#include "i_menu_renderer.hpp"


class MainMenuRenderer : public IMenuRenderer {
public:
    virtual void render_item(MenuItem item) override;

};

#endif // !MM_RENDERER_HPP

