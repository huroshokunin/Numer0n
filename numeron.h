#ifndef _NUMERON_H_
#define _NUMERON_H_
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


#endif
