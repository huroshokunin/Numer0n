#include "mylib.h"

static const int PIN_LED[] = {5, 6, 10, 11};

////////////////////////////////////////////////////////////
// void led_init()
// [機能]  LEDの初期設定を行う
// [引数] なし
// [戻り値]  なし

void led_init() {
  int led;
  for (led = LED0; led <= LED3; led++) {
    pinMode(PIN_LED[led], OUTPUT);
    change_led_on(change_led);
  }
}

// LEDを点灯する
void change_led_on(int change_led) {
  if (change_led < LED0 || change_led > LED3) {
    return;
  }
  digitalWrite(PIN_LED[change_led], HIGH);
}

// LEDを消灯する
void change_led_off(int change_led) {
  if (change_led < LED0 || change_led > LED3) {
    return;
  }
  digitalWrite(PIN_LED[change_led], LOW);
}

////////////////////////////////////////////////////////////
// int run_led(boolean r_run, boolean l_run)
// [機能]   LEDの点灯位置を1秒ごとにずらす
// [引数]   r_run, l_run  LED操作のため
//          true, falseどちらか
// [戻り値] int count 秒数処理のため

int run_led(boolean r_run, boolean l_run) {
  if (r_run) {
    if (count == 0) {
      change_led_off(change_led);
      // move right side
      change_led = (change_led == CHANGE_LED0) ? CHANGE_LED3 : change_led - 1;
      change_led_on(change_led);
      count = 100 - 1;
    } else {
      count--;
    }
  }

  else if (l_run) {
    if (count == 0) {
      change_led_off(change_led);
      // move left side
      change_led = (change_led == CHANGE_LED3) ? CHANGE_LED0 : change_led + 1;
      change_led_on(change_led);
      count = 100 - 1;
    } else {
      count--;
    }
  }
  return count;
}

////////////////////////////////////////////////////////////
// void led_off(led_t led)
// [機能] 引数で指定されたLEDを消灯する
// [引数] led LEDを表す値
//      LED0,LED1,LED2,LED3のいずれか
// [戻り値]  なし

void led_off(led_t led) {
  if (led < LED0 || led > LED3) {
    return;
  }
  digitalWrite(PIN_LED[led], LOW);
}

////////////////////////////////////////////////////////////
// void led_on(led_t led)
// [機能] 引数で指定されたLEDを点灯する
// [引数] led LEDを表す値
//      LED0,LED1,LED2,LED3のいずれか
// [戻り値]  なし

void led_on(led_t led) {
  if (led < LED0 || led > LED3) {
    return;
  }
  digitalWrite(PIN_LED[led], HIGH);
}

////////////////////////////////////////////////////////////
// void led_toggle(led_t led)
// [機能] 引数で指定されたLEDの状態を反転する
// [引数] led LEDを表す値
//      LED0,LED1,LED2,LED3のいずれか
// [戻り値]  なし

void led_toggle(led_t led) {
  if (led < LED0 || led > LED3) {
    return;
  }
  // flash -> 読み込んだLEDの状態を保持する
  int flash;

  flash = digitalRead(PIN_LED[led]);

  // HIGHとLOWを反転
  if (flash == HIGH) {
    digitalWrite(PIN_LED[led], LOW);
  } else if (flash == LOW) {
    digitalWrite(PIN_LED[led], HIGH);
  } else {
    return;  //エラー処理
  }
}