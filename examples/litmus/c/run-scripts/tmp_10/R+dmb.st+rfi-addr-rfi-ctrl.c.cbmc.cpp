// 0:vars:3
// 6:thr0:1
// 3:atom_1_X2_2:1
// 4:atom_1_X6_1:1
// 5:atom_1_X7_0:1
// 7:thr1:1
#define ADDRSIZE 8
#define NPROC 3
#define NCONTEXT 10

#define ASSUME(stmt) __CPROVER_assume(stmt)
#define ASSERT(stmt) __CPROVER_assert(stmt, "error")

#define max(a,b) (a>b?a:b)

char __get_rng();
char get_rng( char from, char to ) {
   char ret = __get_rng();
   ASSUME(ret >= from && ret <= to);
   return ret;
}

char get_rng_th( char from, char to ) {
   char ret = __get_rng();
   ASSUME(ret >= from && ret <= to);
   return ret;
}

int main(int argc, char **argv) {
  // declare arrays for intial value version in contexts
  int meminit_[ADDRSIZE*NCONTEXT];
  #define meminit(x,k) meminit_[(x)*NCONTEXT+k]
  int coinit_[ADDRSIZE*NCONTEXT];
  #define coinit(x,k) coinit_[(x)*NCONTEXT+k]
  int deltainit_[ADDRSIZE*NCONTEXT];
  #define deltainit(x,k) deltainit_[(x)*NCONTEXT+k]

  // declare arrays for running value version in contexts
  int mem_[ADDRSIZE*NCONTEXT];
  #define mem(x,k) mem_[(x)*NCONTEXT+k]
  int co_[ADDRSIZE*NCONTEXT];
  #define co(x,k) co_[(x)*NCONTEXT+k]
  int delta_[ADDRSIZE*NCONTEXT];
  #define delta(x,k) delta_[(x)*NCONTEXT+k]

  // declare arrays for local buffer and observed writes
  int buff_[NPROC*ADDRSIZE];
  #define buff(x,k) buff_[(x)*ADDRSIZE+k]
  int pw_[NPROC*ADDRSIZE];
  #define pw(x,k) pw_[(x)*ADDRSIZE+k]

  // declare arrays for context stamps
  char cr_[NPROC*ADDRSIZE];
  #define cr(x,k) cr_[(x)*ADDRSIZE+k]
  char iw_[NPROC*ADDRSIZE];
  #define iw(x,k) iw_[(x)*ADDRSIZE+k]
  char cw_[NPROC*ADDRSIZE];
  #define cw(x,k) cw_[(x)*ADDRSIZE+k]
  char cx_[NPROC*ADDRSIZE];
  #define cx(x,k) cx_[(x)*ADDRSIZE+k]
  char is_[NPROC*ADDRSIZE];
  #define is(x,k) is_[(x)*ADDRSIZE+k]
  char cs_[NPROC*ADDRSIZE];
  #define cs(x,k) cs_[(x)*ADDRSIZE+k]
  char crmax_[NPROC*ADDRSIZE];
  #define crmax(x,k) crmax_[(x)*ADDRSIZE+k]

  char sforbid_[ADDRSIZE*NCONTEXT];
  #define sforbid(x,k) sforbid_[(x)*NCONTEXT+k]

  // declare arrays for synchronizations
  int cl[NPROC];
  int cdy[NPROC];
  int cds[NPROC];
  int cdl[NPROC];
  int cisb[NPROC];
  int caddr[NPROC];
  int cctrl[NPROC];
  int cstart[NPROC];
  int creturn[NPROC];

  // declare arrays for contexts activity
  int active[NCONTEXT];
  int ctx_used[NCONTEXT];


  __LOCALS__
  buff(0,0) = 0;
  pw(0,0) = 0;
  cr(0,0) = 0;
  iw(0,0) = 0;
  cw(0,0) = 0;
  cx(0,0) = 0;
  is(0,0) = 0;
  cs(0,0) = 0;
  crmax(0,0) = 0;
  buff(0,1) = 0;
  pw(0,1) = 0;
  cr(0,1) = 0;
  iw(0,1) = 0;
  cw(0,1) = 0;
  cx(0,1) = 0;
  is(0,1) = 0;
  cs(0,1) = 0;
  crmax(0,1) = 0;
  buff(0,2) = 0;
  pw(0,2) = 0;
  cr(0,2) = 0;
  iw(0,2) = 0;
  cw(0,2) = 0;
  cx(0,2) = 0;
  is(0,2) = 0;
  cs(0,2) = 0;
  crmax(0,2) = 0;
  buff(0,3) = 0;
  pw(0,3) = 0;
  cr(0,3) = 0;
  iw(0,3) = 0;
  cw(0,3) = 0;
  cx(0,3) = 0;
  is(0,3) = 0;
  cs(0,3) = 0;
  crmax(0,3) = 0;
  buff(0,4) = 0;
  pw(0,4) = 0;
  cr(0,4) = 0;
  iw(0,4) = 0;
  cw(0,4) = 0;
  cx(0,4) = 0;
  is(0,4) = 0;
  cs(0,4) = 0;
  crmax(0,4) = 0;
  buff(0,5) = 0;
  pw(0,5) = 0;
  cr(0,5) = 0;
  iw(0,5) = 0;
  cw(0,5) = 0;
  cx(0,5) = 0;
  is(0,5) = 0;
  cs(0,5) = 0;
  crmax(0,5) = 0;
  buff(0,6) = 0;
  pw(0,6) = 0;
  cr(0,6) = 0;
  iw(0,6) = 0;
  cw(0,6) = 0;
  cx(0,6) = 0;
  is(0,6) = 0;
  cs(0,6) = 0;
  crmax(0,6) = 0;
  buff(0,7) = 0;
  pw(0,7) = 0;
  cr(0,7) = 0;
  iw(0,7) = 0;
  cw(0,7) = 0;
  cx(0,7) = 0;
  is(0,7) = 0;
  cs(0,7) = 0;
  crmax(0,7) = 0;
  cl[0] = 0;
  cdy[0] = 0;
  cds[0] = 0;
  cdl[0] = 0;
  cisb[0] = 0;
  caddr[0] = 0;
  cctrl[0] = 0;
  cstart[0] = get_rng(0,NCONTEXT-1);
  creturn[0] = get_rng(0,NCONTEXT-1);
  buff(1,0) = 0;
  pw(1,0) = 0;
  cr(1,0) = 0;
  iw(1,0) = 0;
  cw(1,0) = 0;
  cx(1,0) = 0;
  is(1,0) = 0;
  cs(1,0) = 0;
  crmax(1,0) = 0;
  buff(1,1) = 0;
  pw(1,1) = 0;
  cr(1,1) = 0;
  iw(1,1) = 0;
  cw(1,1) = 0;
  cx(1,1) = 0;
  is(1,1) = 0;
  cs(1,1) = 0;
  crmax(1,1) = 0;
  buff(1,2) = 0;
  pw(1,2) = 0;
  cr(1,2) = 0;
  iw(1,2) = 0;
  cw(1,2) = 0;
  cx(1,2) = 0;
  is(1,2) = 0;
  cs(1,2) = 0;
  crmax(1,2) = 0;
  buff(1,3) = 0;
  pw(1,3) = 0;
  cr(1,3) = 0;
  iw(1,3) = 0;
  cw(1,3) = 0;
  cx(1,3) = 0;
  is(1,3) = 0;
  cs(1,3) = 0;
  crmax(1,3) = 0;
  buff(1,4) = 0;
  pw(1,4) = 0;
  cr(1,4) = 0;
  iw(1,4) = 0;
  cw(1,4) = 0;
  cx(1,4) = 0;
  is(1,4) = 0;
  cs(1,4) = 0;
  crmax(1,4) = 0;
  buff(1,5) = 0;
  pw(1,5) = 0;
  cr(1,5) = 0;
  iw(1,5) = 0;
  cw(1,5) = 0;
  cx(1,5) = 0;
  is(1,5) = 0;
  cs(1,5) = 0;
  crmax(1,5) = 0;
  buff(1,6) = 0;
  pw(1,6) = 0;
  cr(1,6) = 0;
  iw(1,6) = 0;
  cw(1,6) = 0;
  cx(1,6) = 0;
  is(1,6) = 0;
  cs(1,6) = 0;
  crmax(1,6) = 0;
  buff(1,7) = 0;
  pw(1,7) = 0;
  cr(1,7) = 0;
  iw(1,7) = 0;
  cw(1,7) = 0;
  cx(1,7) = 0;
  is(1,7) = 0;
  cs(1,7) = 0;
  crmax(1,7) = 0;
  cl[1] = 0;
  cdy[1] = 0;
  cds[1] = 0;
  cdl[1] = 0;
  cisb[1] = 0;
  caddr[1] = 0;
  cctrl[1] = 0;
  cstart[1] = get_rng(0,NCONTEXT-1);
  creturn[1] = get_rng(0,NCONTEXT-1);
  buff(2,0) = 0;
  pw(2,0) = 0;
  cr(2,0) = 0;
  iw(2,0) = 0;
  cw(2,0) = 0;
  cx(2,0) = 0;
  is(2,0) = 0;
  cs(2,0) = 0;
  crmax(2,0) = 0;
  buff(2,1) = 0;
  pw(2,1) = 0;
  cr(2,1) = 0;
  iw(2,1) = 0;
  cw(2,1) = 0;
  cx(2,1) = 0;
  is(2,1) = 0;
  cs(2,1) = 0;
  crmax(2,1) = 0;
  buff(2,2) = 0;
  pw(2,2) = 0;
  cr(2,2) = 0;
  iw(2,2) = 0;
  cw(2,2) = 0;
  cx(2,2) = 0;
  is(2,2) = 0;
  cs(2,2) = 0;
  crmax(2,2) = 0;
  buff(2,3) = 0;
  pw(2,3) = 0;
  cr(2,3) = 0;
  iw(2,3) = 0;
  cw(2,3) = 0;
  cx(2,3) = 0;
  is(2,3) = 0;
  cs(2,3) = 0;
  crmax(2,3) = 0;
  buff(2,4) = 0;
  pw(2,4) = 0;
  cr(2,4) = 0;
  iw(2,4) = 0;
  cw(2,4) = 0;
  cx(2,4) = 0;
  is(2,4) = 0;
  cs(2,4) = 0;
  crmax(2,4) = 0;
  buff(2,5) = 0;
  pw(2,5) = 0;
  cr(2,5) = 0;
  iw(2,5) = 0;
  cw(2,5) = 0;
  cx(2,5) = 0;
  is(2,5) = 0;
  cs(2,5) = 0;
  crmax(2,5) = 0;
  buff(2,6) = 0;
  pw(2,6) = 0;
  cr(2,6) = 0;
  iw(2,6) = 0;
  cw(2,6) = 0;
  cx(2,6) = 0;
  is(2,6) = 0;
  cs(2,6) = 0;
  crmax(2,6) = 0;
  buff(2,7) = 0;
  pw(2,7) = 0;
  cr(2,7) = 0;
  iw(2,7) = 0;
  cw(2,7) = 0;
  cx(2,7) = 0;
  is(2,7) = 0;
  cs(2,7) = 0;
  crmax(2,7) = 0;
  cl[2] = 0;
  cdy[2] = 0;
  cds[2] = 0;
  cdl[2] = 0;
  cisb[2] = 0;
  caddr[2] = 0;
  cctrl[2] = 0;
  cstart[2] = get_rng(0,NCONTEXT-1);
  creturn[2] = get_rng(0,NCONTEXT-1);
  // Dumping initializations
  mem(0+0,0) = 0;
  mem(0+1,0) = 0;
  mem(0+2,0) = 0;
  mem(6+0,0) = 0;
  mem(3+0,0) = 0;
  mem(4+0,0) = 0;
  mem(5+0,0) = 0;
  mem(7+0,0) = 0;
  // Dumping context matching equalities
  co(0,0) = 0;
  delta(0,0) = -1;
  mem(0,1) = meminit(0,1);
  co(0,1) = coinit(0,1);
  delta(0,1) = deltainit(0,1);
  mem(0,2) = meminit(0,2);
  co(0,2) = coinit(0,2);
  delta(0,2) = deltainit(0,2);
  mem(0,3) = meminit(0,3);
  co(0,3) = coinit(0,3);
  delta(0,3) = deltainit(0,3);
  mem(0,4) = meminit(0,4);
  co(0,4) = coinit(0,4);
  delta(0,4) = deltainit(0,4);
  mem(0,5) = meminit(0,5);
  co(0,5) = coinit(0,5);
  delta(0,5) = deltainit(0,5);
  mem(0,6) = meminit(0,6);
  co(0,6) = coinit(0,6);
  delta(0,6) = deltainit(0,6);
  mem(0,7) = meminit(0,7);
  co(0,7) = coinit(0,7);
  delta(0,7) = deltainit(0,7);
  mem(0,8) = meminit(0,8);
  co(0,8) = coinit(0,8);
  delta(0,8) = deltainit(0,8);
  mem(0,9) = meminit(0,9);
  co(0,9) = coinit(0,9);
  delta(0,9) = deltainit(0,9);
  co(1,0) = 0;
  delta(1,0) = -1;
  mem(1,1) = meminit(1,1);
  co(1,1) = coinit(1,1);
  delta(1,1) = deltainit(1,1);
  mem(1,2) = meminit(1,2);
  co(1,2) = coinit(1,2);
  delta(1,2) = deltainit(1,2);
  mem(1,3) = meminit(1,3);
  co(1,3) = coinit(1,3);
  delta(1,3) = deltainit(1,3);
  mem(1,4) = meminit(1,4);
  co(1,4) = coinit(1,4);
  delta(1,4) = deltainit(1,4);
  mem(1,5) = meminit(1,5);
  co(1,5) = coinit(1,5);
  delta(1,5) = deltainit(1,5);
  mem(1,6) = meminit(1,6);
  co(1,6) = coinit(1,6);
  delta(1,6) = deltainit(1,6);
  mem(1,7) = meminit(1,7);
  co(1,7) = coinit(1,7);
  delta(1,7) = deltainit(1,7);
  mem(1,8) = meminit(1,8);
  co(1,8) = coinit(1,8);
  delta(1,8) = deltainit(1,8);
  mem(1,9) = meminit(1,9);
  co(1,9) = coinit(1,9);
  delta(1,9) = deltainit(1,9);
  co(2,0) = 0;
  delta(2,0) = -1;
  mem(2,1) = meminit(2,1);
  co(2,1) = coinit(2,1);
  delta(2,1) = deltainit(2,1);
  mem(2,2) = meminit(2,2);
  co(2,2) = coinit(2,2);
  delta(2,2) = deltainit(2,2);
  mem(2,3) = meminit(2,3);
  co(2,3) = coinit(2,3);
  delta(2,3) = deltainit(2,3);
  mem(2,4) = meminit(2,4);
  co(2,4) = coinit(2,4);
  delta(2,4) = deltainit(2,4);
  mem(2,5) = meminit(2,5);
  co(2,5) = coinit(2,5);
  delta(2,5) = deltainit(2,5);
  mem(2,6) = meminit(2,6);
  co(2,6) = coinit(2,6);
  delta(2,6) = deltainit(2,6);
  mem(2,7) = meminit(2,7);
  co(2,7) = coinit(2,7);
  delta(2,7) = deltainit(2,7);
  mem(2,8) = meminit(2,8);
  co(2,8) = coinit(2,8);
  delta(2,8) = deltainit(2,8);
  mem(2,9) = meminit(2,9);
  co(2,9) = coinit(2,9);
  delta(2,9) = deltainit(2,9);
  co(3,0) = 0;
  delta(3,0) = -1;
  mem(3,1) = meminit(3,1);
  co(3,1) = coinit(3,1);
  delta(3,1) = deltainit(3,1);
  mem(3,2) = meminit(3,2);
  co(3,2) = coinit(3,2);
  delta(3,2) = deltainit(3,2);
  mem(3,3) = meminit(3,3);
  co(3,3) = coinit(3,3);
  delta(3,3) = deltainit(3,3);
  mem(3,4) = meminit(3,4);
  co(3,4) = coinit(3,4);
  delta(3,4) = deltainit(3,4);
  mem(3,5) = meminit(3,5);
  co(3,5) = coinit(3,5);
  delta(3,5) = deltainit(3,5);
  mem(3,6) = meminit(3,6);
  co(3,6) = coinit(3,6);
  delta(3,6) = deltainit(3,6);
  mem(3,7) = meminit(3,7);
  co(3,7) = coinit(3,7);
  delta(3,7) = deltainit(3,7);
  mem(3,8) = meminit(3,8);
  co(3,8) = coinit(3,8);
  delta(3,8) = deltainit(3,8);
  mem(3,9) = meminit(3,9);
  co(3,9) = coinit(3,9);
  delta(3,9) = deltainit(3,9);
  co(4,0) = 0;
  delta(4,0) = -1;
  mem(4,1) = meminit(4,1);
  co(4,1) = coinit(4,1);
  delta(4,1) = deltainit(4,1);
  mem(4,2) = meminit(4,2);
  co(4,2) = coinit(4,2);
  delta(4,2) = deltainit(4,2);
  mem(4,3) = meminit(4,3);
  co(4,3) = coinit(4,3);
  delta(4,3) = deltainit(4,3);
  mem(4,4) = meminit(4,4);
  co(4,4) = coinit(4,4);
  delta(4,4) = deltainit(4,4);
  mem(4,5) = meminit(4,5);
  co(4,5) = coinit(4,5);
  delta(4,5) = deltainit(4,5);
  mem(4,6) = meminit(4,6);
  co(4,6) = coinit(4,6);
  delta(4,6) = deltainit(4,6);
  mem(4,7) = meminit(4,7);
  co(4,7) = coinit(4,7);
  delta(4,7) = deltainit(4,7);
  mem(4,8) = meminit(4,8);
  co(4,8) = coinit(4,8);
  delta(4,8) = deltainit(4,8);
  mem(4,9) = meminit(4,9);
  co(4,9) = coinit(4,9);
  delta(4,9) = deltainit(4,9);
  co(5,0) = 0;
  delta(5,0) = -1;
  mem(5,1) = meminit(5,1);
  co(5,1) = coinit(5,1);
  delta(5,1) = deltainit(5,1);
  mem(5,2) = meminit(5,2);
  co(5,2) = coinit(5,2);
  delta(5,2) = deltainit(5,2);
  mem(5,3) = meminit(5,3);
  co(5,3) = coinit(5,3);
  delta(5,3) = deltainit(5,3);
  mem(5,4) = meminit(5,4);
  co(5,4) = coinit(5,4);
  delta(5,4) = deltainit(5,4);
  mem(5,5) = meminit(5,5);
  co(5,5) = coinit(5,5);
  delta(5,5) = deltainit(5,5);
  mem(5,6) = meminit(5,6);
  co(5,6) = coinit(5,6);
  delta(5,6) = deltainit(5,6);
  mem(5,7) = meminit(5,7);
  co(5,7) = coinit(5,7);
  delta(5,7) = deltainit(5,7);
  mem(5,8) = meminit(5,8);
  co(5,8) = coinit(5,8);
  delta(5,8) = deltainit(5,8);
  mem(5,9) = meminit(5,9);
  co(5,9) = coinit(5,9);
  delta(5,9) = deltainit(5,9);
  co(6,0) = 0;
  delta(6,0) = -1;
  mem(6,1) = meminit(6,1);
  co(6,1) = coinit(6,1);
  delta(6,1) = deltainit(6,1);
  mem(6,2) = meminit(6,2);
  co(6,2) = coinit(6,2);
  delta(6,2) = deltainit(6,2);
  mem(6,3) = meminit(6,3);
  co(6,3) = coinit(6,3);
  delta(6,3) = deltainit(6,3);
  mem(6,4) = meminit(6,4);
  co(6,4) = coinit(6,4);
  delta(6,4) = deltainit(6,4);
  mem(6,5) = meminit(6,5);
  co(6,5) = coinit(6,5);
  delta(6,5) = deltainit(6,5);
  mem(6,6) = meminit(6,6);
  co(6,6) = coinit(6,6);
  delta(6,6) = deltainit(6,6);
  mem(6,7) = meminit(6,7);
  co(6,7) = coinit(6,7);
  delta(6,7) = deltainit(6,7);
  mem(6,8) = meminit(6,8);
  co(6,8) = coinit(6,8);
  delta(6,8) = deltainit(6,8);
  mem(6,9) = meminit(6,9);
  co(6,9) = coinit(6,9);
  delta(6,9) = deltainit(6,9);
  co(7,0) = 0;
  delta(7,0) = -1;
  mem(7,1) = meminit(7,1);
  co(7,1) = coinit(7,1);
  delta(7,1) = deltainit(7,1);
  mem(7,2) = meminit(7,2);
  co(7,2) = coinit(7,2);
  delta(7,2) = deltainit(7,2);
  mem(7,3) = meminit(7,3);
  co(7,3) = coinit(7,3);
  delta(7,3) = deltainit(7,3);
  mem(7,4) = meminit(7,4);
  co(7,4) = coinit(7,4);
  delta(7,4) = deltainit(7,4);
  mem(7,5) = meminit(7,5);
  co(7,5) = coinit(7,5);
  delta(7,5) = deltainit(7,5);
  mem(7,6) = meminit(7,6);
  co(7,6) = coinit(7,6);
  delta(7,6) = deltainit(7,6);
  mem(7,7) = meminit(7,7);
  co(7,7) = coinit(7,7);
  delta(7,7) = deltainit(7,7);
  mem(7,8) = meminit(7,8);
  co(7,8) = coinit(7,8);
  delta(7,8) = deltainit(7,8);
  mem(7,9) = meminit(7,9);
  co(7,9) = coinit(7,9);
  delta(7,9) = deltainit(7,9);
  // Dumping thread 1
  int ret_thread_1 = 0;
  cdy[1] = get_rng(0,NCONTEXT-1);
  ASSUME(cdy[1] >= cstart[1]);
T1BLOCK0:
  //   call void @llvm.dbg.value(metadata i8* %arg, metadata !37, metadata !DIExpression()), !dbg !46

  //   br label %label_1, !dbg !47
  goto T1BLOCK1;

T1BLOCK1:
  //   call void @llvm.dbg.label(metadata !45), !dbg !48

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 0), metadata !38, metadata !DIExpression()), !dbg !49

  //   call void @llvm.dbg.value(metadata i64 1, metadata !41, metadata !DIExpression()), !dbg !49

  //   store atomic i64 1, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 0) monotonic, align 8, !dbg !50
  // ST: Guess
  iw(1,0) = get_rng(0,NCONTEXT-1);// 1 ASSIGN STIW 
  old_cw = cw(1,0);
  cw(1,0) = get_rng(0,NCONTEXT-1);// 1 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(1,0)] == 1);
  ASSUME(active[cw(1,0)] == 1);
  ASSUME(sforbid(0,cw(1,0))== 0);
  ASSUME(iw(1,0) >= 0);
  ASSUME(iw(1,0) >= 0);
  ASSUME(cw(1,0) >= iw(1,0));
  ASSUME(cw(1,0) >= old_cw);
  ASSUME(cw(1,0) >= cr(1,0));
  ASSUME(cw(1,0) >= cl[1]);
  ASSUME(cw(1,0) >= cisb[1]);
  ASSUME(cw(1,0) >= cdy[1]);
  ASSUME(cw(1,0) >= cdl[1]);
  ASSUME(cw(1,0) >= cds[1]);
  ASSUME(cw(1,0) >= cctrl[1]);
  ASSUME(cw(1,0) >= caddr[1]);
  // Update
  caddr[1] = max(caddr[1],0);
  buff(1,0) = 1;
  mem(0,cw(1,0)) = 1;
  co(0,cw(1,0))+=1;
  delta(0,cw(1,0)) = -1;
  ASSUME(creturn[1] >= cw(1,0));

  //   call void (...) @dmbst(), !dbg !51
  // dumbst: Guess
  cds[1] = get_rng(0,NCONTEXT-1);
  // Check
  ASSUME(cds[1] >= cdy[1]);
  ASSUME(cds[1] >= cw(1,0+0));
  ASSUME(cds[1] >= cw(1,0+1));
  ASSUME(cds[1] >= cw(1,0+2));
  ASSUME(cds[1] >= cw(1,6+0));
  ASSUME(cds[1] >= cw(1,3+0));
  ASSUME(cds[1] >= cw(1,4+0));
  ASSUME(cds[1] >= cw(1,5+0));
  ASSUME(cds[1] >= cw(1,7+0));
  ASSUME(creturn[1] >= cds[1]);

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 1), metadata !42, metadata !DIExpression()), !dbg !52

  //   call void @llvm.dbg.value(metadata i64 1, metadata !44, metadata !DIExpression()), !dbg !52

  //   store atomic i64 1, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 1) monotonic, align 8, !dbg !53
  // ST: Guess
  iw(1,0+1*1) = get_rng(0,NCONTEXT-1);// 1 ASSIGN STIW 
  old_cw = cw(1,0+1*1);
  cw(1,0+1*1) = get_rng(0,NCONTEXT-1);// 1 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(1,0+1*1)] == 1);
  ASSUME(active[cw(1,0+1*1)] == 1);
  ASSUME(sforbid(0+1*1,cw(1,0+1*1))== 0);
  ASSUME(iw(1,0+1*1) >= 0);
  ASSUME(iw(1,0+1*1) >= 0);
  ASSUME(cw(1,0+1*1) >= iw(1,0+1*1));
  ASSUME(cw(1,0+1*1) >= old_cw);
  ASSUME(cw(1,0+1*1) >= cr(1,0+1*1));
  ASSUME(cw(1,0+1*1) >= cl[1]);
  ASSUME(cw(1,0+1*1) >= cisb[1]);
  ASSUME(cw(1,0+1*1) >= cdy[1]);
  ASSUME(cw(1,0+1*1) >= cdl[1]);
  ASSUME(cw(1,0+1*1) >= cds[1]);
  ASSUME(cw(1,0+1*1) >= cctrl[1]);
  ASSUME(cw(1,0+1*1) >= caddr[1]);
  // Update
  caddr[1] = max(caddr[1],0);
  buff(1,0+1*1) = 1;
  mem(0+1*1,cw(1,0+1*1)) = 1;
  co(0+1*1,cw(1,0+1*1))+=1;
  delta(0+1*1,cw(1,0+1*1)) = -1;
  ASSUME(creturn[1] >= cw(1,0+1*1));

  //   ret i8* null, !dbg !54
  ret_thread_1 = (- 1);


  // Dumping thread 2
  int ret_thread_2 = 0;
  cdy[2] = get_rng(0,NCONTEXT-1);
  ASSUME(cdy[2] >= cstart[2]);
T2BLOCK0:
  //   call void @llvm.dbg.value(metadata i8* %arg, metadata !57, metadata !DIExpression()), !dbg !92

  //   br label %label_2, !dbg !74
  goto T2BLOCK1;

T2BLOCK1:
  //   call void @llvm.dbg.label(metadata !90), !dbg !94

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 1), metadata !58, metadata !DIExpression()), !dbg !95

  //   call void @llvm.dbg.value(metadata i64 2, metadata !60, metadata !DIExpression()), !dbg !95

  //   store atomic i64 2, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 1) monotonic, align 8, !dbg !77
  // ST: Guess
  iw(2,0+1*1) = get_rng(0,NCONTEXT-1);// 2 ASSIGN STIW 
  old_cw = cw(2,0+1*1);
  cw(2,0+1*1) = get_rng(0,NCONTEXT-1);// 2 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(2,0+1*1)] == 2);
  ASSUME(active[cw(2,0+1*1)] == 2);
  ASSUME(sforbid(0+1*1,cw(2,0+1*1))== 0);
  ASSUME(iw(2,0+1*1) >= 0);
  ASSUME(iw(2,0+1*1) >= 0);
  ASSUME(cw(2,0+1*1) >= iw(2,0+1*1));
  ASSUME(cw(2,0+1*1) >= old_cw);
  ASSUME(cw(2,0+1*1) >= cr(2,0+1*1));
  ASSUME(cw(2,0+1*1) >= cl[2]);
  ASSUME(cw(2,0+1*1) >= cisb[2]);
  ASSUME(cw(2,0+1*1) >= cdy[2]);
  ASSUME(cw(2,0+1*1) >= cdl[2]);
  ASSUME(cw(2,0+1*1) >= cds[2]);
  ASSUME(cw(2,0+1*1) >= cctrl[2]);
  ASSUME(cw(2,0+1*1) >= caddr[2]);
  // Update
  caddr[2] = max(caddr[2],0);
  buff(2,0+1*1) = 2;
  mem(0+1*1,cw(2,0+1*1)) = 2;
  co(0+1*1,cw(2,0+1*1))+=1;
  delta(0+1*1,cw(2,0+1*1)) = -1;
  ASSUME(creturn[2] >= cw(2,0+1*1));

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 1), metadata !63, metadata !DIExpression()), !dbg !97

  //   %0 = load atomic i64, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 1) monotonic, align 8, !dbg !79
  // LD: Guess
  old_cr = cr(2,0+1*1);
  cr(2,0+1*1) = get_rng(0,NCONTEXT-1);// 2 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(2,0+1*1)] == 2);
  ASSUME(cr(2,0+1*1) >= iw(2,0+1*1));
  ASSUME(cr(2,0+1*1) >= 0);
  ASSUME(cr(2,0+1*1) >= cdy[2]);
  ASSUME(cr(2,0+1*1) >= cisb[2]);
  ASSUME(cr(2,0+1*1) >= cdl[2]);
  ASSUME(cr(2,0+1*1) >= cl[2]);
  // Update
  creg_r0 = cr(2,0+1*1);
  crmax(2,0+1*1) = max(crmax(2,0+1*1),cr(2,0+1*1));
  caddr[2] = max(caddr[2],0);
  if(cr(2,0+1*1) < cw(2,0+1*1)) {
    r0 = buff(2,0+1*1);
    ASSUME((!(( (cw(2,0+1*1) < 1) && (1 < crmax(2,0+1*1)) )))||(sforbid(0+1*1,1)> 0));
    ASSUME((!(( (cw(2,0+1*1) < 2) && (2 < crmax(2,0+1*1)) )))||(sforbid(0+1*1,2)> 0));
    ASSUME((!(( (cw(2,0+1*1) < 3) && (3 < crmax(2,0+1*1)) )))||(sforbid(0+1*1,3)> 0));
    ASSUME((!(( (cw(2,0+1*1) < 4) && (4 < crmax(2,0+1*1)) )))||(sforbid(0+1*1,4)> 0));
    ASSUME((!(( (cw(2,0+1*1) < 5) && (5 < crmax(2,0+1*1)) )))||(sforbid(0+1*1,5)> 0));
    ASSUME((!(( (cw(2,0+1*1) < 6) && (6 < crmax(2,0+1*1)) )))||(sforbid(0+1*1,6)> 0));
    ASSUME((!(( (cw(2,0+1*1) < 7) && (7 < crmax(2,0+1*1)) )))||(sforbid(0+1*1,7)> 0));
    ASSUME((!(( (cw(2,0+1*1) < 8) && (8 < crmax(2,0+1*1)) )))||(sforbid(0+1*1,8)> 0));
    ASSUME((!(( (cw(2,0+1*1) < 9) && (9 < crmax(2,0+1*1)) )))||(sforbid(0+1*1,9)> 0));
  } else {
    if(pw(2,0+1*1) != co(0+1*1,cr(2,0+1*1))) {
      ASSUME(cr(2,0+1*1) >= old_cr);
    }
    pw(2,0+1*1) = co(0+1*1,cr(2,0+1*1));
    r0 = mem(0+1*1,cr(2,0+1*1));
  }
  ASSUME(creturn[2] >= cr(2,0+1*1));

  //   call void @llvm.dbg.value(metadata i64 %0, metadata !65, metadata !DIExpression()), !dbg !97

  //   %conv = trunc i64 %0 to i32, !dbg !80

  //   call void @llvm.dbg.value(metadata i32 %conv, metadata !61, metadata !DIExpression()), !dbg !92

  //   %xor = xor i32 %conv, %conv, !dbg !81
  creg_r1 = max(creg_r0,creg_r0);
  ASSUME(active[creg_r1] == 2);
  r1 = r0 ^ r0;

  //   call void @llvm.dbg.value(metadata i32 %xor, metadata !66, metadata !DIExpression()), !dbg !92

  //   %add = add nsw i32 2, %xor, !dbg !82
  creg_r2 = max(0,creg_r1);
  ASSUME(active[creg_r2] == 2);
  r2 = 2 + r1;

  //   %idxprom = sext i32 %add to i64, !dbg !82

  //   %arrayidx = getelementptr inbounds [3 x i64], [3 x i64]* @vars, i64 0, i64 %idxprom, !dbg !82
  r3 = 0+r2*1;
  ASSUME(creg_r3 >= 0);
  ASSUME(creg_r3 >= creg_r2);
  ASSUME(active[creg_r3] == 2);

  //   call void @llvm.dbg.value(metadata i64* %arrayidx, metadata !67, metadata !DIExpression()), !dbg !102

  //   call void @llvm.dbg.value(metadata i64 1, metadata !69, metadata !DIExpression()), !dbg !102

  //   store atomic i64 1, i64* %arrayidx monotonic, align 8, !dbg !82
  // ST: Guess
  iw(2,r3) = get_rng(0,NCONTEXT-1);// 2 ASSIGN STIW 
  old_cw = cw(2,r3);
  cw(2,r3) = get_rng(0,NCONTEXT-1);// 2 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(2,r3)] == 2);
  ASSUME(active[cw(2,r3)] == 2);
  ASSUME(sforbid(r3,cw(2,r3))== 0);
  ASSUME(iw(2,r3) >= 0);
  ASSUME(iw(2,r3) >= creg_r3);
  ASSUME(cw(2,r3) >= iw(2,r3));
  ASSUME(cw(2,r3) >= old_cw);
  ASSUME(cw(2,r3) >= cr(2,r3));
  ASSUME(cw(2,r3) >= cl[2]);
  ASSUME(cw(2,r3) >= cisb[2]);
  ASSUME(cw(2,r3) >= cdy[2]);
  ASSUME(cw(2,r3) >= cdl[2]);
  ASSUME(cw(2,r3) >= cds[2]);
  ASSUME(cw(2,r3) >= cctrl[2]);
  ASSUME(cw(2,r3) >= caddr[2]);
  // Update
  caddr[2] = max(caddr[2],creg_r3);
  buff(2,r3) = 1;
  mem(r3,cw(2,r3)) = 1;
  co(r3,cw(2,r3))+=1;
  delta(r3,cw(2,r3)) = -1;
  ASSUME(creturn[2] >= cw(2,r3));

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 2), metadata !71, metadata !DIExpression()), !dbg !103

  //   %1 = load atomic i64, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 2) monotonic, align 8, !dbg !85
  // LD: Guess
  old_cr = cr(2,0+2*1);
  cr(2,0+2*1) = get_rng(0,NCONTEXT-1);// 2 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(2,0+2*1)] == 2);
  ASSUME(cr(2,0+2*1) >= iw(2,0+2*1));
  ASSUME(cr(2,0+2*1) >= 0);
  ASSUME(cr(2,0+2*1) >= cdy[2]);
  ASSUME(cr(2,0+2*1) >= cisb[2]);
  ASSUME(cr(2,0+2*1) >= cdl[2]);
  ASSUME(cr(2,0+2*1) >= cl[2]);
  // Update
  creg_r4 = cr(2,0+2*1);
  crmax(2,0+2*1) = max(crmax(2,0+2*1),cr(2,0+2*1));
  caddr[2] = max(caddr[2],0);
  if(cr(2,0+2*1) < cw(2,0+2*1)) {
    r4 = buff(2,0+2*1);
    ASSUME((!(( (cw(2,0+2*1) < 1) && (1 < crmax(2,0+2*1)) )))||(sforbid(0+2*1,1)> 0));
    ASSUME((!(( (cw(2,0+2*1) < 2) && (2 < crmax(2,0+2*1)) )))||(sforbid(0+2*1,2)> 0));
    ASSUME((!(( (cw(2,0+2*1) < 3) && (3 < crmax(2,0+2*1)) )))||(sforbid(0+2*1,3)> 0));
    ASSUME((!(( (cw(2,0+2*1) < 4) && (4 < crmax(2,0+2*1)) )))||(sforbid(0+2*1,4)> 0));
    ASSUME((!(( (cw(2,0+2*1) < 5) && (5 < crmax(2,0+2*1)) )))||(sforbid(0+2*1,5)> 0));
    ASSUME((!(( (cw(2,0+2*1) < 6) && (6 < crmax(2,0+2*1)) )))||(sforbid(0+2*1,6)> 0));
    ASSUME((!(( (cw(2,0+2*1) < 7) && (7 < crmax(2,0+2*1)) )))||(sforbid(0+2*1,7)> 0));
    ASSUME((!(( (cw(2,0+2*1) < 8) && (8 < crmax(2,0+2*1)) )))||(sforbid(0+2*1,8)> 0));
    ASSUME((!(( (cw(2,0+2*1) < 9) && (9 < crmax(2,0+2*1)) )))||(sforbid(0+2*1,9)> 0));
  } else {
    if(pw(2,0+2*1) != co(0+2*1,cr(2,0+2*1))) {
      ASSUME(cr(2,0+2*1) >= old_cr);
    }
    pw(2,0+2*1) = co(0+2*1,cr(2,0+2*1));
    r4 = mem(0+2*1,cr(2,0+2*1));
  }
  ASSUME(creturn[2] >= cr(2,0+2*1));

  //   call void @llvm.dbg.value(metadata i64 %1, metadata !73, metadata !DIExpression()), !dbg !103

  //   %conv6 = trunc i64 %1 to i32, !dbg !86

  //   call void @llvm.dbg.value(metadata i32 %conv6, metadata !70, metadata !DIExpression()), !dbg !92

  //   %tobool = icmp ne i32 %conv6, 0, !dbg !87

  //   br i1 %tobool, label %if.then, label %if.else, !dbg !89
  old_cctrl = cctrl[2];
  cctrl[2] = get_rng(0,NCONTEXT-1);
  ASSUME(cctrl[2] >= old_cctrl);
  ASSUME(cctrl[2] >= creg_r4);
  ASSUME(cctrl[2] >= 0);
  if((r4!=0)) {
    goto T2BLOCK2;
  } else {
    goto T2BLOCK3;
  }

T2BLOCK2:
  //   br label %lbl_LC00, !dbg !90
  goto T2BLOCK4;

T2BLOCK3:
  //   br label %lbl_LC00, !dbg !91
  goto T2BLOCK4;

T2BLOCK4:
  //   call void @llvm.dbg.label(metadata !91), !dbg !111

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 0), metadata !75, metadata !DIExpression()), !dbg !112

  //   %2 = load atomic i64, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 0) monotonic, align 8, !dbg !94
  // LD: Guess
  old_cr = cr(2,0);
  cr(2,0) = get_rng(0,NCONTEXT-1);// 2 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(2,0)] == 2);
  ASSUME(cr(2,0) >= iw(2,0));
  ASSUME(cr(2,0) >= 0);
  ASSUME(cr(2,0) >= cdy[2]);
  ASSUME(cr(2,0) >= cisb[2]);
  ASSUME(cr(2,0) >= cdl[2]);
  ASSUME(cr(2,0) >= cl[2]);
  // Update
  creg_r5 = cr(2,0);
  crmax(2,0) = max(crmax(2,0),cr(2,0));
  caddr[2] = max(caddr[2],0);
  if(cr(2,0) < cw(2,0)) {
    r5 = buff(2,0);
    ASSUME((!(( (cw(2,0) < 1) && (1 < crmax(2,0)) )))||(sforbid(0,1)> 0));
    ASSUME((!(( (cw(2,0) < 2) && (2 < crmax(2,0)) )))||(sforbid(0,2)> 0));
    ASSUME((!(( (cw(2,0) < 3) && (3 < crmax(2,0)) )))||(sforbid(0,3)> 0));
    ASSUME((!(( (cw(2,0) < 4) && (4 < crmax(2,0)) )))||(sforbid(0,4)> 0));
    ASSUME((!(( (cw(2,0) < 5) && (5 < crmax(2,0)) )))||(sforbid(0,5)> 0));
    ASSUME((!(( (cw(2,0) < 6) && (6 < crmax(2,0)) )))||(sforbid(0,6)> 0));
    ASSUME((!(( (cw(2,0) < 7) && (7 < crmax(2,0)) )))||(sforbid(0,7)> 0));
    ASSUME((!(( (cw(2,0) < 8) && (8 < crmax(2,0)) )))||(sforbid(0,8)> 0));
    ASSUME((!(( (cw(2,0) < 9) && (9 < crmax(2,0)) )))||(sforbid(0,9)> 0));
  } else {
    if(pw(2,0) != co(0,cr(2,0))) {
      ASSUME(cr(2,0) >= old_cr);
    }
    pw(2,0) = co(0,cr(2,0));
    r5 = mem(0,cr(2,0));
  }
  ASSUME(creturn[2] >= cr(2,0));

  //   call void @llvm.dbg.value(metadata i64 %2, metadata !77, metadata !DIExpression()), !dbg !112

  //   %conv10 = trunc i64 %2 to i32, !dbg !95

  //   call void @llvm.dbg.value(metadata i32 %conv10, metadata !74, metadata !DIExpression()), !dbg !92

  //   %cmp = icmp eq i32 %conv, 2, !dbg !96

  //   %conv11 = zext i1 %cmp to i32, !dbg !96

  //   call void @llvm.dbg.value(metadata i32 %conv11, metadata !78, metadata !DIExpression()), !dbg !92

  //   call void @llvm.dbg.value(metadata i64* @atom_1_X2_2, metadata !79, metadata !DIExpression()), !dbg !116

  //   %3 = zext i32 %conv11 to i64

  //   call void @llvm.dbg.value(metadata i64 %3, metadata !81, metadata !DIExpression()), !dbg !116

  //   store atomic i64 %3, i64* @atom_1_X2_2 seq_cst, align 8, !dbg !98
  // ST: Guess
  iw(2,3) = get_rng(0,NCONTEXT-1);// 2 ASSIGN STIW 
  old_cw = cw(2,3);
  cw(2,3) = get_rng(0,NCONTEXT-1);// 2 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(2,3)] == 2);
  ASSUME(active[cw(2,3)] == 2);
  ASSUME(sforbid(3,cw(2,3))== 0);
  ASSUME(iw(2,3) >= max(creg_r0,0));
  ASSUME(iw(2,3) >= 0);
  ASSUME(cw(2,3) >= iw(2,3));
  ASSUME(cw(2,3) >= old_cw);
  ASSUME(cw(2,3) >= cr(2,3));
  ASSUME(cw(2,3) >= cl[2]);
  ASSUME(cw(2,3) >= cisb[2]);
  ASSUME(cw(2,3) >= cdy[2]);
  ASSUME(cw(2,3) >= cdl[2]);
  ASSUME(cw(2,3) >= cds[2]);
  ASSUME(cw(2,3) >= cctrl[2]);
  ASSUME(cw(2,3) >= caddr[2]);
  // Update
  caddr[2] = max(caddr[2],0);
  buff(2,3) = (r0==2);
  mem(3,cw(2,3)) = (r0==2);
  co(3,cw(2,3))+=1;
  delta(3,cw(2,3)) = -1;
  ASSUME(creturn[2] >= cw(2,3));

  //   %cmp15 = icmp eq i32 %conv6, 1, !dbg !99

  //   %conv16 = zext i1 %cmp15 to i32, !dbg !99

  //   call void @llvm.dbg.value(metadata i32 %conv16, metadata !82, metadata !DIExpression()), !dbg !92

  //   call void @llvm.dbg.value(metadata i64* @atom_1_X6_1, metadata !83, metadata !DIExpression()), !dbg !119

  //   %4 = zext i32 %conv16 to i64

  //   call void @llvm.dbg.value(metadata i64 %4, metadata !85, metadata !DIExpression()), !dbg !119

  //   store atomic i64 %4, i64* @atom_1_X6_1 seq_cst, align 8, !dbg !101
  // ST: Guess
  iw(2,4) = get_rng(0,NCONTEXT-1);// 2 ASSIGN STIW 
  old_cw = cw(2,4);
  cw(2,4) = get_rng(0,NCONTEXT-1);// 2 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(2,4)] == 2);
  ASSUME(active[cw(2,4)] == 2);
  ASSUME(sforbid(4,cw(2,4))== 0);
  ASSUME(iw(2,4) >= max(creg_r4,0));
  ASSUME(iw(2,4) >= 0);
  ASSUME(cw(2,4) >= iw(2,4));
  ASSUME(cw(2,4) >= old_cw);
  ASSUME(cw(2,4) >= cr(2,4));
  ASSUME(cw(2,4) >= cl[2]);
  ASSUME(cw(2,4) >= cisb[2]);
  ASSUME(cw(2,4) >= cdy[2]);
  ASSUME(cw(2,4) >= cdl[2]);
  ASSUME(cw(2,4) >= cds[2]);
  ASSUME(cw(2,4) >= cctrl[2]);
  ASSUME(cw(2,4) >= caddr[2]);
  // Update
  caddr[2] = max(caddr[2],0);
  buff(2,4) = (r4==1);
  mem(4,cw(2,4)) = (r4==1);
  co(4,cw(2,4))+=1;
  delta(4,cw(2,4)) = -1;
  ASSUME(creturn[2] >= cw(2,4));

  //   %cmp20 = icmp eq i32 %conv10, 0, !dbg !102

  //   %conv21 = zext i1 %cmp20 to i32, !dbg !102

  //   call void @llvm.dbg.value(metadata i32 %conv21, metadata !86, metadata !DIExpression()), !dbg !92

  //   call void @llvm.dbg.value(metadata i64* @atom_1_X7_0, metadata !87, metadata !DIExpression()), !dbg !122

  //   %5 = zext i32 %conv21 to i64

  //   call void @llvm.dbg.value(metadata i64 %5, metadata !89, metadata !DIExpression()), !dbg !122

  //   store atomic i64 %5, i64* @atom_1_X7_0 seq_cst, align 8, !dbg !104
  // ST: Guess
  iw(2,5) = get_rng(0,NCONTEXT-1);// 2 ASSIGN STIW 
  old_cw = cw(2,5);
  cw(2,5) = get_rng(0,NCONTEXT-1);// 2 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(2,5)] == 2);
  ASSUME(active[cw(2,5)] == 2);
  ASSUME(sforbid(5,cw(2,5))== 0);
  ASSUME(iw(2,5) >= max(creg_r5,0));
  ASSUME(iw(2,5) >= 0);
  ASSUME(cw(2,5) >= iw(2,5));
  ASSUME(cw(2,5) >= old_cw);
  ASSUME(cw(2,5) >= cr(2,5));
  ASSUME(cw(2,5) >= cl[2]);
  ASSUME(cw(2,5) >= cisb[2]);
  ASSUME(cw(2,5) >= cdy[2]);
  ASSUME(cw(2,5) >= cdl[2]);
  ASSUME(cw(2,5) >= cds[2]);
  ASSUME(cw(2,5) >= cctrl[2]);
  ASSUME(cw(2,5) >= caddr[2]);
  // Update
  caddr[2] = max(caddr[2],0);
  buff(2,5) = (r5==0);
  mem(5,cw(2,5)) = (r5==0);
  co(5,cw(2,5))+=1;
  delta(5,cw(2,5)) = -1;
  ASSUME(creturn[2] >= cw(2,5));

  //   ret i8* null, !dbg !105
  ret_thread_2 = (- 1);


  // Dumping thread 0
  int ret_thread_0 = 0;
  cdy[0] = get_rng(0,NCONTEXT-1);
  ASSUME(cdy[0] >= cstart[0]);
T0BLOCK0:
  //   %thr0 = alloca i64, align 8

  //   %thr1 = alloca i64, align 8

  //   call void @llvm.dbg.value(metadata i32 %argc, metadata !132, metadata !DIExpression()), !dbg !189

  //   call void @llvm.dbg.value(metadata i8** %argv, metadata !133, metadata !DIExpression()), !dbg !189

  //   %0 = bitcast i64* %thr0 to i8*, !dbg !100

  //   call void @llvm.lifetime.start.p0i8(i64 8, i8* %0) #7, !dbg !100

  //   call void @llvm.dbg.declare(metadata i64* %thr0, metadata !134, metadata !DIExpression()), !dbg !191

  //   %1 = bitcast i64* %thr1 to i8*, !dbg !102

  //   call void @llvm.lifetime.start.p0i8(i64 8, i8* %1) #7, !dbg !102

  //   call void @llvm.dbg.declare(metadata i64* %thr1, metadata !138, metadata !DIExpression()), !dbg !193

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 2), metadata !139, metadata !DIExpression()), !dbg !194

  //   call void @llvm.dbg.value(metadata i64 0, metadata !141, metadata !DIExpression()), !dbg !194

  //   store atomic i64 0, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 2) monotonic, align 8, !dbg !105
  // ST: Guess
  iw(0,0+2*1) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STIW 
  old_cw = cw(0,0+2*1);
  cw(0,0+2*1) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(0,0+2*1)] == 0);
  ASSUME(active[cw(0,0+2*1)] == 0);
  ASSUME(sforbid(0+2*1,cw(0,0+2*1))== 0);
  ASSUME(iw(0,0+2*1) >= 0);
  ASSUME(iw(0,0+2*1) >= 0);
  ASSUME(cw(0,0+2*1) >= iw(0,0+2*1));
  ASSUME(cw(0,0+2*1) >= old_cw);
  ASSUME(cw(0,0+2*1) >= cr(0,0+2*1));
  ASSUME(cw(0,0+2*1) >= cl[0]);
  ASSUME(cw(0,0+2*1) >= cisb[0]);
  ASSUME(cw(0,0+2*1) >= cdy[0]);
  ASSUME(cw(0,0+2*1) >= cdl[0]);
  ASSUME(cw(0,0+2*1) >= cds[0]);
  ASSUME(cw(0,0+2*1) >= cctrl[0]);
  ASSUME(cw(0,0+2*1) >= caddr[0]);
  // Update
  caddr[0] = max(caddr[0],0);
  buff(0,0+2*1) = 0;
  mem(0+2*1,cw(0,0+2*1)) = 0;
  co(0+2*1,cw(0,0+2*1))+=1;
  delta(0+2*1,cw(0,0+2*1)) = -1;
  ASSUME(creturn[0] >= cw(0,0+2*1));

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 1), metadata !142, metadata !DIExpression()), !dbg !196

  //   call void @llvm.dbg.value(metadata i64 0, metadata !144, metadata !DIExpression()), !dbg !196

  //   store atomic i64 0, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 1) monotonic, align 8, !dbg !107
  // ST: Guess
  iw(0,0+1*1) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STIW 
  old_cw = cw(0,0+1*1);
  cw(0,0+1*1) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(0,0+1*1)] == 0);
  ASSUME(active[cw(0,0+1*1)] == 0);
  ASSUME(sforbid(0+1*1,cw(0,0+1*1))== 0);
  ASSUME(iw(0,0+1*1) >= 0);
  ASSUME(iw(0,0+1*1) >= 0);
  ASSUME(cw(0,0+1*1) >= iw(0,0+1*1));
  ASSUME(cw(0,0+1*1) >= old_cw);
  ASSUME(cw(0,0+1*1) >= cr(0,0+1*1));
  ASSUME(cw(0,0+1*1) >= cl[0]);
  ASSUME(cw(0,0+1*1) >= cisb[0]);
  ASSUME(cw(0,0+1*1) >= cdy[0]);
  ASSUME(cw(0,0+1*1) >= cdl[0]);
  ASSUME(cw(0,0+1*1) >= cds[0]);
  ASSUME(cw(0,0+1*1) >= cctrl[0]);
  ASSUME(cw(0,0+1*1) >= caddr[0]);
  // Update
  caddr[0] = max(caddr[0],0);
  buff(0,0+1*1) = 0;
  mem(0+1*1,cw(0,0+1*1)) = 0;
  co(0+1*1,cw(0,0+1*1))+=1;
  delta(0+1*1,cw(0,0+1*1)) = -1;
  ASSUME(creturn[0] >= cw(0,0+1*1));

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 0), metadata !145, metadata !DIExpression()), !dbg !198

  //   call void @llvm.dbg.value(metadata i64 0, metadata !147, metadata !DIExpression()), !dbg !198

  //   store atomic i64 0, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 0) monotonic, align 8, !dbg !109
  // ST: Guess
  iw(0,0) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STIW 
  old_cw = cw(0,0);
  cw(0,0) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(0,0)] == 0);
  ASSUME(active[cw(0,0)] == 0);
  ASSUME(sforbid(0,cw(0,0))== 0);
  ASSUME(iw(0,0) >= 0);
  ASSUME(iw(0,0) >= 0);
  ASSUME(cw(0,0) >= iw(0,0));
  ASSUME(cw(0,0) >= old_cw);
  ASSUME(cw(0,0) >= cr(0,0));
  ASSUME(cw(0,0) >= cl[0]);
  ASSUME(cw(0,0) >= cisb[0]);
  ASSUME(cw(0,0) >= cdy[0]);
  ASSUME(cw(0,0) >= cdl[0]);
  ASSUME(cw(0,0) >= cds[0]);
  ASSUME(cw(0,0) >= cctrl[0]);
  ASSUME(cw(0,0) >= caddr[0]);
  // Update
  caddr[0] = max(caddr[0],0);
  buff(0,0) = 0;
  mem(0,cw(0,0)) = 0;
  co(0,cw(0,0))+=1;
  delta(0,cw(0,0)) = -1;
  ASSUME(creturn[0] >= cw(0,0));

  //   call void @llvm.dbg.value(metadata i64* @atom_1_X2_2, metadata !148, metadata !DIExpression()), !dbg !200

  //   call void @llvm.dbg.value(metadata i64 0, metadata !150, metadata !DIExpression()), !dbg !200

  //   store atomic i64 0, i64* @atom_1_X2_2 monotonic, align 8, !dbg !111
  // ST: Guess
  iw(0,3) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STIW 
  old_cw = cw(0,3);
  cw(0,3) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(0,3)] == 0);
  ASSUME(active[cw(0,3)] == 0);
  ASSUME(sforbid(3,cw(0,3))== 0);
  ASSUME(iw(0,3) >= 0);
  ASSUME(iw(0,3) >= 0);
  ASSUME(cw(0,3) >= iw(0,3));
  ASSUME(cw(0,3) >= old_cw);
  ASSUME(cw(0,3) >= cr(0,3));
  ASSUME(cw(0,3) >= cl[0]);
  ASSUME(cw(0,3) >= cisb[0]);
  ASSUME(cw(0,3) >= cdy[0]);
  ASSUME(cw(0,3) >= cdl[0]);
  ASSUME(cw(0,3) >= cds[0]);
  ASSUME(cw(0,3) >= cctrl[0]);
  ASSUME(cw(0,3) >= caddr[0]);
  // Update
  caddr[0] = max(caddr[0],0);
  buff(0,3) = 0;
  mem(3,cw(0,3)) = 0;
  co(3,cw(0,3))+=1;
  delta(3,cw(0,3)) = -1;
  ASSUME(creturn[0] >= cw(0,3));

  //   call void @llvm.dbg.value(metadata i64* @atom_1_X6_1, metadata !151, metadata !DIExpression()), !dbg !202

  //   call void @llvm.dbg.value(metadata i64 0, metadata !153, metadata !DIExpression()), !dbg !202

  //   store atomic i64 0, i64* @atom_1_X6_1 monotonic, align 8, !dbg !113
  // ST: Guess
  iw(0,4) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STIW 
  old_cw = cw(0,4);
  cw(0,4) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(0,4)] == 0);
  ASSUME(active[cw(0,4)] == 0);
  ASSUME(sforbid(4,cw(0,4))== 0);
  ASSUME(iw(0,4) >= 0);
  ASSUME(iw(0,4) >= 0);
  ASSUME(cw(0,4) >= iw(0,4));
  ASSUME(cw(0,4) >= old_cw);
  ASSUME(cw(0,4) >= cr(0,4));
  ASSUME(cw(0,4) >= cl[0]);
  ASSUME(cw(0,4) >= cisb[0]);
  ASSUME(cw(0,4) >= cdy[0]);
  ASSUME(cw(0,4) >= cdl[0]);
  ASSUME(cw(0,4) >= cds[0]);
  ASSUME(cw(0,4) >= cctrl[0]);
  ASSUME(cw(0,4) >= caddr[0]);
  // Update
  caddr[0] = max(caddr[0],0);
  buff(0,4) = 0;
  mem(4,cw(0,4)) = 0;
  co(4,cw(0,4))+=1;
  delta(4,cw(0,4)) = -1;
  ASSUME(creturn[0] >= cw(0,4));

  //   call void @llvm.dbg.value(metadata i64* @atom_1_X7_0, metadata !154, metadata !DIExpression()), !dbg !204

  //   call void @llvm.dbg.value(metadata i64 0, metadata !156, metadata !DIExpression()), !dbg !204

  //   store atomic i64 0, i64* @atom_1_X7_0 monotonic, align 8, !dbg !115
  // ST: Guess
  iw(0,5) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STIW 
  old_cw = cw(0,5);
  cw(0,5) = get_rng(0,NCONTEXT-1);// 0 ASSIGN STCOM 
  // Check
  ASSUME(active[iw(0,5)] == 0);
  ASSUME(active[cw(0,5)] == 0);
  ASSUME(sforbid(5,cw(0,5))== 0);
  ASSUME(iw(0,5) >= 0);
  ASSUME(iw(0,5) >= 0);
  ASSUME(cw(0,5) >= iw(0,5));
  ASSUME(cw(0,5) >= old_cw);
  ASSUME(cw(0,5) >= cr(0,5));
  ASSUME(cw(0,5) >= cl[0]);
  ASSUME(cw(0,5) >= cisb[0]);
  ASSUME(cw(0,5) >= cdy[0]);
  ASSUME(cw(0,5) >= cdl[0]);
  ASSUME(cw(0,5) >= cds[0]);
  ASSUME(cw(0,5) >= cctrl[0]);
  ASSUME(cw(0,5) >= caddr[0]);
  // Update
  caddr[0] = max(caddr[0],0);
  buff(0,5) = 0;
  mem(5,cw(0,5)) = 0;
  co(5,cw(0,5))+=1;
  delta(5,cw(0,5)) = -1;
  ASSUME(creturn[0] >= cw(0,5));

  //   %call = call i32 @pthread_create(i64* noundef %thr0, %union.pthread_attr_t* noundef null, i8* (i8*)* noundef @t0, i8* noundef null) #7, !dbg !116
  // dumbsy: Guess
  old_cdy = cdy[0];
  cdy[0] = get_rng(0,NCONTEXT-1);
  // Check
  ASSUME(cdy[0] >= old_cdy);
  ASSUME(cdy[0] >= cisb[0]);
  ASSUME(cdy[0] >= cdl[0]);
  ASSUME(cdy[0] >= cds[0]);
  ASSUME(cdy[0] >= cctrl[0]);
  ASSUME(cdy[0] >= cw(0,0+0));
  ASSUME(cdy[0] >= cw(0,0+1));
  ASSUME(cdy[0] >= cw(0,0+2));
  ASSUME(cdy[0] >= cw(0,6+0));
  ASSUME(cdy[0] >= cw(0,3+0));
  ASSUME(cdy[0] >= cw(0,4+0));
  ASSUME(cdy[0] >= cw(0,5+0));
  ASSUME(cdy[0] >= cw(0,7+0));
  ASSUME(cdy[0] >= cr(0,0+0));
  ASSUME(cdy[0] >= cr(0,0+1));
  ASSUME(cdy[0] >= cr(0,0+2));
  ASSUME(cdy[0] >= cr(0,6+0));
  ASSUME(cdy[0] >= cr(0,3+0));
  ASSUME(cdy[0] >= cr(0,4+0));
  ASSUME(cdy[0] >= cr(0,5+0));
  ASSUME(cdy[0] >= cr(0,7+0));
  ASSUME(creturn[0] >= cdy[0]);
  ASSUME(cstart[1] >= cdy[0]);

  //   %call11 = call i32 @pthread_create(i64* noundef %thr1, %union.pthread_attr_t* noundef null, i8* (i8*)* noundef @t1, i8* noundef null) #7, !dbg !117
  // dumbsy: Guess
  old_cdy = cdy[0];
  cdy[0] = get_rng(0,NCONTEXT-1);
  // Check
  ASSUME(cdy[0] >= old_cdy);
  ASSUME(cdy[0] >= cisb[0]);
  ASSUME(cdy[0] >= cdl[0]);
  ASSUME(cdy[0] >= cds[0]);
  ASSUME(cdy[0] >= cctrl[0]);
  ASSUME(cdy[0] >= cw(0,0+0));
  ASSUME(cdy[0] >= cw(0,0+1));
  ASSUME(cdy[0] >= cw(0,0+2));
  ASSUME(cdy[0] >= cw(0,6+0));
  ASSUME(cdy[0] >= cw(0,3+0));
  ASSUME(cdy[0] >= cw(0,4+0));
  ASSUME(cdy[0] >= cw(0,5+0));
  ASSUME(cdy[0] >= cw(0,7+0));
  ASSUME(cdy[0] >= cr(0,0+0));
  ASSUME(cdy[0] >= cr(0,0+1));
  ASSUME(cdy[0] >= cr(0,0+2));
  ASSUME(cdy[0] >= cr(0,6+0));
  ASSUME(cdy[0] >= cr(0,3+0));
  ASSUME(cdy[0] >= cr(0,4+0));
  ASSUME(cdy[0] >= cr(0,5+0));
  ASSUME(cdy[0] >= cr(0,7+0));
  ASSUME(creturn[0] >= cdy[0]);
  ASSUME(cstart[2] >= cdy[0]);

  //   %2 = load i64, i64* %thr0, align 8, !dbg !118, !tbaa !119
  // LD: Guess
  old_cr = cr(0,6);
  cr(0,6) = get_rng(0,NCONTEXT-1);// 0 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(0,6)] == 0);
  ASSUME(cr(0,6) >= iw(0,6));
  ASSUME(cr(0,6) >= 0);
  ASSUME(cr(0,6) >= cdy[0]);
  ASSUME(cr(0,6) >= cisb[0]);
  ASSUME(cr(0,6) >= cdl[0]);
  ASSUME(cr(0,6) >= cl[0]);
  // Update
  creg_r7 = cr(0,6);
  crmax(0,6) = max(crmax(0,6),cr(0,6));
  caddr[0] = max(caddr[0],0);
  if(cr(0,6) < cw(0,6)) {
    r7 = buff(0,6);
    ASSUME((!(( (cw(0,6) < 1) && (1 < crmax(0,6)) )))||(sforbid(6,1)> 0));
    ASSUME((!(( (cw(0,6) < 2) && (2 < crmax(0,6)) )))||(sforbid(6,2)> 0));
    ASSUME((!(( (cw(0,6) < 3) && (3 < crmax(0,6)) )))||(sforbid(6,3)> 0));
    ASSUME((!(( (cw(0,6) < 4) && (4 < crmax(0,6)) )))||(sforbid(6,4)> 0));
    ASSUME((!(( (cw(0,6) < 5) && (5 < crmax(0,6)) )))||(sforbid(6,5)> 0));
    ASSUME((!(( (cw(0,6) < 6) && (6 < crmax(0,6)) )))||(sforbid(6,6)> 0));
    ASSUME((!(( (cw(0,6) < 7) && (7 < crmax(0,6)) )))||(sforbid(6,7)> 0));
    ASSUME((!(( (cw(0,6) < 8) && (8 < crmax(0,6)) )))||(sforbid(6,8)> 0));
    ASSUME((!(( (cw(0,6) < 9) && (9 < crmax(0,6)) )))||(sforbid(6,9)> 0));
  } else {
    if(pw(0,6) != co(6,cr(0,6))) {
      ASSUME(cr(0,6) >= old_cr);
    }
    pw(0,6) = co(6,cr(0,6));
    r7 = mem(6,cr(0,6));
  }
  ASSUME(creturn[0] >= cr(0,6));

  //   %call12 = call i32 @pthread_join(i64 noundef %2, i8** noundef null), !dbg !123
  // dumbsy: Guess
  old_cdy = cdy[0];
  cdy[0] = get_rng(0,NCONTEXT-1);
  // Check
  ASSUME(cdy[0] >= old_cdy);
  ASSUME(cdy[0] >= cisb[0]);
  ASSUME(cdy[0] >= cdl[0]);
  ASSUME(cdy[0] >= cds[0]);
  ASSUME(cdy[0] >= cctrl[0]);
  ASSUME(cdy[0] >= cw(0,0+0));
  ASSUME(cdy[0] >= cw(0,0+1));
  ASSUME(cdy[0] >= cw(0,0+2));
  ASSUME(cdy[0] >= cw(0,6+0));
  ASSUME(cdy[0] >= cw(0,3+0));
  ASSUME(cdy[0] >= cw(0,4+0));
  ASSUME(cdy[0] >= cw(0,5+0));
  ASSUME(cdy[0] >= cw(0,7+0));
  ASSUME(cdy[0] >= cr(0,0+0));
  ASSUME(cdy[0] >= cr(0,0+1));
  ASSUME(cdy[0] >= cr(0,0+2));
  ASSUME(cdy[0] >= cr(0,6+0));
  ASSUME(cdy[0] >= cr(0,3+0));
  ASSUME(cdy[0] >= cr(0,4+0));
  ASSUME(cdy[0] >= cr(0,5+0));
  ASSUME(cdy[0] >= cr(0,7+0));
  ASSUME(creturn[0] >= cdy[0]);
  ASSUME(cdy[0] >= creturn[1]);

  //   %3 = load i64, i64* %thr1, align 8, !dbg !124, !tbaa !119
  // LD: Guess
  old_cr = cr(0,7);
  cr(0,7) = get_rng(0,NCONTEXT-1);// 0 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(0,7)] == 0);
  ASSUME(cr(0,7) >= iw(0,7));
  ASSUME(cr(0,7) >= 0);
  ASSUME(cr(0,7) >= cdy[0]);
  ASSUME(cr(0,7) >= cisb[0]);
  ASSUME(cr(0,7) >= cdl[0]);
  ASSUME(cr(0,7) >= cl[0]);
  // Update
  creg_r8 = cr(0,7);
  crmax(0,7) = max(crmax(0,7),cr(0,7));
  caddr[0] = max(caddr[0],0);
  if(cr(0,7) < cw(0,7)) {
    r8 = buff(0,7);
    ASSUME((!(( (cw(0,7) < 1) && (1 < crmax(0,7)) )))||(sforbid(7,1)> 0));
    ASSUME((!(( (cw(0,7) < 2) && (2 < crmax(0,7)) )))||(sforbid(7,2)> 0));
    ASSUME((!(( (cw(0,7) < 3) && (3 < crmax(0,7)) )))||(sforbid(7,3)> 0));
    ASSUME((!(( (cw(0,7) < 4) && (4 < crmax(0,7)) )))||(sforbid(7,4)> 0));
    ASSUME((!(( (cw(0,7) < 5) && (5 < crmax(0,7)) )))||(sforbid(7,5)> 0));
    ASSUME((!(( (cw(0,7) < 6) && (6 < crmax(0,7)) )))||(sforbid(7,6)> 0));
    ASSUME((!(( (cw(0,7) < 7) && (7 < crmax(0,7)) )))||(sforbid(7,7)> 0));
    ASSUME((!(( (cw(0,7) < 8) && (8 < crmax(0,7)) )))||(sforbid(7,8)> 0));
    ASSUME((!(( (cw(0,7) < 9) && (9 < crmax(0,7)) )))||(sforbid(7,9)> 0));
  } else {
    if(pw(0,7) != co(7,cr(0,7))) {
      ASSUME(cr(0,7) >= old_cr);
    }
    pw(0,7) = co(7,cr(0,7));
    r8 = mem(7,cr(0,7));
  }
  ASSUME(creturn[0] >= cr(0,7));

  //   %call13 = call i32 @pthread_join(i64 noundef %3, i8** noundef null), !dbg !125
  // dumbsy: Guess
  old_cdy = cdy[0];
  cdy[0] = get_rng(0,NCONTEXT-1);
  // Check
  ASSUME(cdy[0] >= old_cdy);
  ASSUME(cdy[0] >= cisb[0]);
  ASSUME(cdy[0] >= cdl[0]);
  ASSUME(cdy[0] >= cds[0]);
  ASSUME(cdy[0] >= cctrl[0]);
  ASSUME(cdy[0] >= cw(0,0+0));
  ASSUME(cdy[0] >= cw(0,0+1));
  ASSUME(cdy[0] >= cw(0,0+2));
  ASSUME(cdy[0] >= cw(0,6+0));
  ASSUME(cdy[0] >= cw(0,3+0));
  ASSUME(cdy[0] >= cw(0,4+0));
  ASSUME(cdy[0] >= cw(0,5+0));
  ASSUME(cdy[0] >= cw(0,7+0));
  ASSUME(cdy[0] >= cr(0,0+0));
  ASSUME(cdy[0] >= cr(0,0+1));
  ASSUME(cdy[0] >= cr(0,0+2));
  ASSUME(cdy[0] >= cr(0,6+0));
  ASSUME(cdy[0] >= cr(0,3+0));
  ASSUME(cdy[0] >= cr(0,4+0));
  ASSUME(cdy[0] >= cr(0,5+0));
  ASSUME(cdy[0] >= cr(0,7+0));
  ASSUME(creturn[0] >= cdy[0]);
  ASSUME(cdy[0] >= creturn[2]);

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 0), metadata !158, metadata !DIExpression()), !dbg !216

  //   %4 = load atomic i64, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 0) seq_cst, align 8, !dbg !127
  // LD: Guess
  old_cr = cr(0,0);
  cr(0,0) = get_rng(0,NCONTEXT-1);// 0 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(0,0)] == 0);
  ASSUME(cr(0,0) >= iw(0,0));
  ASSUME(cr(0,0) >= 0);
  ASSUME(cr(0,0) >= cdy[0]);
  ASSUME(cr(0,0) >= cisb[0]);
  ASSUME(cr(0,0) >= cdl[0]);
  ASSUME(cr(0,0) >= cl[0]);
  // Update
  creg_r9 = cr(0,0);
  crmax(0,0) = max(crmax(0,0),cr(0,0));
  caddr[0] = max(caddr[0],0);
  if(cr(0,0) < cw(0,0)) {
    r9 = buff(0,0);
    ASSUME((!(( (cw(0,0) < 1) && (1 < crmax(0,0)) )))||(sforbid(0,1)> 0));
    ASSUME((!(( (cw(0,0) < 2) && (2 < crmax(0,0)) )))||(sforbid(0,2)> 0));
    ASSUME((!(( (cw(0,0) < 3) && (3 < crmax(0,0)) )))||(sforbid(0,3)> 0));
    ASSUME((!(( (cw(0,0) < 4) && (4 < crmax(0,0)) )))||(sforbid(0,4)> 0));
    ASSUME((!(( (cw(0,0) < 5) && (5 < crmax(0,0)) )))||(sforbid(0,5)> 0));
    ASSUME((!(( (cw(0,0) < 6) && (6 < crmax(0,0)) )))||(sforbid(0,6)> 0));
    ASSUME((!(( (cw(0,0) < 7) && (7 < crmax(0,0)) )))||(sforbid(0,7)> 0));
    ASSUME((!(( (cw(0,0) < 8) && (8 < crmax(0,0)) )))||(sforbid(0,8)> 0));
    ASSUME((!(( (cw(0,0) < 9) && (9 < crmax(0,0)) )))||(sforbid(0,9)> 0));
  } else {
    if(pw(0,0) != co(0,cr(0,0))) {
      ASSUME(cr(0,0) >= old_cr);
    }
    pw(0,0) = co(0,cr(0,0));
    r9 = mem(0,cr(0,0));
  }
  ASSUME(creturn[0] >= cr(0,0));

  //   call void @llvm.dbg.value(metadata i64 %4, metadata !160, metadata !DIExpression()), !dbg !216

  //   %conv = trunc i64 %4 to i32, !dbg !128

  //   call void @llvm.dbg.value(metadata i32 %conv, metadata !157, metadata !DIExpression()), !dbg !189

  //   %cmp = icmp eq i32 %conv, 1, !dbg !129

  //   %conv14 = zext i1 %cmp to i32, !dbg !129

  //   call void @llvm.dbg.value(metadata i32 %conv14, metadata !161, metadata !DIExpression()), !dbg !189

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 1), metadata !163, metadata !DIExpression()), !dbg !220

  //   %5 = load atomic i64, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 1) seq_cst, align 8, !dbg !131
  // LD: Guess
  old_cr = cr(0,0+1*1);
  cr(0,0+1*1) = get_rng(0,NCONTEXT-1);// 0 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(0,0+1*1)] == 0);
  ASSUME(cr(0,0+1*1) >= iw(0,0+1*1));
  ASSUME(cr(0,0+1*1) >= 0);
  ASSUME(cr(0,0+1*1) >= cdy[0]);
  ASSUME(cr(0,0+1*1) >= cisb[0]);
  ASSUME(cr(0,0+1*1) >= cdl[0]);
  ASSUME(cr(0,0+1*1) >= cl[0]);
  // Update
  creg_r10 = cr(0,0+1*1);
  crmax(0,0+1*1) = max(crmax(0,0+1*1),cr(0,0+1*1));
  caddr[0] = max(caddr[0],0);
  if(cr(0,0+1*1) < cw(0,0+1*1)) {
    r10 = buff(0,0+1*1);
    ASSUME((!(( (cw(0,0+1*1) < 1) && (1 < crmax(0,0+1*1)) )))||(sforbid(0+1*1,1)> 0));
    ASSUME((!(( (cw(0,0+1*1) < 2) && (2 < crmax(0,0+1*1)) )))||(sforbid(0+1*1,2)> 0));
    ASSUME((!(( (cw(0,0+1*1) < 3) && (3 < crmax(0,0+1*1)) )))||(sforbid(0+1*1,3)> 0));
    ASSUME((!(( (cw(0,0+1*1) < 4) && (4 < crmax(0,0+1*1)) )))||(sforbid(0+1*1,4)> 0));
    ASSUME((!(( (cw(0,0+1*1) < 5) && (5 < crmax(0,0+1*1)) )))||(sforbid(0+1*1,5)> 0));
    ASSUME((!(( (cw(0,0+1*1) < 6) && (6 < crmax(0,0+1*1)) )))||(sforbid(0+1*1,6)> 0));
    ASSUME((!(( (cw(0,0+1*1) < 7) && (7 < crmax(0,0+1*1)) )))||(sforbid(0+1*1,7)> 0));
    ASSUME((!(( (cw(0,0+1*1) < 8) && (8 < crmax(0,0+1*1)) )))||(sforbid(0+1*1,8)> 0));
    ASSUME((!(( (cw(0,0+1*1) < 9) && (9 < crmax(0,0+1*1)) )))||(sforbid(0+1*1,9)> 0));
  } else {
    if(pw(0,0+1*1) != co(0+1*1,cr(0,0+1*1))) {
      ASSUME(cr(0,0+1*1) >= old_cr);
    }
    pw(0,0+1*1) = co(0+1*1,cr(0,0+1*1));
    r10 = mem(0+1*1,cr(0,0+1*1));
  }
  ASSUME(creturn[0] >= cr(0,0+1*1));

  //   call void @llvm.dbg.value(metadata i64 %5, metadata !165, metadata !DIExpression()), !dbg !220

  //   %conv18 = trunc i64 %5 to i32, !dbg !132

  //   call void @llvm.dbg.value(metadata i32 %conv18, metadata !162, metadata !DIExpression()), !dbg !189

  //   %cmp19 = icmp eq i32 %conv18, 2, !dbg !133

  //   %conv20 = zext i1 %cmp19 to i32, !dbg !133

  //   call void @llvm.dbg.value(metadata i32 %conv20, metadata !166, metadata !DIExpression()), !dbg !189

  //   call void @llvm.dbg.value(metadata i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 2), metadata !168, metadata !DIExpression()), !dbg !224

  //   %6 = load atomic i64, i64* getelementptr inbounds ([3 x i64], [3 x i64]* @vars, i64 0, i64 2) seq_cst, align 8, !dbg !135
  // LD: Guess
  old_cr = cr(0,0+2*1);
  cr(0,0+2*1) = get_rng(0,NCONTEXT-1);// 0 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(0,0+2*1)] == 0);
  ASSUME(cr(0,0+2*1) >= iw(0,0+2*1));
  ASSUME(cr(0,0+2*1) >= 0);
  ASSUME(cr(0,0+2*1) >= cdy[0]);
  ASSUME(cr(0,0+2*1) >= cisb[0]);
  ASSUME(cr(0,0+2*1) >= cdl[0]);
  ASSUME(cr(0,0+2*1) >= cl[0]);
  // Update
  creg_r11 = cr(0,0+2*1);
  crmax(0,0+2*1) = max(crmax(0,0+2*1),cr(0,0+2*1));
  caddr[0] = max(caddr[0],0);
  if(cr(0,0+2*1) < cw(0,0+2*1)) {
    r11 = buff(0,0+2*1);
    ASSUME((!(( (cw(0,0+2*1) < 1) && (1 < crmax(0,0+2*1)) )))||(sforbid(0+2*1,1)> 0));
    ASSUME((!(( (cw(0,0+2*1) < 2) && (2 < crmax(0,0+2*1)) )))||(sforbid(0+2*1,2)> 0));
    ASSUME((!(( (cw(0,0+2*1) < 3) && (3 < crmax(0,0+2*1)) )))||(sforbid(0+2*1,3)> 0));
    ASSUME((!(( (cw(0,0+2*1) < 4) && (4 < crmax(0,0+2*1)) )))||(sforbid(0+2*1,4)> 0));
    ASSUME((!(( (cw(0,0+2*1) < 5) && (5 < crmax(0,0+2*1)) )))||(sforbid(0+2*1,5)> 0));
    ASSUME((!(( (cw(0,0+2*1) < 6) && (6 < crmax(0,0+2*1)) )))||(sforbid(0+2*1,6)> 0));
    ASSUME((!(( (cw(0,0+2*1) < 7) && (7 < crmax(0,0+2*1)) )))||(sforbid(0+2*1,7)> 0));
    ASSUME((!(( (cw(0,0+2*1) < 8) && (8 < crmax(0,0+2*1)) )))||(sforbid(0+2*1,8)> 0));
    ASSUME((!(( (cw(0,0+2*1) < 9) && (9 < crmax(0,0+2*1)) )))||(sforbid(0+2*1,9)> 0));
  } else {
    if(pw(0,0+2*1) != co(0+2*1,cr(0,0+2*1))) {
      ASSUME(cr(0,0+2*1) >= old_cr);
    }
    pw(0,0+2*1) = co(0+2*1,cr(0,0+2*1));
    r11 = mem(0+2*1,cr(0,0+2*1));
  }
  ASSUME(creturn[0] >= cr(0,0+2*1));

  //   call void @llvm.dbg.value(metadata i64 %6, metadata !170, metadata !DIExpression()), !dbg !224

  //   %conv24 = trunc i64 %6 to i32, !dbg !136

  //   call void @llvm.dbg.value(metadata i32 %conv24, metadata !167, metadata !DIExpression()), !dbg !189

  //   %cmp25 = icmp eq i32 %conv24, 1, !dbg !137

  //   %conv26 = zext i1 %cmp25 to i32, !dbg !137

  //   call void @llvm.dbg.value(metadata i32 %conv26, metadata !171, metadata !DIExpression()), !dbg !189

  //   call void @llvm.dbg.value(metadata i64* @atom_1_X2_2, metadata !173, metadata !DIExpression()), !dbg !228

  //   %7 = load atomic i64, i64* @atom_1_X2_2 seq_cst, align 8, !dbg !139
  // LD: Guess
  old_cr = cr(0,3);
  cr(0,3) = get_rng(0,NCONTEXT-1);// 0 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(0,3)] == 0);
  ASSUME(cr(0,3) >= iw(0,3));
  ASSUME(cr(0,3) >= 0);
  ASSUME(cr(0,3) >= cdy[0]);
  ASSUME(cr(0,3) >= cisb[0]);
  ASSUME(cr(0,3) >= cdl[0]);
  ASSUME(cr(0,3) >= cl[0]);
  // Update
  creg_r12 = cr(0,3);
  crmax(0,3) = max(crmax(0,3),cr(0,3));
  caddr[0] = max(caddr[0],0);
  if(cr(0,3) < cw(0,3)) {
    r12 = buff(0,3);
    ASSUME((!(( (cw(0,3) < 1) && (1 < crmax(0,3)) )))||(sforbid(3,1)> 0));
    ASSUME((!(( (cw(0,3) < 2) && (2 < crmax(0,3)) )))||(sforbid(3,2)> 0));
    ASSUME((!(( (cw(0,3) < 3) && (3 < crmax(0,3)) )))||(sforbid(3,3)> 0));
    ASSUME((!(( (cw(0,3) < 4) && (4 < crmax(0,3)) )))||(sforbid(3,4)> 0));
    ASSUME((!(( (cw(0,3) < 5) && (5 < crmax(0,3)) )))||(sforbid(3,5)> 0));
    ASSUME((!(( (cw(0,3) < 6) && (6 < crmax(0,3)) )))||(sforbid(3,6)> 0));
    ASSUME((!(( (cw(0,3) < 7) && (7 < crmax(0,3)) )))||(sforbid(3,7)> 0));
    ASSUME((!(( (cw(0,3) < 8) && (8 < crmax(0,3)) )))||(sforbid(3,8)> 0));
    ASSUME((!(( (cw(0,3) < 9) && (9 < crmax(0,3)) )))||(sforbid(3,9)> 0));
  } else {
    if(pw(0,3) != co(3,cr(0,3))) {
      ASSUME(cr(0,3) >= old_cr);
    }
    pw(0,3) = co(3,cr(0,3));
    r12 = mem(3,cr(0,3));
  }
  ASSUME(creturn[0] >= cr(0,3));

  //   call void @llvm.dbg.value(metadata i64 %7, metadata !175, metadata !DIExpression()), !dbg !228

  //   %conv30 = trunc i64 %7 to i32, !dbg !140

  //   call void @llvm.dbg.value(metadata i32 %conv30, metadata !172, metadata !DIExpression()), !dbg !189

  //   call void @llvm.dbg.value(metadata i64* @atom_1_X6_1, metadata !177, metadata !DIExpression()), !dbg !231

  //   %8 = load atomic i64, i64* @atom_1_X6_1 seq_cst, align 8, !dbg !142
  // LD: Guess
  old_cr = cr(0,4);
  cr(0,4) = get_rng(0,NCONTEXT-1);// 0 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(0,4)] == 0);
  ASSUME(cr(0,4) >= iw(0,4));
  ASSUME(cr(0,4) >= 0);
  ASSUME(cr(0,4) >= cdy[0]);
  ASSUME(cr(0,4) >= cisb[0]);
  ASSUME(cr(0,4) >= cdl[0]);
  ASSUME(cr(0,4) >= cl[0]);
  // Update
  creg_r13 = cr(0,4);
  crmax(0,4) = max(crmax(0,4),cr(0,4));
  caddr[0] = max(caddr[0],0);
  if(cr(0,4) < cw(0,4)) {
    r13 = buff(0,4);
    ASSUME((!(( (cw(0,4) < 1) && (1 < crmax(0,4)) )))||(sforbid(4,1)> 0));
    ASSUME((!(( (cw(0,4) < 2) && (2 < crmax(0,4)) )))||(sforbid(4,2)> 0));
    ASSUME((!(( (cw(0,4) < 3) && (3 < crmax(0,4)) )))||(sforbid(4,3)> 0));
    ASSUME((!(( (cw(0,4) < 4) && (4 < crmax(0,4)) )))||(sforbid(4,4)> 0));
    ASSUME((!(( (cw(0,4) < 5) && (5 < crmax(0,4)) )))||(sforbid(4,5)> 0));
    ASSUME((!(( (cw(0,4) < 6) && (6 < crmax(0,4)) )))||(sforbid(4,6)> 0));
    ASSUME((!(( (cw(0,4) < 7) && (7 < crmax(0,4)) )))||(sforbid(4,7)> 0));
    ASSUME((!(( (cw(0,4) < 8) && (8 < crmax(0,4)) )))||(sforbid(4,8)> 0));
    ASSUME((!(( (cw(0,4) < 9) && (9 < crmax(0,4)) )))||(sforbid(4,9)> 0));
  } else {
    if(pw(0,4) != co(4,cr(0,4))) {
      ASSUME(cr(0,4) >= old_cr);
    }
    pw(0,4) = co(4,cr(0,4));
    r13 = mem(4,cr(0,4));
  }
  ASSUME(creturn[0] >= cr(0,4));

  //   call void @llvm.dbg.value(metadata i64 %8, metadata !179, metadata !DIExpression()), !dbg !231

  //   %conv34 = trunc i64 %8 to i32, !dbg !143

  //   call void @llvm.dbg.value(metadata i32 %conv34, metadata !176, metadata !DIExpression()), !dbg !189

  //   call void @llvm.dbg.value(metadata i64* @atom_1_X7_0, metadata !181, metadata !DIExpression()), !dbg !234

  //   %9 = load atomic i64, i64* @atom_1_X7_0 seq_cst, align 8, !dbg !145
  // LD: Guess
  old_cr = cr(0,5);
  cr(0,5) = get_rng(0,NCONTEXT-1);// 0 ASSIGN LDCOM 
  // Check
  ASSUME(active[cr(0,5)] == 0);
  ASSUME(cr(0,5) >= iw(0,5));
  ASSUME(cr(0,5) >= 0);
  ASSUME(cr(0,5) >= cdy[0]);
  ASSUME(cr(0,5) >= cisb[0]);
  ASSUME(cr(0,5) >= cdl[0]);
  ASSUME(cr(0,5) >= cl[0]);
  // Update
  creg_r14 = cr(0,5);
  crmax(0,5) = max(crmax(0,5),cr(0,5));
  caddr[0] = max(caddr[0],0);
  if(cr(0,5) < cw(0,5)) {
    r14 = buff(0,5);
    ASSUME((!(( (cw(0,5) < 1) && (1 < crmax(0,5)) )))||(sforbid(5,1)> 0));
    ASSUME((!(( (cw(0,5) < 2) && (2 < crmax(0,5)) )))||(sforbid(5,2)> 0));
    ASSUME((!(( (cw(0,5) < 3) && (3 < crmax(0,5)) )))||(sforbid(5,3)> 0));
    ASSUME((!(( (cw(0,5) < 4) && (4 < crmax(0,5)) )))||(sforbid(5,4)> 0));
    ASSUME((!(( (cw(0,5) < 5) && (5 < crmax(0,5)) )))||(sforbid(5,5)> 0));
    ASSUME((!(( (cw(0,5) < 6) && (6 < crmax(0,5)) )))||(sforbid(5,6)> 0));
    ASSUME((!(( (cw(0,5) < 7) && (7 < crmax(0,5)) )))||(sforbid(5,7)> 0));
    ASSUME((!(( (cw(0,5) < 8) && (8 < crmax(0,5)) )))||(sforbid(5,8)> 0));
    ASSUME((!(( (cw(0,5) < 9) && (9 < crmax(0,5)) )))||(sforbid(5,9)> 0));
  } else {
    if(pw(0,5) != co(5,cr(0,5))) {
      ASSUME(cr(0,5) >= old_cr);
    }
    pw(0,5) = co(5,cr(0,5));
    r14 = mem(5,cr(0,5));
  }
  ASSUME(creturn[0] >= cr(0,5));

  //   call void @llvm.dbg.value(metadata i64 %9, metadata !183, metadata !DIExpression()), !dbg !234

  //   %conv38 = trunc i64 %9 to i32, !dbg !146

  //   call void @llvm.dbg.value(metadata i32 %conv38, metadata !180, metadata !DIExpression()), !dbg !189

  //   %and = and i32 %conv34, %conv38, !dbg !147
  creg_r15 = max(creg_r13,creg_r14);
  ASSUME(active[creg_r15] == 0);
  r15 = r13 & r14;

  //   call void @llvm.dbg.value(metadata i32 %and, metadata !184, metadata !DIExpression()), !dbg !189

  //   %and39 = and i32 %conv30, %and, !dbg !148
  creg_r16 = max(creg_r12,creg_r15);
  ASSUME(active[creg_r16] == 0);
  r16 = r12 & r15;

  //   call void @llvm.dbg.value(metadata i32 %and39, metadata !185, metadata !DIExpression()), !dbg !189

  //   %and40 = and i32 %conv26, %and39, !dbg !149
  creg_r17 = max(max(creg_r11,0),creg_r16);
  ASSUME(active[creg_r17] == 0);
  r17 = (r11==1) & r16;

  //   call void @llvm.dbg.value(metadata i32 %and40, metadata !186, metadata !DIExpression()), !dbg !189

  //   %and41 = and i32 %conv20, %and40, !dbg !150
  creg_r18 = max(max(creg_r10,0),creg_r17);
  ASSUME(active[creg_r18] == 0);
  r18 = (r10==2) & r17;

  //   call void @llvm.dbg.value(metadata i32 %and41, metadata !187, metadata !DIExpression()), !dbg !189

  //   %and42 = and i32 %conv14, %and41, !dbg !151
  creg_r19 = max(max(creg_r9,0),creg_r18);
  ASSUME(active[creg_r19] == 0);
  r19 = (r9==1) & r18;

  //   call void @llvm.dbg.value(metadata i32 %and42, metadata !188, metadata !DIExpression()), !dbg !189

  //   %cmp43 = icmp eq i32 %and42, 1, !dbg !152

  //   br i1 %cmp43, label %if.then, label %if.end, !dbg !154
  old_cctrl = cctrl[0];
  cctrl[0] = get_rng(0,NCONTEXT-1);
  ASSUME(cctrl[0] >= old_cctrl);
  ASSUME(cctrl[0] >= creg_r19);
  ASSUME(cctrl[0] >= 0);
  if((r19==1)) {
    goto T0BLOCK1;
  } else {
    goto T0BLOCK2;
  }

T0BLOCK1:
  //   call void @__assert_fail(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i64 0, i64 0), i8* noundef getelementptr inbounds ([111 x i8], [111 x i8]* @.str.1, i64 0, i64 0), i32 noundef 77, i8* noundef getelementptr inbounds ([23 x i8], [23 x i8]* @__PRETTY_FUNCTION__.main, i64 0, i64 0)) #8, !dbg !155

  //   unreachable, !dbg !155
  r20 = 1;

T0BLOCK2:
  //   %10 = bitcast i64* %thr1 to i8*, !dbg !158

  //   call void @llvm.lifetime.end.p0i8(i64 8, i8* %10) #7, !dbg !158

  //   %11 = bitcast i64* %thr0 to i8*, !dbg !158

  //   call void @llvm.lifetime.end.p0i8(i64 8, i8* %11) #7, !dbg !158

  //   ret i32 0, !dbg !159
  ret_thread_0 = 0;


  ASSUME(meminit(0,1) == mem(0,0));
  ASSUME(coinit(0,1) == co(0,0));
  ASSUME(deltainit(0,1) == delta(0,0));
  ASSUME(meminit(0,2) == mem(0,1));
  ASSUME(coinit(0,2) == co(0,1));
  ASSUME(deltainit(0,2) == delta(0,1));
  ASSUME(meminit(0,3) == mem(0,2));
  ASSUME(coinit(0,3) == co(0,2));
  ASSUME(deltainit(0,3) == delta(0,2));
  ASSUME(meminit(0,4) == mem(0,3));
  ASSUME(coinit(0,4) == co(0,3));
  ASSUME(deltainit(0,4) == delta(0,3));
  ASSUME(meminit(0,5) == mem(0,4));
  ASSUME(coinit(0,5) == co(0,4));
  ASSUME(deltainit(0,5) == delta(0,4));
  ASSUME(meminit(0,6) == mem(0,5));
  ASSUME(coinit(0,6) == co(0,5));
  ASSUME(deltainit(0,6) == delta(0,5));
  ASSUME(meminit(0,7) == mem(0,6));
  ASSUME(coinit(0,7) == co(0,6));
  ASSUME(deltainit(0,7) == delta(0,6));
  ASSUME(meminit(0,8) == mem(0,7));
  ASSUME(coinit(0,8) == co(0,7));
  ASSUME(deltainit(0,8) == delta(0,7));
  ASSUME(meminit(0,9) == mem(0,8));
  ASSUME(coinit(0,9) == co(0,8));
  ASSUME(deltainit(0,9) == delta(0,8));
  ASSUME(meminit(1,1) == mem(1,0));
  ASSUME(coinit(1,1) == co(1,0));
  ASSUME(deltainit(1,1) == delta(1,0));
  ASSUME(meminit(1,2) == mem(1,1));
  ASSUME(coinit(1,2) == co(1,1));
  ASSUME(deltainit(1,2) == delta(1,1));
  ASSUME(meminit(1,3) == mem(1,2));
  ASSUME(coinit(1,3) == co(1,2));
  ASSUME(deltainit(1,3) == delta(1,2));
  ASSUME(meminit(1,4) == mem(1,3));
  ASSUME(coinit(1,4) == co(1,3));
  ASSUME(deltainit(1,4) == delta(1,3));
  ASSUME(meminit(1,5) == mem(1,4));
  ASSUME(coinit(1,5) == co(1,4));
  ASSUME(deltainit(1,5) == delta(1,4));
  ASSUME(meminit(1,6) == mem(1,5));
  ASSUME(coinit(1,6) == co(1,5));
  ASSUME(deltainit(1,6) == delta(1,5));
  ASSUME(meminit(1,7) == mem(1,6));
  ASSUME(coinit(1,7) == co(1,6));
  ASSUME(deltainit(1,7) == delta(1,6));
  ASSUME(meminit(1,8) == mem(1,7));
  ASSUME(coinit(1,8) == co(1,7));
  ASSUME(deltainit(1,8) == delta(1,7));
  ASSUME(meminit(1,9) == mem(1,8));
  ASSUME(coinit(1,9) == co(1,8));
  ASSUME(deltainit(1,9) == delta(1,8));
  ASSUME(meminit(2,1) == mem(2,0));
  ASSUME(coinit(2,1) == co(2,0));
  ASSUME(deltainit(2,1) == delta(2,0));
  ASSUME(meminit(2,2) == mem(2,1));
  ASSUME(coinit(2,2) == co(2,1));
  ASSUME(deltainit(2,2) == delta(2,1));
  ASSUME(meminit(2,3) == mem(2,2));
  ASSUME(coinit(2,3) == co(2,2));
  ASSUME(deltainit(2,3) == delta(2,2));
  ASSUME(meminit(2,4) == mem(2,3));
  ASSUME(coinit(2,4) == co(2,3));
  ASSUME(deltainit(2,4) == delta(2,3));
  ASSUME(meminit(2,5) == mem(2,4));
  ASSUME(coinit(2,5) == co(2,4));
  ASSUME(deltainit(2,5) == delta(2,4));
  ASSUME(meminit(2,6) == mem(2,5));
  ASSUME(coinit(2,6) == co(2,5));
  ASSUME(deltainit(2,6) == delta(2,5));
  ASSUME(meminit(2,7) == mem(2,6));
  ASSUME(coinit(2,7) == co(2,6));
  ASSUME(deltainit(2,7) == delta(2,6));
  ASSUME(meminit(2,8) == mem(2,7));
  ASSUME(coinit(2,8) == co(2,7));
  ASSUME(deltainit(2,8) == delta(2,7));
  ASSUME(meminit(2,9) == mem(2,8));
  ASSUME(coinit(2,9) == co(2,8));
  ASSUME(deltainit(2,9) == delta(2,8));
  ASSUME(meminit(3,1) == mem(3,0));
  ASSUME(coinit(3,1) == co(3,0));
  ASSUME(deltainit(3,1) == delta(3,0));
  ASSUME(meminit(3,2) == mem(3,1));
  ASSUME(coinit(3,2) == co(3,1));
  ASSUME(deltainit(3,2) == delta(3,1));
  ASSUME(meminit(3,3) == mem(3,2));
  ASSUME(coinit(3,3) == co(3,2));
  ASSUME(deltainit(3,3) == delta(3,2));
  ASSUME(meminit(3,4) == mem(3,3));
  ASSUME(coinit(3,4) == co(3,3));
  ASSUME(deltainit(3,4) == delta(3,3));
  ASSUME(meminit(3,5) == mem(3,4));
  ASSUME(coinit(3,5) == co(3,4));
  ASSUME(deltainit(3,5) == delta(3,4));
  ASSUME(meminit(3,6) == mem(3,5));
  ASSUME(coinit(3,6) == co(3,5));
  ASSUME(deltainit(3,6) == delta(3,5));
  ASSUME(meminit(3,7) == mem(3,6));
  ASSUME(coinit(3,7) == co(3,6));
  ASSUME(deltainit(3,7) == delta(3,6));
  ASSUME(meminit(3,8) == mem(3,7));
  ASSUME(coinit(3,8) == co(3,7));
  ASSUME(deltainit(3,8) == delta(3,7));
  ASSUME(meminit(3,9) == mem(3,8));
  ASSUME(coinit(3,9) == co(3,8));
  ASSUME(deltainit(3,9) == delta(3,8));
  ASSUME(meminit(4,1) == mem(4,0));
  ASSUME(coinit(4,1) == co(4,0));
  ASSUME(deltainit(4,1) == delta(4,0));
  ASSUME(meminit(4,2) == mem(4,1));
  ASSUME(coinit(4,2) == co(4,1));
  ASSUME(deltainit(4,2) == delta(4,1));
  ASSUME(meminit(4,3) == mem(4,2));
  ASSUME(coinit(4,3) == co(4,2));
  ASSUME(deltainit(4,3) == delta(4,2));
  ASSUME(meminit(4,4) == mem(4,3));
  ASSUME(coinit(4,4) == co(4,3));
  ASSUME(deltainit(4,4) == delta(4,3));
  ASSUME(meminit(4,5) == mem(4,4));
  ASSUME(coinit(4,5) == co(4,4));
  ASSUME(deltainit(4,5) == delta(4,4));
  ASSUME(meminit(4,6) == mem(4,5));
  ASSUME(coinit(4,6) == co(4,5));
  ASSUME(deltainit(4,6) == delta(4,5));
  ASSUME(meminit(4,7) == mem(4,6));
  ASSUME(coinit(4,7) == co(4,6));
  ASSUME(deltainit(4,7) == delta(4,6));
  ASSUME(meminit(4,8) == mem(4,7));
  ASSUME(coinit(4,8) == co(4,7));
  ASSUME(deltainit(4,8) == delta(4,7));
  ASSUME(meminit(4,9) == mem(4,8));
  ASSUME(coinit(4,9) == co(4,8));
  ASSUME(deltainit(4,9) == delta(4,8));
  ASSUME(meminit(5,1) == mem(5,0));
  ASSUME(coinit(5,1) == co(5,0));
  ASSUME(deltainit(5,1) == delta(5,0));
  ASSUME(meminit(5,2) == mem(5,1));
  ASSUME(coinit(5,2) == co(5,1));
  ASSUME(deltainit(5,2) == delta(5,1));
  ASSUME(meminit(5,3) == mem(5,2));
  ASSUME(coinit(5,3) == co(5,2));
  ASSUME(deltainit(5,3) == delta(5,2));
  ASSUME(meminit(5,4) == mem(5,3));
  ASSUME(coinit(5,4) == co(5,3));
  ASSUME(deltainit(5,4) == delta(5,3));
  ASSUME(meminit(5,5) == mem(5,4));
  ASSUME(coinit(5,5) == co(5,4));
  ASSUME(deltainit(5,5) == delta(5,4));
  ASSUME(meminit(5,6) == mem(5,5));
  ASSUME(coinit(5,6) == co(5,5));
  ASSUME(deltainit(5,6) == delta(5,5));
  ASSUME(meminit(5,7) == mem(5,6));
  ASSUME(coinit(5,7) == co(5,6));
  ASSUME(deltainit(5,7) == delta(5,6));
  ASSUME(meminit(5,8) == mem(5,7));
  ASSUME(coinit(5,8) == co(5,7));
  ASSUME(deltainit(5,8) == delta(5,7));
  ASSUME(meminit(5,9) == mem(5,8));
  ASSUME(coinit(5,9) == co(5,8));
  ASSUME(deltainit(5,9) == delta(5,8));
  ASSUME(meminit(6,1) == mem(6,0));
  ASSUME(coinit(6,1) == co(6,0));
  ASSUME(deltainit(6,1) == delta(6,0));
  ASSUME(meminit(6,2) == mem(6,1));
  ASSUME(coinit(6,2) == co(6,1));
  ASSUME(deltainit(6,2) == delta(6,1));
  ASSUME(meminit(6,3) == mem(6,2));
  ASSUME(coinit(6,3) == co(6,2));
  ASSUME(deltainit(6,3) == delta(6,2));
  ASSUME(meminit(6,4) == mem(6,3));
  ASSUME(coinit(6,4) == co(6,3));
  ASSUME(deltainit(6,4) == delta(6,3));
  ASSUME(meminit(6,5) == mem(6,4));
  ASSUME(coinit(6,5) == co(6,4));
  ASSUME(deltainit(6,5) == delta(6,4));
  ASSUME(meminit(6,6) == mem(6,5));
  ASSUME(coinit(6,6) == co(6,5));
  ASSUME(deltainit(6,6) == delta(6,5));
  ASSUME(meminit(6,7) == mem(6,6));
  ASSUME(coinit(6,7) == co(6,6));
  ASSUME(deltainit(6,7) == delta(6,6));
  ASSUME(meminit(6,8) == mem(6,7));
  ASSUME(coinit(6,8) == co(6,7));
  ASSUME(deltainit(6,8) == delta(6,7));
  ASSUME(meminit(6,9) == mem(6,8));
  ASSUME(coinit(6,9) == co(6,8));
  ASSUME(deltainit(6,9) == delta(6,8));
  ASSUME(meminit(7,1) == mem(7,0));
  ASSUME(coinit(7,1) == co(7,0));
  ASSUME(deltainit(7,1) == delta(7,0));
  ASSUME(meminit(7,2) == mem(7,1));
  ASSUME(coinit(7,2) == co(7,1));
  ASSUME(deltainit(7,2) == delta(7,1));
  ASSUME(meminit(7,3) == mem(7,2));
  ASSUME(coinit(7,3) == co(7,2));
  ASSUME(deltainit(7,3) == delta(7,2));
  ASSUME(meminit(7,4) == mem(7,3));
  ASSUME(coinit(7,4) == co(7,3));
  ASSUME(deltainit(7,4) == delta(7,3));
  ASSUME(meminit(7,5) == mem(7,4));
  ASSUME(coinit(7,5) == co(7,4));
  ASSUME(deltainit(7,5) == delta(7,4));
  ASSUME(meminit(7,6) == mem(7,5));
  ASSUME(coinit(7,6) == co(7,5));
  ASSUME(deltainit(7,6) == delta(7,5));
  ASSUME(meminit(7,7) == mem(7,6));
  ASSUME(coinit(7,7) == co(7,6));
  ASSUME(deltainit(7,7) == delta(7,6));
  ASSUME(meminit(7,8) == mem(7,7));
  ASSUME(coinit(7,8) == co(7,7));
  ASSUME(deltainit(7,8) == delta(7,7));
  ASSUME(meminit(7,9) == mem(7,8));
  ASSUME(coinit(7,9) == co(7,8));
  ASSUME(deltainit(7,9) == delta(7,8));

  ASSERT(r20== 0);

}
