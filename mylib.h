// $Id: mylib.h,v 1.1 2022-09-27 19:39:28+09 knish Exp $

#ifndef _MYLIB_H_
#define _MYLIB_H_

//////// led.ino

typedef enum { LED0, LED1, LED2, LED3 } led_t;

void	led_init(void);
void	led_off(led_t led);
void	led_on(led_t led);
void  all_led_on();
void	led_toggle(led_t led);

//////// disp.ino

typedef enum { DISP0, DISP1, DISP2, DISP3, DISP4 } disp_t;

void	disp_init(void);
void	disp_clear(void);
void	disp_cmd(int cmd);
void	disp_data(disp_t disp, int data);
void  disp_num(int disp,int num);
void  all_disp_zero();

//////// sw.ino

typedef enum { SW0, SW1 } sw_t;
typedef enum { SW_OFF, SW_PUSH, SW_ON, SW_RELEASE } sw_r;

void	sw_init(void);
sw_r	sw_read(sw_t sw);

//////// count.ino

void	count_init(void);
void	count_down(void);
void	count_up(void);
void	count_reset(void);

//////// timer.ino

void	timer_set(unsigned long msec, void (*func)());
void	timer_start(void);
void	timer_stop(void);

#endif
