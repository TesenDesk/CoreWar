#ifndef EXPR_H
#define EXPR_H

//#include "expr_private.h"


typedef struct 	    s_expr t_expr;


/*
 * construction/destruction
*/


t_expr*            expr_constructor(int expr_type,void *expr_ptr[2]);
void               expr_destructor(t_expr **expr);

#endif
