#ifndef __PP
#define __PP
typedef struct PP_ {
  struct Vector_ filename;
  struct Hash_* macros;
  struct Macro_* entry;
  struct pp_info def;
  size_t arg_len, arg_cap;
  int npar;
  unsigned lint : 1;
} PP;
#endif
