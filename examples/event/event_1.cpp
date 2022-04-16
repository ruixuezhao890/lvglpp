#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/core/event.h" // for Event
#include "lvglpp/widgets/label.h" // for Label
#include "lvglpp/widgets/button.h" // for Button

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;

    void event_1() {
        auto root = scr_act();
        auto btn = Button(root);
        btn.set_size(100, 50);
        btn.center();
        auto event_cb = [](Event & e) {
            static uint32_t cnt = 1;
            auto btn = e.get_target<Button>();
            auto label = btn.get_child<Label>(0);
            label.set_text_fmt("%" LV_PRIu32, cnt);
            cnt++;
        };
        btn.add_event_cb(event_cb, LV_EVENT_CLICKED);

        auto label = Label(btn);
        label.set_text("Click me!");
        label.center();
    }
}