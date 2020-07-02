
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

void        *expr_get_arg_value(t_expr *expr, int argnum)
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
	return(expr->args[argnum].value);
}


int                 expr_get_expr_type(t_expr *expr)
{
	if (!expr)
		exit(-1);
	return (expr->type);
}




static void fill_codes(int array_of_codes[NUM_OF_TOKENS])
{
	array_of_codes[TOKEN_AFF] = OP_AFF_CODE;
	array_of_codes[TOKEN_ST]  = OP_ST_CODE;
	array_of_codes[TOKEN_STI] = OP_STI_CODE;
	array_of_codes[TOKEN_ADD] = OP_ADD_CODE;
	array_of_codes[TOKEN_SUB] = OP_SUB_CODE;
	array_of_codes[TOKEN_LD]  = OP_LD_CODE;
	array_of_codes[TOKEN_LLD] = OP_LLD_CODE;
	array_of_codes[TOKEN_LDI] = OP_LDI_CODE;
	array_of_codes[TOKEN_LLDI] = OP_LLDI_CODE;
	array_of_codes[TOKEN_AND] = OP_AND_CODE;
	array_of_codes[TOKEN_OR]  = OP_OR_CODE;
	array_of_codes[TOKEN_XOR] = OP_XOR_CODE;
	array_of_codes[TOKEN_LIVE] = OP_LIVE_CODE;
	array_of_codes[TOKEN_ZJMP] = OP_ZJMP_CODE;
	array_of_codes[TOKEN_FORK] = OP_FORK_CODE;
	array_of_codes[TOKEN_LFORK] = OP_LFORK_CODE;
}


static void map_expr_to_code(t_expr *expr)
{
	static int array_of_exprcodes[NUM_OF_TOKENS];

	if (array_of_exprcodes[TOKEN_LFORK])
		;
	else
		fill_codes(array_of_exprcodes);
	expr->type = array_of_exprcodes[expr->args[OP_NAME].type];
}

void                expr_map_type_to_code(t_expr *expr)
{
	static int array_of_exprcodes[NUM_OF_TOKENS];
	if (!expr)
		exit(-1);
	if (array_of_exprcodes[TOKEN_LFORK])
		;
	else
		fill_codes(array_of_exprcodes);
	expr->type = array_of_exprcodes[expr->args[OP_NAME].type];
}


void                expr_set_dir_size(t_expr *expr, int dir_factor)
{
	if (!expr)
		exit(-1);
	expr->size = dir_factor;
}

int                 expr_get_dir_size(t_expr *expr)
{
	if (!expr)
		exit(-1);
	return (expr->size);
}


//void                *expr_get_first_arg_type(t_expr *expr)
//{
//	if (expr)
//		return((void*)expr->args[FIRST_ARG].type);
//}
//
//void                *expr_get_second_arg_type(t_expr *expr)
//{
//	if (expr)
//		return((void*)expr->args[SECOND_ARG].type);
//}
//
//
//void                *expr_get_third_arg_type(t_expr *expr)
//{
//	if (expr)
//		return((void*)expr->args[THIRD_ARG].type);
//}
