
#include "expr_private.h"
#include "expr_defines.h"

t_expr*               expr_ctor(void)
{
    t_expr         *expr;
    if (!(expr = (t_expr*)malloc(sizeof(t_expr))))
    {
        printf("error\n");
        exit(-1);
    }
    expr->type = EXPR_INIT;
	expr->args[0].type = ARG_INIT;
	expr->args[1].type = ARG_INIT;
	expr->args[2].type = ARG_INIT;
	expr->args[0].value = NULL;
	expr->args[1].value = NULL;
	expr->args[2].value = NULL;
	expr->ar_size = 0;
    return (expr);
}

void                expr_dtor(t_expr **expr)
{
    free(*expr);
    *expr = NULL;
}

