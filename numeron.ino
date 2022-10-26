#include "lib.h"

//現在数字列を作っているかどうか、falseならmake_num()関数終了
static bool isMading = false;
//現在数字列を推測中かどうか,falseならguess_num()関数終了
static bool isGuessing = false;
//現在操作しているディスプレイ番号
static int usingDisp = 0;
//ユーザーが正解に決めた数字列
static int correctNum[3] = {0, 0, 0};
//ユーザーが推測した数字列
static int guessedNum[3] = {0, 0, 0};

////////////////////////////////////////////////////////////
// void make_num(void)
// [機能]	正解の数字列を作る
// [引数]	なし
// [戻り値]	なし

void make_num() {
  isMading = true;
  sw_r sw0;
  sw_r sw1;

  //数字列をつくっている間ループする
  while (isMading) {
    sw0 = sw_read(SW0);  // sw0の状態を読む
    sw1 = sw_read(SW1);  // sw1の状態を読む

    //スイッチ同時押し,
    // sw1を押した後にsw0を押したパターンの処理
    if ((sw0 == SW_PUSH) && (sw1 == SW_ON)) {
      //数字の重複が無ければ数字列決定
      if ((correctNum[0] != correctNum[1]) &&
          (correctNum[0] != correctNum[2]) &&
          (correctNum[1] != correctNum[2])) {
        isMading = false;
        all_disp_zero();
        return;
      } else {
        disp_num(usingDisp, correctNum[usingDisp]);
        delay(1000);
      }
    }
    //スイッチ同時押し
    // sw0を押した後にsw1を押したパターンの処理
    if ((sw0 == SW_ON) && (sw1 == SW_PUSH)) {
      correctNum[usingDisp] =
          (correctNum[usingDisp] == 0) ? 9 : correctNum[usingDisp] - 1;

      //数字の重複が無ければ、数字列決定の処理へ
      if ((correctNum[0] != correctNum[1]) &&
          (correctNum[0] != correctNum[2]) &&
          (correctNum[1] != correctNum[2])) {
        isMading = false;
        all_disp_zero();
        return;
      }
      //数字の重複があったなら、少し待つ
      else {
        disp_num(usingDisp, guessedNum[usingDisp]);
        delay(1000);
      }
    }

    // SW0が押されたら現在操作しているディスプレイの表示されている数字を増やす
    if (sw0 == SW_PUSH) {
      count_up();
    }

    // SW1が押されたら操作中ディスプレイ番号を1増やす
    if (sw1 == SW_PUSH) {
      change_disp();
    }

    delay(10);
  }
}

////////////////////////////////////////////////////////////
// void guess_num(void)
// [機能]	正解の数字列を作る
// [引数]	なし
// [戻り値]	なし

void guess_num() {
  isGuessing = true;  //現在数字列を作っているかどうか、falseなら関数終了
  sw_r sw0;
  sw_r sw1;
  usingDisp = 0;
  int i;
  for (i = 0; i < 3; i++) {
    guessedNum[i] = 0;
  }
  //数字列をつくっている間ループする
  while (isGuessing) {
    sw0 = sw_read(SW0);  // sw0の状態を読む
    sw1 = sw_read(SW1);  // sw1の状態を読む

    //スイッチ同時押し
    // sw1を押した後にsw0を押したときの処理
    if ((sw0 == SW_PUSH) && (sw1 == SW_ON)) {
      //数字の重複が無ければ、数字列決定の処理へ
      if ((guessedNum[0] != guessedNum[1]) &&
          (guessedNum[0] != guessedNum[2]) &&
          (guessedNum[1] != guessedNum[2])) {
        isGuessing = false;
        all_disp_zero();

        Serial.println("推測列");
        Serial.print(guessedNum[2]);
        Serial.print(guessedNum[1]);
        Serial.println(guessedNum[0]);

        return;
      } else {
        disp_num(usingDisp, guessedNum[usingDisp]);
        delay(1000);
      }

    }
    //スイッチ同時押し
    // sw0を押した後にsw1を押したときの処理
    else if ((sw0 == SW_ON) && (sw1 == SW_PUSH)) {
      guessedNum[usingDisp] =
          (guessedNum[usingDisp] == 0) ? 9 : guessedNum[usingDisp] - 1;
      //数字の重複が無ければ、数字列決定の処理へ
      if ((guessedNum[0] != guessedNum[1]) &&
          (guessedNum[0] != guessedNum[2]) &&
          (guessedNum[1] != guessedNum[2])) {
        isGuessing = false;
        all_disp_zero();

        Serial.println("推測列");
        Serial.print(guessedNum[2]);
        Serial.print(guessedNum[1]);
        Serial.println(guessedNum[0]);

        return;
      } else {
        disp_num(usingDisp, guessedNum[usingDisp]);
        delay(1000);
      }
    }

    // SW0が押されたら現在操作しているディスプレイの表示されている数字を増やす
    if (sw0 == SW_PUSH) {
      count_up();
    }

    // SW1が押されたら操作中ディスプレイ番号を1増やす
    if (sw1 == SW_PUSH) {
      change_disp();
    }

    delay(10);
  }
}

////////////////////////////////////////////////////////////
// boolean clear_check(void)
// [機能]	クリアしたかチェックする関数
// [引数]	なし
// [戻り値]	boolean型 trueなら正解 flaseなら不正解

boolean clear_check() {
  if ((correctNum[0] == guessedNum[0]) && (correctNum[1] == guessedNum[1]) &&
      (correctNum[2] == guessedNum[2])) {
    return true;
  }
  return false;
}

////////////////////////////////////////////////////////////
// void disp_hitAndBlow(void)
// [機能]	クリアしたかチェックする関数
// [引数] なし
// [戻り値] なし

void disp_hitAndBlow() {
  int blowCounter = 0;
  int hitCounter = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (correctNum[i] == guessedNum[j]) {
        if (i == j) {
          hitCounter++;
        } else {
          blowCounter++;
        }
      }
    }
  }
  disp_clear();
  disp_num(1, hitCounter);
  disp_data(0, H);
  delay(4000);
  disp_num(1, blowCounter);
  disp_data(0, B);
  delay(4000);
  all_disp_zero();
}

////////////////////////////////////////////////
//ディスプレイに表示されている数値を増加させる
////////////////////////////////////////////////
void count_up() {
  if (isMading) {
    correctNum[usingDisp]++;
    //表示する数字は10になったら0に戻す
    if (correctNum[usingDisp] == 10) {
      correctNum[usingDisp] = 0;
    }
    //現在の操作中ディスプレイの数字を更新する
    disp_num(usingDisp, correctNum[usingDisp]);
  }

  if (isGuessing) {
    guessedNum[usingDisp]++;
    //表示する数字は10になったら0に戻す
    if (guessedNum[usingDisp] == 10) {
      guessedNum[usingDisp] = 0;
    }
    //現在の操作中ディスプレイの数字を更新する
    disp_num(usingDisp, guessedNum[usingDisp]);
  }
}

///////////////////////////////////
//操作するディスプレイを変更する。
//////////////////////////////////
void change_disp() {
  usingDisp++;
  //ディスプレイ番号2の次は0にする
  if (usingDisp > 2) {
    usingDisp = 0;
  }
}
