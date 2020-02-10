

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
 * TERM LITERALS
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

/*
 * TERM CODES
 */

#define TERM_UNDEFINED          -1
#define INTEGER_CODE            0
#define COMMENT_CHAR_CODE		1
#define ALT_COMMENT_CHAR_CODE   2

#define REGISTER_CHAR_CODE      3
#define LABEL_CHAR_CODE         4
#define DIRECT_CHAR_CODE        5

#define SEPARATOR_CHAR_CODE     6

#define LABEL_CHARS_CODE		7
#define NAME_CMD_STRING_CODE	8
#define COMMENT_CMD_STRING_CODE	9
#define WHITE_SPACE_CODE        10


#define ADD_NAME_CODE			11
#define AFF_NAME_CODE			12
#define AND_NAME_CODE			13
#define FORK_NAME_CODE		    14
#define LD_NAME_CODE			15
#define LDI_NAME_CODE		    16
#define LFORK_NAME_CODE		    17
#define LIVE_NAME_CODE		    18
#define LLD_NAME_CODE		    19
#define LLDI_NAME_CODE			20
#define OR_NAME_CODE		    21
#define ST_NAME_CODE		    22
#define STI_NAME_CODE		    23
#define SUB_NAME_CODE	        24
#define XOR_NAME_CODE			25
#define ZJMP_NAME_CODE			26

#define QUOTATION_MARK_CODE		27
#





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
