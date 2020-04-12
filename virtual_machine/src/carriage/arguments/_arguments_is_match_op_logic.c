/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_is_match_op_logic.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:59:35 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 00:59:46 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

int				_arguments_is_match_op_logic(t_arguments *self)
{
	int			conclusion;

	conclusion = (self->op_code == OP_AND ||
		self->op_code == OP_OR || self->op_code == OP_XOR) &&
		_arguments_not_nil_not_nil_reg(self);
	return (conclusion);
}
