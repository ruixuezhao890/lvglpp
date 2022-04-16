#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/button.h" // for Button
#include "lvglpp/widgets/label.h" // for Label
#include "lvglpp/misc/style.h" // for Style, LinearStyleTransition
#include <vector>

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::misc;
    using namespace lvgl::widgets;

    void button_2() {
        auto root = scr_act();

        Style style;

        style.set_radius(3);

        style.set_bg_opa(LV_OPA_100);
        style.set_bg_color(lv_palette_main(LV_PALETTE_BLUE));
        style.set_bg_grad_color(lv_palette_darken(LV_PALETTE_BLUE, 2));
        style.set_bg_grad_dir(LV_GRAD_DIR_VER);

        style.set_border_opa(LV_OPA_40);
        style.set_border_width(2);
        style.set_border_color(lv_palette_main(LV_PALETTE_GREY));

        style.set_shadow_width(8);
        style.set_shadow_color(lv_palette_main(LV_PALETTE_GREY));
        style.set_shadow_ofs_y(8);

        style.set_outline_opa(LV_OPA_COVER);
        style.set_outline_color(lv_palette_main(LV_PALETTE_BLUE));

        style.set_text_color(lv_color_white());
        style.set_pad_all(10);

        /*Init the pressed style*/
        Style style_pr;

        /*Add a large outline when pressed*/
        style_pr.set_outline_width(30);
        style_pr.set_outline_opa(LV_OPA_TRANSP);

        style_pr.set_translate_y(5);
        style_pr.set_shadow_ofs_y(3);
        style_pr.set_bg_color(lv_palette_darken(LV_PALETTE_BLUE, 2));
        style_pr.set_bg_grad_color(lv_palette_darken(LV_PALETTE_BLUE, 4));

        /*Add a transition to the outline*/
        LinearStyleTransition trans;
        static lv_style_prop_t props[] = {LV_STYLE_OUTLINE_WIDTH, LV_STYLE_OUTLINE_OPA, 0};
        trans.set_props(props);
        trans.set_time(300);
        trans.set_delay(0);
        style_pr.set_transition(trans);
        
        auto button = Button(root);
        button.remove_style_all();
        
        button.add_style(style, LV_STATE_DEFAULT);
        button.add_style(style_pr, LV_STATE_PRESSED);
        button.set_size(LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        button.center();

        auto label = Label(button);
        label.set_text("Button");
        label.center();
    }
}
