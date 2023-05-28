/* Copyright (C) 2023 ARM-CBMC
* This benchmark is part of ARM-CBMC */

#include <assert.h>
#include <pthread.h>
#include <stdatomic.h>

// Memory barriers
void dmbld();
void dmbst();
void dmbsy();
void isb();

atomic_long vars[3]; 
atomic_long atom_1_X0_1; 
atomic_long atom_1_X4_1; 
atomic_long atom_1_X6_0; 
atomic_long atom_1_X8_0; 
atomic_long atom_1_X9_1; 

void *t0(void *arg){
label_1:;
  atomic_store_explicit(&vars[0], 2, memory_order_relaxed);
  dmbsy();
  atomic_store_explicit(&vars[1], 1, memory_order_relaxed);
  return NULL;
}

void *t1(void *arg){
label_2:;
  long v3_W0 = atomic_load_explicit(&vars[1], memory_order_relaxed);
  if (v3_W0) goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  atomic_store_explicit(&vars[2], 1, memory_order_relaxed);
  long v6_W4 = atomic_load_explicit(&vars[2], memory_order_relaxed);
  long v7_W5 = v6_W4 ^ v6_W4;
  long v10_W6 = atomic_load_explicit(&vars[0+v7_W5], memory_order_relaxed);
  long v13_W8 = atomic_load_explicit(&vars[0], memory_order_relaxed);
  long v16_W9 = atomic_load_explicit(&vars[0], memory_order_relaxed);
  long v35 = (v3_W0 == 1);
  atomic_store_explicit(&atom_1_X0_1, v35, memory_order_seq_cst);
  long v36 = (v6_W4 == 1);
  atomic_store_explicit(&atom_1_X4_1, v36, memory_order_seq_cst);
  long v37 = (v10_W6 == 0);
  atomic_store_explicit(&atom_1_X6_0, v37, memory_order_seq_cst);
  long v38 = (v13_W8 == 0);
  atomic_store_explicit(&atom_1_X8_0, v38, memory_order_seq_cst);
  long v39 = (v16_W9 == 1);
  atomic_store_explicit(&atom_1_X9_1, v39, memory_order_seq_cst);
  return NULL;
}

void *t2(void *arg){
label_3:;
  atomic_store_explicit(&vars[0], 1, memory_order_relaxed);
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  atomic_init(&vars[2], 0);
  atomic_init(&vars[1], 0);
  atomic_init(&vars[0], 0);
  atomic_init(&atom_1_X0_1, 0); 
  atomic_init(&atom_1_X4_1, 0); 
  atomic_init(&atom_1_X6_0, 0); 
  atomic_init(&atom_1_X8_0, 0); 
  atomic_init(&atom_1_X9_1, 0); 

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  long v17 = atomic_load_explicit(&vars[0], memory_order_seq_cst);
  long v18 = (v17 == 2);
  long v19 = atomic_load_explicit(&vars[1], memory_order_seq_cst);
  long v20 = (v19 == 1);
  long v21 = atomic_load_explicit(&vars[2], memory_order_seq_cst);
  long v22 = (v21 == 1);
  long v23 = atomic_load_explicit(&atom_1_X0_1, memory_order_seq_cst);
  long v24 = atomic_load_explicit(&atom_1_X4_1, memory_order_seq_cst);
  long v25 = atomic_load_explicit(&atom_1_X6_0, memory_order_seq_cst);
  long v26 = atomic_load_explicit(&atom_1_X8_0, memory_order_seq_cst);
  long v27 = atomic_load_explicit(&atom_1_X9_1, memory_order_seq_cst);
  long v28_conj = v26 & v27;
  long v29_conj = v25 & v28_conj;
  long v30_conj = v24 & v29_conj;
  long v31_conj = v23 & v30_conj;
  long v32_conj = v22 & v31_conj;
  long v33_conj = v20 & v32_conj;
  long v34_conj = v18 & v33_conj;
  if (v34_conj == 1) assert(0);
  return 0;
}