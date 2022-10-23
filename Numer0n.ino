void setup() {
  init_led();
  init_sw();
  init_disp();
  if (isMading) {
    isMading = made_num();
  }
}

void loop() {
  if (isChosing) {
    isChosing = chose_num();
  }
  isClear = clear_check();
  if (isClear) {
    clear();
  }
  disp_blow();
  disp_hit();
}
