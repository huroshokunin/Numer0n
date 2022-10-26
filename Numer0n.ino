#include "lib.h"

static const boolean isClear;

void setup() {
  // init_led();  要る?
  sw_init();
  disp_init();
  make_num();
}

void loop() {
  guess_num();
  isClear = clear_check();
  if (isClear) {
    clear();
  }
  disp_blow();
  disp_hit();
}
