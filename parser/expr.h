#ifndef EXPR_H
# define EXPR_H

//#include "expr_private.h"
#include "../lexer/token.h"

typedef struct 	    s_expr t_expr;
typedef struct		s_arg	t_arg;

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

#endif
