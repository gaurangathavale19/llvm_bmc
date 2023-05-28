/* Copyright (C) 2023 ARM-CBMC
* This benchmark is part of ARM-CBMC */

#include <assert.h>
#include <pthread.h>

// Memory barriers
#define FENCE() asm volatile ("mfence" ::: "memory")

volatile int vars[4]; 
volatile int v_1_X0_1; 
volatile int v_1_X4_1; 
volatile int v_1_X8_1; 
volatile int v_1_X10_0; 

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
  int v5_W2 = v4_W2 + 1;
  vars[2] = v5_W2;
  int v8_W4 = vars[2];
  int v9_W5 = v8_W4 ^ v8_W4;
  vars[3+v9_W5] = 1;
  int v12_W8 = vars[3];
  int v13_W9 = v12_W8 ^ v12_W8;
  int v16_W10 = vars[0+v13_W9];
  int v36 = (v3_W0 == 1);
  v_1_X0_1 = v36;
  int v37 = (v8_W4 == 1);
  v_1_X4_1 = v37;
  int v38 = (v12_W8 == 1);
  v_1_X8_1 = v38;
  int v39 = (v16_W10 == 0);
  v_1_X10_0 = v39;
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
  v_1_X4_1 = 0;
  v_1_X8_1 = 0;
  v_1_X10_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v17 = vars[3];
  int v18 = (v17 == 1);
  int v19 = vars[0];
  int v20 = (v19 == 1);
  int v21 = vars[1];
  int v22 = (v21 == 1);
  int v23 = vars[2];
  int v24 = (v23 == 1);
  int v25 = v_1_X0_1;
  int v26 = v_1_X4_1;
  int v27 = v_1_X8_1;
  int v28 = v_1_X10_0;
  int v29_conj = v27 & v28;
  int v30_conj = v26 & v29_conj;
  int v31_conj = v25 & v30_conj;
  int v32_conj = v24 & v31_conj;
  int v33_conj = v22 & v32_conj;
  int v34_conj = v20 & v33_conj;
  int v35_conj = v18 & v34_conj;
  if (v35_conj == 1) assert(0);
  return 0;
}