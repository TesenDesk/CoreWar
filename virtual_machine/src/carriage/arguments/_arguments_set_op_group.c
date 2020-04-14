/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments_set_op_group.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 22:29:29 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:29:53 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

void			_arguments_set_op_group(t_arguments *self)
{
	if (_arguments_op_code_is_op_life(self) == TRUE)
		self->op_group = OP_LIFE;
	else if (_arguments_op_code_is_affect(self) == TRUE)
		self->op_group = OP_AFFECT;
	else if (_arguments_op_code_is_load(self) == TRUE)
		self->op_group = OP_LOAD;
	else if (arguments_op_code_is_store(self) == TRUE)
		self->op_group = OP_STORE;
	else if (_arguments_op_code_is_load_i(self) == TRUE)
		self->op_group = OP_LOAD_I;
	else if (arguments_op_code_is_store_i(self) == TRUE)
		self->op_group = OP_STORE_I;
	else if (_arguments_op_code_is_logic(self) == TRUE)
		self->op_group = OP_LOGIC;
	else if (arguments_op_code_is_arithmetic(self) == TRUE)
		self->op_group = OP_ARITHMETIC;
	else
		self->op_group = OP_ERROR;
	return;
}
