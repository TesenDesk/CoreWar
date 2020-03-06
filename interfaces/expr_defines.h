

#ifndef EXPR_DEFINES_H
#define EXPR_DEFINES_H

/*
 * EXPR_DEFINES
 */

// #define EXPR_UNDEF -1
// #define EXPR_INIT 0
// #define EXPR_CH_NAME_LINE 1
// #define EXPR_CH_COMMENT_LINE 2
// #define EXPR_PRECODE_COMMENT_LINE 3
// #define EXPR_CODE_COMMENT_LINE 4
// #define EXPR_OP_LIFE 5
// #define EXPR_OP_AFCT 6
// #define EXPR_OP_STOR 7
// #define EXPR_OP_LOAD 8
// #define EXPR_OP_STRI 9
// #define EXPR_OP_ARIT 10
// #define EXPR_OP_LODI 11
// #define EXPR_OP_LOGC 12

typedef enum		e_expr_defines
{
	EXPR_UNDEF = -1,
	EXPR_INIT,
	COM_LIVE,
	COM_LD,
	COM_ST,
	COM_ADD,
	COM_SUB,
	COM_AND,
	COM_OR,
	COM_XOR,
	COM_ZJMP,
	COM_LDI,
	COM_STI,
	COM_FORK,
	COM_LLD,
	COM_LLDI,
	COM_LFORK,
	COM_AFF,
	EXPR_LFEED,
	EXPR_LABEL_W,
	EXPR_CH_NAME_LINE,
	EXPR_CH_COMMENT_LINE,
	EXPR_OP_AFCT,
	EXPR_OP_STOR,
	EXPR_OP_STRI,
	EXPR_OP_ARIT,
	EXPR_OP_LOAD,
	EXPR_OP_LODI,
	EXPR_OP_LOGC,
	EXPR_OP_LIFE,
	// EXPR_PRECODE_COMMENT_LINE,
	// EXPR_CODE_COMMENT_LINE,
}					t_expr_defines;


// #define ARG_INIT	0
// #define ARG_TREG	1
// #define ARG_DIR_LAB	2
// #define ARG_DIR_INT	3
// #define ARG_IND_LAB	4
// #define ARG_IND_INT	5

typedef enum		e_arg_defines
{
	ARG_INIT = 0,
	ARG_TREG,
	ARG_DIR_LAB,
	ARG_DIR_INT,
	ARG_IND_LAB,
	ARG_IND_INT,
}					t_arg_defines;


/*
 * TOKEN_TYPES
 */

// #define TOKEN_UNDEF -1
// #define TOKEN_INIT_ST 0
// #define TOKEN_EOF 1
// #define TOKEN_LFEED 2
// #define TOKEN_CHNAME 3
// #define TOKEN_CHCOM 4
// #define TOKEN_OPX 5
// #define TOKEN_TREG 6
// #define TOKEN_TIND_INT 7
// #define TOKEN_TIND_LAB 8
// #define TOKEN_TDIR_INT 9
// #define TOKEN_TDIR_LAB 10

#endif
