/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_is_match_op_arithmetic.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:56:06 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 00:56:18 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_is_match_op_arithmetic(t_arguments *self)
{
	int			conclusion;

	conclusion = (self->op_code == OP_ADD || self->op_code == OP_SUB) &&
		self->types == REG_REG_REG;
	return (conclusion);
}
