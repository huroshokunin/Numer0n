#include "lib.h"

void setup() {
  init_led();
  init_sw();
  init_disp();
  //[変更]不要だったので条件文を削除しました
  make_num(); 
}

void loop() {
  //[変更]不要だったので条件文を削除しました
  guess_num();  //[変更]choose_num()関数の関数名をguess_num()に変更しました
  isClear = clear_check();
  if (isClear) {
    clear();
  }
  disp_blow();
  disp_hit();
}
