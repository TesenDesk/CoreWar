/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_get_arg_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:02:17 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/22 13:02:35 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_expr.h"

void				*expr_get_arg_value(t_expr *expr, int index)
{
	return (expr->args[index].value);
}

int					expr_get_arg_type(t_expr *expr, int index)
{
	return (expr->args[index].type);
}

int					expr_get_arg_size(t_expr *expr)
{
	return (expr->arg_size);
}

t_arg				*expr_get_arg(t_expr *expr, int index)
{
	return (&(expr->args[index]));
}
