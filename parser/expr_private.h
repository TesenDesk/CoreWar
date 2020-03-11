
#ifndef EXPR_PRIVATE_H
#define EXPR_PRIVATE_H

#include "expr.h"

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
