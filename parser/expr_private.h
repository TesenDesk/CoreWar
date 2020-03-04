
#ifndef EXPR_PRIVATE_H
#define EXPR_PRIVATE_H

#include "expr.h"
#include "../lexer/token.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum		e_arg_number
{
	OP_NAME = 0,
	FIRST_ARG,
	SECOND_ARG,
	THIRD_ARG,
	LINE_END_ARG
}					t_arg_number;

typedef struct		s_arg
{
	int 			type;
	void 			*value;
}					t_arg;


typedef struct		s_expr
{
	int				type;
	int				size;
	void			*name;
	// t_arg			*args;
	t_arg			args[5];
////	int				ar_size;

	//изменить на индекс
}					t_expr;

#endif
