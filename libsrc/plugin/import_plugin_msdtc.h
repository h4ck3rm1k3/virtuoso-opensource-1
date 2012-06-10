#ifndef __gate_import_h_
#define __gate_import_h_
/* This file is automatically generated by plugin/gen_gate.sh */

/* First we should include all imported header files to define data types of
   arguments and return values */
#include "../Wi/mts_client.h"
#include "../Wi/mts.h"
#include "gate_virtuoso_stubs.h"

/* Now we should declare dictionary structure with one member per one imported
   function. At connection time, executable will fill an instance of this
   structure with actual pointers to functions. */
struct _gate_s {
  struct { typeof__dbg_calloc *_ptr; const char *_name; } _dbg_calloc;
  struct { typeof__dbg_free *_ptr; const char *_name; } _dbg_free;
  struct { typeof__dbg_malloc *_ptr; const char *_name; } _dbg_malloc;
  struct { typeof__dbg_malloc_enable *_ptr; const char *_name; } _dbg_malloc_enable;
  struct { typeof__dbg_realloc *_ptr; const char *_name; } _dbg_realloc;
  struct { typeof__dbg_strdup *_ptr; const char *_name; } _dbg_strdup;
  struct { void *_ptr; const char *_name; } _gate_end;
  };

/* Only one instance of _gate_s will exist, and macro definitions will be used
   to access functions of main executable via members of this instance. */
extern struct _gate_s _gate;

#define dbg_calloc (_gate._dbg_calloc._ptr)
#define dbg_free (_gate._dbg_free._ptr)
#define dbg_malloc (_gate._dbg_malloc._ptr)
#define dbg_malloc_enable (_gate._dbg_malloc_enable._ptr)
#define dbg_realloc (_gate._dbg_realloc._ptr)
#define dbg_strdup (_gate._dbg_strdup._ptr)

#endif
