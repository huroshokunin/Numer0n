// $Id: mylib.h,v 1.1 2022-09-27 19:39:28+09 knish Exp $

#ifndef _MYLIB_H_
#define _MYLIB_H_

////////////////////////////////////////
//[仕様１]正解の数字列を作る関数
//[仕様２]sw0を押すと現在操作中のディスプレイの数字が増えます
//[仕様３]sw1を押すと操作するディスプレイが左に移動します
//[仕様４]sw0とsw1を同時に押すと現在表示されている数字で決定します。
void make_num(void);

////////////////////////////////////////
//[仕様１]正解の数字列を推測する作る関数
//[仕様２]sw0を押すと現在操作中のディスプレイの数字が増えます
//[仕様３]sw1を押すと操作するディスプレイが左に移動します
//[仕様４]sw0とsw1を同時に押すと現在表示されている数字で決定します。
void guess_num(void);
/////////////////////////////
//[仕様１]クリアしたかどうか判断する関数
//[戻り値]推測した数字と正解の数字が同じならばtrueを返す,一つでも違うならfalseを返す
boolean clear_check();

void disp_hitAndBlow();

//表示する数字を一増やす
void count_up(void);
//操作するディスプレイを左に移動する
void change_disp(void);

//////// led.ino

typedef enum { LED0, LED1, LED2, LED3 } led_t;

void led_init(void);
void led_off(led_t led);
void led_on(led_t led);
void all_led_on();
void led_toggle(led_t led);

//////// disp.ino

typedef enum { DISP0, DISP1, DISP2, DISP3, DISP4 } disp_t;

void disp_init(void);
void disp_clear(void);
void disp_cmd(int cmd);
void disp_data(disp_t disp, int data);
void disp_num(int disp, int num);
void all_disp_zero();

//////// sw.ino

typedef enum { SW0, SW1 } sw_t;
typedef enum { SW_OFF, SW_PUSH, SW_ON, SW_RELEASE } sw_r;

void sw_init(void);
sw_r sw_read(sw_t sw);

////////////////////////////////
// numeron.h

void make_num(void);
void guess_num(void);
void disp_hitAndBlow(void);
void clear_check(void);
void clear(void);

void count_up(void);
void change_disp(void);

#endif
