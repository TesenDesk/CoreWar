
#ifndef EXPR_PRIVATE_H
#define EXPR_PRIVATE_H

#include "expr.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct		s_op
{
	int 			type;
	void 			*value;
}					t_arg;


typedef struct 	    s_expr
{
    int             type;
    int             size;
    t_arg            *args;
    int             ar_size;

    //изменить на индекс
}				    t_expr;

#endif
