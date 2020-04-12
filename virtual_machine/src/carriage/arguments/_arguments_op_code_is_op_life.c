/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_op_code_is_op_life.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:01:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 01:01:49 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_op_code_is_op_life(t_arguments *self)
{
	int			conclusion;

	if (
		self->op_code == OP_LIVE ||
		self->op_code == OP_ZJMP ||
		self->op_code == OP_FORK ||
		self->op_code == OP_LFORK)
		conclusion = TRUE;
	else
		conclusion = FALSE;
	return (conclusion);
}
