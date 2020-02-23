
#include "expr.h"
#include "expr_private.h"
#include "expr_defines.h"

t_expr*               expr_constructor(int type, int size, void *begin)
{
    t_expr         *expr;
    if (!(expr = (t_expr*)malloc(sizeof(t_expr))))
    {
        printf("error\n");
        exit(-1);
    }
    expr->type = type;
    expr->size = size;
    expr->begin = begin;
    return (expr);
}

void                expr_destructor(t_expr **expr)
{
    free(*expr);
    *expr = NULL;
}

