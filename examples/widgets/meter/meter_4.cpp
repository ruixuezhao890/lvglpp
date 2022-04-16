#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/meter.h" // for Meter

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;

    void meter_4() {
        auto root = scr_act();
        auto meter = Meter(root);
        meter.center();
        meter.set_size(200, 200);
        /*Remove the background and the circle from the middle*/
        meter.remove_style(LV_PART_MAIN);
        meter.remove_style(LV_PART_INDICATOR);
        /*Add a scale first with no ticks.*/
        auto scale = meter.add_scale();
        meter.set_scale_ticks(scale, 0, 0, 0, lv_color_black());
        meter.set_scale_range(scale, 0, 100, 360, 0);
        /*Add a three arc indicator*/
        lv_coord_t indic_w = 100;
        auto indic1 = meter.add_arc(scale, indic_w, lv_palette_main(LV_PALETTE_ORANGE), 0);
        meter.set_indicator_start_value(indic1, 0);
        meter.set_indicator_end_value(indic1, 40);

        auto indic2 = meter.add_arc(scale, indic_w, lv_palette_main(LV_PALETTE_YELLOW), 0);
        meter.set_indicator_start_value(indic2, 40);  /*Start from the previous*/
        meter.set_indicator_end_value(indic2, 80);

        auto indic3 = meter.add_arc(scale, indic_w, lv_palette_main(LV_PALETTE_DEEP_ORANGE), 0);
        meter.set_indicator_start_value(indic3, 80);  /*Start from the previous*/
        meter.set_indicator_end_value(indic3, 100);
    }
}