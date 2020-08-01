/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_set_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:22:07 by ftothmur          #+#    #+#             */
/*   Updated: 2020/07/19 19:34:33 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_expr.h"

/*
**	It sets argument type and token of the argument.
*/

int			expr_set_arg(t_expr *expr, t_token *token,
					int args_number, int arg_type)
{
	printf("!!!%d\n", args_number);
	if (args_number == JUNK || args_number == LINE_END) {
		if (expr->args[args_number].value != NULL)
		{
			printf("!!!!!!!!!!!!, %d\n", args_number);
			token_destructor(&(expr->args[args_number].value));
			expr->args[args_number].value = NULL;
		}

//		token_destructor(&token);
//		token = NULL;
//		token_destructor(&token);
//		token = NULL;
	/*
	 * ТЕРЯЕМ ТОКЕНЫ ЗДЕСЬ
	 */
//		return (SUCCESS);
	}
	expr->args[args_number].type = arg_type;
	expr->args[args_number].value = (void *)token;
	return (SUCCESS);
}
