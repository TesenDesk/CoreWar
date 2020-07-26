/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:21:20 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/19 19:32:24 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_expr.h"

t_expr				*expr_ctor(void)
{
	t_expr			*expr;

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

int 				expr_get_arg_type(t_expr *expr, int index)
{
	return (expr->args[index].type);
}

int 				expr_get_arg_size(t_expr *expr)
{
	return (expr->arg_size);
}

t_arg 				*expr_get_arg(t_expr *expr, int index)
{
	return (&(expr->args[index]));
}

int					expr_get_size(t_expr *expr)
{
	return (expr->size);
}

int					expr_get_type(t_expr *expr)
{
	return (expr->type);
}



