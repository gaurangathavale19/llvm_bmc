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

atomic_long vars[2]; 
atomic_long atom_1_X0_1; 
atomic_long atom_1_X2_0; 

void *t0(void *arg){
label_1:;
  atomic_store_explicit(&vars[0], 1, memory_order_release);
  dmbst();
  atomic_store_explicit(&vars[1], 1, memory_order_relaxed);
  return NULL;
}

void *t1(void *arg){
label_2:;
  long v3_W0 = atomic_load_explicit(&vars[1], memory_order_acquire);
  dmbsy();
  long v6_W2 = atomic_load_explicit(&vars[0], memory_order_acquire);
  long v10 = (v3_W0 == 1);
  atomic_store_explicit(&atom_1_X0_1, v10, memory_order_seq_cst);
  long v11 = (v6_W2 == 0);
  atomic_store_explicit(&atom_1_X2_0, v11, memory_order_seq_cst);
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  atomic_init(&vars[1], 0);
  atomic_init(&vars[0], 0);
  atomic_init(&atom_1_X0_1, 0); 
  atomic_init(&atom_1_X2_0, 0); 

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  long v7 = atomic_load_explicit(&atom_1_X0_1, memory_order_seq_cst);
  long v8 = atomic_load_explicit(&atom_1_X2_0, memory_order_seq_cst);
  long v9_conj = v7 & v8;
  if (v9_conj == 1) assert(0);
  return 0;
}