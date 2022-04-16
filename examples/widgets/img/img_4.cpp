#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/image.h" // for Image
#include "lvglpp/core/event.h" // for Event
#include "lvglpp/misc/anim.h" // for Animation
#include "lvglpp/misc/style.h" // for Style

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;
    using namespace lvgl::misc;

    void image_4() {
        auto root = scr_act();
        
        auto img_src = ImageDescriptor();
        img_src.set_src(img_skew_strip_map, 80, 20, LV_IMG_CF_TRUE_COLOR_ALPHA);

        Style style;
        style.set_bg_color(lv_palette_main(LV_PALETTE_YELLOW));
        style.set_bg_opa(LV_OPA_COVER);
        style.set_img_recolor_opa(LV_OPA_COVER);
        style.set_img_recolor(lv_color_black());

        /*Now create the actual image*/
        auto img = Image(root);
        img.set_src(img_src);
        img.add_style(style, LV_PART_MAIN);
        img.set_size(150, 100);
        img.center();

        Animation a;
        a.set_var(img);
        auto ofs_y_anim = [](Image & img, int32_t v) {
            img.set_offset_y(v);
        };
        a.set_exec_cb<Image>(ofs_y_anim);
        a.set_values(0, 100);
        a.set_time(3000);
        a.set_playback_time(500);
        a.set_repeat_count(LV_ANIM_REPEAT_INFINITE);
        a.start();
    }
}