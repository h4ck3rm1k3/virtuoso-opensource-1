/*
 *  $Id: sparql.h,v 1.58.2.27 2011/06/11 16:41:46 source Exp $
 *
 *  This file is part of the OpenLink Software Virtuoso Open-Source (VOS)
 *  project.
 *
 *  Copyright (C) 1998-2006 OpenLink Software
 *
 *  This project is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; only version 2 of the License, dated June 1991.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#ifndef __SPARQL_H
#define __SPARQL_H

#include "libutil.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "langfunc.h"
#ifdef __cplusplus
}
#endif
#include "shuric.h"

#include "rdf_mapping_jso.h"

#ifdef DEBUG
#define SPARYYDEBUG
#endif

#ifdef SPARQL_DEBUG
#define spar_dbg_printf(x) printf x
#else
#define spar_dbg_printf(x)
#endif

/*! Number of NULLs should match number of fields in rdf_val_range_t */
#define SPART_RVR_LIST_OF_NULLS NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL

#define SPAR_ALIAS		(ptrlong)1001
#define SPAR_BLANK_NODE_LABEL	(ptrlong)1002
#define SPAR_BUILT_IN_CALL	(ptrlong)1003
#define SPAR_CONV		(ptrlong)1004	/*!< Tree type for temporary use in SQL printer (conversion from one format to other) */
#define SPAR_FUNCALL		(ptrlong)1005
#define SPAR_GP			(ptrlong)1006
#define SPAR_REQ_TOP		(ptrlong)1007
#define SPAR_RETVAL		(ptrlong)1008	/*!< Tree type for temporary use in SQL printer; this is similar to variable but does not search for field via equiv */
#define SPAR_LIT		(ptrlong)1009
#define SPAR_QNAME		(ptrlong)1011
#define SPAR_SQLCOL		(ptrlong)1012
#define SPAR_VARIABLE		(ptrlong)1013
#define SPAR_TRIPLE		(ptrlong)1014
#define SPAR_QM_SQL_FUNCALL	(ptrlong)1015
#define SPAR_CODEGEN		(ptrlong)1016
#define SPAR_LIST		(ptrlong)1017
#define SPAR_GRAPH		(ptrlong)1018
#define SPAR_WHERE_MODIFS	(ptrlong)1019
#define SPAR_SERVICE_INV	(ptrlong)1020	/*!< Tree type for details of invocation of an external service endpoint */
#define SPAR_BINDINGS_INV	(ptrlong)1021	/*!< Tree type for details of bindings associated with gp */
/* Don't forget to update spart_count_specific_elems_by_type(), sparp_tree_full_clone_int(), sparp_tree_full_copy(), spart_dump() and comments inside typedef struct spar_tree_s */

#define SPARP_MAX_LEXDEPTH 50
#define SPARP_MAX_SYNTDEPTH SPARP_MAX_LEXDEPTH+10

#define SPARP_MAXLIMIT 0x7Fffffff /* Default value for LIMIT clause of SELECT */

struct spar_sqlgen_s;
struct spar_tree_s;

typedef struct spar_tree_s SPART;

typedef struct spar_lexem_s {
  ptrlong sparl_lex_value;
  caddr_t sparl_sem_value;
  ptrlong sparl_lineno;
  ptrlong sparl_depth;
  caddr_t sparl_raw_text;
#ifdef SPARQL_DEBUG
  ptrlong sparl_state;
#endif
} spar_lexem_t;

typedef struct spar_lexbmk_s {
  s_node_t*	sparlb_lexem_bufs_tail;
  ptrlong	sparlb_offset;
} spar_lexbmk_t;


#if 0
typedef struct spar_query_s
  {
    shuric_t *		sparqr_shuric;
    int			sparqr_owned_by_shuric;
    struct spar_tree_s * sparqr_tree;
    caddr_t		sparqr_key;
    dk_set_t		sparqr_imports;
  } spar_query_t;
#endif

/*! WHERE condition template and aliases it refers to */
typedef struct sparp_qm_table_condition_s {
  caddr_t	sparqtc_tmpl;		/*!< The original template text of the condition */
  caddr_t *	sparqtc_aliases;	/*!< Vector of all distinct aliases used in the template */
} sparp_qm_table_condition_t;

/*! Free-text column description */
typedef struct spar_qm_ft_s {
  caddr_t	sparqft_type;		/*!< NULL for plain free-text index, something else for text xml index */
  SPART *	sparqft_ft_sqlcol;	/*!< Free-text indexed column */
  SPART **	sparqft_qmv_sqlcols;	/*!< Columns that are used in quad map value */
  SPART **      sparqft_options;	/*!< Options as declared in 'OPTION (...)' list of 'TEXT LITERAL ...' clause */
  int		sparqft_use_ctr;	/*!< Use counter. It is an error if a 'TEXT LITERAL ...' clause is not used in the QM statement */
} spar_qm_ft_t;

/*! Propvariable, i.e. variable created by ?var*>pred or ?var+>pred expression */
typedef struct spar_propvariable_s {
  SPART *	sparpv_subj_var;	/*!< Left-hand variable operand */
  int		sparpv_op;		/*!< _PLUS_GT or _STAR_GT */
  SPART *	sparpv_verb_qname;	/*!< Right-hand IRIref operand */
  int		sparpv_verb_lexem_type;	/*!< QNAME, QNAME_NS or Q_IRI_REF */
  caddr_t	sparpv_verb_lexem_text;	/*!< original text of right-hand operand */
  caddr_t	sparpv_key;		/*!< Key that is used to find \c this structure */
  caddr_t	sparpv_obj_var_name;	/*!< The name of implicitly create variable for the value of the expression */
  int		sparpv_obj_altered; /*!< The name of variable is abbreviated (0x1) and/or altered (0x2) so it can't be used in result-set as column name */
} spar_propvariable_t;

/*! Configuration of RDF grabber, A.K.A. 'IRI resolver'. */
typedef struct rdf_grab_config_s {
    int		rgc_pview_mode;		/*!< The query is executed using procedure view that will form a result-set by calling more than one statement via exec() */
    int		rgc_all;		/*!< Automatically add all IRI constants/vars (except P) to spare_grab_consts */
    int		rgc_intermediate;	/*!< Automatically add all IRI constants/vars (except P) to spare_grab_consts */
    dk_set_t	rgc_consts;		/*!< Constants to be used as names of additional graphs */
    dk_set_t	rgc_vars;		/*!< Names of variables whose values should be used as names of additional graphs */
    dk_set_t	rgc_sa_graphs;		/*!< SeeAlso graph names. Every time a value can be downloaded, its seeAlso values can also be downloaded */
    dk_set_t	rgc_sa_preds;		/*!< SeeAlso predicate names. Every time a value can be downloaded, its seeAlso values can also be downloaded */
    dk_set_t	rgc_sa_vars;		/*!< Names of variables whose values should be used as names of subjects (not objects!) for seeAlso predicates */
    caddr_t	rgc_depth;		/*!< Number of iterations that can be made to find additional graphs */
    caddr_t	rgc_limit;		/*!< Limit on number of grabbed remote documents */
    caddr_t	rgc_base;		/*!< Base IRI to use as a first argument to the grab IRI resolver */
    caddr_t	rgc_destination;	/*!< IRI of the graph to be extended */
    caddr_t	rgc_group_destination;	/*!< IRI of the commonly used graph to be extended, in addition to usual flow */
    caddr_t	rgc_resolver_name;	/*!< Name of function of the graph IRI resolver */
    caddr_t	rgc_loader_name;	/*!< Name of function that actually load the resource */
} rdf_grab_config_t;

#define SPARE_GLOBALS_ARE_PLAIN		0	/*!< Global parameters are printed without quotes and a colon, so "?:paramname" in query becomes "paramname" in SQL. This is the default so it's value is zero. */
#define SPARE_GLOBALS_ARE_COLONUMBERED	1	/*!< Global parameters are numbered in output so ?:a ?:b ?:a ?:c becomes :0 :1 :0 :2 */
#define SPARE_GLOBALS_ARE_COLONAMED	2	/*!< Global parameters are named parameters in output so ?:a ?:b ?:a ?:c becomes :a :b :a :c */

/*!< Description of query sources (all input graphs, their status, automatic data loading) */
typedef struct sparp_sources_s
  {
    rdf_grab_config_t	ssrc_grab;			/*!< Grabber configuration */
    dk_set_t		ssrc_common_sponge_options;	/*!< Options that are added to every FROM ... OPTION ( ... ) list */
    dk_set_t		ssrc_default_graphs;		/*!< Default graphs and NOT FROM graphs as set by protocol or FROM graph-uri-precode. All NOT FROM are after all FROM! */
    dk_set_t		ssrc_named_graphs;		/*!< Named graphs and NOT FROM NAMED graphs as set by protocol or clauses. All NOT FROM NAMED are after all FROM NAMED! */
    int			ssrc_default_graphs_listed;	/*!< At least one default graph was set, so the list of default graphs is exhaustive even if empty or consists of solely NOT FROM (NOT FROM may remove all FROM, making the list empty) */
    int			ssrc_named_graphs_listed;	/*!< At least one named graph was set, so the list of named graphs is exhaustive even if empty or consists of solely NOT FROM NAMED */
    int			ssrc_default_graphs_locked;	/*!< Default graphs are set by protocol and can not be overwritten. There's no locking for NOT FROM */
    int			ssrc_named_graphs_locked;	/*!< Named graphs are set by protocol and can not be overwritten. There's no locking for NOT FROM NAMED */
  } sparp_sources_t;

#define spare_grab			spare_src.ssrc_grab
#define spare_common_sponge_options	spare_src.ssrc_common_sponge_options
#define spare_default_graphs		spare_src.ssrc_default_graphs
#define spare_named_graphs		spare_src.ssrc_named_graphs
#define spare_default_graphs_listed	spare_src.ssrc_default_graphs_listed
#define spare_named_graphs_listed	spare_src.ssrc_named_graphs_listed
#define spare_default_graphs_locked	spare_src.ssrc_default_graphs_locked
#define spare_named_graphs_locked	spare_src.ssrc_named_graphs_locked


/* When a new field is added here, please check whether it should be added to sparp_clone_for_variant () */
typedef struct sparp_env_s
  {
    /*spar_query_t *	spare_sparqr;*/
    ptrlong		spare_start_lineno;		/*!< The first line number of the query, may be nonzero if inlined into SQL */
    ptrlong *		spare_param_counter_ptr;	/*!< Pointer to parameter counter used to convert '??' or '$?' to ':nnn' in the query */
    dk_set_t		spare_namespace_prefixes;	/*!< Pairs of ns prefixes and URIs */
    dk_set_t		spare_namespace_prefixes_outer;	/*!< Bookmark in spare_namespace_prefixes that points to the first inherited (not local) namespace */
    caddr_t		spare_base_uri;			/*!< Default base URI for fn:doc and fn:resolve-uri */
    caddr_t		spare_input_param_valmode_name;	/*!< Name of valmode for global variables, including protocol parameters listed in \c spare_protocol_params */
    caddr_t		spare_output_valmode_name;	/*!< Name of valmode for top-level result-set */
    caddr_t		spare_output_format_name;	/*!< Name of format for serialization of top-level result-set */
    caddr_t		spare_output_scalar_format_name;	/*!< Overrides generic \c spare_output_format_name for scalar result sets, like ASK */
    caddr_t		spare_output_dict_format_name;	/*!< Overrides generic \c spare_output_format_name for "dictionary of triples" result sets, like CONSTRUCT and DESCRIBE */
    caddr_t		spare_output_route_name;	/*!< Name of procedure that makes a decision re. method of writing SPARUL results (quad storage / DAV file / something else) */
    caddr_t		spare_output_storage_name;	/*!< Name of quad_storage_t JSO object to control the use of quad mapping at SPARUL output side */
    caddr_t		spare_output_maxrows;		/*!< boxed maximum expected number of rows to return */
    caddr_t		spare_storage_name;		/*!< Name of quad_storage_t JSO object to control the use of quad mapping at input side and maybe at SPARUL output side */
    caddr_t		spare_inference_name;		/*!< Name of inference rule set to control the expansion of types */
    struct rdf_inf_ctx_s *	spare_inference_ctx;		/*!< Pointer to an inference structure, to expand transitive and add unions for inverses */
    caddr_t		spare_use_ifp;			/*!< Non-NULL pointer if the resulting SQL should contain OPTION(IFP) */
    caddr_t		spare_use_same_as;		/*!< Non-NULL pointer if the resulting SQL should contain OPTION(SAME_AS) */
    dk_set_t		spare_protocol_params;		/*!< Names of variables that are used as parameters of SPARQL protocol call */
    struct sparp_env_s *spare_parent_env;		/*!< Pointer to parent env */
#if 0 /* These will be used when libraries of inference rules are introduced. Don't forget to patch sparp_clone_for_variant()! */
    id_hash_t *		spare_fundefs;			/*!< In-scope function definitions */
    id_hash_t *		spare_vars;			/*!< Known variables as keys, equivs as values */
    id_hash_t *		spare_global_bindings;		/*!< Dictionary of global bindings, varnames as keys, default value expns as values. DV_DB_NULL box for no expn! */
#endif
    sparp_sources_t	spare_src;			/*!< Query sources, temporarily reset to all zeroes when entering SERVICE with nonempty set of sources */
    dk_set_t		spare_common_sql_table_options;	/*!< SQL 'TABLE OPTION' strings that are added to every table */
    dk_set_t		spare_groupings;		/*!< Variables that should be placed in GROUP BY list */
    dk_set_t		spare_sql_select_options;	/*!< SQL 'OPTION' strings that are added at the end of query (right after permanent QUIETCAST) */
    caddr_t		spare_describe_mode;		/*!< Version of DESCRIBE SQL 'OPTION' strings that are added at the end of query (right after permanent QUIETCAST) */
    dk_set_t		spare_context_sinvs;		/*!< Stack of not yet closed service invocations */
    dk_set_t		spare_context_qms;		/*!< IRIs of allowed quad maps (IRI if quad map is restricted, DEFAULT_L if default qm only, _STAR if not restricted) */
    dk_set_t		spare_context_graphs;		/*!< Expressions that are default values for graph field */
    dk_set_t		spare_context_subjects;		/*!< Expressions that are default values for subject field */
    dk_set_t		spare_context_predicates;	/*!< Expressions that are default values for predicate field */
    dk_set_t		spare_context_objects;		/*!< Expressions that are default values for objects field */
    dk_set_t		spare_context_gp_subtypes;	/*!< Subtypes of not-yet-completed graph patterns */
    dk_set_t		spare_acc_triples;		/*!< Sets of accumulated triples of GPs */
    dk_set_t		spare_acc_filters;		/*!< Sets of accumulated filters of GPs */
    SPART **		spare_bindings_vars;		/*!< List of variables enumerated in local BINDINGS Var+ list */
    SPART ***		spare_bindings_rowset;		/*!< Array of arrays of values in BINDINGS {...} */
    dk_set_t		spare_good_graph_varnames;	/*!< Varnames found in non-optional triples before or outside, (including non-optional inside previous non-optional siblings), but not after or inside */
    dk_set_t		spare_good_graph_varname_sets;	/*!< Pointers to the spare_known_gspo_varnames stack, to pop */
    dk_set_t		spare_good_graph_bmk;		/*!< Varnames found in non-optional triples before or outside, (including non-optional inside previous non-optional siblings), but not after or inside */
    dk_set_t		spare_selids;			/*!< Select IDs of GPs */
    caddr_t		spare_top_retval_selid;		/*!< Select ID for variables in result set and ORDER BY clauses */
    dk_set_t		spare_global_var_names;		/*!< List of all distinct global names used in the query, to know what should be passed to 'rdf grab' procedure view */
    int			spare_globals_mode;		/*!< Flags if all global parameters are translated into ':N' because they're passed via 'params' argument of exec() inside a procedure view, */
    int			spare_global_num_offset;	/*!< If \c spare_globals_mode is set to \c SPARE_GLOBALS_ARE_COLONUMBERED then numbers of 'app-specific' global parameters starts from spare_global_num_offset up, some number of first params are system-specific. */
    dk_set_t		spare_propvar_sets;		/*!< Stack of sets of propvars that should form triples */
    dk_set_t		spare_acc_qm_sqls;		/*!< Backstack of first-level function calls that change quad maps, items are SPART * with SPAR_QM_SQL_FUNCALL type */
    caddr_t		spare_qm_default_table;		/*!< The name of default table (when a single table name is used without an alias for everything. */
    caddr_t		spare_qm_current_table_alias;	/*!< The last alias definition, used for processing of 'FROM table AS alias TEXT LITERAL ...' */
    dk_set_t		spare_qm_parent_tables_of_aliases;	/*!< get_keyword-style list of aliases of relational tables, aliases are keys, tables are values. */
    dk_set_t		spare_qm_parent_aliases_of_aliases;	/*!< get_keyword-style list of aliases of other aliases, parent aliases are values. */
    dk_set_t		spare_qm_descendants_of_aliases;	/*!< get_keyword-style list of aliases of other aliases, bases are keys, sets of descendants are values. */
    dk_set_t		spare_qm_ft_indexes_of_columns;		/*!< get_keyword-style list of free-text indexes of aliased columns, 'alias.col' are keys, spar_qm_ft_t are values. */
    dk_set_t		spare_qm_where_conditions;	/*!< Set of 'where' conditions for tables represented by sparp_qm_table_condition_t structures. */
    dk_set_t		spare_qm_locals;		/*!< Parameters in not-yet-closed '{...}' blocks. Names (as keyword ids) and values, with NULLs as bookmarks. */
    dk_set_t		spare_qm_affected_jso_iris;	/*!< Backstack of affected JS objects */
    dk_set_t		spare_qm_deleted;		/*!< Backstack of deleted JS objects, class IRI pushed first, instance IRI pushed after so it's above) */
    caddr_t		spare_sparul_log_mode;		/*!< log_mode argument of SPARQL_MODIFY_BY_DICT_CONTENTS() and similar procedures; if set then it's a boxed integer or boxed zero */
    int			spare_signal_void_variables;	/*!< Flag if 'Variable xxx can not be bound...' error (and the like) should be signalled. */
    caddr_t		spare_sql_refresh_free_text;	/*!< Flags if there's any use of bif:contains or the like, so 'sql:refresh-free-text' 'yes' option should be added to any vector of sponge options. This is a _boxed_ integer even if it's zero; that is used to store a reference to a changing integer in a compiled tree. */
    struct sparp_trav_params_s *spare_saved_stp;	/*!< Saved sparp_stp, used when a subquery is entered */
    struct sparp_trav_state_s *spare_saved_stss;	/*!< Saved state of \c sparp_stss, used when a subquery is entered */
    int spare_gp_trav_is_saved;	/*!< Flags whether \c spare_saved_stp and \c spare_saved_stss are in use, i.e. \c sparp_gp_trav_suspend() has been called but sparp_gep_trav_resume() is not */
  } sparp_env_t;

typedef struct sparp_globals_s {
  struct sparp_equiv_s **sg_equivs;	/*!< All variable equivalences made for the tree, in pointer to a growing buffer */
  ptrlong sg_equiv_count;		/*!< A count of used items in the beginning of \c sg_equivs buffer */
  ptrlong sg_cloning_serial;		/*!< The pointer to the serial used for current \c sparp_gp_full_clone() operation */
  struct spar_tree_s **sg_sinvs;	/*!< All descriptions of service invocations, in pointer to a growing buffer */
  ptrlong sg_sinv_count;		/*!< A count of used items in the beginning of \c sg_sinvs buffer */
} sparp_globals_t;

typedef struct sparp_s {
/* Generic environment */
  spar_query_env_t *sparp_sparqre;	/*!< External environment of the query */
  caddr_t sparp_err_hdr;
  SPART * sparp_expr;
  struct sparp_s *sparp_parent_sparp;	/*!< Pointer to the parser state used to keep parent query of the current query. */
  encoding_handler_t *sparp_enc;
  lang_handler_t *sparp_lang;
  int sparp_synthighlight;
  dk_set_t *sparp_checked_functions;
  int sparp_reject_extensions;		/*!< Reject Virtuoso-specific extensions */
  int sparp_save_pragmas;		/*!< This instructs the lexer to preserve pragmas for future use. This is not in use right now but may be used pretty soon */
  int sparp_key_gen;			/*!< 0 = do not fill xqr_key, 1 = save source text only, 2 = save source text and custom namespace decls */
#ifdef XPYYDEBUG
  int sparp_yydebug;
#endif
  caddr_t sparp_text;
  int sparp_permitted_syntax;		/*!< Bitmask of permitted syntax extensions, 0 for default */
  int sparp_unictr;			/*!< Unique counter for objects */
/* Environment of yacc */
  sparp_env_t * sparp_env;
  int sparp_lexem_buf_len;
  int sparp_total_lexems_parsed;
  spar_lexem_t *sparp_curr_lexem;
  spar_lexbmk_t sparp_curr_lexem_bmk;
  int sparp_in_precode_expn;		/*!< If nonzero (usually 1) then the parser reads precode-safe expression so it can not contain non-global variables, if bit 2 is set then even global variables are prohibited (like it is in INSERT DATA statement) */
  int sparp_allow_aggregates_in_expn;	/*!< The parser reads result-set expressions, GROUP BY, ORDER BY, or HAVING. Each bit is responsible for one level of nesting. */
  int sparp_query_uses_aggregates;	/*!< Nonzero if there is at least one aggregate in the whole source query, (not in the current SELECT!). This is solely for bypassing expanding top retvals for "plain SPARQL" queries, not for other logic of the compiler */
  int sparp_query_uses_sinvs;		/*!< Nonzero if there is at least one SERVICE invocation in the whole source query, (not in the current SELECT!). This forces (re) composing of \c sinv.param_varnames and \c sinv.retval_varnames lists */
  int sparp_disable_big_const;		/*!< INSERT DATA requires either an sql_comp_t for ssl or define sql:big-data-const 0. The define sets this value to 1 */
  dk_set_t sparp_created_jsos;		/*!< Get-keyword style list of created JS objects. Object IRIs are keys, types (as free-text const char *) are values. This is solely for early (and incomplete) detection of probable errors. */
/* Environment of lex */
  size_t sparp_text_ofs;
  size_t sparp_text_len;
  int sparp_lexlineno;			/*!< Source line number, starting from 1 */
  int sparp_lexdepth;			/*!< Lexical depth, it's equal to the current position in \c sparp_lexpars and \c sparp_lexstates */
  int sparp_rset_lexdepth_plus_1;	/*!< Lexical depth of current result set, increased by 1 (so when it's zero it means not in rset) */
  int sparp_lexpars[SPARP_MAX_LEXDEPTH+2];	/*!< Stack of not-yet-closed parenthesis */
  int sparp_lexstates[SPARP_MAX_LEXDEPTH+2];	/*!< Stack of lexical states */
  int sparp_string_literal_lexval;	/*!< Lexical value of string literal that is now in process. */
  dk_set_t sparp_output_lexem_bufs;	/*!< Reversed list of lexem buffers that are 100% filled by lexems */
  spar_lexem_t * sparp_curr_lexem_buf;	/*!< Lexem buffer that is filled now */
  spar_lexem_t * sparp_curr_lexem_buf_fill;	/*!< Number of lexems in \c sparp_curr_lexem_buf */
/* Environment of term rewriter of the SPARQL-to-SQL compiler */
  dk_set_t sparp_propvars;		/*!< Set of propvars with distinct \c sparv_key fields that were ever used in the query */
  struct quad_storage_s	*sparp_storage;		/*!< Default storage that handles arbitrary quads of any sort plus maybe SPMJVs and relational mappings made by user, usually rdf_sys_storage */
  struct sparp_trav_params_s *sparp_stp;	/*!< Parameters of traverse (callbacks in use). It is filled in by sparp_gp_grav() only, not by sparp_gp_grav_int() */
  struct sparp_trav_state_s *sparp_stss;	/*!< Stack of traverse states. [0] is fake for parent on 'where', [1] is for 'where' etc. */
  sparp_globals_t *sparp_sg;		/*!< Pointer to data common for all sparp_t-s for whole stack of nested sparp-s */
  int sparp_first_equiv_idx;		/*!< The index of the first equivalence class allocated in this sparp, to avoid integrity checks of incomplete equivs of outer sparps */
  int sparp_rewrite_dirty;		/*!< An integer that is incremented when any optimization subroutine rewrites the tree. */
  int sparp_trav_running;		/*!< Flags that some traverse is in progress, in order to GPF if traverse procedure re-enters */
  ccaddr_t *sparp_sprintff_isect_buf;	/*!< Temporary buffer to calculate intersections of value ranges; solely for sparp_rvr_intersect_sprintffs() */
  caddr_t sparp_boxed_exec_uid;		/*!< Cached value returned by spar_boxed_exec_uid(). Do not use directly, call spar_boxed_exec_uid() instead! */
  caddr_t sparp_immortal_exec_uname;	/*!< Cached value returned by spar_immortal_exec_uname(). Do not use directly, call spar_immortal_exec_uname() instead! */
  caddr_t sparp_gs_app_callback;	/*!< NULL or name of application-specific callback function */
  caddr_t sparp_gs_app_uid;		/*!< NULL or ID (supposedly app user ID) for application-specific callback */
#ifdef DEBUG
  int sparp_internal_error_runs_audit;	/*!< Flags whether the sparp_internal_error has called audit so inner sparp_internal_error should not try to re-run audit or signal but should simply report */
#endif
} sparp_t;


#define sparp_env() sparp_arg->sparp_env

#define YY_DECL int sparyylex (void *yylval, sparp_t *sparp)
extern YY_DECL;

/*extern void sparqr_free (spar_query_t *sparqr);*/

extern void spar_error (sparp_t *sparp, const char *format, ...);
extern void spar_internal_error (sparp_t *sparp, const char *strg);
extern int spar_audit_error (sparp_t *sparp, const char *format, ...); /* returns fake 1 as a value for return */
extern caddr_t spar_source_place (sparp_t *sparp, char *raw_text);
extern caddr_t spar_dbg_string_of_triple_field (sparp_t *sparp, SPART *fld);
extern void sparyyerror_impl (sparp_t *xpp, char *raw_text, const char *strg);
extern void sparyyerror_impl_1 (sparp_t *xpp, char *raw_text, int yystate, short *yyssa, short *yyssp, const char *strg);
extern void spar_error_if_unsupported_syntax_imp (sparp_t *sparp, int feature_in_use, const char *feature_name);
#define SPAR_ERROR_IF_UNSUPPORTED_SYNTAX(feat,name) do { \
  if (!((feat) & sparp_arg->sparp_permitted_syntax)) \
    spar_error_if_unsupported_syntax_imp (sparp_arg, (feat), (name)); \
    } while (0)

#define SPART_HEAD 2 /* number of elements before \c _ union in spar_tree_t */
#define SPART_TYPE(st) ((DV_ARRAY_OF_POINTER == DV_TYPE_OF(st)) ? (st)->type : SPAR_LIT)

#define SPART_TRIPLE_GRAPH_IDX		0
#define SPART_TRIPLE_SUBJECT_IDX	1
#define SPART_TRIPLE_PREDICATE_IDX	2
#define SPART_TRIPLE_OBJECT_IDX		3
#define tr_graph	tr_fields[0]
#define tr_subject	tr_fields[1]
#define tr_predicate	tr_fields[2]
#define tr_object	tr_fields[3]
#define SPART_TRIPLE_FIELDS_COUNT 4

/* These values should be greater than any SQL opcode AND greater than 0x7F to not conflict with codepoints of "syntactically important" chars AND less than 0xFF to not conflict with YACC IDs for keywords. */
#define SPART_GRAPH_FROM		0x100
#define SPART_GRAPH_GROUP_BIT		0x001
#define SPART_GRAPH_GROUP		0x101	/*!< == SPART_GRAPH_FROM | SPART_GRAPH_GROUP_BIT */
#define SPART_GRAPH_NAMED		0x110
#define SPART_GRAPH_MIN_NEGATION	0x17F
#define SPART_GRAPH_NOT_FROM		0x180
#define SPART_GRAPH_NOT_GROUP		0x181	/*!< == SPART_GRAPH_NOT_FROM | SPART_GRAPH_GROUP_BIT */
#define SPART_GRAPH_NOT_NAMED		0x190

#define SPARP_EQUIV(sparp,idx) ((sparp)->sparp_sg->sg_equivs[(idx)])
#define SPARP_SINV(sparp,idx) ((sparp)->sparp_sg->sg_sinvs[(idx)])

#ifdef DEBUG
#define ASSERT_EQUIV_INDEX(f,l,sparp,eq_inx) do { \
  if (eq_inx < 0) \
    spar_internal_error (sparp, t_box_sprintf (100, "%s:%d: negative equiv index", f, l)); \
  if (eq_inx >= sparp->sparp_sg->sg_equiv_count) \
    spar_internal_error (sparp, t_box_sprintf (100, "%s:%d: equiv index is too big", f, l)); \
 } while (0)
#else
#define ASSERT_EQUIV_INDEX(f,l,sparp,eq_inx);
#endif

#define SPARP_FOREACH_GP_EQUIV(sparp,groupp,inx,eq) \
  do { \
    int __max_##inx = groupp->_.gp.equiv_count; \
    for (inx = 0; inx < __max_##inx; inx ++) \
      { \
        sparp_equiv_t *eq; \
        ASSERT_EQUIV_INDEX (__FILE__, __LINE__, sparp, groupp->_.gp.equiv_indexes[inx]); \
        eq = SPARP_EQUIV(sparp, groupp->_.gp.equiv_indexes[inx]);

#define END_SPARP_FOREACH_GP_EQUIV \
	  }} while (0)

#define SPARP_REVFOREACH_GP_EQUIV(sparp,groupp,inx,eq) \
  do { \
    for (inx = groupp->_.gp.equiv_count; inx--;) \
      { \
        sparp_equiv_t *eq; \
        ASSERT_EQUIV_INDEX (__FILE__, __LINE__, sparp, groupp->_.gp.equiv_indexes[inx]); \
        eq = SPARP_EQUIV(sparp, groupp->_.gp.equiv_indexes[inx]);

#define END_SPARP_REVFOREACH_GP_EQUIV \
	  }} while (0)

typedef struct qm_format_s *ssg_valmode_t;

/*! Type of callback that can generate an unusual SQL text from a tree of SPAR_CODEGEN type */
typedef void ssg_codegen_callback_t (struct spar_sqlgen_s *ssg, struct spar_tree_s *spart, ...);
/*! Callback to generate the top of an SPARQL query with 'graph-grab' feature */
void ssg_grabber_codegen (struct spar_sqlgen_s *ssg, struct spar_tree_s *spart, ...);
/*! Callback to generate the query that quickly enumerates all known graphs */
void ssg_select_known_graphs_codegen (struct spar_sqlgen_s *ssg, struct spar_tree_s *spart, ...);

/*! A possible use of quad map as data source for a given triple */
typedef struct qm_atable_use_s
{
  const char *qmatu_alias;
  const char *qmatu_tablename;
  void *qmatu_more;
} qm_atable_use_t;

/*! A possible use of quad map as data source for a given triple */
typedef struct triple_case_s
{
  struct quad_map_s *tc_qm;	/*!< Quad map that can generate data that match the triple */
  ccaddr_t *tc_red_cuts[SPART_TRIPLE_FIELDS_COUNT];	/*!< Red cuts for values bound by the triple when they are generated by \c tc_qm */
} triple_case_t;

/*! A node of tree representation of a SPARQL query. Tree format is common for both syntax parser and optimizer. */
typedef struct spar_tree_s
{
  ptrlong	type;
  caddr_t	srcline;
  union {
    struct {
        /* #define SPAR_ALIAS		(ptrlong)1001 */
        SPART *arg;
        caddr_t aname;
        ssg_valmode_t native;	/*!< temporary use in SQL printer */
      } alias; /*!< only for use in top-level result-set list */
    struct {
        SPART *left;
        SPART *right;
      } bin_exp;
    struct {
        /* #define SPAR_BUILT_IN_CALL	(ptrlong)1003 */
        ptrlong btype;
        SPART **args;
      } builtin;
    struct {
        SPART *arg;
        ssg_valmode_t native;
        ssg_valmode_t needed;
      } conv; /*!< temporary use in SQL printer */
    struct {
        /* #define SPAR_FUNCALL		(ptrlong)1005 */
        caddr_t qname;
        SPART **argtrees;
        ptrlong agg_mode;
      } funcall;
    struct {
        /* #define SPAR_GP			(ptrlong)1006 */
        ptrlong subtype;
        SPART **members;
        SPART **filters;
        SPART *subquery;
        caddr_t selid;
        ptrlong *equiv_indexes;		/*!< Array of indexes of equivs used in triples and filters of this GP, some items at the tail of the array may be spare and temporarily not in use */
        ptrlong equiv_count;		/*!< Number of items in \c equiv_indexes array that contains valid data. */
        ptrlong glued_filters_count;	/*!< Last \c glued_filters_count members of \c filters are expressions for ON statement of LEFT OUTER JOIN. They can not be moved to some other GP because they were moved already and next move will break semantics. */
        SPART **options;
      } gp;
    struct {
	/* #define SPAR_GRAPH		(ptrlong)1018 */
        ptrlong subtype;
        caddr_t iri;
        SPART *expn;
      } graph;
    struct {
        /* #define SPAR_LIT		(ptrlong)1009 */
        caddr_t val;
        caddr_t datatype;
        caddr_t language;
      } lit;
    struct { /* Note that all first members of \c qname case should match to \c lit case */
        /* #define SPAR_QNAME		(ptrlong)1011 */
        caddr_t val;
      } qname;
    struct {
        /* #define SPAR_REQ_TOP		(ptrlong)1007 */
        ptrlong subtype;
        caddr_t retvalmode_name;
        caddr_t formatmode_name;
        caddr_t storage_name;
        SPART **retvals;
        SPART **orig_retvals;		/*!< Retvals as they were after expanding '*' and wrapping in MAX() */
        SPART **expanded_orig_retvals;	/*!< Retvals as they were after expanding '*' and wrapping in MAX() and adding vars to grab */
        caddr_t retselid;
        SPART **sources;
        SPART *pattern;
        SPART **groupings;
        SPART *having;
        SPART **order;
        SPART *limit;
        SPART *offset;
        sparp_env_t *shared_spare;	/*!< An environment that is shared among all clones of the tree */
      } req_top;
    struct {
        /* #define SPAR_TRIPLE		(ptrlong)1014 */
        ptrlong subtype;
        SPART *tr_fields[SPART_TRIPLE_FIELDS_COUNT];
        caddr_t qm_iri_or_pair;	/* !< This is one of the following: DEFAULT_L for built-in mapping or _STAR for no restriction or an UNAME of top quad map or a pair of one listed before and a serial number of a sinv */
        caddr_t selid;
        caddr_t tabid;
        triple_case_t **tc_list;
        struct qm_format_s *native_formats[SPART_TRIPLE_FIELDS_COUNT];
        SPART **options;
        ptrlong ft_type;
        ptrlong src_serial;	/*!< Assigned once at parser and preserved in all clone operations */
      } triple;
    struct { /* Note that all first members of \c retval and bnode cases should match to \c var case */
        /* #define SPAR_BLANK_NODE_LABEL	(ptrlong)1002 */
        /* #define SPAR_VARIABLE		(ptrlong)1013 */
        caddr_t vname;
        caddr_t selid;
        caddr_t tabid;
        ptrlong tr_idx;		/*!< Index in quad (0 = graph ... 3 = obj) */
        ptrlong equiv_idx;
        rdf_val_range_t rvr;
      } var;
    struct { /* Note that all first members of \c retval and bnode cases should match to \c var case */
        /* #define SPAR_BLANK_NODE_LABEL	(ptrlong)1002 */
        /* #define SPAR_VARIABLE		(ptrlong)1013 */
        caddr_t vname;
        caddr_t selid;
        caddr_t tabid;
        ptrlong tr_idx;		/*!< Index in quad (0 = graph ... 3 = obj) */
        ptrlong equiv_idx;
        rdf_val_range_t rvr;
        ptrlong bracketed;  /*!< 0 for plain, 1 for [...], 2 for fake and bnodes made for default graphs */
      } bnode;
    struct { /* Note that all first members of \c retval and bnode cases should match to \c var case */
        /* #define SPAR_RETVAL		(ptrlong)1008 */
        caddr_t vname;
        caddr_t selid;
        caddr_t tabid;
        ptrlong tr_idx;		/*!< Index in quad (0 = graph ... 3 = obj) */
        ptrlong equiv_idx;
        rdf_val_range_t rvr;
        SPART *gp;
        SPART *triple;
        ptrlong optional_makes_nullable;
      } retval;
    struct {
        ptrlong direction;
        SPART *expn;
      } oby;
    struct {
        /* #define SPAR_QM_SQL_FUNCALL	(ptrlong)1015 */
        caddr_t fname;	/*!< Function to call (bif or Virtuoso/PL) */
        SPART **fixed;	/*!< Array of 'positional' arguments */
	SPART **named;	/*!< Array of 'named' arguments that are passed as get-keyword style vector as a last arg */
      } qm_sql_funcall;
    struct {
        /* #define SPAR_SQLCOL		(ptrlong)1012 */
        caddr_t qtable;	/*!< Qualified table name */
        caddr_t alias;  /*!< Table alias */
        caddr_t col;	/*!< Column name */
      } qm_sqlcol;
    struct {
        /* #define SPAR_CODEGEN		(ptrlong)1016 */
        ssg_codegen_callback_t **cgen_cbk;	/*!< Pointer to the code generation function as a boxed number */
        SPART *args[1];				/*!< Data for the callback, maybe more then one SPART *, depending on structure size */
      } codegen;
    struct {
        /* #define SPAR_LIST		(ptrlong)1017 */
        SPART **items;	/*!< Some trees, say, items of T_IN_L list of variables */
      } list;
    struct {
        /* #define SPAR_WHERE_MODIFS	(ptrlong)1019 */
        SPART *where_gp;	/*!< Group pattern of WHERE clause, or NULL */
        SPART **groupings;	/*!< Array of groupings */
        SPART *having;		/*!< Expression of HAVING clause, or NULL */
        SPART **obys;		/*!< Array of ORDER BY criteria */
        SPART *lim;		/*!< Boxed LIMIT value or an expression tree */
        SPART *ofs;		/*!< Boxed OFFSET value or an expression tree */
      } wm;
    struct {
        /* define SPAR_SERVICE_INV	(ptrlong)1020 */
        ptrlong own_idx;	/*!< Boxed serial of the sinv in the parser */
        caddr_t endpoint;	/*!< An IRI of web service endpoint without static parameters */
        SPART **iri_params;	/*!< A get_keyword style array of parameters to pass in the IRI, like maxrows */
        caddr_t syntax;		/*!< Boxed bitmask of SSG_SD_xxx flags of allowed query serialization features */
        caddr_t *param_varnames;	/*!< Names of variables that are passed as parameters */
        ptrlong in_list_implicit;	/*!< Flags if IN variables were specified using '*' or not specified at all */
        caddr_t *rset_varnames;	/*!< Names of variables that are returned in the result set from the endpoint, in the order in the rset */
        SPART **defines;	/*!< List of defines to pass, as a get_keyword style list of qnames and values or arrays of values */
        SPART **sources;	/*!< List of sources, similar to one in req_top. If NULL then sources of parent req_top are used */
        caddr_t storage_uri;	/*!< Storage to use: JSO UNAME if specified explicitly for a service IRI, uname_virtrdf_ns_uri_DefaultServiceStorage if unknown service */
      } sinv;
    struct {
        /* define SPAR_BINDINGS_INV		(ptrlong)1021 */
        ptrlong own_idx;	/*!< Boxed serial of the bindings invocation in the parser */
        SPART *vars;		/*!< Names of variables that are passed as parameters */
	SPART ***data_rows;	/*!< Rows of data. Note that they're not copied from spare_bindings_rowset and not duplicated if enclosing GP is duplicated. */
      } binv;
  } _;
} sparp_tree_t;

typedef unsigned char SPART_buf[sizeof (sparp_tree_t) + BOX_AUTO_OVERHEAD];
#define SPART_AUTO(ptr,buf,t) \
  do { \
    BOX_AUTO_TYPED(SPART *,ptr,buf,sizeof(SPART),DV_ARRAY_OF_POINTER); \
    memset ((ptr), 0, sizeof (SPART)); \
    (ptr)->type = t; \
    } while (0)

extern sparp_t * sparp_query_parse (char * str, spar_query_env_t *sparqre, int rewrite_all);
extern int sparyyparse (void *sparp);

extern const char *spart_dump_opname (ptrlong opname, int is_op);
extern void spart_dump (void *tree_arg, dk_session_t *ses, int indent, const char *title, int hint);

#define SPAR_IS_BLANK_OR_VAR(tree) \
  ((DV_ARRAY_OF_POINTER == DV_TYPE_OF (tree)) && \
   ((SPAR_VARIABLE == (tree)->type) || \
    (SPAR_BLANK_NODE_LABEL == (tree)->type) ) )

#define SPAR_IS_LIT(tree) \
  ((DV_ARRAY_OF_POINTER != DV_TYPE_OF (tree)) || \
   (SPAR_LIT == (tree)->type) )

#define SPAR_IS_LIT_OR_QNAME(tree) \
  ((DV_ARRAY_OF_POINTER != DV_TYPE_OF (tree)) || \
   (SPAR_LIT == (tree)->type) || (SPAR_QNAME == (tree)->type)/* || (SPAR_QNAME_NS == (tree)->type)*/ )

#define SPAR_LIT_VAL(tree) \
  ((DV_ARRAY_OF_POINTER != DV_TYPE_OF (tree)) ? ((caddr_t)(tree)) : \
   (SPAR_LIT == (tree)->type) ? (tree)->_.lit.val : NULL )

#define SPAR_LIT_OR_QNAME_VAL(tree) \
  ((DV_ARRAY_OF_POINTER != DV_TYPE_OF (tree)) ? ((caddr_t)(tree)) : \
   ((SPAR_LIT == (tree)->type) || (SPAR_QNAME == (tree)->type)/* || (SPAR_QNAME_NS == tree->type)*/) ? (tree)->_.lit.val : NULL )

#define SPART_VARNAME_IS_GLOB(varname) (':' == (varname)[0])
#define SPART_VARNAME_IS_SPECIAL(varname) ('@' == (varname)[0])
#define SPART_IRI_IS_NAMED_BNODE(iri) (('_' == (iri)[0]) && (':' == (iri)[1]))

#define SPART_IS_DEFAULT_GRAPH_BLANK(g) ( \
  (SPAR_BLANK_NODE_LABEL == SPART_TYPE (g)) && \
  !strncmp (g->_.var.vname, "_::default", 10) )

#define SPART_BAD_EQUIV_IDX (ptrlong)(SMALLEST_POSSIBLE_POINTER-1)
#define SPART_BAD_GP_SUBTYPE (ptrlong)(SMALLEST_POSSIBLE_POINTER-2)

#define SPAR_FT_CONTAINS	11
#define SPAR_FT_XCONTAINS	12
#define SPAR_FT_XPATH_CONTAINS	13
#define SPAR_FT_XQUERY_CONTAINS	14
#define SPAR_GEO_CONTAINS	21

extern caddr_t spar_var_name_of_ret_column (SPART *tree);
extern caddr_t spar_alias_name_of_ret_column (SPART *tree);
/*! If the tree has a fixed value that is either plain SQL value or a QName (but not a typed literal or a literal with language)
then the functions returns SPAR_LIT or SPAR_QNAME and sets \c cval_ret[0] to that value. */
extern int spar_plain_const_value_of_tree (SPART *tree, ccaddr_t *cval_ret);
extern caddr_t spar_boxed_exec_uid (sparp_t *sparp);
extern caddr_t spar_immortal_exec_uname (sparp_t *sparp);
extern SPART *spar_exec_uid_and_gs_cbk (sparp_t *sparp);

/*!< Returns statically known permissions on \c graph_iri.
We assume that if permissions on the graph are "interesting" for some reason then the change in these permission may require query re-compilation.
So if some factor may change some bits set in \c req_perms bitmask then a dependency from the factor is established for
sparp->sparp_sparqre->sparqre_super_sc->sc_cc->cc_super_cc->cc_query
If sparp->sparp_gs_app_callback is set then the "nobody" user is used, because the callback may cut permissions down to that level but we don't know that statically */
extern int spar_graph_static_perms (sparp_t *sparp, caddr_t graph_iri, int req_perms);
/*!< Returns if security testing is needed */
extern int spar_graph_needs_security_testing (sparp_t *sparp, SPART *g_expn, int req_perms);


#ifdef MALLOC_DEBUG
typedef SPART* spartlist_impl_t (sparp_t *sparp, ptrlong length, ptrlong type, ...);
typedef SPART* spartlist_with_tail_impl_t (sparp_t *sparp, ptrlong length, caddr_t tail, ptrlong type, ...);
typedef struct spartlist_track_s
  {
    spartlist_impl_t *spartlist_ptr;
    spartlist_with_tail_impl_t *spartlist_with_tail_ptr;
  } spartlist_track_t;

spartlist_track_t *spartlist_track (const char *file, int line);
#define spartlist spartlist_track (__FILE__, __LINE__)->spartlist_ptr
#define spartlist_with_tail spartlist_track (__FILE__, __LINE__)->spartlist_with_tail_ptr
#else
extern SPART* spartlist (sparp_t *sparp, ptrlong length, ptrlong type, ...);
extern SPART* spartlist_with_tail (sparp_t *sparp, ptrlong length, caddr_t tail, ptrlong type, ...);
#define spartlist_impl spartlist
#define spartlist_with_tail_impl spartlist_with_tail
#endif

extern caddr_t sparp_expand_qname_prefix (sparp_t *sparp, caddr_t qname);
extern caddr_t sparp_expand_q_iri_ref (sparp_t *sparp, caddr_t ref);

extern caddr_t sparp_graph_sec_iri_to_id_nosignal (sparp_t *sparp, ccaddr_t qname);
extern caddr_t sparp_graph_sec_id_to_iri_nosignal (sparp_t *sparp, iri_id_t iid);
extern caddr_t sparp_iri_to_id_nosignal (sparp_t *sparp, ccaddr_t qname); /*!< returns t_boxed IRI_ID or plain NULL pointer */
extern ccaddr_t sparp_id_to_iri (sparp_t *sparp, iri_id_t iid);	/*!< returns t_boxed string or plain NULL pointer */

extern caddr_t spar_strliteral (sparp_t *sparp, const char *sparyytext, int strg_is_long, int is_json);
extern caddr_t spar_mkid (sparp_t * sparp, const char *prefix);
extern void spar_change_sign (caddr_t *lit_ptr);

extern void sparp_define (sparp_t *sparp, caddr_t param, ptrlong value_lexem_type, caddr_t value);
extern caddr_t spar_selid_push (sparp_t *sparp);
extern caddr_t spar_selid_push_reused (sparp_t *sparp, caddr_t selid);
extern caddr_t spar_selid_pop (sparp_t *sparp);
extern void spar_gp_init (sparp_t *sparp, ptrlong subtype);
#define SPARP_ENV_CONTEXT_GP_SUBTYPE(sparp) ((ptrlong)((sparp)->sparp_env->spare_context_gp_subtypes->data))
extern SPART *spar_gp_finalize (sparp_t *sparp, SPART **options);
extern SPART *spar_gp_finalize_with_subquery (sparp_t *sparp, SPART **options, SPART *subquery);
extern void spar_gp_add_member (sparp_t *sparp, SPART *memb);
/*! Makes and adds a triple or a filter like CONTAINS or a SELECT group for transitive prop or a UNION prop with inverse props or combination of few, with optional filter on graph.
\c banned tricks is a bitmask that is 0 by default, 0x1 to ignore transitivity in inf rules or options, 0x2 to ignore inverse props */
extern SPART *spar_gp_add_triple_or_special_filter (sparp_t *sparp, SPART *graph, SPART *subject, SPART *predicate, SPART *object, caddr_t qm_iri, SPART **options, int banned_tricks);
/*! Checks if the given \c filt is a freetext filter. If it is so and \c base_triple is not NULL then it additionally checks if var name matches */
extern int spar_filter_is_freetext (sparp_t *sparp, SPART *filt, SPART *base_triple);
extern void spar_gp_add_filter (sparp_t *sparp, SPART *filt);
extern void spar_gp_add_filters_for_graph (sparp_t *sparp, SPART *graph_expn, int graph_is_named, int suppress_filters_for_good_names);
extern void spar_gp_add_filters_for_named_graph (sparp_t *sparp);
extern SPART *spar_make_list_of_sources_expn (sparp_t *sparp, ptrlong from_subtype, ptrlong from_group_subtype, ptrlong from2_subtype, ptrlong req_perms, SPART *needle_in);
extern SPART *spar_add_propvariable (sparp_t *sparp, SPART *lvar, int opcode, SPART *verb_qname, int verb_lexem_type, caddr_t verb_lexem_text);
extern SPART *spar_make_service_inv (sparp_t *sparp, caddr_t endpoint, dk_set_t all_options, ptrlong permitted_syntax, SPART **sources, caddr_t sinv_storage_uri);
extern caddr_t spar_compose_report_flag (sparp_t *sparp);
extern void spar_compose_retvals_of_construct (sparp_t *sparp, SPART *top, SPART *ctor_gp, const char *formatter, const char *agg_formatter, const char *agg_mdata);
extern void spar_compose_retvals_of_insert_or_delete (sparp_t *sparp, SPART *top, SPART *graph_to_patch, SPART *ctor_gp);
extern void spar_compose_retvals_of_modify (sparp_t *sparp, SPART *top, SPART *graph_to_patch, SPART *del_ctor_gp, SPART *ins_ctor_gp);
extern int spar_optimize_delete_of_single_triple_pattern (sparp_t *sparp, SPART *top);
extern void spar_optimize_retvals_of_insert_or_delete (sparp_t *sparp, SPART *top);
extern void spar_optimize_retvals_of_modify (sparp_t *sparp, SPART *top);
extern SPART **spar_retvals_of_describe (sparp_t *sparp, SPART **retvals, SPART *limit, SPART *offset);
extern void spar_add_rgc_vars_and_consts_from_retvals (sparp_t *sparp, SPART **retvals);
extern SPART *spar_make_wm (sparp_t *sparp, SPART *pattern, SPART **groupings, SPART *having, SPART **order, SPART *limit, SPART *offset);
extern SPART *spar_make_top_or_special_case_from_wm (sparp_t *sparp, ptrlong subtype, SPART **retvals,
  caddr_t retselid, SPART *wm );
extern void spar_alloc_fake_equivs_for_bindings_inv (sparp_t *sparp, SPART *binv);
extern SPART **spar_make_sources_like_top (sparp_t *sparp);
extern SPART *spar_make_top (sparp_t *sparp, ptrlong subtype, SPART **retvals,
  caddr_t retselid, SPART *pattern, SPART **groupings, SPART *having, SPART **order, SPART *limit, SPART *offset);
extern SPART *spar_make_plain_triple (sparp_t *sparp, SPART *graph, SPART *subject, SPART *predicate, SPART *object, caddr_t qm_iri_or_pair, SPART **options);
extern SPART *spar_make_param_or_variable (sparp_t *sparp, caddr_t name);
extern SPART *spar_make_variable (sparp_t *sparp, caddr_t name);
extern SPART *spar_make_blank_node (sparp_t *sparp, caddr_t name, int bracketed);
extern SPART *spar_make_fake_blank_node (sparp_t *sparp); /*!< Not for use in real parse trees! */
extern SPART *spar_make_typed_literal (sparp_t *sparp, caddr_t strg, caddr_t type, caddr_t lang);
extern void sparp_make_and_push_new_graph_source (sparp_t *sparp, ptrlong subtype, SPART *iri_expn, SPART **options);
extern SPART *sparp_make_graph_precode (sparp_t *sparp, ptrlong subtype, SPART *iriref, SPART **options);
extern SPART *spar_default_sparul_target (sparp_t *sparp, const char *clause_type);
extern SPART *spar_make_regex_or_like_or_eq (sparp_t *sparp, SPART *strg, SPART *regexpn);
extern void spar_verify_funcall_security (sparp_t *sparp, ccaddr_t fname, SPART **args);
extern SPART *spar_make_funcall (sparp_t *sparp, int aggregate_mode, const char *funname, SPART **arguments);
extern SPART *spar_make_sparul_clear (sparp_t *sparp, SPART *graph_precode);
extern SPART *spar_make_sparul_load (sparp_t *sparp, SPART *graph_precode, SPART *src_precode);
extern SPART *spar_make_sparul_create (sparp_t *sparp, SPART *graph_precode, int silent);
extern SPART *spar_make_sparul_drop (sparp_t *sparp, SPART *graph_precode, int silent);
extern SPART *spar_make_topmost_sparul_sql (sparp_t *sparp, SPART **actions);
extern SPART *spar_make_fake_action_solution (sparp_t *sparp);

extern void spar_fill_lexem_bufs (sparp_t *sparp);
extern void spar_copy_lexem_bufs (sparp_t *tgt_sparp, spar_lexbmk_t *begin, spar_lexbmk_t *end, int skip_last_n);

extern id_hashed_key_t spar_var_hash (caddr_t p_data);
extern int spar_var_cmp (caddr_t p_data1, caddr_t p_data2);

extern sparp_t *sparp_clone_for_variant (sparp_t *sparp, int allow_output_formatting);
extern void spar_env_push (sparp_t *sparp);
extern void spar_env_pop (sparp_t *sparp);

/*extern shuric_vtable_t shuric_vtable__sparqr;*/

extern void sparp_jso_push_affected (sparp_t *sparp, ccaddr_t inst_iri);
extern void sparp_jso_push_deleted (sparp_t *sparp, ccaddr_t class_iri, ccaddr_t inst_iri);

/* Functions for Quad Map definition statements */
extern void spar_qm_clean_locals (sparp_t *sparp);
extern void spar_qm_push_bookmark (sparp_t *sparp);
extern void spar_qm_pop_bookmark (sparp_t *sparp);
extern void spar_qm_push_local (sparp_t *sparp, int key, SPART *value, int can_overwrite);
extern SPART *spar_qm_get_local (sparp_t *sparp, int key, int error_if_missing);
extern void spar_qm_pop_key (sparp_t *sparp, int key_to_pop);

extern caddr_t spar_make_iri_from_template (sparp_t *sparp, caddr_t tmpl);

#define SPAR_TABLE_IS_SQLQUERY(strg) (('/' == strg[0]) && ('*' == strg[1]))
#define SPAR_SQLQUERY_PLACE(strg) t_box_dv_short_nchars (strg + 2, strstr (strg, "*/") - (strg+2))

extern caddr_t spar_qm_table_or_sqlquery_report_name (caddr_t atbl);
extern caddr_t spar_qm_find_base_alias (sparp_t *sparp, caddr_t descendant_alias);
extern caddr_t spar_qm_find_base_table_or_sqlquery (sparp_t *sparp, caddr_t descendant_alias);
extern dk_set_t spar_qm_find_descendants_of_alias (sparp_t *sparp, caddr_t base_alias);
extern void spar_qm_add_aliased_table_or_sqlquery (sparp_t *sparp, caddr_t parent_qtable, caddr_t new_alias);
extern void spar_qm_add_aliased_alias (sparp_t *sparp, caddr_t parent_alias, caddr_t new_alias);
extern void spar_qm_add_table_filter (sparp_t *sparp, caddr_t tmpl);
extern void spar_qm_add_text_literal (sparp_t *sparp, caddr_t ft_type, caddr_t ft_table_alias, SPART *ft_col, SPART **qmv_cols, SPART **options);
extern void spar_qm_check_filter_aliases (sparp_t *sparp, dk_set_t used_aliases);
extern SPART *sparp_make_qm_sqlcol (sparp_t *sparp, ptrlong type, caddr_t name);
extern caddr_t spar_qm_collist_crc (SPART **cols, const char *prefix, int ignore_order);
extern SPART *spar_make_qm_col_desc (sparp_t *sparp, SPART *col);
extern SPART *spar_make_qm_value (sparp_t *sparp, caddr_t format_name, SPART **cols);
extern void spar_qm_find_all_conditions (sparp_t *sparp, dk_set_t map_aliases, dk_set_t *cond_tmpls_ptr);
extern SPART *spar_make_qm_sql (sparp_t *sparp, const char *fname, SPART **fixed, SPART **named);
extern SPART *spar_make_vector_qm_sql (sparp_t *sparp, SPART **fixed);
extern SPART *spar_make_topmost_qm_sql (sparp_t *sparp);
extern SPART *spar_qm_make_empty_mapping (sparp_t *sparp, caddr_t qm_id, SPART **options);
extern SPART *spar_qm_make_real_mapping (sparp_t *sparp, caddr_t qm_id, SPART **options);


#endif
