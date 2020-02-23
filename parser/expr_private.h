
#ifndef EXPR_PRIVATE_H
#define EXPR_PRIVATE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct 	    s_expr
{
    int             type;
    int             size;
    void            *begin;
    void            *op;
    int             op_size;

    //изменить на индекс
}				    t_expr;


#endif
