/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_set_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:22:07 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/16 13:53:42 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_expr.h"

/*
**	It sets argument type and token of the argument.
** 	if (args_number == JUNK || args_number == LINE_END)
** line 30 ТЕРЯЕМ ТОКЕНЫ ЗДЕСЬ
*/

int			expr_set_arg(t_expr *expr, t_token *token,
					int args_number, int arg_type)
{
	if (args_number == JUNK || args_number == LINE_END)
	{
		if (expr->args[args_number].value != NULL)
		{
			token_destructor((t_token **)&(expr->args[args_number].value));
			expr->args[args_number].value = NULL;
		}
	}
	expr->args[args_number].type = arg_type;
	expr->args[args_number].value = (void *)token;
	return (SUCCESS);
}
