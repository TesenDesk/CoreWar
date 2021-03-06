/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:21:20 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/22 13:02:46 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_expr.h"

int					expr_get_size(t_expr *expr)
{
	return (expr->size);
}

int					expr_get_type(t_expr *expr)
{
	return (expr->type);
}
