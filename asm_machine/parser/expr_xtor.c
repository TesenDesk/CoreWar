/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_xtor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:01:04 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/22 13:01:21 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_expr.h"

t_expr				*expr_ctor(void)
{
	t_expr			*expr;

	if (!(expr = (t_expr*)ft_memalloc(sizeof(t_expr))))
	{
		ft_printf("error\n");
		exit(-1);
	}
	expr->type = EXPR_INIT;
	expr->args[OP_NAME].type = ARG_INIT;
	expr->args[FIRST_ARG].type = ARG_INIT;
	expr->args[SECOND_ARG].type = ARG_INIT;
	expr->args[THIRD_ARG].type = ARG_INIT;
	expr->args[LABEL_ARG].type = ARG_INIT;
	expr->args[LINE_END].type = NULL;
	expr->args[JUNK].type = NULL;
	expr->args[OP_NAME].value = NULL;
	expr->args[FIRST_ARG].value = NULL;
	expr->args[SECOND_ARG].value = NULL;
	expr->args[THIRD_ARG].value = NULL;
	expr->args[LABEL_ARG].value = NULL;
	expr->args[LINE_END].value = NULL;
	expr->args[JUNK].value = NULL;
	return (expr);
}

void				expr_dtor(t_expr **expr)
{
	int				i;
	t_arg			*arg;
	t_token			*token;

	i = 0;
	if (expr)
	{
		if (*expr)
		{
			while (i < 7)
			{
				arg = &((*expr)->args[i]);
				token = arg->value;
				token_destructor(&token);
				token = NULL;
				++i;
			}
		}
		free(*expr);
		*expr = NULL;
	}
}
