// $Id: disp.ino,v 1.1 2022-09-27 19:05:29+09 knish Exp $

#include <Wire.h>
#include "lib.h"

#define DISP_I2C_ADRS 0x70

static const int disp_adrs[] = {0x08, 0x06, 0x02, 0x00, 0x04};

////////////////////////////////////////////////////////////
// void disp_init(void)
// [機能]	7セグメント表示器の初期設定を行う
// [引数]	なし
// [戻り値]	なし

void disp_init(void) {
  Wire.begin(DISP_I2C_ADRS);
  disp_cmd(0x21);  // system setup  : normal operation mode
  disp_cmd(0xEF);  // dimming set   : 16/16 duty
  disp_cmd(0x81);  // display setup : display on / blinking off
  disp_clear();
}

////////////////////////////////////////////////////////////
// void disp_init(void)
// [機能]	7セグメント表示器の表示内容をすべて消去する
// [引数]	なし
// [戻り値]	なし

void disp_clear(void) {
  Wire.beginTransmission(DISP_I2C_ADRS);
  Wire.write(0x00);
  for (int adrs = 0x00; adrs <= 0x0F; adrs++) {
    Wire.write(0x00);
  }
  Wire.endTransmission();
}

////////////////////////////////////////////////////////////
// void disp_cmd(int cmd)
// [機能]	7セグメント表示器に命令cmdを送る
// [引数]	cmd	命令を表す1byteの値
// [戻り値]	なし

void disp_cmd(int cmd) {
  Wire.beginTransmission(DISP_I2C_ADRS);
  Wire.write(cmd);
  Wire.endTransmission();
}

////////////////////////////////////////////////////////////
// void disp_data(int disp, int data)
// [機能]	7セグメント表示器のdisp桁目にdataを表示する
// [引数]	disp	表示位置を表す値
//			DISP0,DISP1,DISP2,DISP3,DISP4のいずれか
//		data	表示する1byteの値
// [戻り値]	なし

void disp_data(int disp, int data) {
  if (disp < DISP0 || disp > DISP4) {
    return;
  }
  Wire.beginTransmission(DISP_I2C_ADRS);
  Wire.write(disp_adrs[disp]);
  Wire.write(data);
  Wire.endTransmission();
}

////////////////////////////////////////////////////////////
// void disp_num(int disp, int num)
// [機能]	7セグメント表示器のdisp桁目に数字numを表示する
// [引数]	disp	表示位置を表す値
//			DISP0,DISP1,DISP2,DISP3,DISP4のいずれか
//		num	表示する1桁の数字
// [戻り値]	なし

void disp_num(int disp, int num) {
  switch (num) {
    case 0:
      disp_data(disp, 0x3F);
      break;
    case 1:
      disp_data(disp, 0x06);
      break;
    case 2:
      disp_data(disp, 0x5B);
      break;
    case 3:
      disp_data(disp, 0x4F);
      break;
    case 4:
      disp_data(disp, 0x66);
      break;
    case 5:
      disp_data(disp, 0x6D);
      break;
    case 6:
      disp_data(disp, 0x7D);
      break;
    case 7:
      disp_data(disp, 0x27);
      break;
    case 8:
      disp_data(disp, 0x7F);
      break;
    case 9:
      disp_data(disp, 0x6F);
      break;
    default:
      return;
  }
}
////////////////////////////////
//全てのディスプレイの数字を0にする
////////////////////////////////
void all_disp_zero(){
  int i;
  for(i=0;i<3;i++){
    disp_num(i,0);
  }
}
