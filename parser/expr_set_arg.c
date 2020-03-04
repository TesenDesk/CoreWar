/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_set_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:22:07 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/03 18:57:53 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr_private.h"

/*
**	It sets argument type and token of the argument.
*/

void			expr_set_arg(t_expr *expr, t_token *token,
					int args_number, int arg_type)
{
	expr->args[args_number].type = arg_type;
	expr->args[args_number].value = (void *)token;
	return ;
}