/* Copyright (C) 2023 ARM-CBMC
* This benchmark is part of ARM-CBMC */

#include <assert.h>
#include <pthread.h>

// Memory barriers
#define FENCE()

volatile int vars[2]; 
volatile int v_0_X2_0; 
volatile int v_1_X3_2; 
volatile int v_1_X4_2; 
volatile int v_1_X6_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  FENCE();
  int v3_W2 = vars[1];
  int v27 = (v3_W2 == 0);
  v_0_X2_0 = v27;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 1;
  vars[1] = 2;
  int v6_W3 = vars[1];
  int v9_W4 = vars[1];
  int v10_W5 = v9_W4 ^ v9_W4;
  int v13_W6 = vars[0+v10_W5];
  int v28 = (v6_W3 == 2);
  v_1_X3_2 = v28;
  int v29 = (v9_W4 == 2);
  v_1_X4_2 = v29;
  int v30 = (v13_W6 == 0);
  v_1_X6_0 = v30;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[0] = 0;
  v_0_X2_0 = 0;
  v_1_X3_2 = 0;
  v_1_X4_2 = 0;
  v_1_X6_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v14 = vars[0];
  int v15 = (v14 == 1);
  int v16 = vars[1];
  int v17 = (v16 == 2);
  int v18 = v_0_X2_0;
  int v19 = v_1_X3_2;
  int v20 = v_1_X4_2;
  int v21 = v_1_X6_0;
  int v22_conj = v20 & v21;
  int v23_conj = v19 & v22_conj;
  int v24_conj = v18 & v23_conj;
  int v25_conj = v17 & v24_conj;
  int v26_conj = v15 & v25_conj;
  if (v26_conj == 1) assert(0);
  return 0;
}