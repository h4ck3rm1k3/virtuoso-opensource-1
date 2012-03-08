#ifndef __gate_import_h_
#define __gate_import_h_
/* This file is automatically generated by plugin/gen_gate.sh */

/* First we should include all imported header files to define data types of
   arguments and return values */
#include "../Dk.h"
#include "../Dk/Dkalloc.h"
#include "../Dk/Dkbox.h"
#include "../Dk/Dkhash.h"
#include "../Dk/Dksession.h"
#include "../Dk/Dkernel.h"
#include "../Dk/Dkhashext.h"
#include "../Dk/Dksets.h"
#include "../Thread/Dkthread.h"
#include "../Wi/wi.h"
#include "../Wi/sqlnode.h"
#include "../Wi/sqlfn.h"
#include "../Wi/eqlcomp.h"
#include "../Wi/lisprdr.h"
#include "../Wi/sqlpar.h"
#include "../Wi/sqlcmps.h"
#include "../Wi/sqlintrp.h"
#include "../Wi/sqlbif.h"
#include "../Wi/widd.h"
#include "../Wi/arith.h"
#include "../Wi/security.h"
#include "../Wi/sqlpfn.h"
#include "../Wi/date.h"
#include "../Wi/datesupp.h"
#include "../Wi/multibyte.h"
#include "../Wi/srvmultibyte.h"
#include "../Wi/bif_xper.h"
#include "../libutil.h"
#include "../Wi/http.h"
#include "../Wi/xmltree.h"
#include "../Wi/sqlofn.h"
#include "../Wi/statuslog.h"
#include "../Wi/bif_text.h"
#include "../Xml.new/xmlparser.h"
#include "../Wi/xmltree.h"
#include "../Wi/sql3.h"
#include "../Wi/repl.h"
#include "../Wi/replsr.h"
#include "../Tidy/html.h"
#include "../langfunc/langfunc.h"
#include "../Wi/wifn.h"
#include "../Wi/sqlfn.h"
#include "../Wi/ltrx.h"
#include "../Wi/2pc.h"
#include "gate_virtuoso_stubs.h"

/* Now we should declare dictionary structure with one member per one imported
   function. At connection time, executable will fill an instance of this
   structure with actual pointers to functions. */
struct _gate_s {
  struct { typeof__DoSQLError *_ptr; const char *_name; } _DoSQLError;
  struct { typeof__PrpcSessionFree *_ptr; const char *_name; } _PrpcSessionFree;
  struct { typeof__bif_arg *_ptr; const char *_name; } _bif_arg;
  struct { typeof__bif_arg_unrdf *_ptr; const char *_name; } _bif_arg_unrdf;
  struct { typeof__bif_array_arg *_ptr; const char *_name; } _bif_array_arg;
  struct { typeof__bif_array_of_pointer_arg *_ptr; const char *_name; } _bif_array_of_pointer_arg;
  struct { typeof__bif_array_or_null_arg *_ptr; const char *_name; } _bif_array_or_null_arg;
  struct { typeof__bif_bin_arg *_ptr; const char *_name; } _bif_bin_arg;
  struct { typeof__bif_date_arg *_ptr; const char *_name; } _bif_date_arg;
  struct { typeof__bif_define *_ptr; const char *_name; } _bif_define;
  struct { typeof__bif_define_typed *_ptr; const char *_name; } _bif_define_typed;
  struct { typeof__bif_dict_iterator_arg *_ptr; const char *_name; } _bif_dict_iterator_arg;
  struct { typeof__bif_dict_iterator_or_null_arg *_ptr; const char *_name; } _bif_dict_iterator_or_null_arg;
  struct { typeof__bif_double_arg *_ptr; const char *_name; } _bif_double_arg;
  struct { typeof__bif_entity_arg *_ptr; const char *_name; } _bif_entity_arg;
  struct { typeof__bif_find *_ptr; const char *_name; } _bif_find;
  struct { typeof__bif_float_arg *_ptr; const char *_name; } _bif_float_arg;
  struct { typeof__bif_iri_id_arg *_ptr; const char *_name; } _bif_iri_id_arg;
  struct { typeof__bif_iri_id_or_null_arg *_ptr; const char *_name; } _bif_iri_id_or_null_arg;
  struct { typeof__bif_long_arg *_ptr; const char *_name; } _bif_long_arg;
  struct { typeof__bif_long_low_range_arg *_ptr; const char *_name; } _bif_long_low_range_arg;
  struct { typeof__bif_long_or_char_arg *_ptr; const char *_name; } _bif_long_or_char_arg;
  struct { typeof__bif_long_or_null_arg *_ptr; const char *_name; } _bif_long_or_null_arg;
  struct { typeof__bif_long_range_arg *_ptr; const char *_name; } _bif_long_range_arg;
  struct { typeof__bif_result_inside_bif *_ptr; const char *_name; } _bif_result_inside_bif;
  struct { typeof__bif_result_names *_ptr; const char *_name; } _bif_result_names;
  struct { typeof__bif_set_uses_index *_ptr; const char *_name; } _bif_set_uses_index;
  struct { typeof__bif_strict_2type_array_arg *_ptr; const char *_name; } _bif_strict_2type_array_arg;
  struct { typeof__bif_strict_array_or_null_arg *_ptr; const char *_name; } _bif_strict_array_or_null_arg;
  struct { typeof__bif_strict_type_array_arg *_ptr; const char *_name; } _bif_strict_type_array_arg;
  struct { typeof__bif_string_arg *_ptr; const char *_name; } _bif_string_arg;
  struct { typeof__bif_string_or_null_arg *_ptr; const char *_name; } _bif_string_or_null_arg;
  struct { typeof__bif_string_or_uname_arg *_ptr; const char *_name; } _bif_string_or_uname_arg;
  struct { typeof__bif_string_or_uname_or_iri_id_arg *_ptr; const char *_name; } _bif_string_or_uname_or_iri_id_arg;
  struct { typeof__bif_string_or_uname_or_wide_or_null_arg *_ptr; const char *_name; } _bif_string_or_uname_or_wide_or_null_arg;
  struct { typeof__bif_string_or_wide_or_null_arg *_ptr; const char *_name; } _bif_string_or_wide_or_null_arg;
  struct { typeof__bif_string_or_wide_or_null_or_strses_arg *_ptr; const char *_name; } _bif_string_or_wide_or_null_or_strses_arg;
  struct { typeof__bif_string_or_wide_or_uname_arg *_ptr; const char *_name; } _bif_string_or_wide_or_uname_arg;
  struct { typeof__bif_strses_arg *_ptr; const char *_name; } _bif_strses_arg;
  struct { typeof__bif_strses_or_http_ses_arg *_ptr; const char *_name; } _bif_strses_or_http_ses_arg;
  struct { typeof__bif_tree_ent_arg *_ptr; const char *_name; } _bif_tree_ent_arg;
  struct { typeof__bif_uses_index *_ptr; const char *_name; } _bif_uses_index;
  struct { typeof__bif_varchar_or_bin_arg *_ptr; const char *_name; } _bif_varchar_or_bin_arg;
  struct { typeof__box_cast *_ptr; const char *_name; } _box_cast;
  struct { typeof__box_copy *_ptr; const char *_name; } _box_copy;
  struct { typeof__box_copy_tree *_ptr; const char *_name; } _box_copy_tree;
  struct { typeof__box_double *_ptr; const char *_name; } _box_double;
  struct { typeof__box_dv_short_concat *_ptr; const char *_name; } _box_dv_short_concat;
  struct { typeof__box_dv_short_nchars *_ptr; const char *_name; } _box_dv_short_nchars;
  struct { typeof__box_dv_short_nchars_reuse *_ptr; const char *_name; } _box_dv_short_nchars_reuse;
  struct { typeof__box_dv_short_strconcat *_ptr; const char *_name; } _box_dv_short_strconcat;
  struct { typeof__box_dv_short_string *_ptr; const char *_name; } _box_dv_short_string;
  struct { typeof__box_dv_short_substr *_ptr; const char *_name; } _box_dv_short_substr;
  struct { typeof__box_dv_ubuf *_ptr; const char *_name; } _box_dv_ubuf;
  struct { typeof__box_dv_uname_from_ubuf *_ptr; const char *_name; } _box_dv_uname_from_ubuf;
  struct { typeof__box_dv_uname_nchars *_ptr; const char *_name; } _box_dv_uname_nchars;
  struct { typeof__box_dv_uname_string *_ptr; const char *_name; } _box_dv_uname_string;
  struct { typeof__box_dv_uname_substr *_ptr; const char *_name; } _box_dv_uname_substr;
  struct { typeof__box_equal *_ptr; const char *_name; } _box_equal;
  struct { typeof__box_find_mt_unsafe_subtree *_ptr; const char *_name; } _box_find_mt_unsafe_subtree;
  struct { typeof__box_float *_ptr; const char *_name; } _box_float;
  struct { typeof__box_make_tree_mt_safe *_ptr; const char *_name; } _box_make_tree_mt_safe;
  struct { typeof__box_num *_ptr; const char *_name; } _box_num;
  struct { typeof__box_num_nonull *_ptr; const char *_name; } _box_num_nonull;
  struct { typeof__box_sprintf *_ptr; const char *_name; } _box_sprintf;
  struct { typeof__box_string *_ptr; const char *_name; } _box_string;
  struct { typeof__box_vsprintf *_ptr; const char *_name; } _box_vsprintf;
  struct { typeof__copy_list_to_array *_ptr; const char *_name; } _copy_list_to_array;
  struct { typeof__dbg_calloc *_ptr; const char *_name; } _dbg_calloc;
  struct { typeof__dbg_free *_ptr; const char *_name; } _dbg_free;
  struct { typeof__dbg_malloc *_ptr; const char *_name; } _dbg_malloc;
  struct { typeof__dbg_malloc_enable *_ptr; const char *_name; } _dbg_malloc_enable;
  struct { typeof__dbg_realloc *_ptr; const char *_name; } _dbg_realloc;
  struct { typeof__dbg_strdup *_ptr; const char *_name; } _dbg_strdup;
  struct { typeof__dk_alloc *_ptr; const char *_name; } _dk_alloc;
  struct { typeof__dk_alloc_box *_ptr; const char *_name; } _dk_alloc_box;
  struct { typeof__dk_alloc_box_long *_ptr; const char *_name; } _dk_alloc_box_long;
  struct { typeof__dk_alloc_box_zero *_ptr; const char *_name; } _dk_alloc_box_zero;
  struct { typeof__dk_free *_ptr; const char *_name; } _dk_free;
  struct { typeof__dk_free_box *_ptr; const char *_name; } _dk_free_box;
  struct { typeof__dk_free_box_and_int_boxes *_ptr; const char *_name; } _dk_free_box_and_int_boxes;
  struct { typeof__dk_free_box_and_numbers *_ptr; const char *_name; } _dk_free_box_and_numbers;
  struct { typeof__dk_free_tree *_ptr; const char *_name; } _dk_free_tree;
  struct { typeof__dk_session_allocate *_ptr; const char *_name; } _dk_session_allocate;
  struct { typeof__dk_set_delete *_ptr; const char *_name; } _dk_set_delete;
  struct { typeof__dk_set_delete_nth *_ptr; const char *_name; } _dk_set_delete_nth;
  struct { typeof__dk_set_push *_ptr; const char *_name; } _dk_set_push;
  struct { typeof__dk_try_alloc *_ptr; const char *_name; } _dk_try_alloc;
  struct { typeof__dk_try_alloc_box *_ptr; const char *_name; } _dk_try_alloc_box;
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
  struct { typeof__id_hash_add_new *_ptr; const char *_name; } _id_hash_add_new;
  struct { typeof__id_hash_allocate *_ptr; const char *_name; } _id_hash_allocate;
  struct { typeof__id_hash_get *_ptr; const char *_name; } _id_hash_get;
  struct { typeof__id_hash_get_with_ctx *_ptr; const char *_name; } _id_hash_get_with_ctx;
  struct { typeof__id_hash_get_with_hash_number *_ptr; const char *_name; } _id_hash_get_with_hash_number;
  struct { typeof__id_hash_set *_ptr; const char *_name; } _id_hash_set;
  struct { typeof__id_hash_set_with_hash_number *_ptr; const char *_name; } _id_hash_set_with_hash_number;
  struct { typeof__lh_get_handler *_ptr; const char *_name; } _lh_get_handler;
  struct { typeof__lh_load_handler *_ptr; const char *_name; } _lh_load_handler;
  struct { typeof__list_to_array *_ptr; const char *_name; } _list_to_array;
  struct { typeof__lt_start *_ptr; const char *_name; } _lt_start;
  struct { typeof__md5 *_ptr; const char *_name; } _md5;
  struct { typeof__mq_add_message *_ptr; const char *_name; } _mq_add_message;
  struct { typeof__mq_create_message *_ptr; const char *_name; } _mq_create_message;
  struct { typeof__mutex_allocate *_ptr; const char *_name; } _mutex_allocate;
  struct { typeof__mutex_enter *_ptr; const char *_name; } _mutex_enter;
  struct { typeof__mutex_free *_ptr; const char *_name; } _mutex_free;
  struct { typeof__mutex_leave *_ptr; const char *_name; } _mutex_leave;
  struct { typeof__registry_get *_ptr; const char *_name; } _registry_get;
  struct { typeof__registry_get_all *_ptr; const char *_name; } _registry_get_all;
  struct { typeof__revlist_to_array *_ptr; const char *_name; } _revlist_to_array;
  struct { typeof__sec_check_dba *_ptr; const char *_name; } _sec_check_dba;
  struct { typeof__semaphore_allocate *_ptr; const char *_name; } _semaphore_allocate;
  struct { typeof__server_logmsg_ap *_ptr; const char *_name; } _server_logmsg_ap;
  struct { typeof__service_read *_ptr; const char *_name; } _service_read;
  struct { typeof__service_write *_ptr; const char *_name; } _service_write;
  struct { typeof__session_accept *_ptr; const char *_name; } _session_accept;
  struct { typeof__session_buffered_read *_ptr; const char *_name; } _session_buffered_read;
  struct { typeof__session_buffered_read_char *_ptr; const char *_name; } _session_buffered_read_char;
  struct { typeof__session_buffered_write *_ptr; const char *_name; } _session_buffered_write;
  struct { typeof__session_buffered_write_char *_ptr; const char *_name; } _session_buffered_write_char;
  struct { typeof__session_connect *_ptr; const char *_name; } _session_connect;
  struct { typeof__session_disconnect *_ptr; const char *_name; } _session_disconnect;
  struct { typeof__session_flush *_ptr; const char *_name; } _session_flush;
  struct { typeof__session_flush_1 *_ptr; const char *_name; } _session_flush_1;
  struct { typeof__session_listen *_ptr; const char *_name; } _session_listen;
  struct { typeof__session_read *_ptr; const char *_name; } _session_read;
  struct { typeof__session_select *_ptr; const char *_name; } _session_select;
  struct { typeof__session_set_address *_ptr; const char *_name; } _session_set_address;
  struct { typeof__session_set_control *_ptr; const char *_name; } _session_set_control;
  struct { typeof__session_write *_ptr; const char *_name; } _session_write;
  struct { typeof__sprintf_inverse *_ptr; const char *_name; } _sprintf_inverse;
  struct { typeof__sprintf_inverse_ex *_ptr; const char *_name; } _sprintf_inverse_ex;
  struct { typeof__sqlr_error *_ptr; const char *_name; } _sqlr_error;
  struct { typeof__sqlr_new_error *_ptr; const char *_name; } _sqlr_new_error;
  struct { typeof__sqlr_resignal *_ptr; const char *_name; } _sqlr_resignal;
  struct { typeof__srv_make_new_error *_ptr; const char *_name; } _srv_make_new_error;
  struct { typeof__strhash *_ptr; const char *_name; } _strhash;
  struct { typeof__strhashcmp *_ptr; const char *_name; } _strhashcmp;
  struct { typeof__strses_allocate *_ptr; const char *_name; } _strses_allocate;
  struct { typeof__strses_flush *_ptr; const char *_name; } _strses_flush;
  struct { typeof__strses_free *_ptr; const char *_name; } _strses_free;
  struct { typeof__strses_length *_ptr; const char *_name; } _strses_length;
  struct { typeof__strses_string *_ptr; const char *_name; } _strses_string;
  struct { typeof__strses_write_out *_ptr; const char *_name; } _strses_write_out;
  struct { typeof__tcpses_get_fd *_ptr; const char *_name; } _tcpses_get_fd;
  struct { typeof__tcpses_get_last_r_errno *_ptr; const char *_name; } _tcpses_get_last_r_errno;
  struct { typeof__tcpses_get_last_w_errno *_ptr; const char *_name; } _tcpses_get_last_w_errno;
  struct { typeof__tcpses_set_fd *_ptr; const char *_name; } _tcpses_set_fd;
  struct { typeof__thr_get_error_code *_ptr; const char *_name; } _thr_get_error_code;
  struct { typeof__thr_set_error_code *_ptr; const char *_name; } _thr_set_error_code;
  struct { typeof__thread_current *_ptr; const char *_name; } _thread_current;
  struct { typeof__thread_getattr *_ptr; const char *_name; } _thread_getattr;
  struct { typeof__thread_setattr *_ptr; const char *_name; } _thread_setattr;
  struct { typeof__tp_get_main_queue *_ptr; const char *_name; } _tp_get_main_queue;
  struct { typeof__tp_retire *_ptr; const char *_name; } _tp_retire;
  struct { typeof__twopc_log *_ptr; const char *_name; } _twopc_log;
  struct { typeof__unbox *_ptr; const char *_name; } _unbox;
  struct { typeof__unbox_int64 *_ptr; const char *_name; } _unbox_int64;
  struct { typeof__unbox_ptrlong *_ptr; const char *_name; } _unbox_ptrlong;
  struct { typeof__unichar_getlcase *_ptr; const char *_name; } _unichar_getlcase;
  struct { typeof__unichar_getprops *_ptr; const char *_name; } _unichar_getprops;
  struct { typeof__unichar_getucase *_ptr; const char *_name; } _unichar_getucase;
  struct { typeof__uudecode_base64 *_ptr; const char *_name; } _uudecode_base64;
  struct { typeof__wi_instance_get *_ptr; const char *_name; } _wi_instance_get;
  struct { void *_ptr; const char *_name; } _gate_end;
  };

/* Only one instance of _gate_s will exist, and macro definitions will be used
   to access functions of main executable via members of this instance. */
extern struct _gate_s _gate;

#define DoSQLError (_gate._DoSQLError._ptr)
#define PrpcSessionFree (_gate._PrpcSessionFree._ptr)
#define bif_arg (_gate._bif_arg._ptr)
#define bif_arg_unrdf (_gate._bif_arg_unrdf._ptr)
#define bif_array_arg (_gate._bif_array_arg._ptr)
#define bif_array_of_pointer_arg (_gate._bif_array_of_pointer_arg._ptr)
#define bif_array_or_null_arg (_gate._bif_array_or_null_arg._ptr)
#define bif_bin_arg (_gate._bif_bin_arg._ptr)
#define bif_date_arg (_gate._bif_date_arg._ptr)
#define bif_define (_gate._bif_define._ptr)
#define bif_define_typed (_gate._bif_define_typed._ptr)
#define bif_dict_iterator_arg (_gate._bif_dict_iterator_arg._ptr)
#define bif_dict_iterator_or_null_arg (_gate._bif_dict_iterator_or_null_arg._ptr)
#define bif_double_arg (_gate._bif_double_arg._ptr)
#define bif_entity_arg (_gate._bif_entity_arg._ptr)
#define bif_find (_gate._bif_find._ptr)
#define bif_float_arg (_gate._bif_float_arg._ptr)
#define bif_iri_id_arg (_gate._bif_iri_id_arg._ptr)
#define bif_iri_id_or_null_arg (_gate._bif_iri_id_or_null_arg._ptr)
#define bif_long_arg (_gate._bif_long_arg._ptr)
#define bif_long_low_range_arg (_gate._bif_long_low_range_arg._ptr)
#define bif_long_or_char_arg (_gate._bif_long_or_char_arg._ptr)
#define bif_long_or_null_arg (_gate._bif_long_or_null_arg._ptr)
#define bif_long_range_arg (_gate._bif_long_range_arg._ptr)
#define bif_result_inside_bif (_gate._bif_result_inside_bif._ptr)
#define bif_result_names (_gate._bif_result_names._ptr)
#define bif_set_uses_index (_gate._bif_set_uses_index._ptr)
#define bif_strict_2type_array_arg (_gate._bif_strict_2type_array_arg._ptr)
#define bif_strict_array_or_null_arg (_gate._bif_strict_array_or_null_arg._ptr)
#define bif_strict_type_array_arg (_gate._bif_strict_type_array_arg._ptr)
#define bif_string_arg (_gate._bif_string_arg._ptr)
#define bif_string_or_null_arg (_gate._bif_string_or_null_arg._ptr)
#define bif_string_or_uname_arg (_gate._bif_string_or_uname_arg._ptr)
#define bif_string_or_uname_or_iri_id_arg (_gate._bif_string_or_uname_or_iri_id_arg._ptr)
#define bif_string_or_uname_or_wide_or_null_arg (_gate._bif_string_or_uname_or_wide_or_null_arg._ptr)
#define bif_string_or_wide_or_null_arg (_gate._bif_string_or_wide_or_null_arg._ptr)
#define bif_string_or_wide_or_null_or_strses_arg (_gate._bif_string_or_wide_or_null_or_strses_arg._ptr)
#define bif_string_or_wide_or_uname_arg (_gate._bif_string_or_wide_or_uname_arg._ptr)
#define bif_strses_arg (_gate._bif_strses_arg._ptr)
#define bif_strses_or_http_ses_arg (_gate._bif_strses_or_http_ses_arg._ptr)
#define bif_tree_ent_arg (_gate._bif_tree_ent_arg._ptr)
#define bif_uses_index (_gate._bif_uses_index._ptr)
#define bif_varchar_or_bin_arg (_gate._bif_varchar_or_bin_arg._ptr)
#define box_cast (_gate._box_cast._ptr)
#define box_copy (_gate._box_copy._ptr)
#define box_copy_tree (_gate._box_copy_tree._ptr)
#define box_double (_gate._box_double._ptr)
#define box_dv_short_concat (_gate._box_dv_short_concat._ptr)
#define box_dv_short_nchars (_gate._box_dv_short_nchars._ptr)
#define box_dv_short_nchars_reuse (_gate._box_dv_short_nchars_reuse._ptr)
#define box_dv_short_strconcat (_gate._box_dv_short_strconcat._ptr)
#define box_dv_short_string (_gate._box_dv_short_string._ptr)
#define box_dv_short_substr (_gate._box_dv_short_substr._ptr)
#define box_dv_ubuf (_gate._box_dv_ubuf._ptr)
#define box_dv_uname_from_ubuf (_gate._box_dv_uname_from_ubuf._ptr)
#define box_dv_uname_nchars (_gate._box_dv_uname_nchars._ptr)
#define box_dv_uname_string (_gate._box_dv_uname_string._ptr)
#define box_dv_uname_substr (_gate._box_dv_uname_substr._ptr)
#define box_equal (_gate._box_equal._ptr)
#define box_find_mt_unsafe_subtree (_gate._box_find_mt_unsafe_subtree._ptr)
#define box_float (_gate._box_float._ptr)
#define box_make_tree_mt_safe (_gate._box_make_tree_mt_safe._ptr)
#define box_num (_gate._box_num._ptr)
#define box_num_nonull (_gate._box_num_nonull._ptr)
#define box_sprintf (_gate._box_sprintf._ptr)
#define box_string (_gate._box_string._ptr)
#define box_vsprintf (_gate._box_vsprintf._ptr)
#define copy_list_to_array (_gate._copy_list_to_array._ptr)
#define dbg_calloc (_gate._dbg_calloc._ptr)
#define dbg_free (_gate._dbg_free._ptr)
#define dbg_malloc (_gate._dbg_malloc._ptr)
#define dbg_malloc_enable (_gate._dbg_malloc_enable._ptr)
#define dbg_realloc (_gate._dbg_realloc._ptr)
#define dbg_strdup (_gate._dbg_strdup._ptr)
#define dk_alloc (_gate._dk_alloc._ptr)
#define dk_alloc_box (_gate._dk_alloc_box._ptr)
#define dk_alloc_box_long (_gate._dk_alloc_box_long._ptr)
#define dk_alloc_box_zero (_gate._dk_alloc_box_zero._ptr)
#define dk_free (_gate._dk_free._ptr)
#define dk_free_box (_gate._dk_free_box._ptr)
#define dk_free_box_and_int_boxes (_gate._dk_free_box_and_int_boxes._ptr)
#define dk_free_box_and_numbers (_gate._dk_free_box_and_numbers._ptr)
#define dk_free_tree (_gate._dk_free_tree._ptr)
#define dk_session_allocate (_gate._dk_session_allocate._ptr)
#define dk_set_delete (_gate._dk_set_delete._ptr)
#define dk_set_delete_nth (_gate._dk_set_delete_nth._ptr)
#define dk_set_push (_gate._dk_set_push._ptr)
#define dk_try_alloc (_gate._dk_try_alloc._ptr)
#define dk_try_alloc_box (_gate._dk_try_alloc_box._ptr)
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
#define id_hash_add_new (_gate._id_hash_add_new._ptr)
#define id_hash_allocate (_gate._id_hash_allocate._ptr)
#define id_hash_get (_gate._id_hash_get._ptr)
#define id_hash_get_with_ctx (_gate._id_hash_get_with_ctx._ptr)
#define id_hash_get_with_hash_number (_gate._id_hash_get_with_hash_number._ptr)
#define id_hash_set (_gate._id_hash_set._ptr)
#define id_hash_set_with_hash_number (_gate._id_hash_set_with_hash_number._ptr)
#define lh_get_handler (_gate._lh_get_handler._ptr)
#define lh_load_handler (_gate._lh_load_handler._ptr)
#define list_to_array (_gate._list_to_array._ptr)
#define lt_start (_gate._lt_start._ptr)
#define md5 (_gate._md5._ptr)
#define mq_add_message (_gate._mq_add_message._ptr)
#define mq_create_message (_gate._mq_create_message._ptr)
#define mutex_allocate (_gate._mutex_allocate._ptr)
#define mutex_enter (_gate._mutex_enter._ptr)
#define mutex_free (_gate._mutex_free._ptr)
#define mutex_leave (_gate._mutex_leave._ptr)
#define registry_get (_gate._registry_get._ptr)
#define registry_get_all (_gate._registry_get_all._ptr)
#define revlist_to_array (_gate._revlist_to_array._ptr)
#define sec_check_dba (_gate._sec_check_dba._ptr)
#define semaphore_allocate (_gate._semaphore_allocate._ptr)
#define server_logmsg_ap (_gate._server_logmsg_ap._ptr)
#define service_read (_gate._service_read._ptr)
#define service_write (_gate._service_write._ptr)
#define session_accept (_gate._session_accept._ptr)
#define session_buffered_read (_gate._session_buffered_read._ptr)
#define session_buffered_read_char (_gate._session_buffered_read_char._ptr)
#define session_buffered_write (_gate._session_buffered_write._ptr)
#define session_buffered_write_char (_gate._session_buffered_write_char._ptr)
#define session_connect (_gate._session_connect._ptr)
#define session_disconnect (_gate._session_disconnect._ptr)
#define session_flush (_gate._session_flush._ptr)
#define session_flush_1 (_gate._session_flush_1._ptr)
#define session_listen (_gate._session_listen._ptr)
#define session_read (_gate._session_read._ptr)
#define session_select (_gate._session_select._ptr)
#define session_set_address (_gate._session_set_address._ptr)
#define session_set_control (_gate._session_set_control._ptr)
#define session_write (_gate._session_write._ptr)
#define sprintf_inverse (_gate._sprintf_inverse._ptr)
#define sprintf_inverse_ex (_gate._sprintf_inverse_ex._ptr)
#define sqlr_error (_gate._sqlr_error._ptr)
#define sqlr_new_error (_gate._sqlr_new_error._ptr)
#define sqlr_resignal (_gate._sqlr_resignal._ptr)
#define srv_make_new_error (_gate._srv_make_new_error._ptr)
#define strhash (_gate._strhash._ptr)
#define strhashcmp (_gate._strhashcmp._ptr)
#define strses_allocate (_gate._strses_allocate._ptr)
#define strses_flush (_gate._strses_flush._ptr)
#define strses_free (_gate._strses_free._ptr)
#define strses_length (_gate._strses_length._ptr)
#define strses_string (_gate._strses_string._ptr)
#define strses_write_out (_gate._strses_write_out._ptr)
#define tcpses_get_fd (_gate._tcpses_get_fd._ptr)
#define tcpses_get_last_r_errno (_gate._tcpses_get_last_r_errno._ptr)
#define tcpses_get_last_w_errno (_gate._tcpses_get_last_w_errno._ptr)
#define tcpses_set_fd (_gate._tcpses_set_fd._ptr)
#define thr_get_error_code (_gate._thr_get_error_code._ptr)
#define thr_set_error_code (_gate._thr_set_error_code._ptr)
#define thread_current (_gate._thread_current._ptr)
#define thread_getattr (_gate._thread_getattr._ptr)
#define thread_setattr (_gate._thread_setattr._ptr)
#define tp_get_main_queue (_gate._tp_get_main_queue._ptr)
#define tp_retire (_gate._tp_retire._ptr)
#define twopc_log (_gate._twopc_log._ptr)
#define unbox (_gate._unbox._ptr)
#define unbox_int64 (_gate._unbox_int64._ptr)
#define unbox_ptrlong (_gate._unbox_ptrlong._ptr)
#define unichar_getlcase (_gate._unichar_getlcase._ptr)
#define unichar_getprops (_gate._unichar_getprops._ptr)
#define unichar_getucase (_gate._unichar_getucase._ptr)
#define uudecode_base64 (_gate._uudecode_base64._ptr)
#define wi_instance_get (_gate._wi_instance_get._ptr)

#endif