#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/misc/style.h" // for Style
#include "lvglpp/widgets/slider.h" // for Slider

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::misc;
    using namespace lvgl::widgets;

    void style_13() {
        Style style_indic;
        style_indic.set_bg_color(lv_palette_lighten(LV_PALETTE_RED, 3));
        style_indic.set_bg_grad_color(lv_palette_main(LV_PALETTE_RED));
        style_indic.set_bg_grad_dir(LV_GRAD_DIR_HOR);

        Style style_indic_pr;
        style_indic_pr.set_shadow_color(lv_palette_main(LV_PALETTE_RED));
        style_indic_pr.set_shadow_width(10);
        style_indic_pr.set_shadow_spread(3);

        /*Create an object with the new style_pr*/
        auto root = scr_act();
        auto obj = Slider(root);
        obj.add_style(style_indic, LV_PART_INDICATOR);
        obj.add_style(style_indic_pr, LV_PART_INDICATOR | LV_STATE_PRESSED);
        obj.set_value(70, LV_ANIM_OFF);
        obj.center();
    }
}