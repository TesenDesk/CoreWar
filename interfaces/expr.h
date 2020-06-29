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


void                *expr_get_first_arg_value(t_expr *expr);
void                *expr_get_second_arg_value(t_expr *expr);
void                *expr_get_third_arg_value(t_expr *expr);
void                *expr_get_first_arg_type(t_expr *expr);
void                *expr_get_second_arg_type(t_expr *expr);
void                *expr_get_third_arg_type(t_expr *expr);


int                 expr_get_arg_type(t_expr *expr, int argnum);

#endif
