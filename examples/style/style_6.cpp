#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/misc/style.h" // for Style
#include "lvglpp/widgets/image.h" // for Image

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::misc;
    using namespace lvgl::widgets;

    void style_6() {
        Style style;
        /*Set a background color and a radius*/
        style.set_radius(5);
        style.set_bg_opa(LV_OPA_COVER);
        style.set_bg_color(lv_palette_lighten(LV_PALETTE_GREY, 3));
        style.set_border_width(2);
        style.set_border_color(lv_palette_main(LV_PALETTE_BLUE));

        style.set_img_recolor(lv_palette_main(LV_PALETTE_BLUE));
        style.set_img_recolor_opa(LV_OPA_50);
        style.set_transform_angle(300);
        
        /*Create an object with the new style*/
        auto root = scr_act();
        auto obj = Image(root);
        obj.add_style(style, LV_STATE_DEFAULT);
        ImageDescriptor img_cogwheel_argb;
        img_cogwheel_argb.set_src(img_cogwheel_argb_map, 100, 100, LV_IMG_CF_TRUE_COLOR_ALPHA);
        obj.set_src(img_cogwheel_argb);
        obj.center();
    }
}