

#ifndef TOKEN_DEFINES_H
#define TOKEN_DEFINES_H
/*
 * TOKEN TYPES
 */
enum			e_token_types
{
	NO_TOKEN = -1,
	TOKEN_LFEED,
	TOKEN_LABEL_WORD,
	TOKEN_CHNAME,
	TOKEN_CHCOM,
	/*
	*TOKEN_AFFCt_arg
	*/
	TOKEN_AFF,
	/*
	*TOKEN_St_arg
	*/
	TOKEN_ST,
	/*
	* TOKEN_STI_OP
	*/
	TOKEN_STI,
	/*
	* TOKEN_ARITHM_OP
	*/
	TOKEN_ADD,
	TOKEN_SUB,
	/*
	* TOKEN_LOAD_OP
	*/
	TOKEN_LD,
	TOKEN_LLD,
	/*
	* TOKEN_LOADI_OP
	*/
	TOKEN_LDI,
	TOKEN_LLDI,
	/*
	* TOKEN_LOGIC_OP
	*/
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_XOR,
	/*
	* TOKEN_LIFE_OP
	*/
	TOKEN_LIVE,
	TOKEN_ZJMP,
	TOKEN_FORK,
	TOKEN_LFORK,
	/*
	* TOKEN_ARGS
	*/
	TOKEN_TREG,
	TOKEN_TIND_INT,
	TOKEN_TIND_LAB,
	TOKEN_TDIR_INT,
	TOKEN_TDIR_LAB,

	TOKEN_UNDEF,
	TOKEN_INIT_ST,
	TOKEN_EOF,
	NUM_OF_TOKENS,
};

// #define NO_TOKEN -1
// #define TOKEN_UNDEF 0
// #define TOKEN_INIT_ST 1
// #define TOKEN_EOF 2
// #define TOKEN_LFEED 3
// #define TOKEN_CHNAME 4
// #define TOKEN_CHCOM 5
// /*
//  * TOKEN_LIFE_OP
//  */
// #define TOKEN_LIVE 6
// #define TOKEN_ZJMP 7
// #define TOKEN_FORK 8
// #define TOKEN_LFORK 9
// /*
//  *TOKEN_AFFCt_arg
//  */
// #define TOKEN_AFF 10
// /*
//  * TOKEN_LOAD_OP
//  */
// #define TOKEN_LD 11
// #define TOKEN_LLD 12
// /*
//  *TOKEN_St_arg
//  */
// #define TOKEN_ST 13
// /*
//  * TOKEN_ARITHM_OP
//  */
// #define TOKEN_ADD 14
// #define TOKEN_SUB 15
// /*
//  * TOKEN_LOADI_OP
//  */
// #define TOKEN_LDI 16
// #define TOKEN_LLDI 17
// /*
//  * TOKEN_LOGIC_OP
//  */
// #define TOKEN_AND 18
// #define TOKEN_OR 19
// #define TOKEN_XOR 20
// /*
//  * TOKEN_STI_OP
//  */
// #define TOKEN_STI 21
// /*
//  * TOKEN_ARGS
//  */
// #define TOKEN_TREG 22
// #define TOKEN_TIND_INT 23
// #define TOKEN_TIND_LAB 24
// #define TOKEN_TDIR_INT 25
// #define TOKEN_TDIR_LAB 26
//
// #define TOKEN_LABEL_WORD 27

/*
 * TERM LITERALS
 */

#include "libft.h"

#define COMMENT_CHAR			'#'
#define ALT_COMMENT_CHAR		';'

#define REGISTER_CHAR			'r'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'

#define SEPARATOR_CHAR			','
#define LINE_FEED				'\n'

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789" // 17
#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"
#define WHITE_SPACE				" \t"

/*
** Operation names.
*/

#define ADD_NAME				"add"
#define AFF_NAME				"aff"
#define AND_NAME				"and"
#define FORK_NAME				"fork"
#define LD_NAME					"ld"
#define LDI_NAME				"ldi"
#define LFORK_NAME				"lfork"
#define LIVE_NAME				"live"
#define LLD_NAME				"lld"
#define LLDI_NAME				"lldi"
#define OR_NAME					"or"
#define ST_NAME					"st"
#define STI_NAME				"sti"
#define SUB_NAME				"sub"
#define XOR_NAME				"xor"
#define ZJMP_NAME				"zjmp"

#define QUOTATION_MARK			'\"'

/*
 * TERM CODES
 */
enum							e_term_codes
{
	TERM_UNDEFINED_CODE = -1,
	INTEGER_CODE,
	COMMENT_CHAR_CODE,
	ALT_COMMENT_CHAR_CODE,
	REGISTER_CHAR_CODE,
	LABEL_CHAR_CODE,
	DIRECT_CHAR_CODE,
	SEPARATOR_CHAR_CODE,
	LABEL_CHARS_CODE,
	NAME_CMD_STRING_CODE,
	COMMENT_CMD_STRING_CODE,
	WHITE_SPACE_CODE,
	ADD_NAME_CODE,
	AFF_NAME_CODE,
	AND_NAME_CODE,
	FORK_NAME_CODE,
	LD_NAME_CODE,
	LDI_NAME_CODE,
	LFORK_NAME_CODE,
	LIVE_NAME_CODE,
	LLD_NAME_CODE,
	LLDI_NAME_CODE,
	OR_NAME_CODE,
	ST_NAME_CODE,
	STI_NAME_CODE,
	SUB_NAME_CODE,
	XOR_NAME_CODE,
	ZJMP_NAME_CODE,
	OPX_CODE,
	QUOTATION_MARK_CODE,
	LINE_FEED_CODE,
	EOF_CODE,
};

#endif

