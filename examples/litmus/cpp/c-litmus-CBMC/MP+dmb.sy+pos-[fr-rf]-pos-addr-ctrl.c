/* Copyright (C) 2023 ARM-CBMC
* This benchmark is part of ARM-CBMC */

#include <assert.h>
#include <pthread.h>

// Memory barriers
#define FENCE() asm volatile ("mfence" ::: "memory")

volatile int vars[3]; 
volatile int v_1_X0_1; 
volatile int v_1_X2_1; 
volatile int v_1_X3_2; 
volatile int v_1_X4_2; 
volatile int v_1_X8_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  FENCE();
  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v3_W0 = vars[1];
  int v6_W2 = vars[1];
  int v9_W3 = vars[1];
  int v12_W4 = vars[1];
  int v13_W5 = v12_W4 ^ v12_W4;
  int v16_W6 = vars[2+v13_W5];
  if (v16_W6) goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  int v19_W8 = vars[0];
  int v35 = (v3_W0 == 1);
  v_1_X0_1 = v35;
  int v36 = (v6_W2 == 1);
  v_1_X2_1 = v36;
  int v37 = (v9_W3 == 2);
  v_1_X3_2 = v37;
  int v38 = (v12_W4 == 2);
  v_1_X4_2 = v38;
  int v39 = (v19_W8 == 0);
  v_1_X8_0 = v39;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[1] = 2;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[2] = 0;
  vars[1] = 0;
  vars[0] = 0;
  v_1_X0_1 = 0;
  v_1_X2_1 = 0;
  v_1_X3_2 = 0;
  v_1_X4_2 = 0;
  v_1_X8_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v20 = vars[0];
  int v21 = (v20 == 1);
  int v22 = vars[1];
  int v23 = (v22 == 2);
  int v24 = v_1_X0_1;
  int v25 = v_1_X2_1;
  int v26 = v_1_X3_2;
  int v27 = v_1_X4_2;
  int v28 = v_1_X8_0;
  int v29_conj = v27 & v28;
  int v30_conj = v26 & v29_conj;
  int v31_conj = v25 & v30_conj;
  int v32_conj = v24 & v31_conj;
  int v33_conj = v23 & v32_conj;
  int v34_conj = v21 & v33_conj;
  if (v34_conj == 1) assert(0);
  return 0;
}
