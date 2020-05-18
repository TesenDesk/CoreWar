
#include "expr_private.h"


t_expr					*expr_ctor(void)
{
	t_expr				*expr;
	if (!(expr = (t_expr*)ft_memalloc(sizeof(t_expr))))
	{
		printf("error\n");
		exit(-1);
	}
	expr->type = EXPR_INIT;
	expr->args[OP_NAME].type = ARG_INIT;
	expr->args[FIRST_ARG].type = ARG_INIT;
	expr->args[SECOND_ARG].type = ARG_INIT;
	expr->args[THIRD_ARG].type = ARG_INIT;
	expr->args[LABEL_ARG].type = ARG_INIT;

	return (expr);
}

void				expr_dtor(t_expr **expr)
{
	free(*expr);
	*expr = NULL;
}

void				*expr_get_arg_value(t_expr *expr, int index)
{
	return (expr->args[index].value);
}

