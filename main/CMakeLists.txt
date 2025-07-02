idf_component_register(
    SRCS "waveshare_rgb_lcd_port.c" 
    "main.c" 
    "lvgl_port.c" 
    "clock_ui.c"
    "clock_messages.c"
    "arrow_1.c"
    "brygada_1918_24.c"
    "calendar.c"
    "checkmark.c"
    "gear.c"
    "set_time.c"
    "sono_28.c"
    "xanh_mono_108.c"
    INCLUDE_DIRS "."
)

idf_component_get_property(lvgl_lib lvgl__lvgl COMPONENT_LIB)
target_compile_options(${lvgl_lib} PRIVATE -Wno-format)
