/* Copyright (C) 2023 ARM-CBMC
* This benchmark is part of ARM-CBMC */

#include <assert.h>
#include <pthread.h>

// Memory barriers
#define FENCE() asm volatile ("mfence" ::: "memory")

volatile int vars[4]; 
volatile int v_1_X0_1; 
volatile int v_1_X9_0; 

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
  int v4_W2 = v3_W0 ^ v3_W0;
  int v7_W3 = vars[2+v4_W2];
  int v10_W5 = vars[2];
  if (v10_W5) goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  int v13_W6 = vars[3];
  int v16_W8 = vars[3];
  if (v16_W8) goto lbl_LC01; else goto lbl_LC01;
lbl_LC01:;
  int v19_W9 = vars[0];
  int v29 = (v3_W0 == 1);
  v_1_X0_1 = v29;
  int v30 = (v19_W9 == 0);
  v_1_X9_0 = v30;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[3] = 0;
  vars[2] = 0;
  vars[1] = 0;
  vars[0] = 0;
  v_1_X0_1 = 0;
  v_1_X9_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v20 = vars[0];
  int v21 = (v20 == 1);
  int v22 = vars[1];
  int v23 = (v22 == 1);
  int v24 = v_1_X0_1;
  int v25 = v_1_X9_0;
  int v26_conj = v24 & v25;
  int v27_conj = v23 & v26_conj;
  int v28_conj = v21 & v27_conj;
  if (v28_conj == 1) assert(0);
  return 0;
}