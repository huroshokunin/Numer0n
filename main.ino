#include "mylib.h"

static int i = 0;

void setup() {
  led_init();
  sw_init();
  disp_init();
  Serial.begin(9600);
  //最初は全てのディスプレイに0を表示する
  all_disp_zero();
  //数字列をつくって、numで受け取る
  make_num();
  delay(500);
}

void loop() {
  bool isClear;
  guess_num();
  delay(500);
  disp_hitAndBlow();
  isClear = clear_check();
  if (isClear) {
    all_led_on();
    win_ring();
    while (1) {
    }
  }
}
