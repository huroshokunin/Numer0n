#define N_C 524  // ド
#define N_CS 554
#define N_D 587  // レ
#define N_DS 622
#define N_E 659  // ミ
#define N_F 698  // ファ
#define N_FS 740
#define N_G 784  // ソ
#define N_GS 831
#define N_A 880  // ラ
#define N_AS 932
#define N_B 988       // シ
#define DURATION 250  //

#define SP 7

void win_ring() {
  int duration;
  static int melody[] = {N_FS,      N_D, (N_A / 2), N_D, N_E,       N_A,
                         (N_A / 2), N_E, N_F,       N_E, (N_A / 2), N_D3};
  for (int i = 0; i < 12; i++) {
    duration = (i == 5) ? (DURATION * 2) : DURATION;
    tone(SP, melody[i]);
    delay(duration);
  }
  noTone(SP);
}