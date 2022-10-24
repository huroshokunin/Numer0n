#ifndef _LIB_H_
#define _LIB_H_

//[変更]libファイルに入れる必要のない変数を削除しました

void make_num();    //[変更]返り値をvoidにしました
void guess_num();   //[変更]choose_num()関数をguess_num()関数にしました。返り値をvoidにしました
void disp_blow();
void disp_hit();
void clear_check();
void clear();

void count_up();      //[追加]表示されている数字を増加される関数
void change_disp();  //[追加]操作するディスプレイを変更する関数

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
