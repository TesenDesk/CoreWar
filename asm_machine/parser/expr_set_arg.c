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
	if (args_number == UNDEF_ARG) {
//		token_destructor(&token);
//		token = NULL;
	/*
	 * ТЕРЯЕМ ТОКЕНЫ ЗДЕСЬ
	 */
		return (SUCCESS);
	}
	expr->args[args_number].type = arg_type;
	expr->args[args_number].value = (void *)token;
	return (SUCCESS);
}
