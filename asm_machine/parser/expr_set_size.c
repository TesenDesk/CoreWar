/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_set_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:36:09 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/22 13:13:42 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_expr.h"

void		expr_set_size(t_expr *q)
{
	if (q->args[OP_NAME].type == TOKEN_ZJMP
		|| q->args[OP_NAME].type == TOKEN_LDI
		|| q->args[OP_NAME].type == TOKEN_STI
		|| q->args[OP_NAME].type == TOKEN_FORK
		|| q->args[OP_NAME].type == TOKEN_LLDI
		|| q->args[OP_NAME].type == TOKEN_LFORK)
		q->size = 2;
	else
		q->size = 1;
}
