// $Id: sw.ino,v 1.1 2022-09-27 19:30:34+09 knish Exp $

#include "lib.h"

#define PIN_SW0 A0
#define PIN_SW1 A1
#define TRUE 1
#define FALSE 0

typedef enum { ST_OFF, ST_ON } st_t;
static st_t state[] = {ST_OFF, ST_OFF};

////////////////////////////////////////////////////////////
// void sw_init(void)
// [機能]	押しボタンスイッチの初期設定を行う
// [引数]	なし
// [戻り値]	なし

void sw_init(void) {
  pinMode(PIN_SW0, INPUT);
  pinMode(PIN_SW1, INPUT);
}

////////////////////////////////////////////////////////////
// sw_r sw_read(sw_t sw)
// [機能]	引数で指定された押しボタンスイッチの状態を読み込む
// [引数]	sw	押しボタンスイッチを表す値
//			SW0,SW1のいずれか
// [戻り値]	押しボタンスイッチの状態を表す値
//		SW_OFF,SW_PUSH,SW_ON,SW_RELEASEのいずれか

sw_r sw_read(sw_t sw) {
  int val;
  if (sw == SW0) {
    val = digitalRead(PIN_SW0);
  } else if (sw == SW1) {
    val = digitalRead(PIN_SW1);
  } else {
    return SW_OFF;  // wrong argument
  }
  if (state[sw] == ST_OFF) {
    if (val == LOW) {
      return SW_OFF;
    } else {
      state[sw] = ST_ON;
      return SW_PUSH;
    }
  } else {
    if (val == LOW) {
      state[sw] = ST_OFF;
      return SW_RELEASE;
    } else {
      return SW_ON;
    }
  }
}