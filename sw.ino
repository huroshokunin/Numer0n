#include "mylib.h"

#define PIN_SW0 A0
#define PIN_SW1 A1

typedef enum { ST_OFF, ST_ON } st_t;
static st_t state[] = {ST_ON, ST_OFF};

void sw_init() {
  pinMode(PIN_SW0, INPUT);
  pinMode(PIN_SW1, INPUT);
}

sw_r sw_read(sw_t sw) {
  int val;
  //引数で渡されたスイッチの状態を得る
  if (sw == SW0) {
    val = digitalRead(PIN_SW0);
  } else if (sw == SW1) {
    val = digitalRead(PIN_SW1);
  } else {
    return SW_OFF;
  }

  //スイッチの状態を調べる

  //前のスイッチの状態がonだった時
  if (state[sw] == ST_ON) {
    //今回もスイッチがonだったなら
    if (val == HIGH) {
      state[sw] = ST_ON;  // stateの更新
      return SW_ON;       //押され続けている
    }
    //今回はスイッチがoffだったら
    else {
      state[sw] = ST_OFF;  // stateの更新
      return SW_RELEASE;   //離された
    }
  }

  //前のスイッチの状態がoffだった時
  if (state[sw] == ST_OFF) {
    //今回はスイッチがonだったなら
    if (val == HIGH) {
      state[sw] = ST_ON;  // stateの更新
      return SW_PUSH;     //押された
    }
    //今回もスイッチがoffだったなら
    else {
      state[sw] = ST_OFF;  // stateの更新
      return SW_OFF;       //押されていないのが続いている
    }
  }
}
