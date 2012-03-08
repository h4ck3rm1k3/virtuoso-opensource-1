#ifndef __gate_import_h_
#define __gate_import_h_
/* This file is automatically generated by plugin/gen_gate.sh */

/* First we should include all imported header files to define data types of
   arguments and return values */
#include "../langfunc/langfunc.h"
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
  struct { typeof__eh_create_charset_handler *_ptr; const char *_name; } _eh_create_charset_handler;
  struct { typeof__eh_create_ucm_handler *_ptr; const char *_name; } _eh_create_ucm_handler;
  struct { eh_decode_buffer_t *_ptr; const char *_name; } _eh_decode_buffer__ASCII;
  struct { eh_decode_buffer_t *_ptr; const char *_name; } _eh_decode_buffer__ISO8859_1;
  struct { eh_decode_buffer_t *_ptr; const char *_name; } _eh_decode_buffer__UCS4BE;
  struct { eh_decode_buffer_t *_ptr; const char *_name; } _eh_decode_buffer__UCS4LE;
  struct { eh_decode_buffer_t *_ptr; const char *_name; } _eh_decode_buffer__UTF16BE;
  struct { eh_decode_buffer_t *_ptr; const char *_name; } _eh_decode_buffer__UTF16LE;
  struct { eh_decode_buffer_t *_ptr; const char *_name; } _eh_decode_buffer__UTF7;
  struct { eh_decode_buffer_t *_ptr; const char *_name; } _eh_decode_buffer__UTF8;
  struct { eh_decode_buffer_t *_ptr; const char *_name; } _eh_decode_buffer__UTF8_QR;
  struct { eh_decode_buffer_t *_ptr; const char *_name; } _eh_decode_buffer__WIDE_121;
  struct { eh_decode_buffer_to_wchar_t *_ptr; const char *_name; } _eh_decode_buffer_to_wchar__ASCII;
  struct { eh_decode_buffer_to_wchar_t *_ptr; const char *_name; } _eh_decode_buffer_to_wchar__ISO8859_1;
  struct { eh_decode_buffer_to_wchar_t *_ptr; const char *_name; } _eh_decode_buffer_to_wchar__UCS4BE;
  struct { eh_decode_buffer_to_wchar_t *_ptr; const char *_name; } _eh_decode_buffer_to_wchar__UCS4LE;
  struct { eh_decode_buffer_to_wchar_t *_ptr; const char *_name; } _eh_decode_buffer_to_wchar__UTF16BE;
  struct { eh_decode_buffer_to_wchar_t *_ptr; const char *_name; } _eh_decode_buffer_to_wchar__UTF16LE;
  struct { eh_decode_buffer_to_wchar_t *_ptr; const char *_name; } _eh_decode_buffer_to_wchar__UTF7;
  struct { eh_decode_buffer_to_wchar_t *_ptr; const char *_name; } _eh_decode_buffer_to_wchar__UTF8;
  struct { eh_decode_buffer_to_wchar_t *_ptr; const char *_name; } _eh_decode_buffer_to_wchar__UTF8_QR;
  struct { eh_decode_buffer_to_wchar_t *_ptr; const char *_name; } _eh_decode_buffer_to_wchar__WIDE_121;
  struct { eh_decode_char_t *_ptr; const char *_name; } _eh_decode_char__ASCII;
  struct { eh_decode_char_t *_ptr; const char *_name; } _eh_decode_char__ISO8859_1;
  struct { eh_decode_char_t *_ptr; const char *_name; } _eh_decode_char__UCS4BE;
  struct { eh_decode_char_t *_ptr; const char *_name; } _eh_decode_char__UCS4LE;
  struct { eh_decode_char_t *_ptr; const char *_name; } _eh_decode_char__UTF16BE;
  struct { eh_decode_char_t *_ptr; const char *_name; } _eh_decode_char__UTF16LE;
  struct { eh_decode_char_t *_ptr; const char *_name; } _eh_decode_char__UTF7;
  struct { eh_decode_char_t *_ptr; const char *_name; } _eh_decode_char__UTF8;
  struct { eh_decode_char_t *_ptr; const char *_name; } _eh_decode_char__UTF8_QR;
  struct { eh_decode_char_t *_ptr; const char *_name; } _eh_decode_char__WIDE_121;
  struct { typeof__eh_duplicate_handler *_ptr; const char *_name; } _eh_duplicate_handler;
  struct { eh_encode_buffer_t *_ptr; const char *_name; } _eh_encode_buffer__ASCII;
  struct { eh_encode_buffer_t *_ptr; const char *_name; } _eh_encode_buffer__ISO8859_1;
  struct { eh_encode_buffer_t *_ptr; const char *_name; } _eh_encode_buffer__UCS4BE;
  struct { eh_encode_buffer_t *_ptr; const char *_name; } _eh_encode_buffer__UCS4LE;
  struct { eh_encode_buffer_t *_ptr; const char *_name; } _eh_encode_buffer__UTF16BE;
  struct { eh_encode_buffer_t *_ptr; const char *_name; } _eh_encode_buffer__UTF16LE;
  struct { eh_encode_buffer_t *_ptr; const char *_name; } _eh_encode_buffer__UTF7;
  struct { eh_encode_buffer_t *_ptr; const char *_name; } _eh_encode_buffer__UTF8;
  struct { eh_encode_buffer_t *_ptr; const char *_name; } _eh_encode_buffer__WIDE_121;
  struct { eh_encode_char_t *_ptr; const char *_name; } _eh_encode_char__ASCII;
  struct { eh_encode_char_t *_ptr; const char *_name; } _eh_encode_char__ISO8859_1;
  struct { eh_encode_char_t *_ptr; const char *_name; } _eh_encode_char__UCS4BE;
  struct { eh_encode_char_t *_ptr; const char *_name; } _eh_encode_char__UCS4LE;
  struct { eh_encode_char_t *_ptr; const char *_name; } _eh_encode_char__UTF16BE;
  struct { eh_encode_char_t *_ptr; const char *_name; } _eh_encode_char__UTF16LE;
  struct { eh_encode_char_t *_ptr; const char *_name; } _eh_encode_char__UTF7;
  struct { eh_encode_char_t *_ptr; const char *_name; } _eh_encode_char__UTF8;
  struct { eh_encode_char_t *_ptr; const char *_name; } _eh_encode_char__WIDE_121;
  struct { eh_encode_wchar_buffer_t *_ptr; const char *_name; } _eh_encode_wchar_buffer__ASCII;
  struct { eh_encode_wchar_buffer_t *_ptr; const char *_name; } _eh_encode_wchar_buffer__ISO8859_1;
  struct { eh_encode_wchar_buffer_t *_ptr; const char *_name; } _eh_encode_wchar_buffer__UCS4BE;
  struct { eh_encode_wchar_buffer_t *_ptr; const char *_name; } _eh_encode_wchar_buffer__UCS4LE;
  struct { eh_encode_wchar_buffer_t *_ptr; const char *_name; } _eh_encode_wchar_buffer__UTF16BE;
  struct { eh_encode_wchar_buffer_t *_ptr; const char *_name; } _eh_encode_wchar_buffer__UTF16LE;
  struct { eh_encode_wchar_buffer_t *_ptr; const char *_name; } _eh_encode_wchar_buffer__UTF7;
  struct { eh_encode_wchar_buffer_t *_ptr; const char *_name; } _eh_encode_wchar_buffer__UTF8;
  struct { eh_encode_wchar_buffer_t *_ptr; const char *_name; } _eh_encode_wchar_buffer__WIDE_121;
  struct { typeof__eh_get_handler *_ptr; const char *_name; } _eh_get_handler;
  struct { typeof__eh_load_handler *_ptr; const char *_name; } _eh_load_handler;
  struct { typeof__eh_wide_from_narrow *_ptr; const char *_name; } _eh_wide_from_narrow;
  struct { typeof__elh_get_handler *_ptr; const char *_name; } _elh_get_handler;
  struct { typeof__elh_load_handler *_ptr; const char *_name; } _elh_load_handler;
  struct { typeof__lh_get_handler *_ptr; const char *_name; } _lh_get_handler;
  struct { typeof__lh_load_handler *_ptr; const char *_name; } _lh_load_handler;
  struct { typeof__unichar_getlcase *_ptr; const char *_name; } _unichar_getlcase;
  struct { typeof__unichar_getprops *_ptr; const char *_name; } _unichar_getprops;
  struct { typeof__unichar_getucase *_ptr; const char *_name; } _unichar_getucase;
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
#define eh_create_charset_handler (_gate._eh_create_charset_handler._ptr)
#define eh_create_ucm_handler (_gate._eh_create_ucm_handler._ptr)
#define eh_decode_buffer__ASCII (_gate._eh_decode_buffer__ASCII._ptr)
#define eh_decode_buffer__ISO8859_1 (_gate._eh_decode_buffer__ISO8859_1._ptr)
#define eh_decode_buffer__UCS4BE (_gate._eh_decode_buffer__UCS4BE._ptr)
#define eh_decode_buffer__UCS4LE (_gate._eh_decode_buffer__UCS4LE._ptr)
#define eh_decode_buffer__UTF16BE (_gate._eh_decode_buffer__UTF16BE._ptr)
#define eh_decode_buffer__UTF16LE (_gate._eh_decode_buffer__UTF16LE._ptr)
#define eh_decode_buffer__UTF7 (_gate._eh_decode_buffer__UTF7._ptr)
#define eh_decode_buffer__UTF8 (_gate._eh_decode_buffer__UTF8._ptr)
#define eh_decode_buffer__UTF8_QR (_gate._eh_decode_buffer__UTF8_QR._ptr)
#define eh_decode_buffer__WIDE_121 (_gate._eh_decode_buffer__WIDE_121._ptr)
#define eh_decode_buffer_to_wchar__ASCII (_gate._eh_decode_buffer_to_wchar__ASCII._ptr)
#define eh_decode_buffer_to_wchar__ISO8859_1 (_gate._eh_decode_buffer_to_wchar__ISO8859_1._ptr)
#define eh_decode_buffer_to_wchar__UCS4BE (_gate._eh_decode_buffer_to_wchar__UCS4BE._ptr)
#define eh_decode_buffer_to_wchar__UCS4LE (_gate._eh_decode_buffer_to_wchar__UCS4LE._ptr)
#define eh_decode_buffer_to_wchar__UTF16BE (_gate._eh_decode_buffer_to_wchar__UTF16BE._ptr)
#define eh_decode_buffer_to_wchar__UTF16LE (_gate._eh_decode_buffer_to_wchar__UTF16LE._ptr)
#define eh_decode_buffer_to_wchar__UTF7 (_gate._eh_decode_buffer_to_wchar__UTF7._ptr)
#define eh_decode_buffer_to_wchar__UTF8 (_gate._eh_decode_buffer_to_wchar__UTF8._ptr)
#define eh_decode_buffer_to_wchar__UTF8_QR (_gate._eh_decode_buffer_to_wchar__UTF8_QR._ptr)
#define eh_decode_buffer_to_wchar__WIDE_121 (_gate._eh_decode_buffer_to_wchar__WIDE_121._ptr)
#define eh_decode_char__ASCII (_gate._eh_decode_char__ASCII._ptr)
#define eh_decode_char__ISO8859_1 (_gate._eh_decode_char__ISO8859_1._ptr)
#define eh_decode_char__UCS4BE (_gate._eh_decode_char__UCS4BE._ptr)
#define eh_decode_char__UCS4LE (_gate._eh_decode_char__UCS4LE._ptr)
#define eh_decode_char__UTF16BE (_gate._eh_decode_char__UTF16BE._ptr)
#define eh_decode_char__UTF16LE (_gate._eh_decode_char__UTF16LE._ptr)
#define eh_decode_char__UTF7 (_gate._eh_decode_char__UTF7._ptr)
#define eh_decode_char__UTF8 (_gate._eh_decode_char__UTF8._ptr)
#define eh_decode_char__UTF8_QR (_gate._eh_decode_char__UTF8_QR._ptr)
#define eh_decode_char__WIDE_121 (_gate._eh_decode_char__WIDE_121._ptr)
#define eh_duplicate_handler (_gate._eh_duplicate_handler._ptr)
#define eh_encode_buffer__ASCII (_gate._eh_encode_buffer__ASCII._ptr)
#define eh_encode_buffer__ISO8859_1 (_gate._eh_encode_buffer__ISO8859_1._ptr)
#define eh_encode_buffer__UCS4BE (_gate._eh_encode_buffer__UCS4BE._ptr)
#define eh_encode_buffer__UCS4LE (_gate._eh_encode_buffer__UCS4LE._ptr)
#define eh_encode_buffer__UTF16BE (_gate._eh_encode_buffer__UTF16BE._ptr)
#define eh_encode_buffer__UTF16LE (_gate._eh_encode_buffer__UTF16LE._ptr)
#define eh_encode_buffer__UTF7 (_gate._eh_encode_buffer__UTF7._ptr)
#define eh_encode_buffer__UTF8 (_gate._eh_encode_buffer__UTF8._ptr)
#define eh_encode_buffer__WIDE_121 (_gate._eh_encode_buffer__WIDE_121._ptr)
#define eh_encode_char__ASCII (_gate._eh_encode_char__ASCII._ptr)
#define eh_encode_char__ISO8859_1 (_gate._eh_encode_char__ISO8859_1._ptr)
#define eh_encode_char__UCS4BE (_gate._eh_encode_char__UCS4BE._ptr)
#define eh_encode_char__UCS4LE (_gate._eh_encode_char__UCS4LE._ptr)
#define eh_encode_char__UTF16BE (_gate._eh_encode_char__UTF16BE._ptr)
#define eh_encode_char__UTF16LE (_gate._eh_encode_char__UTF16LE._ptr)
#define eh_encode_char__UTF7 (_gate._eh_encode_char__UTF7._ptr)
#define eh_encode_char__UTF8 (_gate._eh_encode_char__UTF8._ptr)
#define eh_encode_char__WIDE_121 (_gate._eh_encode_char__WIDE_121._ptr)
#define eh_encode_wchar_buffer__ASCII (_gate._eh_encode_wchar_buffer__ASCII._ptr)
#define eh_encode_wchar_buffer__ISO8859_1 (_gate._eh_encode_wchar_buffer__ISO8859_1._ptr)
#define eh_encode_wchar_buffer__UCS4BE (_gate._eh_encode_wchar_buffer__UCS4BE._ptr)
#define eh_encode_wchar_buffer__UCS4LE (_gate._eh_encode_wchar_buffer__UCS4LE._ptr)
#define eh_encode_wchar_buffer__UTF16BE (_gate._eh_encode_wchar_buffer__UTF16BE._ptr)
#define eh_encode_wchar_buffer__UTF16LE (_gate._eh_encode_wchar_buffer__UTF16LE._ptr)
#define eh_encode_wchar_buffer__UTF7 (_gate._eh_encode_wchar_buffer__UTF7._ptr)
#define eh_encode_wchar_buffer__UTF8 (_gate._eh_encode_wchar_buffer__UTF8._ptr)
#define eh_encode_wchar_buffer__WIDE_121 (_gate._eh_encode_wchar_buffer__WIDE_121._ptr)
#define eh_get_handler (_gate._eh_get_handler._ptr)
#define eh_load_handler (_gate._eh_load_handler._ptr)
#define eh_wide_from_narrow (_gate._eh_wide_from_narrow._ptr)
#define elh_get_handler (_gate._elh_get_handler._ptr)
#define elh_load_handler (_gate._elh_load_handler._ptr)
#define lh_get_handler (_gate._lh_get_handler._ptr)
#define lh_load_handler (_gate._lh_load_handler._ptr)
#define unichar_getlcase (_gate._unichar_getlcase._ptr)
#define unichar_getprops (_gate._unichar_getprops._ptr)
#define unichar_getucase (_gate._unichar_getucase._ptr)

#endif