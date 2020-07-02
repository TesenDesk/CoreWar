#ifndef EXPR_H
# define EXPR_H

//#include "expr_private.h"
//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "token.h"
#include "expr_defines.h"
#include "constants.h"

typedef struct s_expr		t_expr;
typedef struct s_arg		t_arg;


typedef enum		e_arg_number
{
	UNDEF_ARG = -1,
	OP_NAME,
	FIRST_ARG,
	SECOND_ARG,
	THIRD_ARG,
	LABEL_ARG,
}					t_arg_number;

typedef struct		s_arg
{
	int 			type;
	void 			*value;
}					t_arg;

enum 				e_t_opcodes
{
	NO_OPCODE = 0,
	OP_LIVE_CODE,
	OP_LD_CODE,
	OP_ST_CODE,
	OP_ADD_CODE,
	OP_SUB_CODE,
	OP_AND_CODE,
	OP_OR_CODE,
	OP_XOR_CODE,
	OP_ZJMP_CODE,
	OP_LDI_CODE,
	OP_STI_CODE,
	OP_FORK_CODE,
	OP_LLD_CODE,
	OP_LLDI_CODE,
	OP_LFORK_CODE,
	OP_AFF_CODE,
	OP_NUM_OF_CODES,
};

/*
 * TOKEN TYPES
 */
//#define NO_TOKEN -1
//#define TOKEN_UNDEF 0
//#define TOKEN_INIT_ST 1
//#define TOKEN_EOF 2
//#define TOKEN_LFEED 3
//#define TOKEN_CHNAME 4
//#define TOKEN_CHCOM 5
//#define TOKEN_OPX 6
//#define TOKEN_TREG 7
//#define TOKEN_TIND_INT 8
//#define TOKEN_TIND_LAB 9
//#define TOKEN_TDIR_INT 10
//#define TOKEN_TDIR_LAB 11

t_expr				*expr_ctor(void);
void				expr_dtor(t_expr **expr);

int					expr_set_arg(t_expr *expr, t_token *token,
						int args_number, int arg_type);
void				*expr_get_arg_value(t_expr *expr, int index);
int                 expr_get_expr_type(t_expr *expr);

void                expr_map_type_to_code(t_expr *expr);
void                expr_set_dir_size(t_expr *expr, int dir_factor);

int                 expr_get_arg_type(t_expr *expr, int argnum);
int                 expr_get_dir_size(t_expr *expr);

#endif
