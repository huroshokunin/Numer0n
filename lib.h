#ifndef _LIB_H_
#define _LIB_H_

//[変更]isMading変数とisChoosing変数を削除
//クリアしたかどうか
static boolean isClear;
//つくられた数字列
static int num[3];

boolean made_num();
boolean guess_num();   //choose_num()関数をguess_num()関数に変更
void disp_blow();
void disp_hit();
void clear_check();
void clear();

////////////////////////////////
// disp.h

enum { DISP0, DISP1, DISP2, DISP3, DISP4 };

void disp_init(void);
void disp_clear(void);
void disp_cmd(int cmd);
void disp_data(int disp, int data);
void disp_num(int disp, int num);

////////////////////////////////
// sw.ino

typedef enum { SW0, SW1 } sw_t;
typedef enum { SW_OFF, SW_PUSH, SW_ON, SW_RELEASE } sw_r;

void sw_init(void);
sw_r sw_read(sw_t sw);
