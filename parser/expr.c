
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
	expr->args[OP_NAME].value = NULL;
	expr->args[FIRST_ARG].value = NULL;
	expr->args[SECOND_ARG].value = NULL;
	expr->args[THIRD_ARG].value = NULL;
	expr->args[LABEL_ARG].value = NULL;

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

void                *expr_get_first_arg_value(t_expr *expr)
{
	if (expr)
		return((void*)expr->args[FIRST_ARG].value);
}

void                *expr_get_second_arg_value(t_expr *expr)
{
	if (expr)
		return((void*)expr->args[SECOND_ARG].value);
}


void                *expr_get_third_arg_value(t_expr *expr)
{
	if (expr)
		return((void*)expr->args[THIRD_ARG].value);
}

int             expr_get_arg_type(t_expr *expr, int argnum)
{
	if (argnum > 5 || argnum < 0)
	{
		printf("wrong argnum\n");
		exit(-1);
	}
	if (!expr) {
		printf("no_expr_arg\n");
		exit(-1);
	}
	if (!(expr->args))
	{
		printf("args_undef\n");
		exit(-1);
	}
	return(expr->args[argnum].type);
}
void                *expr_get_first_arg_type(t_expr *expr)
{
	if (expr)
		return((void*)expr->args[FIRST_ARG].type);
}

void                *expr_get_second_arg_type(t_expr *expr)
{
	if (expr)
		return((void*)expr->args[SECOND_ARG].type);
}


void                *expr_get_third_arg_type(t_expr *expr)
{
	if (expr)
		return((void*)expr->args[THIRD_ARG].type);
}
