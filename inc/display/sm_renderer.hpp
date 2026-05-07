#ifndef SM_RENDERER_HPP
#define SM_RENDERER_HPP

#include "i_menu_renderer.hpp"
#include "../types.hpp"     // MenuItem


class SettingsMenuRenderer : public IMenuRenderer {
public:
    virtual void render_item(MenuItem item) override;

};

#endif // !SM_RENDERER_HPP

