
#include "Display_ST7789.h"
#include "LVGL_Driver.h"
#include "ui.h"

void setup()
{       

  LCD_Init();
  Lvgl_Init();
  ui_init();
  
}

void loop()
{
  static uint32_t last_update =0;
  if (millis() - last_update >= 2000) {
    last_update = millis();

    int cpt = random(0, 150);
    lv_bar_set_value(objects.bar_test, cpt, LV_ANIM_OFF);
    lv_label_set_text(objects.lbl_main, String(cpt).c_str());

  }
  
  Timer_Loop();
  delay(5);
}
