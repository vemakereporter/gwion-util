#ifndef __DEF
#define __DEF

#ifdef USE_GETTEXT
#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#define _(String) dgettext(PACKAGE, String)
#else
#define _(String) (String)
#endif

#define container_of(ptr, type, member) ((type *)( (char *)(ptr) - offsetof(type,member) ))

#define GW_ERROR -1
#define GW_OK     1
#define MEM_STEP 16
#define SIZEOF_MEM (0x1 << MEM_STEP)
#define SIZEOF_REG (0x1 << 14)

#define ANN __attribute__((nonnull))
#define ANN2(...) __attribute__((nonnull(__VA_ARGS__)))
#define ANEW __attribute__((returns_nonnull,malloc))
#define NUSED __attribute__((unused))

#ifdef __GNUC__
#ifdef __clang__
#define LOOP_OPTIM
#else
#define LOOP_OPTIM _Pragma("GCC ivdep")
#endif
#else
#define LOOP_OPTIM
#endif

#define CHECK_BB(f) { if(f < 0) return -1;   }
#define CHECK_OB(f) { if(!f)    return -1;   }
#define CHECK_BO(f) { if(f < 0) return NULL; }
#define CHECK_OO(f) { if(!f)    return NULL; }

#define DECL_BB(decl, f, exp) decl f exp; { if(f < 0) return -1;   }
#define DECL_OB(decl, f, exp) decl f exp; { if(!f)    return -1;   }
#define DECL_BO(decl, f, exp) decl f exp; { if(f < 0) return NULL; }
#define DECL_OO(decl, f, exp) decl f exp; { if(!f)    return NULL; }

#define SET_FLAG(a, b) (a)->flag |= (ae_flag_##b)
#define GET_FLAG(a, b) (((a)->flag & ae_flag_##b) == (ae_flag_##b))
#define SAFE_FLAG(a, b) (a && ((a)->flag & (ae_flag_##b)) == (ae_flag_##b))
#define UNSET_FLAG(a, b) ((a)->flag &= (uint)~(ae_flag_##b))

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "generated.h"

typedef unsigned int uint;

ANEW const void* xmalloc(const m_uint);
ANEW const void* xcalloc(const m_uint, const m_uint);
ANEW const void* xrealloc(void*, const m_uint);
#define xfree free

typedef enum {
  ae_flag_none = 1 << 0,
  ae_flag_builtin = 1 << 1,
  ae_flag_checked   = 1 << 2,
  ae_flag_member  = 1 << 3,
  ae_flag_static  = 1 << 4,
  ae_flag_template  = 1 << 5,
  ae_flag_variadic  = 1 << 6,
  ae_flag_ctor  = 1 << 7,
  ae_flag_dtor  = 1 << 8,
  ae_flag_op  = 1 << 9,
  ae_flag_private  = 1 << 10,
  ae_flag_global  = 1 << 11,
  ae_flag_const  = 1 << 12,
  ae_flag_enum  = 1 << 13,
  ae_flag_union  = 1 << 14,
  ae_flag_arg  = 1 << 15,
  ae_flag_ref  = 1 << 16,
  ae_flag_abstract  = 1 << 17, // abstract type and variables in global functions
  ae_flag_typedef  = 1 << 18,
  ae_flag_unary  = 1 << 19,
  ae_flag_func  = 1 << 20, // for value holding func
  ae_flag_empty  = 1 << 21, // for typedef with empty array
    // and complete vararg func def
// parsing flags for class_def->type
  ae_flag_scan0 = 1 << 22,
  ae_flag_scan1 = 1 << 23,
  ae_flag_scan2 = 1 << 24,
  ae_flag_check = 1 << 25,
  ae_flag_emit  = 1 << 26,
  ae_flag_protect = 1 << 27,
  ae_flag_used = 1 << 28,
  ae_flag_pure = 1 << 29,
  ae_flag_force = 1 << 30,
  ae_flag_nonnull = 1 << 31
} ae_flag;

static inline m_uint num_digit(const m_uint i) {
  return i ? (m_uint)floor(log10((float)i) + 1) : 1;
}

static inline m_uint round2szint(const m_uint i) {
  return ((i + (SZ_INT-1)) & ~(SZ_INT-1));
}
#endif
