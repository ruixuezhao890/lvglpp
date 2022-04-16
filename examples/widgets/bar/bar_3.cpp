#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/bar.h" // for Bar
#include "lvglpp/misc/style.h" // for Style
#include "lvglpp/misc/anim.h" // for Animation

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;
    using namespace lvgl::misc;

    void bar_3() {
        Style style_indic;

        style_indic.set_bg_opa(LV_OPA_COVER);
        style_indic.set_bg_color(lv_palette_main(LV_PALETTE_RED));
        style_indic.set_bg_grad_color(lv_palette_main(LV_PALETTE_BLUE));
        style_indic.set_bg_grad_dir(LV_GRAD_DIR_VER);

        auto root = scr_act();
        auto bar = Bar(root);
        bar.add_style(style_indic, LV_PART_INDICATOR);
        bar.set_size(20, 200);
        bar.center();
        bar.set_range(-20, 40);

        Animation a;
        auto set_temp = [](Bar & bar, int32_t temp) {
            bar.set_value(temp, LV_ANIM_ON);
        };
        a.set_exec_cb<Bar>(set_temp);
        a.set_time(3000);
        a.set_playback_time(3000);
        a.set_var(bar);
        a.set_values(-20, 40);
        a.set_repeat_count(LV_ANIM_REPEAT_INFINITE);
        a.start();
   }

}