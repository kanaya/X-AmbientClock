#include <Tlc5940.h>
#include <tlc_animations.h>
#include <tlc_config.h>
#include <tlc_fades.h>
#include <tlc_progmem_utils.h>
#include <tlc_servos.h>
#include <tlc_shifts.h>

#include "Time.h"

/// Do not turn on more than 33 segments

/// #define NUM_TLCS 4

//              01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
/*
int ssp[16] = {  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int sex[16] = {  0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0 };  // !
int sdq[16] = {  0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };  // "
int ssh[16] = {  0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0 };  // #
int sdl[16] = {  0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0 };  // $
int spc[16] = {  1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1 };  // %
int sam[16] = {  0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0 };  // &
int sap[16] = {  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };  // '
int sop[16] = {  0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };  // (
int scp[16] = {  0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0 };  // )
int sas[16] = {  0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 };  // *
int spl[16] = {  0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0 };  // +
int scm[16] = {  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 };  // ,
int smn[16] = {  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 };  // -
int spr[16] = {  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };  // .
int ssl[16] = {  0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 };  // /
int scl[16] = {  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 };  // :
int ssc[16] = {  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0 };  // ;
int slt[16] = {  0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };  // <
int seq[16] = {  0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 };  // =
int sgt[16] = {  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 };  // >
int sit[16] = {  0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 };  // ?
int sat[16] = {  1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };  // @
int sob[16] = {  0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 };  // [
int sbs[16] = {  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };  // backslash
int scb[16] = {  0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 };  // ]
int sca[16] = {  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 };  // ^
int sub[16] = {  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };  // _
*/

int n0[16] = {  1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1 };
int n1[16] = {  0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };
int n2[16] = {  0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0 };
int n3[16] = {  1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0 };
int n4[16] = {  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };
int n5[16] = {  1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1 };
int n6[16] = {  1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1 };
int n7[16] = {  1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 };
int n8[16] = {  1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1 };
int n9[16] = {  1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1 };

/*
int aa[16] = {  1, 2, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
int ab[16] = {  0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1 };
int ac[16] = {  0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1 };
int ad[16] = {  1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0 };
int ae[16] = {  0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1 };
int af[16] = {  0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1 };
int ag[16] = {  1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1 };
int ah[16] = {  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1 };
int ai[16] = {  0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0 };
int aj[16] = {  1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0 };
int ak[16] = {  0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1 };
int al[16] = {  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1 };
int am[16] = {  1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1 };
int an[16] = {  1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1 };
int ao[16] = {  1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1 };
int ap[16] = {  0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1 };
int aq[16] = {  1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1 };
int ar[16] = {  0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1 };
int as[16] = {  0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1 };
int at[16] = {  0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 };
int au[16] = {  1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1 };
int av[16] = {  1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
int aw[16] = {  1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1 };
int ax[16] = {  0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0 };
int ay[16] = {  0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0 };
int az[16] = {  0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0 };
*/

int *alphanums[] = {
  n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, 
  /* aa, ab, ac, ad, ae, af, ag, ah, ai, aj, ak, al, am, an, ao, ap, aq, ar, as, at, au, av, aw, ax, ay, az,
  ssp, sex, sdq, ssh, sdl, spc, sam, sap, sop, scp, sas, spl, scm, smn, spr, ssl, scl, ssc, slt, seq, sgt, 
  sit, sat, sob, sbs, scb, sca, sub */ };

int segs[64];

#define POWAN 100
#define DELAY 5000

#define OFF       0
#define AFTERGLOW 5
#define ON        10

#define N_SEGS (16 * NUM_TLCS)
#define MAX_BRIGHTNESS (4096 / 2)

void setup() { 
  Tlc.init(); 
  Tlc.clear(); 
  for(int s = 0; s < N_SEGS; ++s) { 
    Tlc.set(s, 0);
    segs[s] = OFF;
  } 
  Tlc.update(); 
  setTime(10, 30, 0, 11, 8, 2013);
}

void turn_segs_on_and_off(int *pattern1, int *pattern2, int *pattern3, int *pattern4) {
  int *patterns[4];
  patterns[0] = pattern1;
  patterns[1] = pattern2;
  patterns[2] = pattern3;
  patterns[3] = pattern4;
  
  // AFTERGLOW --> OFF
  for (int j = 0; j < 4; ++j) {
    for (int k = 0; k < 16; ++k) {
      int l = j * 16 + k;
      if (segs[l] == AFTERGLOW && patterns[j][k] == 0) {
        Tlc.set(l, 0);
      }
    }
  }
  Tlc.update();
  delayMicroseconds(POWAN);
  
  // ON --> AFTERGLOW
  for (int i = MAX_BRIGHTNESS - 1; i > 0; --i) {
    for (int j = 0; j < 4 /* 4 */; ++j) {
      for (int k = 0; k < 16; ++k) {
        int l = j * 16 + k;
        if (segs[l] == ON && patterns[j][k] == 0) {
          Tlc.set(l, i);
        }
      }
    }
    Tlc.update();
    delayMicroseconds(POWAN);
  }
  
  // _ --> ON
  for (int i = 0; i < MAX_BRIGHTNESS; ++i) {
    for (int j = 0; j < 4 /* 4 */; ++j) {
      for (int k = 0; k < 16; ++k) {
        int l = j * 16 + k;
        if (patterns[j][k] == 1) {
          Tlc.set(l, i);
        }
      }
    }
    Tlc.update();
    delayMicroseconds(POWAN);
  }
  
  for (int j = 0; j < 4; ++j) {
    for (int k = 0; k < 16; ++k) {
      // ON
      if (patterns[j][k] == 1) {
        segs[j * 16 + k] = ON;
      }
      // ON --> OFF
      else if (segs[j * 16 + k] == ON && patterns[j][k] == 0) {
        segs[j * 16 + k] = AFTERGLOW;
      }
      else {
        segs[j * 16 + k] = OFF;
      }
    }
  }
}

void loop() {
  int h = hour();
  int m = minute();
  int a0 = h / 10;
  int a1 = h % 10;
  int a2 = m / 10;
  int a3 = m % 10;
  turn_segs_on_and_off(alphanums[a0], alphanums[a1], alphanums[a2], alphanums[a3]);
  delay(DELAY);
}
