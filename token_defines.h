

/*
 * TOKEN TYPES
 */

#define TOKEN_UNDEF -1
#define TOKEN_EOF 0
#define TOKEN_LFEED 1
#define TOKEN_CHNAME 2
#define TOKEN_CHCOM 3
#define TOKEN_OPX 4
#define TOKEN_TREG 5
#define TOKEN_TIND_INT 6
#define TOKEN_TIND_LAB 7

/*
 * TOKEN TERMS
 */

#define COMMENT_CHAR			'#'
#define ALT_COMMENT_CHAR		';'

#define REGISTER_CHAR           'r'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'

#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
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

//enum							e_words
//{
//	UNDEFINED_TOKEN = -1,
//	EOF_WORD,
//	LINE_FEED,
//	CH_NAME,
//	CH_COMMENT,
//	LABEL_WORD,
//	OP_NAME,
//	T_REG,
//	T_IND,
//	T_DIR
//};
