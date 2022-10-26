#ifndef _LIB_H_
#define _LIB_H_

////////////////////////////////
// numeron.h

void make_num();
void guess_num();
void disp_blow();
void disp_hit();
void clear_check();
void clear();
void all_disp_zero();

void count_up();
void change_disp();

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

#endif