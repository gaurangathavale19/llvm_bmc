/* Copyright (C) 2023 ARM-CBMC
* This benchmark is part of ARM-CBMC */

#include <assert.h>
#include <pthread.h>

// Memory barriers
#define FENCE()

volatile int vars[4]; 
volatile int v_1_X0_1; 
volatile int v_1_X8_1; 
volatile int v_1_X12_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;
  FENCE();
  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v3_W0 = vars[1];
  int v4_W2 = v3_W0 ^ v3_W0;
  int v7_W3 = vars[2+v4_W2];
  int v8_W5 = v7_W3 ^ v7_W3;
  vars[3+v8_W5] = 1;
  int v11_W8 = vars[3];
  int v12_W9 = v11_W8 ^ v11_W8;
  vars[0+v12_W9] = 1;
  int v15_W12 = vars[0];
  int v30 = (v3_W0 == 1);
  v_1_X0_1 = v30;
  int v31 = (v11_W8 == 1);
  v_1_X8_1 = v31;
  int v32 = (v15_W12 == 1);
  v_1_X12_1 = v32;
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
  v_1_X8_1 = 0;
  v_1_X12_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v16 = vars[3];
  int v17 = (v16 == 1);
  int v18 = vars[0];
  int v19 = (v18 == 2);
  int v20 = vars[1];
  int v21 = (v20 == 1);
  int v22 = v_1_X0_1;
  int v23 = v_1_X8_1;
  int v24 = v_1_X12_1;
  int v25_conj = v23 & v24;
  int v26_conj = v22 & v25_conj;
  int v27_conj = v21 & v26_conj;
  int v28_conj = v19 & v27_conj;
  int v29_conj = v17 & v28_conj;
  if (v29_conj == 1) assert(0);
  return 0;
}